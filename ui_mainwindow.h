/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *event_page;
    QGridLayout *gridLayout_2;
    QListWidget *eventList;
    QWidget *calendar_page;
    QGridLayout *gridLayout_3;
    QTableWidget *calendarTable;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(714, 510);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/event.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setIcon(icon1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(150, 16777215));
        listWidget->setIconSize(QSize(96, 96));
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setGridSize(QSize(148, 156));
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setUniformItemSizes(false);
        listWidget->setWordWrap(true);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        event_page = new QWidget();
        event_page->setObjectName(QStringLiteral("event_page"));
        gridLayout_2 = new QGridLayout(event_page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        eventList = new QListWidget(event_page);
        eventList->setObjectName(QStringLiteral("eventList"));
        eventList->setSpacing(8);

        gridLayout_2->addWidget(eventList, 0, 0, 1, 1);

        stackedWidget->addWidget(event_page);
        calendar_page = new QWidget();
        calendar_page->setObjectName(QStringLiteral("calendar_page"));
        gridLayout_3 = new QGridLayout(calendar_page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        calendarTable = new QTableWidget(calendar_page);
        if (calendarTable->columnCount() < 5)
            calendarTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        calendarTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        calendarTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        calendarTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        calendarTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        calendarTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        calendarTable->setObjectName(QStringLiteral("calendarTable"));

        gridLayout_3->addWidget(calendarTable, 0, 0, 1, 1);

        stackedWidget->addWidget(calendar_page);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 714, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        listWidget->setCurrentRow(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\320\265 \320\277\320\276 \321\201\320\276\320\261\321\213\321\202\320\270\321\217\320\274", 0));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\320\265 \320\277\320\276 \321\201\320\276\320\261\321\213\321\202\320\270\321\217\320\274</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\320\265 \320\277\320\276 \320\264\320\260\321\202\320\260\320\274", 0));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem1->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\320\265 \320\277\320\276 \320\264\320\260\321\202\320\260\320\274</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        listWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem = calendarTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem1 = calendarTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277", 0));
        QTableWidgetItem *___qtablewidgetitem2 = calendarTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", 0));
        QTableWidgetItem *___qtablewidgetitem3 = calendarTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem4 = calendarTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\320\273", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
