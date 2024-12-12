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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QPushButton *Search_Button;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLineEdit *Search_line_edit;
    QPushButton *Edit_Button;
    QLabel *label_43;
    QPushButton *Delete_Button;
    QLabel *label_23;
    QTableView *tableView;
    QPushButton *pdf_Button;
    QComboBox *sort_criterion;
    QPushButton *Sort_Button;
    QPushButton *cancel_search_button;
    QPushButton *messaging_Button;
    QWidget *Add;
    QWidget *widget;
    QLineEdit *id_add;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_28;
    QLineEdit *Add_Nom;
    QLineEdit *Add_Address;
    QLineEdit *Add_email;
    QLineEdit *Add_Phone;
    QDateEdit *birthdate_add;
    QPushButton *Confirm_Add_Button;
    QLabel *label_25;
    QPushButton *cancel_search_button_3;
    QLabel *label_26;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *Add_firstname;
    QLineEdit *Add_region;
    QWidget *Edit;
    QWidget *widget_2;
    QLineEdit *id_edit;
    QWidget *widget_4;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_43;
    QLineEdit *nom_edit;
    QLineEdit *email_edit;
    QLineEdit *tel_edit;
    QDateEdit *birthdate_edit;
    QPushButton *Confirm_Edit_Button;
    QLabel *label_27;
    QPushButton *cancel_search_button_2;
    QLabel *label_28;
    QLineEdit *adr_edit;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_44;
    QLineEdit *region_edit;
    QLineEdit *firstname_edit;
    QWidget *Stat;
    QWidget *Arduino;
    QLCDNumber *lcdNumber;
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
        label_13->setGeometry(QRect(1110, 10, 63, 61));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../admin.png")));
        label_13->setScaledContents(true);
        lineEdit_3 = new QLineEdit(frame_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(970, 20, 113, 31));
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
        Search_Button = new QPushButton(list_view);
        Search_Button->setObjectName(QString::fromUtf8("Search_Button"));
        Search_Button->setGeometry(QRect(210, 30, 91, 29));
        Search_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);\n"
"color: rgb(255, 255, 255);"));
        label_3 = new QLabel(list_view);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 64, 31, 31));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/search.png")));
        label_3->setScaledContents(true);
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
        Search_line_edit = new QLineEdit(list_view);
        Search_line_edit->setObjectName(QString::fromUtf8("Search_line_edit"));
        Search_line_edit->setGeometry(QRect(40, 40, 161, 41));
        Search_line_edit->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(247, 255, 229);\n"
"\n"
""));
        Edit_Button = new QPushButton(list_view);
        Edit_Button->setObjectName(QString::fromUtf8("Edit_Button"));
        Edit_Button->setGeometry(QRect(720, 210, 141, 71));
        Edit_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        Delete_Button = new QPushButton(list_view);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));
        Delete_Button->setGeometry(QRect(720, 300, 141, 71));
        Delete_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        tableView->setGeometry(QRect(40, 110, 641, 421));
        tableView->setStyleSheet(QString::fromUtf8(""));
        pdf_Button = new QPushButton(list_view);
        pdf_Button->setObjectName(QString::fromUtf8("pdf_Button"));
        pdf_Button->setGeometry(QRect(720, 390, 141, 71));
        pdf_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        sort_criterion = new QComboBox(list_view);
        sort_criterion->addItem(QString());
        sort_criterion->addItem(QString());
        sort_criterion->setObjectName(QString::fromUtf8("sort_criterion"));
        sort_criterion->setGeometry(QRect(480, 60, 101, 31));
        Sort_Button = new QPushButton(list_view);
        Sort_Button->setObjectName(QString::fromUtf8("Sort_Button"));
        Sort_Button->setGeometry(QRect(590, 60, 121, 41));
        Sort_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        cancel_search_button = new QPushButton(list_view);
        cancel_search_button->setObjectName(QString::fromUtf8("cancel_search_button"));
        cancel_search_button->setGeometry(QRect(210, 70, 91, 29));
        cancel_search_button->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);\n"
"color: rgb(255, 255, 255);"));
        messaging_Button = new QPushButton(list_view);
        messaging_Button->setObjectName(QString::fromUtf8("messaging_Button"));
        messaging_Button->setGeometry(QRect(720, 480, 131, 61));
        messaging_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        stackedWidget->addWidget(list_view);
        Add = new QWidget();
        Add->setObjectName(QString::fromUtf8("Add"));
        widget = new QWidget(Add);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 10, 811, 551));
        widget->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        id_add = new QLineEdit(widget);
        id_add->setObjectName(QString::fromUtf8("id_add"));
        id_add->setGeometry(QRect(210, 70, 151, 51));
        id_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
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
        lineEdit_12->setGeometry(QRect(440, 230, 121, 28));
        lineEdit_12->setFont(font5);
        lineEdit_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_12->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_13 = new QLineEdit(widget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(70, 290, 121, 28));
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
        Add_Nom = new QLineEdit(widget);
        Add_Nom->setObjectName(QString::fromUtf8("Add_Nom"));
        Add_Nom->setGeometry(QRect(210, 140, 151, 51));
        Add_Nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_Address = new QLineEdit(widget);
        Add_Address->setObjectName(QString::fromUtf8("Add_Address"));
        Add_Address->setGeometry(QRect(590, 220, 151, 51));
        Add_Address->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_email = new QLineEdit(widget);
        Add_email->setObjectName(QString::fromUtf8("Add_email"));
        Add_email->setGeometry(QRect(590, 70, 151, 51));
        Add_email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_Phone = new QLineEdit(widget);
        Add_Phone->setObjectName(QString::fromUtf8("Add_Phone"));
        Add_Phone->setGeometry(QRect(590, 140, 151, 51));
        Add_Phone->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        birthdate_add = new QDateEdit(widget);
        birthdate_add->setObjectName(QString::fromUtf8("birthdate_add"));
        birthdate_add->setGeometry(QRect(210, 280, 151, 51));
        birthdate_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Confirm_Add_Button = new QPushButton(widget);
        Confirm_Add_Button->setObjectName(QString::fromUtf8("Confirm_Add_Button"));
        Confirm_Add_Button->setGeometry(QRect(260, 440, 151, 71));
        Confirm_Add_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        cancel_search_button_3 = new QPushButton(widget);
        cancel_search_button_3->setObjectName(QString::fromUtf8("cancel_search_button_3"));
        cancel_search_button_3->setGeometry(QRect(490, 440, 151, 71));
        cancel_search_button_3->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        lineEdit_15 = new QLineEdit(widget);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(60, 210, 121, 28));
        lineEdit_15->setFont(font5);
        lineEdit_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_15->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_16 = new QLineEdit(widget);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(440, 310, 121, 28));
        lineEdit_16->setFont(font5);
        lineEdit_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_16->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        Add_firstname = new QLineEdit(widget);
        Add_firstname->setObjectName(QString::fromUtf8("Add_firstname"));
        Add_firstname->setGeometry(QRect(210, 210, 151, 51));
        Add_firstname->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Add_region = new QLineEdit(widget);
        Add_region->setObjectName(QString::fromUtf8("Add_region"));
        Add_region->setGeometry(QRect(590, 300, 151, 51));
        Add_region->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        stackedWidget->addWidget(Add);
        Edit = new QWidget();
        Edit->setObjectName(QString::fromUtf8("Edit"));
        widget_2 = new QWidget(Edit);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(40, 10, 811, 551));
        widget_2->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        id_edit = new QLineEdit(widget_2);
        id_edit->setObjectName(QString::fromUtf8("id_edit"));
        id_edit->setGeometry(QRect(210, 70, 151, 51));
        id_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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
        lineEdit_38 = new QLineEdit(widget_2);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));
        lineEdit_38->setGeometry(QRect(70, 320, 121, 28));
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
        nom_edit = new QLineEdit(widget_2);
        nom_edit->setObjectName(QString::fromUtf8("nom_edit"));
        nom_edit->setGeometry(QRect(210, 150, 151, 51));
        nom_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        email_edit = new QLineEdit(widget_2);
        email_edit->setObjectName(QString::fromUtf8("email_edit"));
        email_edit->setGeometry(QRect(590, 70, 151, 51));
        email_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        tel_edit = new QLineEdit(widget_2);
        tel_edit->setObjectName(QString::fromUtf8("tel_edit"));
        tel_edit->setGeometry(QRect(590, 140, 151, 51));
        tel_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        birthdate_edit = new QDateEdit(widget_2);
        birthdate_edit->setObjectName(QString::fromUtf8("birthdate_edit"));
        birthdate_edit->setGeometry(QRect(210, 320, 151, 51));
        birthdate_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        Confirm_Edit_Button = new QPushButton(widget_2);
        Confirm_Edit_Button->setObjectName(QString::fromUtf8("Confirm_Edit_Button"));
        Confirm_Edit_Button->setGeometry(QRect(260, 460, 151, 71));
        Confirm_Edit_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        cancel_search_button_2 = new QPushButton(widget_2);
        cancel_search_button_2->setObjectName(QString::fromUtf8("cancel_search_button_2"));
        cancel_search_button_2->setGeometry(QRect(477, 460, 151, 71));
        cancel_search_button_2->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        adr_edit = new QLineEdit(widget_2);
        adr_edit->setObjectName(QString::fromUtf8("adr_edit"));
        adr_edit->setGeometry(QRect(590, 220, 151, 51));
        adr_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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
        lineEdit_41 = new QLineEdit(widget_2);
        lineEdit_41->setObjectName(QString::fromUtf8("lineEdit_41"));
        lineEdit_41->setGeometry(QRect(70, 230, 121, 28));
        lineEdit_41->setFont(font5);
        lineEdit_41->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_41->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_44 = new QLineEdit(widget_2);
        lineEdit_44->setObjectName(QString::fromUtf8("lineEdit_44"));
        lineEdit_44->setGeometry(QRect(460, 300, 121, 28));
        lineEdit_44->setFont(font5);
        lineEdit_44->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_44->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        region_edit = new QLineEdit(widget_2);
        region_edit->setObjectName(QString::fromUtf8("region_edit"));
        region_edit->setGeometry(QRect(590, 290, 151, 51));
        region_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        firstname_edit = new QLineEdit(widget_2);
        firstname_edit->setObjectName(QString::fromUtf8("firstname_edit"));
        firstname_edit->setGeometry(QRect(210, 230, 151, 51));
        firstname_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        stackedWidget->addWidget(Edit);
        Stat = new QWidget();
        Stat->setObjectName(QString::fromUtf8("Stat"));
        stackedWidget->addWidget(Stat);
        Arduino = new QWidget();
        Arduino->setObjectName(QString::fromUtf8("Arduino"));
        lcdNumber = new QLCDNumber(Arduino);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(110, 130, 591, 241));
        stackedWidget->addWidget(Arduino);
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

        stackedWidget->setCurrentIndex(4);


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
        Search_Button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_3->setText(QString());
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        Search_line_edit->setText(QCoreApplication::translate("MainWindow", "Enter ID", nullptr));
        Edit_Button->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label_43->setText(QString());
        Delete_Button->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_23->setText(QString());
        pdf_Button->setText(QCoreApplication::translate("MainWindow", "PDF Export", nullptr));
        sort_criterion->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        sort_criterion->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));

        Sort_Button->setText(QCoreApplication::translate("MainWindow", "sort", nullptr));
        cancel_search_button->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        messaging_Button->setText(QCoreApplication::translate("MainWindow", "Messaging", nullptr));
        id_add->setText(QString());
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "birthdate", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        lineEdit_25->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_28->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        Add_Nom->setText(QString());
        Add_Address->setText(QString());
        Add_email->setText(QString());
        Add_Phone->setText(QString());
        Confirm_Add_Button->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_25->setText(QString());
        cancel_search_button_3->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_26->setText(QString());
        lineEdit_15->setText(QCoreApplication::translate("MainWindow", "First name", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("MainWindow", "Region", nullptr));
        Add_firstname->setText(QString());
        Add_region->setText(QString());
        id_edit->setText(QCoreApplication::translate("MainWindow", "2315067", nullptr));
        lineEdit_35->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_38->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        lineEdit_39->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        lineEdit_40->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_43->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        nom_edit->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        email_edit->setText(QCoreApplication::translate("MainWindow", "Mohamed.Hammemi@gmail.com", nullptr));
        tel_edit->setText(QCoreApplication::translate("MainWindow", "55436728", nullptr));
        Confirm_Edit_Button->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_27->setText(QString());
        cancel_search_button_2->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_28->setText(QString());
        adr_edit->setText(QCoreApplication::translate("MainWindow", "Rue Palestine", nullptr));
        lineEdit_42->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        lineEdit_41->setText(QCoreApplication::translate("MainWindow", "First name", nullptr));
        lineEdit_44->setText(QCoreApplication::translate("MainWindow", "Region", nullptr));
        region_edit->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        firstname_edit->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
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
