#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QInputDialog>
#include <QMessageBox>
#include <QTcpSocket>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString currentServer;
    void RBXChatConnect(QString hostname);
    void sendMessage(QString message);
    QString readFromSocket();
    QTextEdit* newTextBox;
    QTcpSocket* sock;
    void setUsernamePassword(QString un, QString pw);
    void sendRegisterRequest(QString un, QString pw, QString em);
    void printMessage(QString message);
    void sendActivationCode(QString rblxusername);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createActions();
    void createMenus();
    void createUI();

    void openConnection();

    QMenu* serverMenu;
    QAction* newAct;
    QString username;
    QString password;
    QLineEdit* lineEdit;

    bool connected = false;
    bool ispinging = false;

    QTime currenttimer;
public slots:
    void connectionClosed();
private slots:
    void changeServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void showDataFromSocket();
    void on_pushbtn_clicked();
    void pingServer();
private:
    void keyPressEvent(QKeyEvent* ev);
};

#endif // MAINWINDOW_H
