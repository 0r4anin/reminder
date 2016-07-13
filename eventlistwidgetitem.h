#ifndef EVENTLISTWIDGETITEM_H
#define EVENTLISTWIDGETITEM_H

#include <QWidget>

#include "ui_eventlistwidgetitem.h"

class EventListWidgetItem : public QWidget
{
    Q_OBJECT
public:
    EventListWidgetItem(QWidget *parent = 0);

    void loadFromDBByType(int type);
    void setIconPath(QString path);
    void setEventName(QString name);
    void setMessages(QString msg1, QString msg2);
    void setTimes(QTime tm1, QTime tm2);

private slots:
    void changeEnabled();
    void saveChangesToDB();

signals:
    void hasChanges();


private:
    Ui::uilistitem *ui;
    int _currentType;
};

#endif // EVENTLISTWIDGETITEM_H
