/********************************************************************************
** Form generated from reading UI file 'activationcode.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATIONCODE_H
#define UI_ACTIVATIONCODE_H

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

class Ui_ActivationCode
{
public:
    QPushButton *btnDone;
    QLabel *label;
    QLineEdit *lineRobloxAccount;
    QLabel *label_2;

    void setupUi(QDialog *ActivationCode)
    {
        if (ActivationCode->objectName().isEmpty())
            ActivationCode->setObjectName(QStringLiteral("ActivationCode"));
        ActivationCode->resize(508, 77);
        btnDone = new QPushButton(ActivationCode);
        btnDone->setObjectName(QStringLiteral("btnDone"));
        btnDone->setGeometry(QRect(400, 10, 93, 61));
        label = new QLabel(ActivationCode);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 391, 21));
        lineRobloxAccount = new QLineEdit(ActivationCode);
        lineRobloxAccount->setObjectName(QStringLiteral("lineRobloxAccount"));
        lineRobloxAccount->setGeometry(QRect(160, 20, 231, 22));
        label_2 = new QLabel(ActivationCode);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 15, 141, 31));

        retranslateUi(ActivationCode);

        QMetaObject::connectSlotsByName(ActivationCode);
    } // setupUi

    void retranslateUi(QDialog *ActivationCode)
    {
        ActivationCode->setWindowTitle(QApplication::translate("ActivationCode", "Activation Code Required", 0));
        btnDone->setText(QApplication::translate("ActivationCode", "Done", 0));
        label->setText(QApplication::translate("ActivationCode", "Put the following code in your ROBLOX account's blurb:", 0));
        label_2->setText(QApplication::translate("ActivationCode", "Your ROBLOX account:", 0));
    } // retranslateUi

};

namespace Ui {
    class ActivationCode: public Ui_ActivationCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATIONCODE_H
