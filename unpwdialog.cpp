#include "unpwdialog.h"
#include "ui_unpwdialog.h"
#include "mainwindow.h"
#include "registerdialog.h"
#include <QMessageBox>

UNPWDialog::UNPWDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UNPWDialog) {
        ui->setupUi(this);
    }

UNPWDialog::~UNPWDialog()
{
    delete ui;
}

void UNPWDialog::on_OKButton_clicked() {
    this->mainwin->setUsernamePassword(this->ui->usernameInput->text(), this->ui->passwordInput->text());
    this->hide();
}

void UNPWDialog::on_commandLinkButton_clicked() {
    registerdialog* r = new registerdialog();
    r->mainwin = this->mainwin;
    r->show();
    this->hide();
}

void UNPWDialog::closeEvent(QCloseEvent* voidthis) {
    this->mainwin->sock->close();
    this->mainwin->connectionClosed();
}
