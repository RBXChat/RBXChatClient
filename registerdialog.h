#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class registerdialog;
}

class registerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerdialog(QWidget *parent = 0);
    MainWindow* mainwin;
    ~registerdialog();

private slots:
    void on_pushButton_clicked();

protected:
    void closeEvent(QCloseEvent* voidthis);

private:
    Ui::registerdialog *ui;
};

#endif // REGISTERDIALOG_H
