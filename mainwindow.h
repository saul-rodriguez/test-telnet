#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qttelnet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QtTelnet *t;

public slots:
    void telnetMessage(const QString &msg);
    void telnetLoginRequired();
    void telnetLoginFailed();
    void telnetLoggedOut();
    void telnetLoggedIn();
    void telnetConnectionError(QAbstractSocket::SocketError error);

    QString stripCR(const QString &msg);

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_Send_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
