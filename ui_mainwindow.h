/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Change_Server;
    QAction *action_Ping_Server;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *autoScroll;
    QTextBrowser *txtbox;
    QLineEdit *txtbox2;
    QPushButton *pushbtn;
    QMenuBar *menuBar;
    QMenu *menuServer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 650);
        action_Change_Server = new QAction(MainWindow);
        action_Change_Server->setObjectName(QStringLiteral("action_Change_Server"));
        action_Ping_Server = new QAction(MainWindow);
        action_Ping_Server->setObjectName(QStringLiteral("action_Ping_Server"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1100, 550));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 1081, 571));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        autoScroll = new QCheckBox(gridLayoutWidget);
        autoScroll->setObjectName(QStringLiteral("autoScroll"));
        autoScroll->setChecked(true);

        gridLayout->addWidget(autoScroll, 0, 0, 1, 1);

        txtbox = new QTextBrowser(gridLayoutWidget);
        txtbox->setObjectName(QStringLiteral("txtbox"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        txtbox->setFont(font);
        txtbox->setLineWrapMode(QTextEdit::WidgetWidth);
        txtbox->setOpenExternalLinks(true);

        gridLayout->addWidget(txtbox, 1, 0, 1, 2);

        txtbox2 = new QLineEdit(gridLayoutWidget);
        txtbox2->setObjectName(QStringLiteral("txtbox2"));
        txtbox2->setFont(font);

        gridLayout->addWidget(txtbox2, 2, 0, 1, 1);

        pushbtn = new QPushButton(gridLayoutWidget);
        pushbtn->setObjectName(QStringLiteral("pushbtn"));
        pushbtn->setAutoDefault(true);
        pushbtn->setDefault(true);

        gridLayout->addWidget(pushbtn, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 26));
        menuServer = new QMenu(menuBar);
        menuServer->setObjectName(QStringLiteral("menuServer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuServer->menuAction());
        menuServer->addAction(action_Change_Server);
        menuServer->addAction(action_Ping_Server);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RBXChat Client", 0));
        action_Change_Server->setText(QApplication::translate("MainWindow", "&Change Server", 0));
        action_Change_Server->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_Ping_Server->setText(QApplication::translate("MainWindow", "&Ping Server", 0));
        action_Ping_Server->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        autoScroll->setText(QApplication::translate("MainWindow", "Autoscroll", 0));
        pushbtn->setText(QApplication::translate("MainWindow", "Send", 0));
        menuServer->setTitle(QApplication::translate("MainWindow", "&Server", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
