#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "connection.h"
#include <iostream>
using namespace std;
MainWindow::~MainWindow()
{
    delete ui;
}
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)


{
    ui->setupUi(this);
    Connection c;
    c.createconnect();

    // Connexion des boutons aux pages correspondantes du QStackedWidget
    connect(ui->List_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->list_view);  // Affiche la page viewemp
    });

    connect(ui->Add_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Add);  // Affiche la page addemp
    });

    connect(ui->Stat_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Stat);  // Affiche la page statemp
    });

    connect(ui->Edit_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Edit);  // Affiche la page modemp
    });

    // Assurez-vous que vous utilisez la bonne syntaxe pour référencer le bouton dans le QStackedWidget
    //connect(ui->Add_Button, &QPushButton::clicked, this, &MainWindow::on_Add_Button_clicked);

}
void MainWindow::on_confirm_add_clicked()
{

    // Récupérer les données des QLineEdit
    int Id_E = ui->id_add->text().toInt();
    QString Nom_E = ui->nom_add->text();
    QString Prenom_E = ui->prenom_add->text();
    //QDate date = ui->birthdate_add->date();  // This gives a QDate
     // QString Date_Nais_E = date.toString("yyyy-MM-dd");
    QDate Date_Nais_E= ui->birthdate_add->date();
      if (Date_Nais_E.isValid()) {
          cout << "date_nais=" << Date_Nais_E.toString("yyyy-MM-dd").toStdString() << endl;  // Format as 'YYYY-MM-DD'
      } else {
          qDebug() << "Invalid date!";
          cout<<"date_format_incorrect"<<endl;
      }
    QString Adresse_E = ui->adr_add->text();
    QString Email_E = ui->email_add->text();
    int Tel_E = ui->tel_add->text().toInt();
    QString Poste_E = ui->poste_add->text(); // Utilise la méthode `date()` pour récupérer une date
    QString Mdp_E = ui->mdp_add->text();
    QString Sexe_E = ui->gender_add->currentText();

    cout << Id_E << endl;
    cout<< "nom:  " << Nom_E.toStdString() << " prenom: " <<Prenom_E.toStdString()<< " adresse:  " <<Adresse_E.toStdString()<< " Email:  " <<Email_E.toStdString()<< " tel:  " <<Tel_E<< " poste:  "<< Poste_E.toStdString() << "mdp:  "<<Mdp_E.toStdString()<< "sexe:  "<< Sexe_E.toStdString() << std::endl;


    // Vérifier si les champs ne sont pas vides
    if (Id_E == 0 || Nom_E.isEmpty() || Prenom_E.isEmpty() || Sexe_E.isEmpty()  || Adresse_E.isEmpty() || Email_E.isEmpty() || Tel_E == 0 || Poste_E.isEmpty() || Mdp_E.isEmpty() ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    Employees E(Id_E,Nom_E,Prenom_E,Sexe_E,Date_Nais_E,Adresse_E,Email_E,Tel_E,Poste_E,Mdp_E);
    bool res=E.ajouter();


    // Exécuter la requête et vérifier si l'insertion a réussi
    if (res) {
        QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès.");
        // Réinitialiser les champs après l'ajout
        ui->id_add->clear();
        ui->nom_add->clear();
        ui->prenom_add->clear();
        ui->gender_add->clear();
        ui->birthdate_add->clear();
        ui->adr_add->clear();
        ui->email_add->clear();
        ui->tel_add->clear();
        ui->poste_add->clear();
        ui->mdp_add->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }

}

void MainWindow::on_delete_clicked()
{

   /* int id = ui->id_delete->text().toInt();

    if (cin_employee.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez entrer la cin de l'employé à supprimer.");
        return;
    }*/

   Employees E;

    bool success = E.supprimer(E.getId_E());

    if (success) {

        QMessageBox::information(this, "Succès", "Le service a été supprimé avec succès.");
    } else {

        QMessageBox::warning(this, "Erreur", "Une erreur est survenue lors de la suppression.");
    }

    ui->id_delete->clear();

    ui->tableView->setModel(E.afficher());
}




