#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSettings>
#include <reminder.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Reminder *r, QWidget *parent = 0);
    ~MainWindow();

signals:
    void settingsChanged();

private:
    Ui::MainWindow *ui;
    bool _readyToClose;
    Reminder *_r;

protected:
    virtual void closeEvent(QCloseEvent *event);


private slots:
    void on_action_triggered();
};

#endif // MAINWINDOW_H
