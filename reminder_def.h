#ifndef REMINDER_DEF_H
#define REMINDER_DEF_H

#include <QString>

#define SETTINGSDB_PATH "/reminder.sqlite"

struct EventHolder {
    bool enabled;
    QString eventName;
    int eventType;
    time_t timer1;
    time_t timer2;
    QString msg1;
    bool msg1Showed;
    QString msg2;
    bool msg2Showed;
};

struct MessageHolder {
    int msgType;
    QString title;
    QString message;
};


#endif // REMINDER_DEF_H

