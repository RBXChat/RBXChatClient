#include <QDateTime>
#include <QScrollBar>
#include <QKeyEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unpwdialog.h"
#include "activationcode.h"
#include "ui_activationcode.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        this->setWindowTitle("RBXChat Client");
        ui->setupUi(this);
        //this->createActions();
        //this->createMenus();
        //this->createUI();
        this->newTextBox = ui->txtbox;
        this->lineEdit = ui->txtbox2;
        //connect(this->ui->actionChange_Server, SIGNAL(triggered()), this, SLOT(changeServer()));
        connect(this->ui->action_Change_Server, SIGNAL(triggered()), this, SLOT(changeServer()));
        connect(this->ui->action_Ping_Server, SIGNAL(triggered()), this, SLOT(pingServer()));
        this->ui->centralWidget->setLayout(this->ui->gridLayout);
    }
/*void MainWindow::createActions() {
    newAct = new QAction(tr("&Change Server..."), this);
    newAct->setShortcuts(QKeySequence::Save); // Ctrl + S == Change /S/erver
    newAct->setStatusTip(tr("Change the server connected to"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(changeServer()));
}*/
/*void MainWindow::createMenus() {
    serverMenu = menuBar()->addMenu(tr("&Server"));
    serverMenu->addAction(newAct);
}*/
/*void MainWindow::createUI() {
    newTextBox = new QTextEdit("Ready to connect to server.", this->centralWidget());
    newTextBox->setReadOnly(true);
}*/

void MainWindow::changeServer() {
    //QString msg = tr("HELLO!");
    //statusBar()->showMessage(msg);
    if (this->connected)
        newTextBox->setHtml(newTextBox->toHtml() + "You are already connected to a server!\n");
    else {
        QInputDialog* inputdia = new QInputDialog(this);
        bool ok;
        QString txt = inputdia->getText(this, tr("Enter server address"), tr("Address:"), QLineEdit::Normal, "", &ok);
        statusBar()->showMessage(txt);
        QRegExp* rx = new QRegExp("^(\\d{1,3}\\.){3}\\d{1,3}$");
        bool match = rx->exactMatch(txt);
        //statusBar()->showMessage(QString::number(match));
        if (!match) {
            QMessageBox msgBox;
            msgBox.setText("The address you entered is invalid!");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();
        }
        else
            RBXChatConnect(txt);
    }
}

void MainWindow::RBXChatConnect(QString hostname) {
    sock = new QTcpSocket(this);
    //connect(sock, SIGNAL(readyRead()), this, SLOT(()));
    connect(sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    sock->abort();
    sock->connectToHost(hostname, 998);
    if (sock->waitForConnected(5000)) {
        this->connected = true;
        qDebug() << "CONNECT" << "\n";
        this->printMessage("Connected to server " + hostname + " at port 998.<br />");
        UNPWDialog* w = new UNPWDialog();
        w->mainwin = this;
        w->show();
    }
    else
        QMessageBox::critical(this, tr("Connection error"), tr("Failed to connect to the server: timed out"));
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            //this->connectionClosed();
            QMessageBox::information(this, tr("RBXChat Client"),
                                 tr("The remote host has closed the connection."));
        break;
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, tr("RBXChat Client"),
                                     tr("The host was not found. Please check the "
                                        "host name and port settings."));
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("RBXChat Client"),
                                     tr("The connection was refused by the peer. "
                                        "Make sure the fortune server is running, "
                                        "and check that the host name and port "
                                        "settings are correct."));
            break;
        default:
            QMessageBox::information(this, tr("RBXChat Client"),
                                     tr("The following error occurred: %1.")
                                     .arg(sock->errorString()));
        }
}

void MainWindow::sendMessage(QString message) {
    if (!this->connected)
        this->printMessage("Not connected to a server!\n");
    else {
        qint64 w = sock->write(message.toStdString().c_str());
        sock->flush();
        qDebug() << "Written bytes: " << w;
        sock->waitForBytesWritten(-1);
        qDebug() << "Written";
    }
}

QString MainWindow::readFromSocket() {
    qDebug() << "Available bytes: " << sock->bytesAvailable() << "\n";
    QString ret = sock->readAll();
    if (!ret.compare(ret, "Login rejected\n", Qt::CaseInsensitive)) {
        qDebug() << "invalid login";
        sock->close();
        this->connectionClosed();
    }
    else if (!ret.compare(ret, "\x10")) {
        int ping = this->currenttimer.elapsed();
        qDebug() << "pinging took " << ping << "ms";
        this->ispinging = false;
        return QString("Your ping is ") + QString::number(ping) + QString("ms.");
    }
    else if (ret[0] == '\x01') { // Activation code required
        qDebug() << "activation required";
        ActivationCode* activationwindow = new ActivationCode();
        activationwindow->mainwin = this;
        activationwindow->ui->label->setText("Put the following code in your account's blurb: " + ret.left(ret.length() - 3));
        activationwindow->show();
        return QString("Activation required");
    }

    return ret;
}

void MainWindow::showDataFromSocket() {
    this->printMessage(this->readFromSocket());
}

void MainWindow::setUsernamePassword(QString un, QString pw) {
    this->username = un;
    this->password = pw;
    //qDebug() << "UN = " << un << "PW = " << pw << endl;
    this->openConnection();
}

void MainWindow::openConnection() {
    //qDebug() << "connect";
    connect(sock, SIGNAL(readyRead()), this, SLOT(showDataFromSocket()));
    connect(sock, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
    QString send = "\x01" + this->username + "\x02" + this->password + "\x03";
    this->sendMessage(send);
}

void MainWindow::connectionClosed() {
    this->printMessage("The remote host has closed the connection.\n");
    this->connected = false;
}

void MainWindow::printMessage(QString message) {
    newTextBox->setHtml(newTextBox->toHtml() + "[" + QDate::currentDate().toString() + " -- " + QTime::currentTime().toString() + "] " + message);
    if (this->ui->autoScroll->isChecked())
        newTextBox->verticalScrollBar()->setValue(newTextBox->verticalScrollBar()->maximum());
}

void MainWindow::sendRegisterRequest(QString un, QString pw, QString em) {
    this->sendMessage("\x04" + un + "\x02" + pw + "\x02" + em + "\x03");
    connect(sock, SIGNAL(readyRead()), this, SLOT(showDataFromSocket()));
    connect(sock, SIGNAL(disconnected()), this, SLOT(connectionClosed()));
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushbtn_clicked() {
    this->sendMessage(this->lineEdit->text());
    this->lineEdit->setText("");
}

void MainWindow::keyPressEvent(QKeyEvent* ev) {
    if (ev->key() == Qt::Key_Return)
        this->on_pushbtn_clicked();
}

void MainWindow::pingServer() {
    if (!this->connected)
        this->printMessage("Not connected to a server!");
    else {
        if (this->ispinging)
            this->printMessage("You are already pinging the server!");
        else {
            this->currenttimer = QTime();
            this->currenttimer.start();
            this->ispinging = true;
            this->sendMessage("\x10"); // Send ping request
        }
    }
}

void MainWindow::sendActivationCode(QString rblxusername) {
    this->sendMessage("\x05" + rblxusername);
}
