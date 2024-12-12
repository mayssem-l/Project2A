/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label;
    QToolButton *toolButton;
    QLabel *label_4;
    QToolButton *toolButton_2;
    QLabel *label_7;
    QToolButton *toolButton_5;
    QLabel *label_8;
    QToolButton *toolButton_6;
    QLabel *label_9;
    QToolButton *toolButton_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QToolButton *toolButton_3;
    QLabel *label_14;
    QLabel *label_13;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QStackedWidget *stackedWidget;
    QWidget *list_view;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_18;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QLabel *label_19;
    QLabel *label_42;
    QPushButton *editButton;
    QLabel *label_43;
    QPushButton *deleteButton;
    QLabel *label_23;
    QTableView *tableView;
    QWidget *Add;
    QWidget *widget;
    QLineEdit *lineEdit_2;
    QWidget *idk;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_31;
    QDateEdit *birthdate;
    QPushButton *Add_Button_2;
    QLabel *label_25;
    QPushButton *Add_Button_3;
    QLabel *label_26;
    QWidget *Edit;
    QWidget *widget_2;
    QLineEdit *id;
    QWidget *widget_4;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_43;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *email;
    QLineEdit *tel;
    QDateEdit *date;
    QPushButton *Add_Button_4;
    QLabel *label_27;
    QPushButton *Add_Button_5;
    QLabel *label_28;
    QLineEdit *adresse;
    QLineEdit *lineEdit_42;
    QWidget *Stat;
    QPushButton *List_Button;
    QLabel *label_16;
    QPushButton *Add_Button;
    QLabel *label_21;
    QPushButton *Stat_Button;
    QLabel *label_22;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1282, 845);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 0, 1200, 721));
        frame_2->setMaximumSize(QSize(1200, 1200));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"border: 2px solid;\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 249, 231);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 251, 721));
        frame->setStyleSheet(QString::fromUtf8("#frame{border: 2px solid black;\n"
"	\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border-radius: 15px;\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 60, 41, 31));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../menu (2).png")));
        label_2->setScaledContents(true);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 91, 91));
        label->setPixmap(QPixmap(QString::fromUtf8("../../logo original.png")));
        label->setScaledContents(true);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(0, 220, 251, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rage Italic")});
        font.setPointSize(18);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;\n"
""));
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setCheckable(false);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 230, 41, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../employees (1).png")));
        label_4->setScaledContents(true);
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 290, 251, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rage Italic")});
        font1.setPointSize(19);
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(171, 168, 111);\n"
"border: 2px solid black;\n"
"\n"
""));
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setCheckable(false);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 300, 41, 41));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../client.png")));
        label_7->setScaledContents(true);
        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(0, 360, 251, 71));
        toolButton_5->setFont(font);
        toolButton_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;\n"
""));
        toolButton_5->setIconSize(QSize(20, 20));
        toolButton_5->setCheckable(false);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 370, 41, 41));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../canned-food.png")));
        label_8->setScaledContents(true);
        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(0, 430, 251, 71));
        toolButton_6->setFont(font);
        toolButton_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;"));
        toolButton_6->setIconSize(QSize(20, 20));
        toolButton_6->setCheckable(false);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 440, 41, 41));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../delivery-bike.png")));
        label_9->setScaledContents(true);
        toolButton_7 = new QToolButton(frame);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setGeometry(QRect(0, 500, 251, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rage Italic")});
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setKerning(true);
        toolButton_7->setFont(font2);
        toolButton_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;"));
        toolButton_7->setIconSize(QSize(20, 20));
        toolButton_7->setCheckable(false);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 510, 41, 41));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../image (1).png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(160, 630, 41, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../check-out (1) (1).png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, 630, 41, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../gear.png")));
        label_12->setScaledContents(true);
        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(0, 150, 251, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rage Italic")});
        font3.setPointSize(18);
        font3.setBold(false);
        toolButton_3->setFont(font3);
        toolButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;"));
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setCheckable(false);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 160, 41, 41));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../home (3).png")));
        label_14->setScaledContents(true);
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1090, 30, 63, 61));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../admin.png")));
        label_13->setScaledContents(true);
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(970, 50, 113, 28));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 249, 231);\n"
"font: 20pt \"Rage Italic\";\n"
"color: rgb(148, 125, 66);"));
        lineEdit_3->setDragEnabled(false);
        lineEdit_5 = new QLineEdit(frame_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(540, 40, 151, 71));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("MV Boli")});
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        lineEdit_5->setFont(font4);
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt ;\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        lineEdit_5->setFrame(true);
        lineEdit_5->setCursorPosition(12);
        lineEdit_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_5->setDragEnabled(false);
        lineEdit_5->setReadOnly(false);
        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(281, 130, 891, 571));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        list_view = new QWidget();
        list_view->setObjectName(QString::fromUtf8("list_view"));
        pushButton = new QPushButton(list_view);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 66, 91, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_4 = new QLineEdit(list_view);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(452, 60, 131, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"\n"
"background-color: rgb(247, 255, 229);\n"
""));
        label_3 = new QLabel(list_view);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 64, 31, 31));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/search.png")));
        label_3->setScaledContents(true);
        label_18 = new QLabel(list_view);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(752, 400, 81, 81));
        label_18->setCursor(QCursor(Qt::PointingHandCursor));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../pdf-file.png")));
        label_18->setScaledContents(true);
        lineEdit_7 = new QLineEdit(list_view);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(340, 56, 111, 51));
        lineEdit_7->setFont(font4);
        lineEdit_7->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt ;\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        lineEdit_7->setFrame(true);
        lineEdit_7->setCursorPosition(7);
        lineEdit_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_7->setDragEnabled(false);
        lineEdit_7->setReadOnly(false);
        lineEdit_8 = new QLineEdit(list_view);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(true);
        lineEdit_8->setGeometry(QRect(590, 53, 121, 51));
        lineEdit_8->setFont(font4);
        lineEdit_8->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(18, 115, 83);\n"
"\n"
"\n"
"border-radius:20px;\n"
""));
        lineEdit_8->setFrame(true);
        lineEdit_8->setCursorPosition(9);
        lineEdit_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_8->setDragEnabled(false);
        lineEdit_8->setReadOnly(false);
        tableWidget = new QTableWidget(list_view);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem17);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 130, 641, 421));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(133, 144, 121);\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 241, 226);\n"
"border:1px solid ;\n"
"border-color: rgb(121, 170, 147);"));
        lineEdit = new QLineEdit(list_view);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 60, 161, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(247, 255, 229);\n"
"\n"
""));
        label_19 = new QLabel(list_view);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(550, 65, 31, 31));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 255, 229);"));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/arrange (1).png")));
        label_19->setScaledContents(true);
        label_42 = new QLabel(list_view);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(672, 67, 21, 21));
        label_42->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);"));
        label_42->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/filter (1).png")));
        label_42->setScaledContents(true);
        editButton = new QPushButton(list_view);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(720, 210, 141, 71));
        editButton->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(68, 189, 133);\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_43 = new QLabel(list_view);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(700, 220, 51, 51));
        label_43->setStyleSheet(QString::fromUtf8("background-color:none;"));
        label_43->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/edit.png")));
        label_43->setScaledContents(true);
        deleteButton = new QPushButton(list_view);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(720, 300, 141, 71));
        deleteButton->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(126, 61, 64);\n"
"background-color: rgb(230, 57, 70);\n"
"\n"
"border-radius:30px;\n"
""));
        label_23 = new QLabel(list_view);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(690, 310, 51, 51));
        label_23->setStyleSheet(QString::fromUtf8("background-color:none;"));
        label_23->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/trash.png")));
        label_23->setScaledContents(true);
        tableView = new QTableView(list_view);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(730, 480, 641, 421));
        tableView->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->addWidget(list_view);
        Add = new QWidget();
        Add->setObjectName(QString::fromUtf8("Add"));
        widget = new QWidget(Add);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 10, 811, 551));
        widget->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 70, 151, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        idk = new QWidget(widget);
        idk->setObjectName(QString::fromUtf8("idk"));
        idk->setGeometry(QRect(870, 320, 811, 551));
        idk->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 20px;\n"
""));
        lineEdit_16 = new QLineEdit(idk);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(210, 100, 121, 28));
        lineEdit_17 = new QLineEdit(idk);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(210, 170, 121, 28));
        lineEdit_18 = new QLineEdit(idk);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(210, 234, 121, 28));
        lineEdit_19 = new QLineEdit(idk);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(210, 310, 121, 28));
        lineEdit_20 = new QLineEdit(idk);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(210, 380, 121, 28));
        lineEdit_10 = new QLineEdit(widget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(70, 80, 121, 28));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        lineEdit_10->setFont(font5);
        lineEdit_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_12 = new QLineEdit(widget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(70, 214, 121, 28));
        lineEdit_12->setFont(font5);
        lineEdit_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_12->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_13 = new QLineEdit(widget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(460, 230, 121, 28));
        lineEdit_13->setFont(font5);
        lineEdit_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_13->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_14 = new QLineEdit(widget);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(70, 150, 121, 28));
        lineEdit_14->setFont(font5);
        lineEdit_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_14->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_25 = new QLineEdit(widget);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        lineEdit_25->setGeometry(QRect(430, 80, 131, 28));
        lineEdit_25->setFont(font5);
        lineEdit_25->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_25->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_28 = new QLineEdit(widget);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        lineEdit_28->setGeometry(QRect(430, 150, 131, 28));
        lineEdit_28->setFont(font5);
        lineEdit_28->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_28->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_30 = new QLineEdit(widget);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));
        lineEdit_30->setGeometry(QRect(210, 140, 151, 51));
        lineEdit_30->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_9 = new QLineEdit(widget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(210, 210, 151, 51));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(590, 70, 151, 51));
        lineEdit_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_31 = new QLineEdit(widget);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        lineEdit_31->setGeometry(QRect(590, 140, 151, 51));
        lineEdit_31->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        birthdate = new QDateEdit(widget);
        birthdate->setObjectName(QString::fromUtf8("birthdate"));
        birthdate->setGeometry(QRect(600, 220, 151, 51));
        birthdate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_Button_2 = new QPushButton(widget);
        Add_Button_2->setObjectName(QString::fromUtf8("Add_Button_2"));
        Add_Button_2->setGeometry(QRect(260, 440, 151, 71));
        Add_Button_2->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(70, 148, 119);\n"
"\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(232, 457, 41, 41));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/verified.png")));
        label_25->setScaledContents(true);
        Add_Button_3 = new QPushButton(widget);
        Add_Button_3->setObjectName(QString::fromUtf8("Add_Button_3"));
        Add_Button_3->setGeometry(QRect(490, 440, 151, 71));
        Add_Button_3->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(97, 0, 0);\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(463, 457, 41, 41));
        label_26->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));
        label_26->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cancel.png")));
        label_26->setScaledContents(true);
        stackedWidget->addWidget(Add);
        Edit = new QWidget();
        Edit->setObjectName(QString::fromUtf8("Edit"));
        widget_2 = new QWidget(Edit);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(40, 10, 811, 551));
        widget_2->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        id = new QLineEdit(widget_2);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(210, 70, 151, 51));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(870, 320, 811, 551));
        widget_4->setStyleSheet(QString::fromUtf8("border:2px solid black;\n"
"border-radius: 20px;\n"
""));
        lineEdit_23 = new QLineEdit(widget_4);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setGeometry(QRect(210, 100, 121, 28));
        lineEdit_24 = new QLineEdit(widget_4);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        lineEdit_24->setGeometry(QRect(210, 170, 121, 28));
        lineEdit_32 = new QLineEdit(widget_4);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        lineEdit_32->setGeometry(QRect(210, 234, 121, 28));
        lineEdit_33 = new QLineEdit(widget_4);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setGeometry(QRect(210, 310, 121, 28));
        lineEdit_34 = new QLineEdit(widget_4);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        lineEdit_34->setGeometry(QRect(210, 380, 121, 28));
        lineEdit_35 = new QLineEdit(widget_2);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        lineEdit_35->setGeometry(QRect(70, 80, 121, 28));
        lineEdit_35->setFont(font5);
        lineEdit_35->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_35->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_37 = new QLineEdit(widget_2);
        lineEdit_37->setObjectName(QString::fromUtf8("lineEdit_37"));
        lineEdit_37->setGeometry(QRect(70, 240, 121, 28));
        lineEdit_37->setFont(font5);
        lineEdit_37->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_37->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_38 = new QLineEdit(widget_2);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));
        lineEdit_38->setGeometry(QRect(70, 310, 121, 28));
        lineEdit_38->setFont(font5);
        lineEdit_38->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_38->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_39 = new QLineEdit(widget_2);
        lineEdit_39->setObjectName(QString::fromUtf8("lineEdit_39"));
        lineEdit_39->setGeometry(QRect(70, 150, 121, 28));
        lineEdit_39->setFont(font5);
        lineEdit_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_39->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_40 = new QLineEdit(widget_2);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));
        lineEdit_40->setGeometry(QRect(430, 80, 131, 28));
        lineEdit_40->setFont(font5);
        lineEdit_40->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_40->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_43 = new QLineEdit(widget_2);
        lineEdit_43->setObjectName(QString::fromUtf8("lineEdit_43"));
        lineEdit_43->setGeometry(QRect(430, 150, 131, 28));
        lineEdit_43->setFont(font5);
        lineEdit_43->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_43->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        nom = new QLineEdit(widget_2);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(210, 140, 151, 51));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        prenom = new QLineEdit(widget_2);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(210, 220, 151, 51));
        prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        email = new QLineEdit(widget_2);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(590, 70, 151, 51));
        email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        tel = new QLineEdit(widget_2);
        tel->setObjectName(QString::fromUtf8("tel"));
        tel->setGeometry(QRect(590, 140, 151, 51));
        tel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        date = new QDateEdit(widget_2);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(210, 300, 151, 51));
        date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_Button_4 = new QPushButton(widget_2);
        Add_Button_4->setObjectName(QString::fromUtf8("Add_Button_4"));
        Add_Button_4->setGeometry(QRect(260, 460, 151, 71));
        Add_Button_4->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(70, 148, 119);\n"
"\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_27 = new QLabel(widget_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(230, 476, 41, 41));
        label_27->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/verified.png")));
        label_27->setScaledContents(true);
        Add_Button_5 = new QPushButton(widget_2);
        Add_Button_5->setObjectName(QString::fromUtf8("Add_Button_5"));
        Add_Button_5->setGeometry(QRect(477, 460, 151, 71));
        Add_Button_5->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"background-color: rgb(97, 0, 0);\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_28 = new QLabel(widget_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(450, 476, 41, 41));
        label_28->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));
        label_28->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cancel.png")));
        label_28->setScaledContents(true);
        adresse = new QLineEdit(widget_2);
        adresse->setObjectName(QString::fromUtf8("adresse"));
        adresse->setGeometry(QRect(590, 220, 151, 51));
        adresse->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_42 = new QLineEdit(widget_2);
        lineEdit_42->setObjectName(QString::fromUtf8("lineEdit_42"));
        lineEdit_42->setGeometry(QRect(460, 230, 121, 28));
        lineEdit_42->setFont(font5);
        lineEdit_42->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_42->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        stackedWidget->addWidget(Edit);
        Stat = new QWidget();
        Stat->setObjectName(QString::fromUtf8("Stat"));
        stackedWidget->addWidget(Stat);
        List_Button = new QPushButton(frame_2);
        List_Button->setObjectName(QString::fromUtf8("List_Button"));
        List_Button->setGeometry(QRect(310, 40, 151, 71));
        List_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(284, 50, 51, 51));
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../complete.png")));
        label_16->setScaledContents(true);
        Add_Button = new QPushButton(frame_2);
        Add_Button->setObjectName(QString::fromUtf8("Add_Button"));
        Add_Button->setGeometry(QRect(540, 40, 151, 71));
        Add_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(510, 50, 41, 41));
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../sign-up (1) - Copy.png")));
        label_21->setScaledContents(true);
        Stat_Button = new QPushButton(frame_2);
        Stat_Button->setObjectName(QString::fromUtf8("Stat_Button"));
        Stat_Button->setGeometry(QRect(770, 40, 151, 71));
        Stat_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(171, 168, 111);\n"
"\n"
"\n"
"\n"
"\n"
"border-radius:30px;\n"
""));
        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(750, 50, 41, 41));
        label_22->setPixmap(QPixmap(QString::fromUtf8("../../monitor - Copy.png")));
        label_22->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1282, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "        Employees", nullptr));
        label_4->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "        Clients", nullptr));
        label_7->setText(QString());
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "        Products", nullptr));
        label_8->setText(QString());
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "        Delivery", nullptr));
        label_9->setText(QString());
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "         Equipments", nullptr));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "        Home", nullptr));
        label_14->setText(QString());
        label_13->setText(QString());
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "           Welcome", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "Add Employee", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "    First Name", nullptr));
        label_3->setText(QString());
        label_18->setText(QString());
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindow", "   Filter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Phone number", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "email", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "2315067", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "29.524.587", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "1/1/1996", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "av", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Mohamed.Hammemi@gmail.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "2456421", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Halweni", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "98.547.365", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "2/5/1992", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "av", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Halweni.Soumaya@gmail.com", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        lineEdit->setText(QCoreApplication::translate("MainWindow", "Enter ID", nullptr));
        label_19->setText(QString());
        label_42->setText(QString());
        editButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label_43->setText(QString());
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_23->setText(QString());
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "2315067", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        lineEdit_25->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_28->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        lineEdit_30->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "Mohamed", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "Mohamed.Hammemi@gmail.com", nullptr));
        lineEdit_31->setText(QCoreApplication::translate("MainWindow", "55436728", nullptr));
        Add_Button_2->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_25->setText(QString());
        Add_Button_3->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_26->setText(QString());
        id->setText(QCoreApplication::translate("MainWindow", "2315067", nullptr));
        lineEdit_35->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_37->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lineEdit_38->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        lineEdit_39->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        lineEdit_40->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_43->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        nom->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        prenom->setText(QCoreApplication::translate("MainWindow", "Mohamed", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Mohamed.Hammemi@gmail.com", nullptr));
        tel->setText(QCoreApplication::translate("MainWindow", "55436728", nullptr));
        Add_Button_4->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_27->setText(QString());
        Add_Button_5->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_28->setText(QString());
        adresse->setText(QCoreApplication::translate("MainWindow", "Rue Palestine", nullptr));
        lineEdit_42->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        List_Button->setText(QCoreApplication::translate("MainWindow", "Client List", nullptr));
        label_16->setText(QString());
        Add_Button->setText(QCoreApplication::translate("MainWindow", "Add Client", nullptr));
        label_21->setText(QString());
        Stat_Button->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        label_22->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
