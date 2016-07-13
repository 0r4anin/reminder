#include "reminder.h"
#include <QDebug>
#include <QMessageBox>
#include <QCoreApplication>
#include <QFile>
#include <QTimer>
#include <QSqlQuery>
#include <QMenu>
#include <QTime>
#include <QtConcurrent/QtConcurrentRun>

#include <unistd.h>


//используем screensaver
#include <X11/Xlib.h>
#include <X11/extensions/dpms.h>
#include <X11/extensions/scrnsaver.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/Xos.h>
#include <X11/extensions/shape.h>
#include <X11/Xlocale.h>

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

    QMenu *mn = new QMenu();
    mn->addAction("О программе", this, SIGNAL(showAboutWindow()));
    mn->addAction("Показать насткойки", this, SIGNAL(showSettingsWindow()));
    mn->addSeparator();
    mn->addAction("Выйти из программы", this, SIGNAL(aboutToClose()));


    this->startTimer(1000);

    trayIcon->setContextMenu(mn);

    _mn = mn;
    _eventCircleExit = false;
    _iddleTime.start();
    _goHomeTime.start();
    _internetTime.start();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(triggerTrayIcon(QSystemTrayIcon::ActivationReason)));
    _lastReminde = QDateTime::currentDateTime();

    rereadsettings();

}

Reminder::~Reminder()
{
    trayIcon->hide();
}

void Reminder::rereadsettings()
{
    //Нужно завести таймер на периодические напомнинания
    _eventCircleExit = false;
    _eventParams.clear();
    QSqlQuery query;
//    //нужно вычитать настройки по event`ам
    query.exec("SELECT eventName, eventType, message1, message2, eventTimer1, eventTimer2, enabled FROM event");

    while(query.next())
    {
        EventHolder tmp;
        tmp.eventName = query.value(0).toString();
        tmp.eventType = query.value(1).toInt();
        tmp.msg1 = query.value(2).toString();
        tmp.msg2 = query.value(3).toString();
        tmp.timer1 = query.value(4).toUInt();
        tmp.timer2 = query.value(5).toUInt();
        tmp.enabled = query.value(5).toUInt() > 0 ? true : false;
        tmp.msg1Showed = false;
        tmp.msg2Showed = false;
        _eventParams.insert(query.value(1).toInt(), tmp);
    }


    _eventCircleExit = true;

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
        _messageQuery.append(QStringList()<<title<<message);
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
    case QSystemTrayIcon::MiddleClick:
        _mn->show();
        break;
    case QSystemTrayIcon::DoubleClick:
        emit showSettingsWindow();
        break;
    default:
        qDebug()<<"не знаю ничего - такого не обрабатывается";
        break;
    }
}

void Reminder::timerEvent(QTimerEvent *)
{
    if (!_messageQuery.isEmpty())
    {
        QStringList lst = _messageQuery.takeFirst();
        showMessage(lst.at(0),lst.at(1));
    }


    if(_eventCircleExit)
    {
        if (_eventParams[1].enabled ) // событие просиживания штанов
        {
            if (_iddleTime.elapsed() > _eventParams[1].timer2 * 1000 && !_eventParams[1].msg2Showed)
            {
                    //показать msg2

                _eventParams[1].msg2Showed = true;
            }
            else if (_iddleTime.elapsed() > _eventParams[1].timer1 * 1000 && !_eventParams[1].msg1Showed)
            {
                showMessage(_eventParams[1].eventName, _eventParams[1].msg1);
                _eventParams[1].msg1Showed = true;

            }
            else if (getIddleTime() > 60000)
            {
                _iddleTime.restart();
                _eventParams[1].msg1Showed = false;
                _eventParams[1].msg2Showed = false;

            }

        }

        if (_eventParams[2].enabled ) // событие пора собираться домой
        {
            if (_iddleTime.elapsed() > _eventParams[2].timer2 * 1000 && !_eventParams[2].msg2Showed)
            {

                //показать msg2
                _eventParams[2].msg2Showed = true;

            } else if (_iddleTime.elapsed() > _eventParams[2].timer1 * 1000 && !_eventParams[2].msg1Showed)
            {

                showMessage(_eventParams[2].eventName, _eventParams[2].msg1);

                _eventParams[2].msg1Showed = true;

            }
        }

        if (_eventParams[3].enabled ) // событие сидения в интернете
        {
            QString str = getFocusWindowName();


            if (str.contains("Chrome"))
            {
                if (_internetTime.elapsed() > _eventParams[3].timer2 * 1000 && !_eventParams[3].msg2Showed)
                {
                    _eventParams[3].msg2Showed = true;
                }else if (_internetTime.elapsed() > _eventParams[3].timer1 * 1000 && !_eventParams[3].msg1Showed)
                {
                    showMessage(_eventParams[3].eventName, _eventParams[3].msg1);
                    _eventParams[3].msg1Showed = true;
                }

            }else
            {
                _internetTime.restart();
                _eventParams[3].msg1Showed = false;
                _eventParams[3].msg2Showed = false;
            }
        }
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
            exit(0);
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

QString Reminder::getFocusWindowName()
{
    QString str;
    XScreenSaverInfo ssi;
    Display *dpy;
    Window focus;
    XTextProperty tp;

    int revert;
    char *window_name;
    dpy = XOpenDisplay(NULL);
    if (dpy == NULL) {
        qDebug()<< "couldn't open display";
        return str;
    }

    XGetInputFocus(dpy, &focus, &revert);
    if (XFetchName(dpy, focus, &window_name))
    {
        str.append(window_name);
    }
    else if (!XGetWMName(dpy, focus, &tp)) { /* Get window name if any */
        qDebug()<<" (has no name)";
    } else if (tp.nitems > 0) {

        {
            int count = 0, i, ret;
            char **list = NULL;
            ret = XmbTextPropertyToTextList(dpy, &tp, &list, &count);
            if((ret == Success || ret > 0) && list != NULL){
                for(i=0; i<count; i++)
                {
                    str.append(list[i]);
                }
                XFreeStringList(list);
            } else {
                {
                    str.append((char*)tp.value);
                }
            }
        }

    }

    XCloseDisplay(dpy);
//    qDebug()<<str;
    return str;
}




