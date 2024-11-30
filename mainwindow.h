#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QStackedWidget>
#include <QTextEdit>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QString>
#include <QList>


struct Delivery { QString phoneNumber;};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlQueryModel* getDeliveriesModel();
    QString getSelectedDeliveryClientPhoneNumber();

private slots:
    void loadClientData(int clientId) ;
    void validateClientId(const QString &text);
    void checkClientIdExists(const QString &text);
    void addDELIVERY(bool isConfirm);
    void clearInputFields();
    void displayDeliveries();
    void validateID(const QString &text);
    void validateFields(const QString &text);
    void deleteDelivery();
    void editDelivery();
    void checkIdExists(const QString &text);
    void highlightField(QLineEdit *field, bool isValid);
    void searchDelivery();
    void trie();
    void displayStatistics();
    void displayHistorique();
    void exportPDF();
    void onSmsButtonClicked();



private:
    Ui::MainWindow *ui;
    int currentIdForEditing = -1; // Variable à suivre pour l'édition
    QStackedWidget *stat;
    QList<Delivery> deliveries;
    int currentSelectedIndex;




};
#endif // MAINWINDOW_H
