#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t = new QtTelnet;

    connect(t, SIGNAL(message(const QString &)),
                   this, SLOT(telnetMessage(const QString &)));
    connect(t, SIGNAL(loginRequired()),
                    this, SLOT(telnetLoginRequired()));
    connect(t, SIGNAL(loginFailed()),
                    this, SLOT(telnetLoginFailed()));
    connect(t, SIGNAL(loggedOut()),
                   this, SLOT(telnetLoggedOut()));
    connect(t, SIGNAL(loggedIn()),
                   this, SLOT(telnetLoggedIn()));
    connect(t, SIGNAL(connectionError(QAbstractSocket::SocketError)),
                    this, SLOT(telnetConnectionError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::telnetMessage(const QString &msg)
{
    ui->textEdit->append(stripCR(msg));
    //QScrollBar *s = ui->textEdit->verticalScrollBar();
    //s->setValue(s->maximum());
}

void MainWindow::telnetLoginRequired()
{

}

void MainWindow::telnetLoginFailed()
{

}

void MainWindow::telnetLoggedOut()
{

}

void MainWindow::telnetLoggedIn()
{

}

void MainWindow::telnetConnectionError(QAbstractSocket::SocketError error)
{
    ui->lineEdit_status->setText(QString("Connection error: %1").arg(error));
}

void MainWindow::on_pushButton_connect_clicked()
{
    t->connectToHost("localhost",5401);
}

QString MainWindow::stripCR(const QString &msg)
   {
       QString nmsg(msg);
       nmsg.remove('\r');
       nmsg.remove(QRegExp("\033\\[[0-9;]*[A-Za-z]")); // Also remove terminal control codes
       return nmsg;
   }

void MainWindow::on_pushButton_Send_clicked()
{
    QString aux;
    aux = ui->lineEdit_data->text();

    t->sendData(aux);

    ui->lineEdit_data->clear();
}
