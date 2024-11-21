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
signals:
    void loginSuccessful(const QString &role);

private slots:
    void on_confirm_add_clicked();
    void on_delete_clicked();
    void on_edit_clicked();
    void on_confirm_edit_clicked();
    void recherche_emp();
    void on_cancel_search_button_clicked();
    void on_Login_Button_clicked();
    //void on_export_pdf_button_clicked();
    void exportToPDF();
    void on_Sort_Button_clicked();
    void displayStatistics();
    void on_Recover_Button_clicked();
    bool getEmailAndPassword(int id, QString &email, QString &password);
    //bool sendEmail(const QString &to, const QString &password);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
