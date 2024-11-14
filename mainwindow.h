#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employees.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_list_view();

private slots:
    void on_confirm_add_clicked();
    void on_delete_clicked();
    void on_edit_clicked();
    void on_confirm_edit_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
