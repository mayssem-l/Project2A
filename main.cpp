#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "messagingwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    MessagingWindow window1;
    MessagingWindow window2;

    QObject::connect(&window1, &MessagingWindow::messageSent, &window2, &MessagingWindow::onMessageReceived);
    QObject::connect(&window2, &MessagingWindow::messageSent, &window1, &MessagingWindow::onMessageReceived);

    window1.setWindowTitle("Interface 1");
    window2.setWindowTitle("Interface 2");

    window1.show();
    window2.show();



    return a.exec();
}
