#ifndef REMINDER_H
#define REMINDER_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QSqlDatabase>
#include <QDateTime>
#include <QStringList>
#include <QList>
#include <QTimerEvent>

#include <reminder_def.h>

#include <QMenu>
#include <QMap>


class Reminder : public QObject
{
    Q_OBJECT
public:
    explicit Reminder(QObject *parent = 0);
    ~Reminder();

signals:
    void showSettingsWindow();
    void showAboutWindow();
    void aboutToClose();



public slots:
    void rereadsettings();
    void showTrayIcon();
    void hideTrayIcon();
    void showMessage(QString title, QString message);

private slots:
    void triggerTrayIcon(QSystemTrayIcon::ActivationReason reason);

protected:
    virtual void timerEvent(QTimerEvent *);

private:
    QSystemTrayIcon *trayIcon;
    QSqlDatabase _db;
    QDateTime _lastReminde;
    QMenu *_mn;
    QMap<int, EventHolder> _eventParams;
    QList<QStringList> _messageQuery;
    QTime _iddleTime;
    QTime _goHomeTime;
    QTime _internetTime;


    bool _eventCircleExit;

    void checkDataBase();
    quint64 getIddleTime();
    QString getFocusWindowName();

};

#endif // REMINDER_H
