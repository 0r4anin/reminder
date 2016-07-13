#include "eventlistwidgetitem.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

EventListWidgetItem::EventListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uilistitem)
{
    ui->setupUi(this);
    connect(ui->checkButton, SIGNAL(released()), this, SLOT(changeEnabled()));
    connect(ui->textMessage, SIGNAL(textEdited(QString)), this, SLOT(saveChangesToDB()));
    connect(ui->repeatTextMessage, SIGNAL(textEdited(QString)), this, SLOT(saveChangesToDB()));
    connect(ui->eventTime, SIGNAL(userTimeChanged(QTime)), this, SLOT(saveChangesToDB()));
    connect(ui->repeatTime, SIGNAL(userTimeChanged(QTime)), this, SLOT(saveChangesToDB()));

    _currentType = 0;
}

void EventListWidgetItem::loadFromDBByType(int type)
{
    _currentType = type;
    QSqlQuery query;
    query.exec(QString("SELECT eventName, message1, message2, eventTimer1, eventTimer2, enabled FROM event WHERE eventType=%1").arg(type));

    if (query.next())
    {
        setMessages(query.value("message1").toString(), query.value("message2").toString());
        setTimes(QTime::fromMSecsSinceStartOfDay(query.value("eventTimer1").toInt()*1000),
                 QTime::fromMSecsSinceStartOfDay(query.value("eventTimer2").toInt()*1000));
        setEventName(query.value("eventName").toString());

        if (!(query.value("enabled").toInt() > 0 && ui->eventName->isEnabled()))
        {
            changeEnabled();
        }
    }

    switch(type)
    {
    case 1:
        setIconPath(":/icon/seeting.png");
        break;
    case 2:
        setIconPath(":/icon/work_time.png");
        break;
    case 3:
        setIconPath(":/icon/internet.png");
        break;
    }
}

void EventListWidgetItem::changeEnabled()
{
    if (ui->eventName->isEnabled())
    {
        ui->eventName->setEnabled(false);
        ui->eventTime->setEnabled(false);
        ui->image->setEnabled(false);
        ui->textMessage->setEnabled(false);
        ui->repeatTextMessage->setEnabled(false);
        ui->repeatTime->setEnabled(false);
        ui->label->setEnabled(false);
        ui->label_2->setEnabled(false);
        ui->checkButton->setIcon(QIcon(":/icon/check.png"));

    }else
    {
        ui->eventName->setEnabled(true);
        ui->eventTime->setEnabled(true);
        ui->image->setEnabled(true);
        ui->textMessage->setEnabled(true);
        ui->repeatTextMessage->setEnabled(true);
        ui->repeatTime->setEnabled(true);
        ui->label->setEnabled(true);
        ui->label_2->setEnabled(true);
        ui->checkButton->setIcon(QIcon(":/icon/sign-error.png"));
    }
    saveChangesToDB();
}

void EventListWidgetItem::saveChangesToDB()
{
    if (_currentType > 0)
    {
        QSqlQuery query;
        if (!query.exec(QString("UPDATE event SET message1='%2', message2='%3', eventTimer1=%4, eventTimer2=%5, enabled=%6 WHERE eventType=%1").arg(_currentType)
                   .arg(ui->textMessage->text())
                   .arg(ui->repeatTextMessage->text())
                   .arg(ui->eventTime->time().msecsSinceStartOfDay() / 1000)
                   .arg(ui->repeatTime->time().msecsSinceStartOfDay() / 1000)
                   .arg(ui->eventName->isEnabled() ? 1 : 0)))
        {
            qDebug()<<query.lastError().text();
        }


    }

    emit hasChanges();
}

void EventListWidgetItem::setIconPath(QString path)
{
    ui->image->setPixmap(QPixmap(path));

}

void EventListWidgetItem::setEventName(QString name)
{
    ui->eventName->setText(name);
}

void EventListWidgetItem::setMessages(QString msg1, QString msg2)
{
    ui->textMessage->setText(msg1);
    ui->repeatTextMessage->setText(msg2);
}

void EventListWidgetItem::setTimes(QTime tm1, QTime tm2)
{
    ui->eventTime->setTime(tm1);
    ui->repeatTime->setTime(tm2);
}

