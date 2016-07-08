#-------------------------------------------------
#
# Project created by QtCreator 2016-07-07T09:02:01
#
#-------------------------------------------------

QT       += core gui dbus sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lX11 -lXss -lXext

TARGET = reminder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reminder.cpp \
    eventlistwidgetitem.cpp

HEADERS  += mainwindow.h \
    reminder.h \
    reminder_def.h \
    eventlistwidgetitem.h

FORMS    += mainwindow.ui \
    eventlistwidgetitem.ui

DESTDIR = ./bin
MOC_DIR     += ./mocs # для файлов moc-компилятора
OBJECTS_DIR += ./objs # для объектных файлов


RESOURCES += \
    img.qrc

DISTFILES +=
