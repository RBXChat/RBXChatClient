#include "registerdialog.h"
#include "ui_registerdialog.h"

registerdialog::registerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerdialog) {
    ui->setupUi(this);
}

registerdialog::~registerdialog() {
    delete ui;
}

void registerdialog::on_pushButton_clicked() {
    this->mainwin->sendRegisterRequest(this->ui->unedit->text(), this->ui->pwedit->text(), this->ui->emedit->text());
    this->hide();
}

void registerdialog::closeEvent(QCloseEvent* voidthis) {
    this->mainwin->sock->close();
    this->mainwin->connectionClosed();
}
