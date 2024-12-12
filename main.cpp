#include "mainwindow.h"
#include "messagingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MessagingWindow window1;
    MessagingWindow window2;

    QObject::connect(&window1, &MessagingWindow::messageSent, &window2, &MessagingWindow::onMessageReceived);
    QObject::connect(&window2, &MessagingWindow::messageSent, &window1, &MessagingWindow::onMessageReceived);

    window1.setWindowTitle("Interface 1");
    window2.setWindowTitle("Interface 2");

    window1.show();
    window2.show();
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.show();
    return a.exec();
}

