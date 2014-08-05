#ifndef ACTIVATIONCODE_H
#define ACTIVATIONCODE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ActivationCode;
}

class ActivationCode : public QDialog
{
    Q_OBJECT

public:
    explicit ActivationCode(QWidget *parent = 0);
    ~ActivationCode();
    void setActivationData(QString code);

    MainWindow* mainwin;

private slots:
    void on_btnDone_clicked();

public:
    Ui::ActivationCode *ui;
};

#endif // ACTIVATIONCODE_H
