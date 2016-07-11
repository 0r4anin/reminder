#ifndef REMINDER_H
#define REMINDER_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QSqlDatabase>
#include <QDateTime>

#include <QMenu>



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

private:
    QSystemTrayIcon *trayIcon;
    QSqlDatabase _db;
    QDateTime _lastReminde;
    QMenu *_mn;


    void checkDataBase();
    void eventCircle();

    quint64 getIddleTime();

};

#endif // REMINDER_H
