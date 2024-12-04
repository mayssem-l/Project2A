QT += core gui sql charts widgets printsupport network serialport

CONFIG += c++17

SOURCES += \
    arduino.cpp \
    connection.cpp \
    employees.cpp \
    mailer.cpp \
    main.cpp \
    mainwindow.cpp #\
    # notifier.cpp

HEADERS += \
    arduino.h \
    connection.h \
    employees.h \
    mailer.h \
    mainwindow.h #\
    # notifier.h

FORMS += \
    mainwindow.ui

QT += network
