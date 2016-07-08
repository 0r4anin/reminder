#include "reminder.h"
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>
#include <QFile>
#include <QTimer>

#include <reminder_def.h>
//используем screensaver
#include <X11/Xlib.h>
#include <X11/extensions/dpms.h>
#include <X11/extensions/scrnsaver.h>

Reminder::Reminder(QObject *parent) : QObject(parent)
{
    if (!QSystemTrayIcon::isSystemTrayAvailable())
    {
        QMessageBox::critical(0, trUtf8("Напоминалка"),
                              trUtf8("Systray icon недоступна - увы..."));
        exit(0);
    }
    checkDataBase();


    trayIcon = new QSystemTrayIcon();

    trayIcon->setIcon(QIcon("://icon/reminder.png"));
    trayIcon->setToolTip(trUtf8("Напоминалка"));
    trayIcon->setVisible(true);

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(triggerTrayIcon(QSystemTrayIcon::ActivationReason)));
    _lastReminde = QDateTime::currentDateTime();
}

Reminder::~Reminder()
{
    trayIcon->hide();
}

void Reminder::rereadsettings()
{
    //Нужно завести таймер на периодические напомнинания

}

void Reminder::showTrayIcon()
{
    trayIcon->show();

}

void Reminder::hideTrayIcon()
{
    trayIcon->hide();
}

void Reminder::showMessage(QString title, QString message)
{
    if ((QDateTime::currentDateTime().toTime_t() - _lastReminde.toTime_t()) > 10)
    {
        trayIcon->showMessage(title, message);
    }
    else //отложим напоминание
    {
//        QTimer::singleShot((QDateTime::currentDateTime().toTime_t() - _lastReminde.toTime_t() + 1)*1000, this, showMessage(title, message));//используем лямбда
    }
}

void Reminder::triggerTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
//    Unknown,
//    Context,
//    DoubleClick,
//    Trigger,
//    MiddleClick
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        emit showSettingsWindow();
        break;
    default:
        qDebug()<<"не знаю ничего - такого не обрабатывается";
        break;
    }
}

void Reminder::checkDataBase()
{
    if (!_db.isDriverAvailable("QSQLITE"))
    {
        QMessageBox::critical(0, trUtf8("Напоминалка"),
                              trUtf8("Увы не хватает драйвера sqlite..."),
                              QMessageBox::Ok);

        exit(0);
    }

    if (!QFile::exists(QCoreApplication::applicationDirPath() + SETTINGSDB_PATH))
    {
        QMessageBox::critical(0, trUtf8("Напоминалка"),
                              trUtf8("Не могу найти базу с настройками %1").arg(SETTINGSDB_PATH),
                              QMessageBox::Ok);

        exit(0);
    }


    _db = QSqlDatabase::addDatabase("QSQLITE");

    if (!_db.isOpen())
    {
        _db.setDatabaseName(QCoreApplication::applicationDirPath() + SETTINGSDB_PATH);
        if (!_db.open())
        {
            QMessageBox::critical(0, trUtf8("Напоминалка"),
                                  trUtf8("Не могу открыть базу с настройками %1").arg(SETTINGSDB_PATH),
                                  QMessageBox::Ok);
        }
    }
}

quint64 Reminder::getIddleTime()
{

    XScreenSaverInfo ssi;
    Display *dpy;
    dpy = XOpenDisplay(NULL);
    if (dpy == NULL) {
        qDebug()<< "couldn't open display";
        return 0;
    }
    int event_basep, error_basep;
    if (!XScreenSaverQueryExtension(dpy, &event_basep, &error_basep)) {
        qDebug()<< "screen saver extension not supported";
        return 0;
    }

    if (!XScreenSaverQueryInfo(dpy, DefaultRootWindow(dpy), &ssi)) {
        qDebug()<< "couldn't query screen saver info";
        return 0;
    }

    int dummy;
    CARD16 standby, suspend, off;
    CARD16 state;
    BOOL onoff;
    quint64 _idleTime = ssi.idle;

    if (DPMSQueryExtension(dpy, &dummy, &dummy)) {
        if (DPMSCapable(dpy)) {
            DPMSGetTimeouts(dpy, &standby, &suspend, &off);
            DPMSInfo(dpy, &state, &onoff);

            if (onoff) {
                switch (state) {
                case DPMSModeStandby:
                    /* this check is a littlebit paranoid, but be sure */
                    if (_idleTime < (unsigned) (standby * 1000))
                        _idleTime += (standby * 1000);
                    break;
                case DPMSModeSuspend:
                    if (_idleTime < (unsigned) ((suspend + standby) * 1000))
                        _idleTime += ((suspend + standby) * 1000);
                    break;
                case DPMSModeOff:
                    if (_idleTime < (unsigned) ((off + suspend + standby) * 1000))
                        _idleTime += ((off + suspend + standby) * 1000);
                    break;
                case DPMSModeOn:
                default:
                    break;
                }
            }
        }
    }



    XCloseDisplay(dpy);
    return _idleTime;
}

