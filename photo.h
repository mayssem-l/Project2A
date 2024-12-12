#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QLabel>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pic_2_clicked();   // Slot for uploading an image
    void on_disimage_clicked(); // Slot for displaying an image

private:
    void displayImageInTable(const QPixmap &pixmap); // Helper function to display image in `widgetph`

    Ui::MainWindow *ui; // Pointer to the UI
};

#endif // MAINWINDOW_H
