/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerdialog
{
public:
    QLabel *label;
    QLineEdit *unedit;
    QLabel *label_2;
    QLineEdit *pwedit;
    QLineEdit *emedit;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QDialog *registerdialog)
    {
        if (registerdialog->objectName().isEmpty())
            registerdialog->setObjectName(QStringLiteral("registerdialog"));
        registerdialog->resize(250, 204);
        label = new QLabel(registerdialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        unedit = new QLineEdit(registerdialog);
        unedit->setObjectName(QStringLiteral("unedit"));
        unedit->setGeometry(QRect(80, 10, 161, 22));
        label_2 = new QLabel(registerdialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 16));
        pwedit = new QLineEdit(registerdialog);
        pwedit->setObjectName(QStringLiteral("pwedit"));
        pwedit->setGeometry(QRect(80, 40, 161, 22));
        pwedit->setEchoMode(QLineEdit::Password);
        emedit = new QLineEdit(registerdialog);
        emedit->setObjectName(QStringLiteral("emedit"));
        emedit->setGeometry(QRect(80, 70, 161, 22));
        label_3 = new QLabel(registerdialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 53, 16));
        pushButton = new QPushButton(registerdialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 160, 93, 28));
        label_4 = new QLabel(registerdialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 95, 231, 61));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setWordWrap(true);

        retranslateUi(registerdialog);

        QMetaObject::connectSlotsByName(registerdialog);
    } // setupUi

    void retranslateUi(QDialog *registerdialog)
    {
        registerdialog->setWindowTitle(QApplication::translate("registerdialog", "Register", 0));
        label->setText(QApplication::translate("registerdialog", "Username:", 0));
        label_2->setText(QApplication::translate("registerdialog", "Password:", 0));
        label_3->setText(QApplication::translate("registerdialog", "E-Mail:", 0));
        pushButton->setText(QApplication::translate("registerdialog", "OK", 0));
        label_4->setText(QApplication::translate("registerdialog", "Please give a valid E-Mail address. Accounts with an invalid E-Mail address will be banned automatically.", 0));
    } // retranslateUi

};

namespace Ui {
    class registerdialog: public Ui_registerdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
