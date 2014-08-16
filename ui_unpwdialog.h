/********************************************************************************
** Form generated from reading UI file 'unpwdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNPWDIALOG_H
#define UI_UNPWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UNPWDialog
{
public:
    QPushButton *OKButton;
    QLabel *label;
    QLineEdit *usernameInput;
    QLabel *label_2;
    QLineEdit *passwordInput;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *UNPWDialog)
    {
        if (UNPWDialog->objectName().isEmpty())
            UNPWDialog->setObjectName(QStringLiteral("UNPWDialog"));
        UNPWDialog->resize(400, 112);
        OKButton = new QPushButton(UNPWDialog);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(292, 67, 101, 41));
        label = new QLabel(UNPWDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        usernameInput = new QLineEdit(UNPWDialog);
        usernameInput->setObjectName(QStringLiteral("usernameInput"));
        usernameInput->setGeometry(QRect(80, 10, 311, 22));
        label_2 = new QLabel(UNPWDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 16));
        passwordInput = new QLineEdit(UNPWDialog);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(80, 40, 311, 22));
        passwordInput->setEchoMode(QLineEdit::Password);
        commandLinkButton = new QCommandLinkButton(UNPWDialog);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 70, 191, 41));

        retranslateUi(UNPWDialog);

        QMetaObject::connectSlotsByName(UNPWDialog);
    } // setupUi

    void retranslateUi(QDialog *UNPWDialog)
    {
        UNPWDialog->setWindowTitle(QApplication::translate("UNPWDialog", "Dialog", 0));
        OKButton->setText(QApplication::translate("UNPWDialog", "OK", 0));
        label->setText(QApplication::translate("UNPWDialog", "Username:", 0));
        label_2->setText(QApplication::translate("UNPWDialog", "Password:", 0));
        commandLinkButton->setText(QApplication::translate("UNPWDialog", "No account? Register", 0));
    } // retranslateUi

};

namespace Ui {
    class UNPWDialog: public Ui_UNPWDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNPWDIALOG_H
