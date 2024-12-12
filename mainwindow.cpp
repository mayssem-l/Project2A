#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QModelIndex>
#include <QItemSelectionModel>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QtNetwork/QTcpSocket>   // Pour la communication via TCP
#include <QtNetwork/QSslSocket>   // Pour les connexions sécurisées (SSL/TLS)
#include <QByteArray>
#include <QObject>
#include "connection.h"
#include "mailer.h"
#include "arduino.h"
#include "client.h"
#include "messagingwindow.h"

using namespace std;

MainWindow::~MainWindow() {
    delete arduino;
    delete ui;
}
void MainWindow::load_list_view_employee() {
    Employees E;
    ui->tableView->setModel(E.afficher());
    ui->stackedWidget->setCurrentWidget(ui->list_view);

}
void MainWindow::load_list_view()
{
    Client C;
    ui->tableView_Client->setModel(C.afficher());
    ui->stackedWidget_Client->setCurrentWidget(ui->list_view_Client);  // Switch to the list view
}


void MainWindow::readarduino()
{

    //int lastIndex;
    //int valueToSend = 42;
    static QString serialBuffer;
    QString fin;
    QString lastLine;
    QString firstName,lastName;
    QString combined;
    int attemptsLeft;


    QByteArray data = serialPort->readAll();
    serialBuffer += QString::fromUtf8(data);
    QStringList lines = serialBuffer.split('\n', Qt::SkipEmptyParts);
    QString message;
    cout << "serialBuffer: " << serialBuffer.toStdString() << endl;
    while (serialBuffer.contains('\n')) {
        int index = serialBuffer.indexOf('\n'); // Find the delimiter
        message = serialBuffer.left(index); // Extract the message
        serialBuffer.remove(0, index + 1); // Remove the processed message and delimiter
        message.replace(" ", "");
        message = message.trimmed();
        // Process the complete message
        qDebug() << "Received message:" << message;
    }
    // for (QString line: lines) {
    //     cout << "_Line_: " << line.toStdString() << endl;
    // }
    // if (!lines.isEmpty()) {
    //     serialBuffer = "";
    //     lastLine = lines.last();
    //     if (lastLine.startsWith("Received:")) {
    //         lastLine = lastLine.mid(9).trimmed();
    //         lastLine.erase(lastLine.begin()+9,lastLine.begin()+10);
    //         fin=lastLine;
    //     }
    //     bool conversionOk;
    //     cout << "Last Line: " << lastLine.toStdString() << endl;
    //     lastIndex = lastLine.toInt(&conversionOk);
    //     qDebug() << "---------------->" << fin;
    //     if (conversionOk) {
    //         qDebug() << "---------------->" << lastIndex;
    //     } else {
    //         qDebug() << "Conversion failed for line:" << lastLine;
    //     }
    // } else {
    //     qDebug() << "No complete lines received yet.";
    // }
    // lastLine.remove('\r');
    // qDebug() << "---------------->" << lastLine;
    QSqlQuery query;
    query.prepare("SELECT NOM_E, PRENOM_E, ATTEMPTSLEFT_E FROM MAYSSEM.EMPLOYEES WHERE RFID_E = :rfid");
    query.bindValue(":rfid", message);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Database query execution error:" << query.lastError().text();
        return;
    }

    // Check if a record is found
    if (query.next()) {
        // Retrieve the name and last name
        firstName = query.value("NOM_E").toString();
        lastName = query.value("PRENOM_E").toString();
        qDebug() << "Employee found:" << firstName << lastName;
        attemptsLeft = query.value("ATTEMPTSLEFT_E").toInt();
        if (attemptsLeft > 0) {
            // Décrémentez le nombre de tentatives
            attemptsLeft--;
            // Mettez à jour la base de données avec le nouveau nombre de tentatives
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE MAYSSEM.EMPLOYEES SET ATTEMPTSLEFT_E = :attemptsLeft WHERE RFID_E = :rfid");
            updateQuery.bindValue(":attemptsLeft", attemptsLeft);
            updateQuery.bindValue(":rfid", message);

            if (!updateQuery.exec()) {
                qDebug() << "Failed to update attempts:" << updateQuery.lastError().text();
            } else {
                qDebug() << "Attempts left updated to:" << attemptsLeft;
            }


            combined = firstName+" "+lastName + '\n';
        }
        else {
            // Accès refusé
            combined = "\n";
        }

        QByteArray tosd = combined.toUtf8();
        qDebug() << "Sending: " << tosd;
        serialPort->write(tosd);

        /*// Update the ACCESS_STATUS to 1
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE MAYSSEM.EMPLOYEES SET ACCESS_STATUS = 1 WHERE CARD_NUMBER = :card_num");
        updateQuery.bindValue(":card_num", lastLine);

        if (!updateQuery.exec()) {
            qDebug() << "Failed to update ACCESS_STATUS:" << updateQuery.lastError().text();
        } else {
            qDebug() << "ACCESS_STATUS updated successfully for CARD_NUMBER:" << lastLine;
            qDebug() << "---------------->" << firstName+" "+lastName;
            combined = firstName+" "+lastName + '\n';
            QByteArray tosd = combined.toUtf8();
            qDebug() << "Sending: " << tosd;
            serialPort->write(tosd);
        }*/
    } else {
        qDebug() << "No employee found with RFID_E =" << serialBuffer;
        qDebug() << "---------------->" << firstName+" "+lastName;
        combined = '\n';
        QByteArray tosd = combined.toUtf8();
        qDebug() << "Sending: " << tosd;
        serialPort->write(tosd);
    }



}

void MainWindow::connect_rfid(){
    cout << "Incoming message..." << endl;
    QByteArray data = arduino->read_from_arduino();
    QString uid = QString::fromStdString(data.toStdString());

    qDebug()<<uid;//pour tester dans la console de
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {


    Connection c;
    c.createconnect();

    ui->setupUi(this);
    ui->stackedWidget_gestions->setCurrentWidget(ui->login_page);
    /*ui->Id_login->clear();
  ui->Password_login->clear();*/
    //load_list_view();

    // Connexion des boutons aux pages correspondantes du QStackedWidget
    connect(ui->List_Button, &QPushButton::clicked, this, &MainWindow::load_list_view_employee );

    connect(ui->Add_Button, &QPushButton::clicked, this, [ = ]() {
        ui->stackedWidget->setCurrentWidget(ui->Add);  // Affiche la page addemp
    });
    connect(ui->forgotpassword_Button, &QPushButton::clicked, this, [ = ]() {
        ui->stackedWidget_gestions->setCurrentWidget(ui->recover_password);
    });

    /*connect(ui->Stat_Button, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentWidget(ui->Stat);  // Affiche la page statemp
  });*/

    /*connect(ui->Edit_Button, &QPushButton::clicked, this, [=]() {
      ui->stackedWidget->setCurrentWidget(ui->Edit);  // Affiche la page modemp
  });*/


    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui->Delete_Button, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Edit_Button, &QPushButton::clicked, this, &MainWindow::on_edit_clicked);
    connect(ui->Search_Button, &QPushButton::clicked, this, &MainWindow::recherche_emp);
    connect(ui->export_pdf_button, &QPushButton::clicked, this, &MainWindow::exportToPDF);
    connect(ui->Stat_Button, &QPushButton::clicked, this, &MainWindow::displayStatistics);

    //Yassine
    load_list_view();
    // Connect navigation buttons to respective pages
    connect(ui->List_Button_Client, &QPushButton::clicked, this, &MainWindow::load_list_view);

    connect(ui->Add_Button_Client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_Client->setCurrentWidget(ui->Add_Client);  // Navigate to the Add page
    });

    connect(ui->Stat_Button_Client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_Client->setCurrentWidget(ui->Stat_Client);  // Navigate to the Statistics page
    });

    connect(ui->Edit_Button_Client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_Client->setCurrentWidget(ui->Edit_Client);  // Navigate to the Edit page
    });
    //connect(ui->Delete_Button_Client, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Confirm_Add_Button_Client, &QPushButton::clicked, this, &MainWindow::on_confirm_add_client_clicked);
    connect(ui->Confirm_Edit_Button_Client, &QPushButton::clicked, this, &MainWindow::on_confirm_edit_client_clicked);

    // Configure table view for row selection
    ui->tableView_Client->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_Client->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect buttons to their respective functionalities
    connect(ui->Delete_Button_Client, &QPushButton::clicked, this, &MainWindow::on_delete_client_clicked);
    connect(ui->Edit_Button_Client, &QPushButton::clicked, this, &MainWindow::on_edit_client_clicked);
    connect(ui->Search_Button_Client, &QPushButton::clicked, this, &MainWindow::recherche_client);
    connect(ui->pdf_Button_Client, &QPushButton::clicked, this, &MainWindow::exportTableToPDF);
    connect(ui->Sort_Button_Client, &QPushButton::clicked, this, &MainWindow::on_Sort_Button_client_clicked);
    connect(ui->cancel_search_button_Client, &QPushButton::clicked, this, &MainWindow::on_cancel_search_client_clicked);
    connect(ui->Stat_Button_Client, &QPushButton::clicked, this, &MainWindow::displayStatistics_client);

    // In MainWindow constructor or setup function
    // int ret = arduino->connect_arduino(); // Try to connect to Arduino
    // switch (ret) {
    // case 0:
    //     qDebug() << "Arduino is available and connected to:" << arduino->getarduino_port_name();
    //     break;
    // case 1:
    //     qDebug() << "Arduino is available but not connected to:" << arduino->getarduino_port_name();
    //     break;
    // case -1:
    //     qDebug() << "Arduino is not available";
    //     break;
    //     }

    // QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(connect_rfid()));
    serialbuffer="";
    QString portName;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == "COM3") {
            portName = info.portName();
            qDebug() << "COM3 found.";
            break;
        }
    }

    if (portName.isEmpty()) {
        qDebug() << "COM3 not found.";
    }
    serialPort = new QSerialPort(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readarduino);
    // Open the serial port
    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open the serial port.";
        delete serialPort;

    }

    // A.read_from_arduino();
    /*switch (ret) {
  case 0: // Success
      qDebug() << "Arduino is available and connected to:" << A.getarduino_port_name();
      // Connect the readyRead signal to handle incoming data
      QObject::connect(A.getserial(), &QSerialPort::readyRead, [&]() {
          QByteArray data = A.read_from_arduino();
          qDebug() << "Received Data:" << data;

          // Check if the received data contains the UID
          if (data.startsWith("UID:")) {
              QString uid = QString::fromUtf8(data.mid(4)); // Extract UID
              qDebug() << "Extracted UID:" << uid;

              // Process the UID (e.g., database lookup, display, etc.)
          }
      });
      break;

  case 1: // Port available but failed to open
      qDebug() << "Arduino is available but not connected to:" << A.getarduino_port_name();
      break;

  case -1: // Arduino not found
      qDebug() << "Arduino is not available.";
      break;

  default:
      qDebug() << "Unexpected error.";
      break;
  }
  int ret=A.connect_arduino(); // lancer la connexion à arduino
  switch(ret){
  case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
      break;
  case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
      break;
  case(-1):qDebug() << "arduino is not available";
      break;
  }

  if (A.connect_arduino()) {
      qDebug() << "Arduino connected.";
      // Connect the readyRead signal to a slot or lambda to handle incoming data
      QObject::connect(A.getserial(), &QSerialPort::readyRead, [&]() {
          QByteArray data = A.read_from_arduino();
          qDebug() << "Received Data:" << data;

          // Check if the received data contains the UID
          if (data.startsWith("UID:")) {
              QString uid = QString::fromUtf8(data.mid(4)); // Extract UID from the data
              qDebug() << "Extracted UID:" << uid;

              // Process the UID, e.g., check it against a database, display it, etc.
          }
      });
  } else {
      qDebug() << "Failed to connect to Arduino.";
  }

  QByteArray buffer; // Buffer to store incomplete messages
  QObject::connect(A.getserial(), &QSerialPort::readyRead, [&]() {
      cout << "Entered Here1" << endl;
      if (!A.getserial()) {
          qDebug() << "Serial object is null!";
          return;
      }
      cout << "Entered Here3" << endl;

      if (!A.getserial()->isOpen()) {
          qDebug() << "Serial port is not open!";
          return;
      }

      cout << "Entered Here4" << endl;

      // Check if data is available before reading
      if (A.getserial()->bytesAvailable() > 0) {
          cout << "Entered Here2" << endl;
          buffer.append(A.getserial()->readAll()); // Append new data to the buffer
          cout << "Entered Here2" << endl;

          // Check for complete messages
          while (buffer.contains('\n')) {
              int index = buffer.indexOf('\n'); // Find the delimiter
              QByteArray message = buffer.left(index); // Extract the message
              buffer.remove(0, index + 1); // Remove the processed message and delimiter

              // Process the complete message
              qDebug() << "Received message:" << message;
          }
      } else {
          qDebug() << "No data available to read.";
      }
  });
  QObject::connect(A.getserial(), &QSerialPort::readyRead, [&]() {
      cout << "Entered Here1" << endl;
      buffer.append(A.getserial()->readAll()); // Append new data to the buffer
      cout << "Entered Here2" << endl;
      // Check for complete messages
      while (buffer.contains('\n')) {
          int index = buffer.indexOf('\n'); // Find the delimiter
          QByteArray message = buffer.left(index); // Extract the message
          buffer.remove(0, index + 1); // Remove the processed message and delimiter

          // Process the complete message
          qDebug() << "Received message:" << message;
      }
  });
  QObject::connect(A.getserial(), &QSerialPort::readyRead, [&]() {

      static QByteArray buffer; // Buffer to accumulate data

      QByteArray data = A.read_from_arduino(); // Use your custom function to read data
      buffer.append(data); // Append the data to the buffer

      int endIndex;
      while ((endIndex = buffer.indexOf('\n')) != -1) { // Look for complete lines
          QByteArray line = buffer.left(endIndex).trimmed(); // Extract the line
          buffer.remove(0, endIndex + 1); // Remove the processed line from buffer

          qDebug() << "Received Data:" << line; // Process and print the line

          // Process specific lines, e.g., lines containing a UID
          if (line.startsWith("UID:")) {
              QString uid = QString::fromUtf8(line.mid(4)); // Extract UID after "UID:"
              qDebug() << "Extracted UID:" << uid;

              // Handle the UID logic here (e.g., database queries, updates, etc.)
          }
      }
  });*/

    // QObject::connect(A.getserial(), &QSerialPort::readyRead, [&](){
    //      cout << "Entered Here" << endl;
    //      QByteArray data = A.read_from_arduino();
    //}); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).




}

void MainWindow::on_Login_Button_clicked() {

    int id = ui->Id_login->text().toInt();
    QString password = ui->Password_login->text();

    Employees employee;
    QString role;

    // Appeler la fonction authenticate
    if (employee.authenticate(id, password, role)) {
        emit loginSuccessful(role); // Notifie le rôle à MainWindow
        QMessageBox::information(this, "Succès", "LOGIN successful");
        if (role == "RH") {
            // Switch to Employee Management Interface
            ui->stackedWidget_gestions->setCurrentWidget(ui->employees_page);
        } else if (role == "service_client") {
            // Switch to Client Management Interface
            ui->stackedWidget_gestions->setCurrentWidget(ui->clients_page);
        } else if (role == "technicien") {
            // Switch to Equipment Management Interface
            ui->stackedWidget_gestions->setCurrentWidget(ui->equipments_page);
        }
        else if (role == "livreur") {
            // Switch to Equipment Management Interface
            ui->stackedWidget_gestions->setCurrentWidget(ui->delivery_page);
        }
        else {
            // Handle unknown roles
            QMessageBox::critical(this, "Erreur", "Rôle inconnu.");
            ui->stackedWidget_gestions->setCurrentWidget(ui->login_page); // Return to Login Interface
        }

    } else {
        QMessageBox::critical(this, "Erreur", "ID ou mot de passe incorrect.");
    }

}

void MainWindow::on_confirm_add_clicked() {

    // Récupérer les données des QLineEdit
    int Id_E = ui->id_add->text().toInt();
    QString Nom_E = ui->nom_add->text();
    QString Prenom_E = ui->prenom_add->text();
    //QDate date = ui->birthdate_add->date();  // This gives a QDate
    // QString Date_Nais_E = date.toString("yyyy-MM-dd");
    QDate Date_Nais_E = ui->birthdate_add->date();
    if (Date_Nais_E.isValid()) {
        cout << "date_nais=" << Date_Nais_E.toString("yyyy-MM-dd").toStdString() << endl;  // Format as 'YYYY-MM-DD'
    } else {
        qDebug() << "Invalid date!";
        cout << "date_format_incorrect" << endl;
    }
    QString Adresse_E = ui->adr_add->text();
    QString Email_E = ui->email_add->text();
    QString Tel_E = ui->tel_add->text();
    QString Poste_E = ui->poste_add->text(); // Utilise la méthode `date()` pour récupérer une date
    QString Mdp_E = ui->mdp_add->text();
    QString Sexe_E = ui->gender_add->currentText();
    QString Answ1_E = ui->fav_anim_add->text();
    QString Answ2_E = ui->fav_snack_add->text();
    QString RFID_E = ui->rfid_add->text();
    int Attempts_E;
    cout << Id_E << endl;
    cout << "nom:  " << Nom_E.toStdString() << " prenom: " << Prenom_E.toStdString() << " adresse:  " << Adresse_E.toStdString() << " Email:  " << Email_E.toStdString() << " tel:  " << Tel_E.toStdString() << " poste:  " << Poste_E.toStdString() << "mdp:  " << Mdp_E.toStdString() << "sexe:  " << Sexe_E.toStdString() << "sexe:  " << Answ1_E.toStdString() << Answ2_E.toStdString() << std::endl;


    // Vérifier si les champs ne sont pas vides
    if (Id_E == 0 || Nom_E.isEmpty() || Prenom_E.isEmpty() || Sexe_E.isEmpty()  || Adresse_E.isEmpty() || Email_E.isEmpty() || Tel_E.isEmpty() || Poste_E.isEmpty() || Mdp_E.isEmpty() ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }
    // VALID e-mail
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(Email_E).hasMatch()) {
        QMessageBox::warning(this, "Adresse e-mail invalide", "Veuillez entrer une adresse e-mail valide.");
        return;
    }

    // valid tel (8 chiffres)
    QRegularExpression phoneRegex("^\\d{8}$");
    if (!phoneRegex.match(Tel_E).hasMatch()) {
        QMessageBox::warning(this, "Numéro de téléphone invalide", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    Employees E(Id_E, Nom_E, Prenom_E, Sexe_E, Date_Nais_E, Adresse_E, Email_E, Tel_E, Poste_E, Mdp_E, Answ1_E, Answ2_E, RFID_E, Attempts_E);
    bool ajout = E.ajouter();


    // Exécuter la requête et vérifier si l'insertion a réussi
    if (ajout) {
        QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès.");
        // Réinitialiser les champs après l'ajout
        ui->id_add->clear();
        ui->nom_add->clear();
        ui->prenom_add->clear();
        //ui->gender_add->clear();
        ui->birthdate_add->clear();
        ui->adr_add->clear();
        ui->email_add->clear();
        ui->tel_add->clear();
        ui->poste_add->clear();
        ui->mdp_add->clear();
        ui->fav_anim_add->clear();
        ui->fav_snack_add->clear();
        ui->rfid_add->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
    load_list_view_employee();


}

void MainWindow::on_delete_clicked() {
    // Get the currently selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }
    // Get the first selected row's index
    int row = selectedRows.first().row();

    // Assuming your model is connected to the database:
    // 1. Get the ID of the employee from the selected row
    int id_emp = ui->tableView->model()->index(row, 0).data().toInt();  // assuming the ID is in column 0

    // 2. Confirm deletion with the user (optional)
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this employee?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;
    Employees E;
    bool success = E.supprimer(id_emp);
    if (success) {
        QMessageBox::information(this, "Success", "Employee deleted successfully.");
        load_list_view_employee();
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete employee.");
    }
}

void MainWindow::on_edit_clicked() {
    // Get the currently selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to edit.");
        cout << "here_warning" << endl;
        return;
    }

    int row = selectedRows.first().row();
    cout << "row:" << row << endl;

    //get data in row_selected
    // Access the model associated with the QTableView

    QAbstractItemModel *model = ui->tableView->model();

    int id_E = model->data(model->index(row, 0)).toInt(); // First column data
    QString nom_E = model->data(model->index(row, 1)).toString();
    QString prenom_E = model->data(model->index(row, 2)).toString();  // Prenom (third column)
    QDate date_Nais_E = model->data(model->index(row, 3)).toDate();  // Date de naissance (fourth column)
    QString adresse_E = model->data(model->index(row, 4)).toString();  // Adresse (fifth column)
    QString email_E = model->data(model->index(row, 5)).toString();  // Email (sixth column)
    QString tel_E = model->data(model->index(row, 6)).toString();  // Telephone (seventh column)
    QString poste_E = model->data(model->index(row, 7)).toString();  // Poste (eighth column)
    string decrypted_pw = (model->data(model->index(row, 8))).toString().toStdString();
    QString mdp_E = QString::fromStdString(Employees::decryptPassword(decrypted_pw));  // Mot de passe (ninth column)
    QString sexe_E = model->data(model->index(row, 9)).toString();
    QString Answ1_E = model->data(model->index(row, 10)).toString(); // ANSW1 (eleventh column)
    QString Answ2_E = model->data(model->index(row, 11)).toString(); // ANSW2 (twelfth column)
    QString RFID_E = model->data(model->index(row, 12)).toString();  // RFID (thirteenth column)
    int Attempts_E = model->data(model->index(row, 13)).toInt();     // Attempts (fourteenth column)



    //display the edit_interface
    ui->stackedWidget->setCurrentWidget(ui->Edit);
    cout << "here_affichage" << endl;
    //set the line_edits in edit interface
    ui->id_edit->setText(QString::number(id_E));
    ui->nom_edit->setText(nom_E);
    ui->prenom_edit->setText(prenom_E);
    ui->birthdate_edit->setDate(date_Nais_E);
    ui->adr_edit->setText(adresse_E);
    ui->email_edit->setText(email_E);
    ui->tel_edit->setText(tel_E);
    ui->poste_edit->setText(poste_E);
    ui->mdp_edit->setText(mdp_E);
    ui->gender_edit->setCurrentText(sexe_E);
    ui->fav_anim_edit->setText(Answ1_E);
    ui->fav_snack_edit->setText(Answ2_E);

    //update
    //on_confirm_edit_clicked();


}

void MainWindow::on_confirm_edit_clicked() {
    //Recuperer les données encore une fois des line_edits
    int Id_E = ui->id_edit->text().toInt();
    QString Nom_E = ui->nom_edit->text();
    QString Prenom_E = ui->prenom_edit->text();
    QDate Date_Nais_E = ui->birthdate_edit->date();
    if (Date_Nais_E.isValid()) {
        cout << "date_nais=" << Date_Nais_E.toString("yyyy-MM-dd").toStdString() << endl;  // Format as 'YYYY-MM-DD'
    } else {
        qDebug() << "Invalid date!";
        cout << "date_format_incorrect" << endl;
    }
    QString Adresse_E = ui->adr_edit->text();
    QString Email_E = ui->email_edit->text();
    QString Tel_E = ui->tel_edit->text();
    QString Poste_E = ui->poste_edit->text(); // Utilise la méthode `date()` pour récupérer une date
    QString Mdp_E = ui->mdp_edit->text();
    QString Sexe_E = ui->gender_edit->currentText();
    QString Answ1_E = ui->fav_anim_edit->text();
    QString Answ2_E = ui->fav_snack_edit->text();
    QString RFID_E;
    int Attempts_E;
    cout << Id_E << endl;
    cout << "nom:  " << Nom_E.toStdString() << " prenom: " << Prenom_E.toStdString() << " adresse:  " << Adresse_E.toStdString() << " Email:  " << Email_E.toStdString() << " tel:  " << Tel_E.toStdString() << " poste:  " << Poste_E.toStdString() << "mdp:  " << Mdp_E.toStdString() << "sexe:  " << Sexe_E.toStdString() << std::endl;
    cout << "im here" << endl;

    // Vérifier si les champs ne sont pas vides
    if (Id_E == 0 || Nom_E.isEmpty() || Prenom_E.isEmpty() || Sexe_E.isEmpty()  || Adresse_E.isEmpty() || Email_E.isEmpty() || Tel_E.isEmpty() || Poste_E.isEmpty() || Mdp_E.isEmpty() ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }
    Employees E(Id_E, Nom_E, Prenom_E, Sexe_E, Date_Nais_E, Adresse_E, Email_E, Tel_E, Poste_E, Mdp_E, Answ1_E, Answ2_E, RFID_E, Attempts_E);
    bool edit = E.modifier();
    if (edit) {
        QMessageBox::information(this, "Succès", "L'employé a été modifié avec succès.");
        // Réinitialiser les champs après l'ajout
        ui->id_edit->clear();
        ui->nom_edit->clear();
        ui->prenom_edit->clear();
        //ui->gender_add->clear();
        ui->birthdate_edit->clear();
        ui->adr_edit->clear();
        ui->email_edit->clear();
        ui->tel_edit->clear();
        ui->poste_edit->clear();
        ui->mdp_edit->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification de l'employé a échoué.");
    }
    load_list_view_employee();

}

void MainWindow::recherche_emp() {
    QString search_id = ui->Search_line_edit->text().trimmed();

    // Convert the ID to integer if needed
    int id = search_id.toInt();

    // Check if the ID is valid
    if (id == 0) {
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid ID.");
        return;
    }

    // Create an instance of the Employees class (assuming it exists in employees.h)
    Employees emp;

    // Call the search_employee function from employees.cpp
    QSqlQueryModel *model = emp.search(id);

    if (model) {
        // Set the result to the table view
        ui->tableView->setModel(model);
    }
}
void MainWindow::on_cancel_search_button_clicked() {
    ui->Search_line_edit->clear();
    Employees E;
    ui->tableView->setModel(E.afficher());

}
/*void MainWindow::exportToPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    // Create a PDF writer
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));

    // Create a painter
    QPainter painter(&pdfWriter);
    painter.setFont(QFont("Times", 12));

    // Table headers
    QStringList headers = QStringList() << "ID" << "NOM" << "PRENOM" << "DATE_NAISSANCE" << "ADRESSE" << "EMAIL" << "TELEPHONE" << "POSTE" << "MDP" << "SEXE";
    int rowHeight = 20;
    int columnWidth = 100;

    // Draw headers
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(i*columnWidth, rowHeight, headers[i]);
    }

    // Draw a line
    painter.drawLine(0, rowHeight + 5, columnWidth * headers.size(), rowHeight + 5);
    rowHeight += 25;

    // Fetch deliveries from the model
    QSqlQueryModel * model = new QSqlQueryModel();
    Employees Emp;
    model = Emp.afficher();
    int rowCount = model->rowCount();

    // Populate the PDF with the data
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < headers.size(); ++column) {
            QString itemText = model->data(model->index(row, column)).toString();
            painter.drawText(column*columnWidth, rowHeight, itemText);
        }
        rowHeight += 20;  // Move to next row
    }

    painter.end();
    QMessageBox::information(this, "Export Successful", "Le fichier PDF a été effectué avec succès ");
}*/

void MainWindow::exportToPDF() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (filePath.isEmpty()) {
        return;
    }

    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(10, 10, 10, 10));

    QPainter painter(&pdfWriter);

    QAbstractItemModel* model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, "Export Error", "No data available to export.");
        return;
    }

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    // Calculate column widths dynamically based on content
    QVector<int> columnWidths(columnCount, 0);
    QFontMetrics metrics(painter.font());
    for (int col = 0; col < columnCount; ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
        int maxWidth = metrics.horizontalAdvance(headerText) + 20; // Padding for headers
        for (int row = 0; row < rowCount; ++row) {
            QString cellText = model->data(model->index(row, col), Qt::DisplayRole).toString();
            int textWidth = metrics.horizontalAdvance(cellText) + 20; // Padding for content
            maxWidth = qMax(maxWidth, textWidth);
        }
        columnWidths[col] = maxWidth;
    }

    // Adjust row height dynamically
    int rowHeight = metrics.height() + 20; // Padding for rows

    // Title
    int yPos = 100;
    QFont titleFont("Arial", 20, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(0, yPos - 50, pdfWriter.width(), rowHeight, Qt::AlignCenter, "Employees Table");

    // Draw headers
    QFont headerFont("Arial", 14, QFont::Bold);
    painter.setFont(headerFont);
    int xPos = 0;
    for (int col = 0; col < columnCount; ++col) {
        QRect headerRect(xPos, yPos, columnWidths[col], rowHeight);
        painter.fillRect(headerRect, Qt::lightGray);
        painter.drawRect(headerRect);
        QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
        painter.drawText(headerRect.adjusted(5, 5, -5, -5), Qt::AlignCenter, headerText);
        xPos += columnWidths[col];
    }
    yPos += rowHeight;

    // Draw table content
    QFont contentFont("Arial", 12);
    painter.setFont(contentFont);
    for (int row = 0; row < rowCount; ++row) {
        xPos = 0;
        QColor rowColor = (row % 2 == 0) ? QColor(240, 240, 240) : Qt::white;

        for (int col = 0; col < columnCount; ++col) {
            QRect cellRect(xPos, yPos, columnWidths[col], rowHeight);
            painter.fillRect(cellRect, rowColor);
            painter.drawRect(cellRect);
            QString cellText = model->data(model->index(row, col), Qt::DisplayRole).toString();
            painter.drawText(cellRect.adjusted(5, 5, -5, -5), Qt::AlignLeft | Qt::AlignVCenter, cellText);
            xPos += columnWidths[col];
        }
        yPos += rowHeight;

        // Page overflow handling
        if (yPos + rowHeight > pdfWriter.height()) {
            pdfWriter.newPage();
            yPos = 100;

            // Redraw headers
            xPos = 0;
            painter.setFont(headerFont);
            for (int col = 0; col < columnCount; ++col) {
                QRect headerRect(xPos, yPos, columnWidths[col], rowHeight);
                painter.fillRect(headerRect, Qt::lightGray);
                painter.drawRect(headerRect);
                QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
                painter.drawText(headerRect.adjusted(5, 5, -5, -5), Qt::AlignCenter, headerText);
                xPos += columnWidths[col];
            }
            yPos += rowHeight;
            painter.setFont(contentFont);
        }
    }

    painter.end();
    QMessageBox::information(this, "PDF Export", "PDF successfully created at: " + filePath);
}


void MainWindow::on_Sort_Button_clicked() {
    // Get the sort criterion from the user input (e.g., ComboBox or LineEdit)
    QString sortBy = ui->sort_criterion->currentText();  // Assuming a QComboBox is used

    // Prepare the SQL query to fetch all employees from the database
    QSqlQuery query;
    QString sortOrder = "ASC";  // Default sort order (ascending)

    if (sortBy == "Nom") {
        query.prepare("SELECT * FROM MAYSSEM.EMPLOYEES ORDER BY NOM_E " + sortOrder);
    } else if (sortBy == "Prenom") {
        query.prepare("SELECT * FROM MAYSSEM.EMPLOYEES ORDER BY PRENOM_E " + sortOrder);
    } else if (sortBy == "ID") {
        query.prepare("SELECT * FROM MAYSSEM.EMPLOYEES ORDER BY ID_E " + sortOrder);
    } else {
        QMessageBox::warning(this, "Invalid Sort Criterion", "Please select a valid criterion to sort by.");
        return;
    }

    // Execute the query
    if (query.exec()) {
        // Create a model to hold the data from the database
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);

        // Set the model to the table view to display the sorted data
        ui->tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to execute query.");
    }
}
void MainWindow::displayStatistics() {
    // Verify that 'stat' is indeed a QWidget (it should hold content like charts)
    if (!ui->Stat) {
        qDebug() << "'stat' widget is null!";
        return;
    }

    // Clear any existing charts or widgets in the 'stat' page
    QLayout *layout = ui->Stat->layout(); // Assuming 'stat' has a layout set
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->Stat); // Create layout if not exists
        ui->Stat->setLayout(layout);
    }

    // Create a map to hold the status counts
    QMap<QString, int> statusCounts;
    QSqlQuery query;

    // Prepare and execute the query
    query.prepare("SELECT SEXE_E, COUNT(*) FROM MAYSSEM.EMPLOYEES GROUP BY SEXE_E");
    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        QMessageBox::warning(this, "SQL Error", "Error retrieving statistics.");
        return;
    }

    // Populate statusCounts
    while (query.next()) {
        QString etat = query.value(0).toString(); // Delivery state
        int count = query.value(1).toInt(); // Count for this state
        statusCounts[etat] = count; // Store in the map
    }

    if (statusCounts.isEmpty()) {
        QMessageBox::information(this, "Statistics", "No Employees found.");
        return;
    }

    // Create the pie series and populate it
    QPieSeries *series = new QPieSeries();
    for (auto it = statusCounts.constBegin(); it != statusCounts.constEnd(); ++it) {
        series->append(it.key(), it.value());
    }

    // Create the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Status Statistics");

    // Create a chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add the chart view to the stat widget
    layout->addWidget(chartView); // Add chart view to the layout of the stat widget

    // Switch to the stat page inside the stacked widget
    ui->stackedWidget->setCurrentWidget(ui->Stat);  // Assuming 'stackedWidget' is the name of your QStackedWidget
}
bool MainWindow::getEmailAndPassword(int id, QString &email, QString &password) {
    QSqlQuery query;
    query.prepare("SELECT EMAIL_E, MDP_E FROM MAYSSEM.EMPLOYEES WHERE ID_E = :id");
    query.bindValue(":id", id);
    std::cout << "id:" << id << endl;

    if (query.exec() && query.next()) {
        email = query.value("EMAIL_E").toString();
        std::cout << "email:" << email.toStdString() << endl;
        password = query.value("MDP_E").toString();
        std::cout << "password:" << password.toStdString() << endl;
        return true;
    }

    return false; // ID non trouvé
}

void MainWindow::on_send_email_button_clicked() {
    // Récupérer l'ID saisi par l'utilisateur
    int id = ui->Id_login->text().toInt();
    std::cout<<"id_here:"<<id<<endl;
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QString email, password;

    // Rechercher l'email et le mot de passe dans la base de données
    if (!getEmailAndPassword(id, email, password)) {
        QMessageBox::critical(this, "Erreur", "ID non trouvé dans la base de données.");
        return;
    }
    std::cout << "email-2:" << email.toStdString() << endl;
    std::cout << "password-2:" << password.toStdString() << endl;

    std::string decrypted_pw = Employees::decryptPassword(password.toStdString());
    std::cout << "passwor_decryptee:" << decrypted_pw << endl;
    Mailer mailer = Mailer();
    mailer.sendEmail(email, "Password_Recovered", QString::fromStdString(decrypted_pw));
    QMessageBox::information(this, "Send_Email", "Email successfully sent");

}

bool MainWindow::getAnsw1AndAnsw2(int id, QString &answ1, QString &answ2) {
    QSqlQuery query;
    query.prepare("SELECT ANSW1_E, ANSW2_E FROM MAYSSEM.EMPLOYEES WHERE ID_E = :id");
    query.bindValue(":id", id);
    std::cout << "id:" << id << endl;

    if (query.exec() && query.next()) {
        answ1 = query.value("ANSW1_E").toString();
        std::cout << "answ1:" << answ1.toStdString() << endl;
        answ2 = query.value("ANSW2_E").toString();
        std::cout << "answ2:" << answ2.toStdString() << endl;
        return true;
    }

    return false; // ID non trouvé
}
void MainWindow::on_Recover_Button_clicked() {
    // Récupérer l'ID saisi par l'utilisateur
    int id = ui->Id_Recover->text().toInt();

    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }
    QString answ1, answ2;
    if (!getAnsw1AndAnsw2(id,answ1,answ2)) {
        QMessageBox::critical(this, "Erreur", "ID non trouvé dans la base de données.");
        return;
    }
    //lire les reponses
    QString answ1_nouv, answ2_nouv;
    answ1_nouv=ui->fav_anim_recover->text();
    answ2_nouv=ui->fav_snack_recover->text();
    if(!((answ1==answ1_nouv) && (answ2==answ2_nouv)))
    {       QMessageBox::critical(this, "Erreur", "Reponses incorrectes.");
        return;
    }
    ui->stackedWidget_gestions->setCurrentWidget(ui->change_password_page);
}
void MainWindow::on_confirm_changed_psw_Button_clicked()
{
    int id = ui->Id_Recover->text().toInt();

    Employees E;
    //ui->stackedWidget_gestions->setCurrentWidget(ui->change_password_page);
    QString new_password=ui->changed_password->text();
    string encrypted_new_psw=E.encryptPassword(new_password.toStdString());
    QString upd_pw=QString::fromStdString(encrypted_new_psw);
    bool res=E.update_password(id,upd_pw);
    if(res)
    {
        QMessageBox::information(this, "Succès", "Le mot de passe a été reinitialisé avec succés.");
        ui->stackedWidget_gestions->setCurrentWidget(ui->login_page);
    }
}
/*void MainWindow::readRFIDTag() {
    Arduino a;
    QByteArray data = a.read_from_arduino();
    QString message = QString(data).trimmed();
    //cout<<"message:"<<message.toStdString()<<endl;

    if (message.startsWith("UID:")) {
        QString rfidTag = message.mid(4); // Extraire l'UID
        qDebug() << "Tag detected:" << rfidTag;

        // Chercher l'UID dans la base de données
        checkUIDInDatabase(rfidTag);
    }
}

void MainWindow::checkUIDInDatabase(const QString &rfidTag) {
    QSqlQuery query;
    Arduino a;
    query.prepare("SELECT COUNT(*) FROM MAYSSEM.EMPLOYEES WHERE RFID_E = :rfid");
    query.bindValue(":rfid", rfidTag);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count > 0) {
            qDebug() << "Access granted for tag:" << rfidTag;
            a.write_to_arduino("ACCESS_GRANTED\n");
        } else {
            qDebug() << "Access denied for tag:" << rfidTag;
            a.write_to_arduino("ACCESS_DENIED\n");
        }
    } else {
        qDebug() << "Database error: " << query.lastError().text();
        a.write_to_arduino("ACCESS_DENIED\n");
    }
}*/

//Yassine

// Add a new client
void MainWindow::on_confirm_add_client_clicked()
{
    // Récupérer les données des champs d'entrée
    int id = ui->id_add_Client->text().toInt();
    QString name = ui->Add_Nom_Client->text();
    QString first_name = ui->Add_firstname_Client->text();  // Champ pour le prénom

    QDate age = ui->birthdate_add_Client->date(); // Use birthdate instead of age
    QString address = ui->Add_Address_Client->text();
    QString region = ui->Add_region_Client->text();  // Champ pour la région
    QString email = ui->Add_email_Client->text();
    int phone_number = ui->Add_Phone_Client->text().toInt();

    // Validate the inputs
    if (id == 0 || name.isEmpty() || first_name.isEmpty()  || address.isEmpty() || email.isEmpty() || region.isEmpty()|| phone_number==0) {
        QMessageBox::warning(this, "Champs Manquants", "Veuillez remplir tous les champs.");
        return;
    }

    static const QRegularExpression phoneRegex("^[0-9]{8}$"); // Static regular expression
    if (!phoneRegex.match(QString::number(phone_number)).hasMatch()) {
        QMessageBox::warning(this, "Numéro de Téléphone Invalide", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }


    static const QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@esprit\\.tn$"); // Static regular expression
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email Invalide", "L'adresse email doit se terminer par @esprit.tn.");
        return;
    }


    // Créer un objet Client et tenter de l'ajouter à la base de données
    Client C (id, name, first_name, age, address, region, email, phone_number);
    bool ajout = C.ajouter();

    if (ajout) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès.");

        // Vider les champs d'entrée après l'ajout réussi
        ui->id_add_Client->clear();
        ui->Add_Nom_Client->clear();
        ui->Add_firstname_Client->clear();  // Effacer le prénom
        ui->Add_Phone_Client->clear();
        ui->birthdate_add_Client->clear();
        ui->Add_Address_Client->clear();
        ui->Add_region_Client->clear();  // Effacer la région
        ui->Add_email_Client->clear();

        load_list_view();  // Recharger la vue de liste pour refléter l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}
// Delete a client
void MainWindow::on_delete_client_clicked()
{
    // Get the selected row
    QModelIndexList selectedRows = ui->tableView_Client->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to delete.");
        return;
    }

    int row = selectedRows.first().row();
    int id = ui->tableView_Client->model()->index(row, 0).data().toInt();  // Get ID from the first column

    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this client?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No)
        return;

    Client C;
    if (C.supprimer(id)) {
        QMessageBox::information(this, "Success", "Client deleted successfully.");
        load_list_view();
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete client.");
    }
}

// Edit a client
void MainWindow::on_edit_client_clicked()
{
    QModelIndexList selectedRows = ui->tableView_Client->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to edit.");
        return;
    }

    int row = selectedRows.first().row();
    QAbstractItemModel *model = ui->tableView_Client->model();

    // Fetch data from the selected row
    int id = model->data(model->index(row, 0)).toInt();
    QString name = model->data(model->index(row, 1)).toString();
    QString firstname = model->data(model->index(row, 2)).toString();  // Added firstname
    QDate age = model->data(model->index(row, 3)).toDate();
    QString address = model->data(model->index(row, 4)).toString();
    QString region = model->data(model->index(row, 5)).toString();  // Added region
    QString phone_number = model->data(model->index(row, 7)).toString();
    QString email = model->data(model->index(row, 6)).toString();  // Assuming the photo path is in the 9th column


    // Populate the Edit page fields
    ui->id_edit_Client->setText(QString::number(id));
    ui->nom_edit_Client->setText(name);
    ui->firstname_edit_Client->setText(firstname);  // Set firstname
    ui->birthdate_edit_Client->setDate(age);
    ui->adr_edit_Client->setText(address);
    ui->region_edit_Client->setText(region);  // Set region
    ui->tel_edit_Client->setText(phone_number);
    ui->email_edit_Client->setText(email);
}

// Confirm edit
void MainWindow::on_confirm_edit_client_clicked()
{
    // Get updated data from input fields
    int id = ui->id_edit_Client->text().toInt();
    QString name = ui->nom_edit_Client->text().trimmed(); // Trim whitespace
    QString firstname = ui->firstname_edit_Client->text().trimmed(); // Trim whitespace
    QDate age = ui->birthdate_edit_Client->date();
    QString address = ui->adr_edit_Client->text().trimmed(); // Trim whitespace
    QString region = ui->region_edit_Client->text().trimmed(); // Trim whitespace
    QString email = ui->email_edit_Client->text().trimmed(); // Trim whitespace
    int phone_number = ui->tel_edit_Client->text().toInt();


    qDebug() << "phone printing :" << phone_number;

    // Validate inputs
    if (id <= 0 || name.isEmpty() || firstname.isEmpty() || phone_number <= 0 || address.isEmpty() || email.isEmpty() || region.isEmpty()) {
        QMessageBox::warning(this, "Missing Fields", "Please fill in all fields.");
        return;
    }

    // Create updated Client object
    Client C(id, firstname, name, age, address, region, email, phone_number); // Include firstname and region
    if (C.modifier()) { // Ensure modifier handles firstname and region
        QMessageBox::information(this, "Success", "Client updated successfully.");
        load_list_view();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update client.");
    }
}

// Search for a client
void MainWindow::recherche_client()
{
    int id = ui->Search_line_edit_Client->text().toInt();

    // Validate ID
    if (id == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid ID.");
        return;
    }

    Client C;
    QSqlQueryModel *model = C.search(id);

    if (model->rowCount() > 0) {
        ui->tableView_Client->setModel(model);
    } else {
        QMessageBox::warning(this, "No Results", "No client found with the entered ID.");}
}

void MainWindow::exportTableToPDF()
{
    // Ask user for a location to save the PDF file
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (filePath.isEmpty()) {
        return;
    }

    // Ensure the file has a .pdf extension
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    // Create a QPdfWriter with reduced margins for a larger table
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(10, 10, 10, 10)); // Reduced margins

    QPainter painter(&pdfWriter);

    QAbstractItemModel* model = ui->tableView_Client->model();
    if (!model) {
        QMessageBox::warning(this, "Export Error", "No data available to export.");
        return;
    }

    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    // Adjust column widths to fill the page width
    int pageWidth = pdfWriter.width() - 20; // Adjust for margins
    QVector<int> columnWidths(columnCount);
    for (int col = 0; col < columnCount; ++col) {
        columnWidths[col] = pageWidth / columnCount + 5; // Increase width slightly for better spacing
    }

    // Set initial positions and larger font settings
    int yPos = 100;  // Starting y position for the table
    int rowHeight = 300; // Larger row height for bigger rows

    // Title with larger font and centered alignment
    QFont titleFont("Arial", 20, QFont::Bold); // Bigger font size
    painter.setFont(titleFont);
    painter.drawText(0, yPos - 300, pdfWriter.width(), rowHeight, Qt::AlignCenter, "Client Table");

    // Set font for headers and content
    QFont headerFont("Arial", 14, QFont::Bold); // Bigger header font
    QFont contentFont("Arial", 12); // Bigger content font

    // Draw column headers
    painter.setFont(headerFont);
    int xPos = 0;
    for (int col = 0; col < columnCount; ++col) {
        QRect headerRect(xPos, yPos, columnWidths[col], rowHeight);
        painter.fillRect(headerRect, Qt::lightGray); // Background color for headers
        painter.drawRect(headerRect);  // Draw rectangle around the header cell
        QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
        painter.drawText(headerRect.adjusted(15, 15, -15, -15), Qt::AlignCenter, headerText); // Add more padding
        xPos += columnWidths[col];
    }
    yPos += rowHeight;

    // Draw table rows
    painter.setFont(contentFont);
    for (int row = 0; row < rowCount; ++row) {
        xPos = 0;
        QColor rowColor = (row % 2 == 0) ? QColor(240, 240, 240) : Qt::white; // Alternating row color

        for (int col = 0; col < columnCount; ++col) {
            QRect cellRect(xPos, yPos, columnWidths[col], rowHeight);
            painter.fillRect(cellRect, rowColor);  // Apply background color
            painter.drawRect(cellRect);  // Draw rectangle around the cell

            QModelIndex index = model->index(row, col);
            QString cellText = model->data(index, Qt::DisplayRole).toString();
            painter.drawText(cellRect.adjusted(15, 15, -15, -15), Qt::AlignCenter, cellText); // Add more padding
            xPos += columnWidths[col];
        }
        yPos += rowHeight;

        // Check for page overflow
        if (yPos + rowHeight > pdfWriter.height()) {
            pdfWriter.newPage();
            yPos = 100;  // Reset y position for new page

            // Redraw headers
            xPos = 0;
            painter.setFont(headerFont);
            for (int col = 0; col < columnCount; ++col) {
                QRect headerRect(xPos, yPos, columnWidths[col], rowHeight);
                painter.fillRect(headerRect, Qt::lightGray);
                painter.drawRect(headerRect);
                QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
                painter.drawText(headerRect.adjusted(15, 15, -15, -15), Qt::AlignCenter, headerText);
                xPos += columnWidths[col];
            }
            yPos += rowHeight;
            painter.setFont(contentFont);  // Reset to content font for rows
        }
    }

    painter.end();

    QMessageBox::information(this, "PDF Export", "PDF successfully created at: " + filePath);
}

void MainWindow::on_Sort_Button_client_clicked() {
    // Get the sort criterion from the user input (e.g., ComboBox or LineEdit)
    QString sortBy = ui->sort_criterion_Client->currentText();  // Assuming a QComboBox is used

    // Prepare the SQL query to fetch all clients from the database
    QSqlQuery query;
    QString sortOrder = "ASC";  // Default sort order (ascending)

    if (sortBy == "Nom") {
        query.prepare("SELECT * FROM MAYSSEM.CLIENTS ORDER BY NOM_C " + sortOrder);
    } else if (sortBy == "ID") {
        query.prepare("SELECT * FROM MAYSSEM.CLIENTS ORDER BY ID_C " + sortOrder);
    } else {
        QMessageBox::warning(this, "Invalid Sort Criterion", "Please select a valid criterion to sort by.");
        return;
    }

    // Log the query to see if it's correct
    qDebug() << "SQL Query: " << query.lastQuery();

    // Execute the query
    if (query.exec()) {
        // Check if the query returned any results
        if (query.size() == 0) {
            QMessageBox::information(this, "No Data", "No data found for the given sort criterion.");
        } else {
            // Create a model to hold the data from the database
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(query);

            // Check for errors in the model
            if (model->lastError().isValid()) {
                QMessageBox::critical(this, "Model Error", model->lastError().text());
                return;
            }

            // Set the model to the table view to display the sorted data
            ui->tableView_Client->setModel(model);
        }
    } else {
        // If the query fails, show the error message
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + query.lastError().text());
    }
}

void MainWindow::on_cancel_search_client_clicked()
{
    ui->Search_line_edit_Client->clear();
    Client C;
    ui->tableView_Client->setModel(C.afficher());

}

void MainWindow::displayStatistics_client() {
    // Verify that 'Stat' is indeed a QWidget (it should hold content like charts)
    if (!ui->Stat_Client) {
        qDebug() << "'Stat' widget is null!";
        return;
    }

    // Clear any existing charts or widgets in the 'Stat' page
    QLayout *layout = ui->Stat_Client->layout(); // Assuming 'Stat' has a layout set
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            if (item->widget()) delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->Stat_Client); // Create layout if not exists
        ui->Stat_Client->setLayout(layout);
    }

    // Create a map to hold the region counts
    QMap<QString, int> regionCounts;
    QSqlQuery query;

    // Prepare and execute the query
    query.prepare("SELECT REGION_C, COUNT(*) FROM MAYSSEM.CLIENTS GROUP BY REGION_C");
    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();
        QMessageBox::warning(this, "SQL Error", "Error retrieving statistics.");
        return;
    }

    int totalClients = 0;

    // Populate regionCounts and calculate total clients
    while (query.next()) {
        QString region = query.value(0).toString();
        int count = query.value(1).toInt();
        regionCounts[region] = count;
        totalClients += count;
    }

    if (regionCounts.isEmpty()) {
        QMessageBox::information(this, "Statistics", "No regions found in the database.");
        return;
    }

    // Create the pie series and populate it with percentages
    QPieSeries *series = new QPieSeries();
    for (auto it = regionCounts.constBegin(); it != regionCounts.constEnd(); ++it) {
        double percentage = (static_cast<double>(it.value()) / totalClients) * 100.0;
        QString label = QString("%1 (%2%)").arg(it.key()).arg(QString::number(percentage, 'f', 2));
        series->append(label, it.value());
    }

    // Create the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Client Distribution by Region (Total: %1)").arg(totalClients));

    // Add labels with percentage directly on the chart
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    // Create a chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add the chart view to the Stat widget
    layout->addWidget(chartView);

    // Switch to the Stat page inside the stacked widget
    ui->stackedWidget_Client->setCurrentWidget(ui->Stat_Client);
}
















