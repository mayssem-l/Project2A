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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QPushButton *Search_Button;
    QLineEdit *lineEdit_7;
    QTableWidget *tableWidget;
    QLineEdit *Search_line_edit;
    QLabel *label_42;
    QPushButton *Edit_Button;
    QLabel *label_43;
    QPushButton *Delete_Button;
    QLabel *label_23;
    QTableView *tableView;
    QPushButton *cancel_search_button;
    QPushButton *Sort_Button;
    QPushButton *export_pdf_button;
    QComboBox *sort_criterion;
    QWidget *Add;
    QWidget *widget_add;
    QLineEdit *id_add;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *nom_add;
    QLineEdit *prenom_add;
    QLineEdit *email_add;
    QLineEdit *poste_add;
    QLineEdit *mdp_add;
    QLineEdit *tel_add;
    QDateEdit *birthdate_add;
    QComboBox *gender_add;
    QPushButton *confirm_add;
    QLabel *label_25;
    QPushButton *cancel_add;
    QLabel *label_26;
    QLineEdit *adr_add;
    QWidget *Edit;
    QWidget *widget_edit;
    QLineEdit *id_edit;
    QLineEdit *lineEdit_59;
    QLineEdit *lineEdit_60;
    QLineEdit *lineEdit_61;
    QLineEdit *lineEdit_62;
    QLineEdit *lineEdit_63;
    QLineEdit *lineEdit_64;
    QLineEdit *lineEdit_65;
    QLineEdit *lineEdit_66;
    QLineEdit *lineEdit_67;
    QLineEdit *lineEdit_68;
    QLineEdit *nom_edit;
    QLineEdit *prenom_edit;
    QLineEdit *email_edit;
    QLineEdit *poste_edit;
    QLineEdit *mdp_edit;
    QLineEdit *tel_edit;
    QDateEdit *birthdate_edit;
    QComboBox *gender_edit;
    QPushButton *confirm_edit;
    QLabel *label_29;
    QPushButton *cancel_edit;
    QLabel *label_30;
    QLineEdit *adr_edit;
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
        frame_2->setGeometry(QRect(30, 0, 1200, 721));
        frame_2->setMaximumSize(QSize(1200, 1200));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"border: 2px solid;\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 249, 231);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
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
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 60, 41, 31));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/menu (2).png")));
        label_2->setScaledContents(true);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 91, 91));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/logo1-2.png")));
        label->setScaledContents(true);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(0, 220, 251, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rage Italic")});
        font.setPointSize(18);
        toolButton->setFont(font);
        toolButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(171, 168, 111);\n"
"border: 2px solid black;\n"
"\n"
""));
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setCheckable(false);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 230, 41, 41));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/employees (1).png")));
        label_4->setScaledContents(true);
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 290, 251, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rage Italic")});
        font1.setPointSize(19);
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
"	background-color: rgb(139, 21, 21);\n"
"background-color: rgb(97, 0, 0);\n"
"border: 2px solid black;"));
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setCheckable(false);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 300, 41, 41));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/client.png")));
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
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/canned-food.png")));
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
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/delivery-bike.png")));
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
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/image (1).png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(160, 630, 41, 41));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/check-out (1) (1).png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, 630, 41, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/gear.png")));
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
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/home (3).png")));
        label_14->setScaledContents(true);
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1090, 30, 63, 61));
        label_13->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/user (1).png")));
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
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setDragEnabled(false);
        lineEdit_5->setReadOnly(false);
        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(281, 132, 891, 571));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        list_view = new QWidget();
        list_view->setObjectName(QString::fromUtf8("list_view"));
        Search_Button = new QPushButton(list_view);
        Search_Button->setObjectName(QString::fromUtf8("Search_Button"));
        Search_Button->setGeometry(QRect(180, 20, 111, 41));
        Search_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);\n"
"color: rgb(255, 255, 255);"));
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
        lineEdit_7->setAlignment(Qt::AlignCenter);
        lineEdit_7->setDragEnabled(false);
        lineEdit_7->setReadOnly(false);
        tableWidget = new QTableWidget(list_view);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem22);
        QFont font5;
        font5.setStyleStrategy(QFont::PreferDefault);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font5);
        tableWidget->setItem(0, 6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem32);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 130, 641, 421));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(133, 144, 121);\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 241, 226);\n"
"border:1px solid ;\n"
"border-color: rgb(121, 170, 147);"));
        Search_line_edit = new QLineEdit(list_view);
        Search_line_edit->setObjectName(QString::fromUtf8("Search_line_edit"));
        Search_line_edit->setGeometry(QRect(10, 40, 161, 41));
        Search_line_edit->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(247, 255, 229);\n"
"\n"
""));
        label_42 = new QLabel(list_view);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(690, 80, 21, 21));
        label_42->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);"));
        label_42->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/filter (1).png")));
        label_42->setScaledContents(true);
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
        tableView->setGeometry(QRect(20, 130, 641, 421));
        tableView->setStyleSheet(QString::fromUtf8(""));
        cancel_search_button = new QPushButton(list_view);
        cancel_search_button->setObjectName(QString::fromUtf8("cancel_search_button"));
        cancel_search_button->setGeometry(QRect(180, 70, 111, 41));
        cancel_search_button->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 115, 83);\n"
"background-color: rgb(97, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Downloads/no-data (1).png"), QSize(), QIcon::Normal, QIcon::On);
        cancel_search_button->setIcon(icon);
        Sort_Button = new QPushButton(list_view);
        Sort_Button->setObjectName(QString::fromUtf8("Sort_Button"));
        Sort_Button->setGeometry(QRect(594, 55, 131, 51));
        Sort_Button->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt ;\n"
"\n"
"background-color: rgb(18, 115, 83);\n"
"\n"
"\n"
"border-radius:20px;\n"
""));
        export_pdf_button = new QPushButton(list_view);
        export_pdf_button->setObjectName(QString::fromUtf8("export_pdf_button"));
        export_pdf_button->setGeometry(QRect(740, 410, 101, 101));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Downloads/pdf-file (1) - Copy.png"), QSize(), QIcon::Normal, QIcon::On);
        export_pdf_button->setIcon(icon1);
        sort_criterion = new QComboBox(list_view);
        sort_criterion->addItem(QString());
        sort_criterion->addItem(QString());
        sort_criterion->addItem(QString());
        sort_criterion->setObjectName(QString::fromUtf8("sort_criterion"));
        sort_criterion->setGeometry(QRect(450, 60, 141, 41));
        sort_criterion->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"\n"
"background-color: rgb(247, 255, 229);\n"
""));
        stackedWidget->addWidget(list_view);
        Add = new QWidget();
        Add->setObjectName(QString::fromUtf8("Add"));
        widget_add = new QWidget(Add);
        widget_add->setObjectName(QString::fromUtf8("widget_add"));
        widget_add->setGeometry(QRect(40, 10, 811, 551));
        widget_add->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        id_add = new QLineEdit(widget_add);
        id_add->setObjectName(QString::fromUtf8("id_add"));
        id_add->setGeometry(QRect(210, 70, 151, 51));
        id_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_10 = new QLineEdit(widget_add);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(70, 80, 121, 28));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        lineEdit_10->setFont(font6);
        lineEdit_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_11 = new QLineEdit(widget_add);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(70, 290, 121, 28));
        lineEdit_11->setFont(font6);
        lineEdit_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_12 = new QLineEdit(widget_add);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(70, 214, 121, 28));
        lineEdit_12->setFont(font6);
        lineEdit_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_13 = new QLineEdit(widget_add);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(70, 360, 121, 28));
        lineEdit_13->setFont(font6);
        lineEdit_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_14 = new QLineEdit(widget_add);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(70, 150, 121, 28));
        lineEdit_14->setFont(font6);
        lineEdit_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_25 = new QLineEdit(widget_add);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));
        lineEdit_25->setGeometry(QRect(430, 80, 131, 28));
        lineEdit_25->setFont(font6);
        lineEdit_25->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_26 = new QLineEdit(widget_add);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));
        lineEdit_26->setGeometry(QRect(430, 280, 141, 41));
        lineEdit_26->setFont(font6);
        lineEdit_26->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_27 = new QLineEdit(widget_add);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));
        lineEdit_27->setGeometry(QRect(430, 220, 131, 28));
        lineEdit_27->setFont(font6);
        lineEdit_27->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_28 = new QLineEdit(widget_add);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));
        lineEdit_28->setGeometry(QRect(430, 150, 131, 28));
        lineEdit_28->setFont(font6);
        lineEdit_28->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_29 = new QLineEdit(widget_add);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));
        lineEdit_29->setGeometry(QRect(430, 360, 131, 28));
        lineEdit_29->setFont(font6);
        lineEdit_29->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nom_add = new QLineEdit(widget_add);
        nom_add->setObjectName(QString::fromUtf8("nom_add"));
        nom_add->setGeometry(QRect(210, 140, 151, 51));
        nom_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        prenom_add = new QLineEdit(widget_add);
        prenom_add->setObjectName(QString::fromUtf8("prenom_add"));
        prenom_add->setGeometry(QRect(210, 210, 151, 51));
        prenom_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        email_add = new QLineEdit(widget_add);
        email_add->setObjectName(QString::fromUtf8("email_add"));
        email_add->setGeometry(QRect(590, 70, 151, 51));
        email_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        poste_add = new QLineEdit(widget_add);
        poste_add->setObjectName(QString::fromUtf8("poste_add"));
        poste_add->setGeometry(QRect(590, 280, 151, 51));
        poste_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        mdp_add = new QLineEdit(widget_add);
        mdp_add->setObjectName(QString::fromUtf8("mdp_add"));
        mdp_add->setGeometry(QRect(590, 350, 151, 51));
        mdp_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        tel_add = new QLineEdit(widget_add);
        tel_add->setObjectName(QString::fromUtf8("tel_add"));
        tel_add->setGeometry(QRect(590, 140, 151, 51));
        tel_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        birthdate_add = new QDateEdit(widget_add);
        birthdate_add->setObjectName(QString::fromUtf8("birthdate_add"));
        birthdate_add->setGeometry(QRect(210, 350, 151, 51));
        birthdate_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        gender_add = new QComboBox(widget_add);
        gender_add->addItem(QString());
        gender_add->addItem(QString());
        gender_add->setObjectName(QString::fromUtf8("gender_add"));
        gender_add->setGeometry(QRect(210, 280, 151, 51));
        gender_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        confirm_add = new QPushButton(widget_add);
        confirm_add->setObjectName(QString::fromUtf8("confirm_add"));
        confirm_add->setGeometry(QRect(260, 440, 151, 71));
        confirm_add->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        label_25 = new QLabel(widget_add);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(232, 457, 41, 41));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/verified.png")));
        label_25->setScaledContents(true);
        cancel_add = new QPushButton(widget_add);
        cancel_add->setObjectName(QString::fromUtf8("cancel_add"));
        cancel_add->setGeometry(QRect(490, 440, 151, 71));
        cancel_add->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        label_26 = new QLabel(widget_add);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(463, 457, 41, 41));
        label_26->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));
        label_26->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cancel.png")));
        label_26->setScaledContents(true);
        adr_add = new QLineEdit(widget_add);
        adr_add->setObjectName(QString::fromUtf8("adr_add"));
        adr_add->setGeometry(QRect(590, 210, 151, 51));
        adr_add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        stackedWidget->addWidget(Add);
        Edit = new QWidget();
        Edit->setObjectName(QString::fromUtf8("Edit"));
        widget_edit = new QWidget(Edit);
        widget_edit->setObjectName(QString::fromUtf8("widget_edit"));
        widget_edit->setGeometry(QRect(40, 10, 811, 551));
        widget_edit->setStyleSheet(QString::fromUtf8("border:2px solid green;\n"
"border-radius: 20px;\n"
""));
        id_edit = new QLineEdit(widget_edit);
        id_edit->setObjectName(QString::fromUtf8("id_edit"));
        id_edit->setGeometry(QRect(210, 70, 151, 51));
        id_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        lineEdit_59 = new QLineEdit(widget_edit);
        lineEdit_59->setObjectName(QString::fromUtf8("lineEdit_59"));
        lineEdit_59->setGeometry(QRect(70, 80, 121, 28));
        lineEdit_59->setFont(font6);
        lineEdit_59->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_59->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_60 = new QLineEdit(widget_edit);
        lineEdit_60->setObjectName(QString::fromUtf8("lineEdit_60"));
        lineEdit_60->setGeometry(QRect(70, 290, 121, 28));
        lineEdit_60->setFont(font6);
        lineEdit_60->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_60->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_61 = new QLineEdit(widget_edit);
        lineEdit_61->setObjectName(QString::fromUtf8("lineEdit_61"));
        lineEdit_61->setGeometry(QRect(70, 214, 121, 28));
        lineEdit_61->setFont(font6);
        lineEdit_61->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_61->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_62 = new QLineEdit(widget_edit);
        lineEdit_62->setObjectName(QString::fromUtf8("lineEdit_62"));
        lineEdit_62->setGeometry(QRect(70, 360, 121, 28));
        lineEdit_62->setFont(font6);
        lineEdit_62->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_62->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_63 = new QLineEdit(widget_edit);
        lineEdit_63->setObjectName(QString::fromUtf8("lineEdit_63"));
        lineEdit_63->setGeometry(QRect(70, 150, 121, 28));
        lineEdit_63->setFont(font6);
        lineEdit_63->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_63->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_64 = new QLineEdit(widget_edit);
        lineEdit_64->setObjectName(QString::fromUtf8("lineEdit_64"));
        lineEdit_64->setGeometry(QRect(430, 80, 131, 28));
        lineEdit_64->setFont(font6);
        lineEdit_64->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_64->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_65 = new QLineEdit(widget_edit);
        lineEdit_65->setObjectName(QString::fromUtf8("lineEdit_65"));
        lineEdit_65->setGeometry(QRect(430, 280, 141, 41));
        lineEdit_65->setFont(font6);
        lineEdit_65->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_65->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_66 = new QLineEdit(widget_edit);
        lineEdit_66->setObjectName(QString::fromUtf8("lineEdit_66"));
        lineEdit_66->setGeometry(QRect(430, 220, 131, 28));
        lineEdit_66->setFont(font6);
        lineEdit_66->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_66->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_67 = new QLineEdit(widget_edit);
        lineEdit_67->setObjectName(QString::fromUtf8("lineEdit_67"));
        lineEdit_67->setGeometry(QRect(430, 150, 131, 28));
        lineEdit_67->setFont(font6);
        lineEdit_67->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_67->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_68 = new QLineEdit(widget_edit);
        lineEdit_68->setObjectName(QString::fromUtf8("lineEdit_68"));
        lineEdit_68->setGeometry(QRect(430, 360, 131, 28));
        lineEdit_68->setFont(font6);
        lineEdit_68->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        lineEdit_68->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nom_edit = new QLineEdit(widget_edit);
        nom_edit->setObjectName(QString::fromUtf8("nom_edit"));
        nom_edit->setGeometry(QRect(210, 140, 151, 51));
        nom_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        prenom_edit = new QLineEdit(widget_edit);
        prenom_edit->setObjectName(QString::fromUtf8("prenom_edit"));
        prenom_edit->setGeometry(QRect(210, 210, 151, 51));
        prenom_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        email_edit = new QLineEdit(widget_edit);
        email_edit->setObjectName(QString::fromUtf8("email_edit"));
        email_edit->setGeometry(QRect(590, 70, 151, 51));
        email_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        poste_edit = new QLineEdit(widget_edit);
        poste_edit->setObjectName(QString::fromUtf8("poste_edit"));
        poste_edit->setGeometry(QRect(590, 280, 151, 51));
        poste_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        mdp_edit = new QLineEdit(widget_edit);
        mdp_edit->setObjectName(QString::fromUtf8("mdp_edit"));
        mdp_edit->setGeometry(QRect(590, 350, 151, 51));
        mdp_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        tel_edit = new QLineEdit(widget_edit);
        tel_edit->setObjectName(QString::fromUtf8("tel_edit"));
        tel_edit->setGeometry(QRect(590, 140, 151, 51));
        tel_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        birthdate_edit = new QDateEdit(widget_edit);
        birthdate_edit->setObjectName(QString::fromUtf8("birthdate_edit"));
        birthdate_edit->setGeometry(QRect(210, 350, 151, 51));
        birthdate_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
        gender_edit = new QComboBox(widget_edit);
        gender_edit->addItem(QString());
        gender_edit->addItem(QString());
        gender_edit->setObjectName(QString::fromUtf8("gender_edit"));
        gender_edit->setGeometry(QRect(210, 280, 151, 51));
        gender_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        confirm_edit = new QPushButton(widget_edit);
        confirm_edit->setObjectName(QString::fromUtf8("confirm_edit"));
        confirm_edit->setGeometry(QRect(260, 440, 151, 71));
        confirm_edit->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        label_29 = new QLabel(widget_edit);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(232, 457, 41, 41));
        label_29->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/verified.png")));
        label_29->setScaledContents(true);
        cancel_edit = new QPushButton(widget_edit);
        cancel_edit->setObjectName(QString::fromUtf8("cancel_edit"));
        cancel_edit->setGeometry(QRect(490, 440, 151, 71));
        cancel_edit->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
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
        label_30 = new QLabel(widget_edit);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(463, 457, 41, 41));
        label_30->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);"));
        label_30->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cancel.png")));
        label_30->setScaledContents(true);
        adr_edit = new QLineEdit(widget_edit);
        adr_edit->setObjectName(QString::fromUtf8("adr_edit"));
        adr_edit->setGeometry(QRect(590, 210, 151, 51));
        adr_edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border_radius:10px;"));
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
        label_16->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/complete.png")));
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
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/sign-up (1).png")));
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
        label_22->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/monitor.png")));
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
        Search_Button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "Sort by", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Work Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Department", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "9", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(0, 0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "2315067", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(0, 1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Hammemi", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(0, 2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Mohamed", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(0, 3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "1/1/1996", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Mohamed.Hammemi@gmail.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(0, 5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Responsable RH", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(0, 6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Employees", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(0, 7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "medham_2000", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(1, 0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "2456421", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(1, 1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Halweni", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(1, 2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Soumaya", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(1, 3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "2/5/1992", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(1, 4);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Halweni.Soumaya@gmail.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(1, 5);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Technicien maintenance", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(1, 6);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Equipments", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(1, 7);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "sousou_1992", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        Search_line_edit->setText(QCoreApplication::translate("MainWindow", "Enter ID", nullptr));
        label_42->setText(QString());
        Edit_Button->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        label_43->setText(QString());
        Delete_Button->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_23->setText(QString());
        cancel_search_button->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        Sort_Button->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        export_pdf_button->setText(QCoreApplication::translate("MainWindow", "export_pdf", nullptr));
        sort_criterion->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        sort_criterion->setItemText(1, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        sort_criterion->setItemText(2, QCoreApplication::translate("MainWindow", "Prenom", nullptr));

        id_add->setText(QString());
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        lineEdit_25->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_26->setText(QCoreApplication::translate("MainWindow", "Work Position", nullptr));
        lineEdit_27->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        lineEdit_28->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        lineEdit_29->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        nom_add->setText(QString());
        prenom_add->setText(QString());
        email_add->setText(QString());
        poste_add->setText(QString());
        mdp_add->setText(QString());
        tel_add->setText(QString());
        gender_add->setItemText(0, QCoreApplication::translate("MainWindow", "Male", nullptr));
        gender_add->setItemText(1, QCoreApplication::translate("MainWindow", "Female", nullptr));

        confirm_add->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_25->setText(QString());
        cancel_add->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_26->setText(QString());
        adr_add->setText(QString());
        id_edit->setText(QString());
        lineEdit_59->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lineEdit_60->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        lineEdit_61->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        lineEdit_62->setText(QCoreApplication::translate("MainWindow", "Birth Date", nullptr));
        lineEdit_63->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        lineEdit_64->setText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        lineEdit_65->setText(QCoreApplication::translate("MainWindow", "Work Position", nullptr));
        lineEdit_66->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        lineEdit_67->setText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        lineEdit_68->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        nom_edit->setText(QString());
        prenom_edit->setText(QString());
        email_edit->setText(QString());
        poste_edit->setText(QString());
        mdp_edit->setText(QString());
        tel_edit->setText(QString());
        gender_edit->setItemText(0, QCoreApplication::translate("MainWindow", "Male", nullptr));
        gender_edit->setItemText(1, QCoreApplication::translate("MainWindow", "Female", nullptr));

        confirm_edit->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_29->setText(QString());
        cancel_edit->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        label_30->setText(QString());
        adr_edit->setText(QString());
        List_Button->setText(QCoreApplication::translate("MainWindow", "Employees List", nullptr));
        label_16->setText(QString());
        Add_Button->setText(QCoreApplication::translate("MainWindow", "Add Employee", nullptr));
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
