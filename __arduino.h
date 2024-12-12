#ifndef ARDUINO_H
#define ARDUINO_H
#include <QSerialPort>
#include <QDebug>

class Arduino{

public:
    Arduino();
    QSerialPort serial;
};

#endif // ARDUINO_H
