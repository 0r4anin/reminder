#include "eventlistwidgetitem.h"

EventListWidgetItem::EventListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uilistitem)
{
    ui->setupUi(this);
    connect(ui->checkButton, SIGNAL(released()), this, SLOT(changeEnabled()));


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

