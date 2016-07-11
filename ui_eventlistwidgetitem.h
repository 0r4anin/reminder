/********************************************************************************
** Form generated from reading UI file 'eventlistwidgetitem.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTLISTWIDGETITEM_H
#define UI_EVENTLISTWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uilistitem
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *image;
    QToolButton *checkButton;
    QVBoxLayout *verticalLayout;
    QLabel *eventName;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTimeEdit *eventTime;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTimeEdit *repeatTime;
    QSpacerItem *horizontalSpacer;
    QLineEdit *textMessage;
    QLineEdit *repeatTextMessage;

    void setupUi(QWidget *uilistitem)
    {
        if (uilistitem->objectName().isEmpty())
            uilistitem->setObjectName(QStringLiteral("uilistitem"));
        uilistitem->setEnabled(true);
        uilistitem->resize(887, 150);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(uilistitem->sizePolicy().hasHeightForWidth());
        uilistitem->setSizePolicy(sizePolicy);
        uilistitem->setMinimumSize(QSize(0, 150));
        uilistitem->setMaximumSize(QSize(16777215, 150));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        uilistitem->setPalette(palette);
        uilistitem->setAutoFillBackground(false);
        uilistitem->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(uilistitem);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        groupBox = new QGroupBox(uilistitem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String("QGroupBox#groupBox {\n"
"	background-color: white;\n"
"	border-style: outset;\n"
"    border-width: 1px;\n"
"    border-radius: 10px;\n"
"    border-color: black;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"}"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        image = new QLabel(groupBox);
        image->setObjectName(QStringLiteral("image"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy1);
        image->setMinimumSize(QSize(128, 128));
        image->setMaximumSize(QSize(128, 128));
        image->setPixmap(QPixmap(QString::fromUtf8(":/icon/seeting.png")));
        image->setScaledContents(true);

        gridLayout_2->addWidget(image, 0, 0, 1, 1);

        checkButton = new QToolButton(groupBox);
        checkButton->setObjectName(QStringLiteral("checkButton"));
        checkButton->setMinimumSize(QSize(128, 128));
        checkButton->setMaximumSize(QSize(128, 128));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        checkButton->setPalette(palette1);
        checkButton->setAutoFillBackground(true);
        checkButton->setStyleSheet(QLatin1String("QToolButton#checkButton {\n"
"	background-color: white\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/sign-error.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkButton->setIcon(icon);
        checkButton->setIconSize(QSize(128, 128));
        checkButton->setPopupMode(QToolButton::InstantPopup);
        checkButton->setAutoRaise(true);

        gridLayout_2->addWidget(checkButton, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        eventName = new QLabel(groupBox);
        eventName->setObjectName(QStringLiteral("eventName"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        eventName->setFont(font);

        verticalLayout->addWidget(eventName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        eventTime = new QTimeEdit(groupBox);
        eventTime->setObjectName(QStringLiteral("eventTime"));

        horizontalLayout->addWidget(eventTime);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        repeatTime = new QTimeEdit(groupBox);
        repeatTime->setObjectName(QStringLiteral("repeatTime"));

        horizontalLayout_2->addWidget(repeatTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        textMessage = new QLineEdit(groupBox);
        textMessage->setObjectName(QStringLiteral("textMessage"));

        verticalLayout->addWidget(textMessage);

        repeatTextMessage = new QLineEdit(groupBox);
        repeatTextMessage->setObjectName(QStringLiteral("repeatTextMessage"));

        verticalLayout->addWidget(repeatTextMessage);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(uilistitem);

        QMetaObject::connectSlotsByName(uilistitem);
    } // setupUi

    void retranslateUi(QWidget *uilistitem)
    {
        uilistitem->setWindowTitle(QApplication::translate("uilistitem", "Form", 0));
        groupBox->setTitle(QString());
        image->setText(QString());
        checkButton->setText(QString());
        eventName->setText(QApplication::translate("uilistitem", "Event Name", 0));
        label->setText(QApplication::translate("uilistitem", "\320\222\321\200\320\265\320\274\321\217 \321\201\321\200\320\260\320\261\320\260\321\202\321\213\320\262\320\260\320\275\320\270\321\217:", 0));
        label_2->setText(QApplication::translate("uilistitem", "\320\237\320\276\320\262\321\202\320\276\321\200\320\275\320\276\320\265 \321\201\321\200\320\260\320\261\320\260\321\202\321\213\320\262\320\260\320\275\320\270\320\265:", 0));
        textMessage->setText(QString());
        textMessage->setPlaceholderText(QApplication::translate("uilistitem", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\277\321\200\320\270 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270", 0));
        repeatTextMessage->setText(QString());
        repeatTextMessage->setPlaceholderText(QApplication::translate("uilistitem", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\277\321\200\320\270 \320\277\320\276\320\262\321\202\320\276\321\200\320\275\320\276\320\271 \320\260\320\272\321\202\320\270\320\262\320\260\321\206\320\270\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class uilistitem: public Ui_uilistitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTLISTWIDGETITEM_H
