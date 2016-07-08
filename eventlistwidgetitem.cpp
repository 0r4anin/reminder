#include "eventlistwidgetitem.h"

EventListWidgetItem::EventListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uilistitem)
{
    ui->setupUi(this);
//    connect(ui->checkButton, SIGNAL());


}

void EventListWidgetItem::changeEnabled()
{

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

