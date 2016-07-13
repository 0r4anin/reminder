#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>
#include <QListWidgetItem>
#include <eventlistwidgetitem.h>

MainWindow::MainWindow(Reminder *r, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(r, SIGNAL(showSettingsWindow()), this, SLOT(show()));
    connect(this, SIGNAL(settingsChanged()), r, SLOT(rereadsettings()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
    connect(r, SIGNAL(aboutToClose()), this, SLOT(on_action_triggered()));


    _readyToClose = false;

    //заводим event
    for (int i=1; i <= 3; i++)
    {
        EventListWidgetItem *nt = new EventListWidgetItem(this);
        nt->loadFromDBByType(i);
        QListWidgetItem *it = new QListWidgetItem();
        it->setSizeHint(QSize(0, nt->height()));
        ui->eventList->addItem(it);
        ui->eventList->setItemWidget(it,nt);
        connect(nt, SIGNAL(hasChanges()), r, SLOT(rereadsettings()));
    }

    _r = r;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!_readyToClose)
    {
        event->ignore();
        hide();

    }

}

void MainWindow::on_action_triggered()
{
    _readyToClose = true;
    this->close();
}
