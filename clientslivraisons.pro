QT       += core gui
QT       += core gui sql
QT += charts
QT += core gui widgets charts
QT += core gui printsupport
QT += widgets




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    connection.cpp \
    livraison.cpp \
    main.cpp \
    mainwindow.cpp \
    messagingwindow.cpp

HEADERS += \
    client.h \
    connection.h \
    livraison.h \
    mainwindow.h \
    messagingwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target