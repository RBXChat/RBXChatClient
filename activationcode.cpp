#include "activationcode.h"
#include "ui_activationcode.h"

ActivationCode::ActivationCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivationCode) {
        ui->setupUi(this);
}

ActivationCode::~ActivationCode() {
    delete ui;
}

void ActivationCode::on_btnDone_clicked() {
    this->mainwin->sendActivationCode(this->ui->lineRobloxAccount->text());
}
