#ifndef UNPWDIALOG_H
#define UNPWDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class UNPWDialog;
}

class UNPWDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UNPWDialog(QWidget *parent = 0);
    MainWindow* mainwin;
    ~UNPWDialog();

private slots:
    void on_OKButton_clicked();
    void on_commandLinkButton_clicked();

protected:
    void closeEvent(QCloseEvent* voidthis);

private:
    Ui::UNPWDialog *ui;
};

#endif // UNPWDIALOG_H
