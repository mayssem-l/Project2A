#include "arduino.h"

Arduino::Arduino() {
    serial.setPortName("COM3"); // Replace with your port name
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.open(QIODevice::ReadOnly)) {
        qDebug() << "Error opening port:" << serial.errorString();
    }
}
