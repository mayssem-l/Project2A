
#define MAINWINDOW_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraison.h"  // Include your Livraison class
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QModelIndex>
#include <QItemSelectionModel>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include "connection.h"
#include "client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QString>
#include <QPixmap>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QListView>
#include <QRegularExpressionValidator>
#include <QDebug>
#include <QDoubleValidator>
#include <QFile>
#include <QTextStream>
#include <QPageSize>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);



    const QRegularExpression idRegex("^\\d{1,9}$");
    const QRegularExpression nameRegex("^[a-zA-Z\\s]*$");
    const QRegularExpression numberRegex("^\\d{8}$"); // Phone number exactly 8 digits
    const QRegularExpression addressRegex("^[a-zA-Z0-9\\s]*$");

    // Set validators for input fields
    ui->IDdeliv->setValidator(new QRegularExpressionValidator(idRegex, this));
    ui->FNdeli->setValidator(new QRegularExpressionValidator(nameRegex, this));
    ui->LSdeli->setValidator(new QRegularExpressionValidator(nameRegex, this));
    ui->NUMdeli->setValidator(new QRegularExpressionValidator(numberRegex, this));
    ui->ADdeli->setValidator(new QRegularExpressionValidator(addressRegex, this));
    ui->PRdeli->setValidator(new QDoubleValidator(0.01, 9999.99, 2, this)); // Allow decimal prices
    ui->ID_2deliv->setValidator(new QRegularExpressionValidator(idRegex, this)); // Apply digit-only validation to ID_2


    connect(ui->ID_2deliv, &QLineEdit::textChanged, this, [=](const QString &text) {
        bool parsedOk;
        int clientId = text.toInt(&parsedOk); // Essayer de convertir le texte en entier
        if (parsedOk && clientId > 0) { // Si l'ID est valide (supérieur à 0)
            loadClientData(clientId); // Charger les données pour cet ID
        } else {
            // Vider les champs si l'ID n'est pas valide
            ui->FNdeli->clear();
            ui->LSdeli->clear();
            ui->NUMdeli->clear();
            ui->ADdeli->clear();
        }
    });

    // Connect buttons to show the appropriate widgets
    connect(ui->ADDDELIVERY, &QToolButton::clicked, this, [=]() {
        ui->stackedWidgetdeli->setCurrentWidget(ui->Adddeli);
        clearInputFields();  // Clear fields when navigating to Add
    });

    connect(ui->DList, &QToolButton::clicked, this, [=]() {
        displayDeliveries();
        ui->stackedWidgetdeli->setCurrentWidget(ui->LISTdeli);
    });

    connect(ui->CONFIRMdeli, &QToolButton::clicked, this, [=]() {
        addDELIVERY(true); // Confirm button clicked
    });

    connect(ui->CANCELdeli, &QToolButton::clicked, this, [=]() {
        addDELIVERY(false); // Cancel button clicked
    });

    connect(ui->histodeli, &QToolButton::clicked, this, [=]() {
        displayDeliveries();
        ui->stackedWidgetdeli->setCurrentWidget(ui->historique);
    });

    // Handle text change for validation
    connect(ui->IDdeliv, &QLineEdit::textChanged, this, &MainWindow::validateID);
    connect(ui->FNdeli, &QLineEdit::textChanged, this, &MainWindow::validateFields);
    connect(ui->LSdeli, &QLineEdit::textChanged, this, &MainWindow::validateFields);
    connect(ui->NUMdeli, &QLineEdit::textChanged, this, &MainWindow::validateFields);
    connect(ui->ADdeli, &QLineEdit::textChanged, this, &MainWindow::validateFields);
    connect(ui->PRdeli, &QLineEdit::textChanged, this, &MainWindow::validateFields);

    connect(ui->DELETEdeli, &QToolButton::clicked, this, &MainWindow::deleteDelivery);
    connect(ui->EDITdeli, &QToolButton::clicked, this, &MainWindow::editDelivery);
    connect(ui->Searchdeli, &QToolButton::clicked, this, &MainWindow::searchDelivery);
    connect(ui->FILTERdeli, &QToolButton::clicked, this, &MainWindow::trie);
    connect(ui->statdeliv, &QToolButton::clicked, this, &MainWindow::displayStatistics);
    connect(ui->histodeli, &QToolButton::clicked, this, &MainWindow::displayHistorique);
    connect(ui->PDFdeli, &QToolButton::clicked, this, &MainWindow::exportPDF);
    connect(ui->SMSdeli, &QToolButton::clicked, this, &MainWindow::onSmsButtonClicked);

    // Assurez-vous que la locale est spécifiée pour accepter le point comme séparateur décimal
    QDoubleValidator *priceValidator = new QDoubleValidator(0.01, 9999.99, 2, this);
    priceValidator->setNotation(QDoubleValidator::StandardNotation);
    priceValidator->setLocale(QLocale(QLocale::English, QLocale::UnitedStates)); // Remplacez par votre locale si besoin
    ui->PRdeli->setValidator(priceValidator);


    //soukeh
    load_list_view();


    // Connect navigation buttons to respective pages
    connect(ui->List_Button_client, &QPushButton::clicked, this, &MainWindow::load_list_view);

    connect(ui->Add_Button_client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_client->setCurrentWidget(ui->Add_client);  // Navigate to the Add page
    });

    connect(ui->Stat_Button_client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_client->setCurrentWidget(ui->Stat_client);  // Navigate to the Statistics page
    });

    connect(ui->Edit_Button_client, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget_client->setCurrentWidget(ui->Edit_client);  // Navigate to the Edit page
    });
    connect(ui->Delete_Button_client, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Confirm_Add_Button_client, &QPushButton::clicked, this, &MainWindow::on_confirm_add_clicked);
    connect(ui->Confirm_Edit_Button_client, &QPushButton::clicked, this, &MainWindow::on_confirm_edit_clicked);

    // Configure table view for row selection
    ui->tableView_client->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_client->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect buttons to their respective functionalities
    connect(ui->Delete_Button_client, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Edit_Button_client, &QPushButton::clicked, this, &MainWindow::on_edit_clicked);
    connect(ui->Search_Button_client, &QPushButton::clicked, this, &MainWindow::recherche_emp);
    connect(ui->pdf_Button_client, &QPushButton::clicked, this, &MainWindow::exportTableToPDF);
    connect(ui->Sort_Button_client, &QPushButton::clicked, this, &MainWindow::on_Sort_Button_clicked);
    connect(ui->Stat_Button_client, &QPushButton::clicked, this, &MainWindow::displayStatistics);
    // In MainWindow constructor or setup function


}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::displayHistorique() {
     QFile file("C:/Users/Lenovo/Desktop/3awedcrud/hhh/historique.txt");

    // Assurez-vous que le fichier est créé s'il n'existe pas
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Erreur lors de la création du fichier:" << file.errorString();
            QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier d'historique.");
            return;
        }
        file.close(); // Fermez le fichier après l'avoir créé
    }

    // Essayer d'ouvrir le fichier en mode lecture
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString contenu = in.readAll(); // Lire tout le contenu du fichier
        file.close();

        // Afficher le contenu dans un QLabel
        ui->label_17deli->setText(contenu);
    } else {
        // Si l'ouverture échoue, afficher un message d'avertissement à l'utilisateur
        qDebug() << "Erreur lors de l'ouverture du fichier:" << file.errorString();
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
    }
}
void MainWindow::validateID(const QString &text) {
    highlightField(ui->IDdeliv, !text.isEmpty() && QRegularExpression("^\\d{1,9}$").match(text).hasMatch());
    if (currentIdForEditing == -1 || (text.toInt() != currentIdForEditing)) {
        checkIdExists(text);
    } else {
        ui->idWarningIcondeli->setVisible(false);
        ui->CONFIRMdeli->setEnabled(true);
    }
}

void MainWindow::validateFields(const QString &) {
    highlightField(ui->FNdeli, !ui->FNdeli->text().isEmpty() && QRegularExpression("^[a-zA-Z\\s]*$").match(ui->FNdeli->text()).hasMatch());
    highlightField(ui->LSdeli, !ui->LSdeli->text().isEmpty() && QRegularExpression("^[a-zA-Z\\s]*$").match(ui->LSdeli->text()).hasMatch());
    highlightField(ui->NUMdeli, !ui->NUMdeli->text().isEmpty() && QRegularExpression("^\\d{8}$").match(ui->NUMdeli->text()).hasMatch());
    highlightField(ui->ADdeli, !ui->ADdeli->text().isEmpty() && QRegularExpression("^[a-zA-Z0-9\\s]*$").match(ui->ADdeli->text()).hasMatch());
    highlightField(ui->PRdeli, !ui->PRdeli->text().isEmpty());
}

void MainWindow::highlightField(QLineEdit *field, bool isValid) {
    field->setStyleSheet(isValid ? "" : "background-color: lightpink;");
}

void MainWindow::checkIdExists(const QString &text) {
    if (text.isEmpty()) {
        ui->idWarningIcondeli->setVisible(false);
        ui->CONFIRMdeli->setEnabled(true);
        return;
    }

    int ID_LIV = text.toInt();
    Livraison livraison;

    if (livraison.idExists(ID_LIV)) {
        ui->idWarningIcondeli->setVisible(true);
        ui->idWarningIcondeli->setText("ID existe déjà");
        ui->IDdeliv->setStyleSheet("background-color: red;");
        ui->CONFIRMdeli->setEnabled(false);
    } else {
        ui->idWarningIcondeli->setVisible(false);
        ui->IDdeliv->setStyleSheet("");
        ui->CONFIRMdeli->setEnabled(true);
    }
}

void MainWindow::validateClientId(const QString &text) {

if (currentIdForEditing == -1 || (text.toInt() != currentIdForEditing)) {
checkIdExists(text);
} else {
ui->idWarningIcon_2deli->setVisible(false);
ui->CONFIRMdeli->setEnabled(true);
}
}

void MainWindow::checkClientIdExists(const QString &text) {
if (text.isEmpty()) {
ui->idWarningIcon_2deli->setText(""); // Vider le message si le champ de texte est vide
ui->CONFIRMdeli->setEnabled(false); // Désactiver le bouton de confirmation
return;
}

int clientId = text.toInt();
Livraison livraison;

if (livraison.idExists(clientId)) {
ui->idWarningIcon_2deli->setVisible(false);
ui->idWarningIcon_2deli->setText("ID valide"); // Affiche que l'ID est valide
ui->CONFIRMdeli->setEnabled(true); // Activer le bouton de confirmation
} else {
ui->idWarningIcon_2deli->setVisible(true);
ui->idWarningIcon_2deli->setText("ID n'existe pas"); // Affiche que l'ID n'existe pas
ui->ID_2deliv->setStyleSheet("background-color: red;");
ui->CONFIRMdeli->setEnabled(false); // Désactiver le bouton de confirmation
}
}





void MainWindow::loadClientData(int clientId) {
    QSqlQuery query;
    query.prepare("SELECT NOM_C, FIRST_NAME_C, TEL_C, ADRESSE_C FROM clients WHERE ID_C = :id");
    query.bindValue(":id", clientId);

    if (query.exec() && query.next()) {
        ui->FNdeli->setText(query.value("NOM_C").toString());
        ui->LSdeli->setText(query.value("FIRST_NAME_C").toString());
        ui->NUMdeli->setText(query.value("TEL_C").toString());
        ui->ADdeli->setText(query.value("ADRESSE_C").toString());
    } else {
        ui->FNdeli->clear();
        ui->LSdeli->clear();
        ui->NUMdeli->clear();
        ui->ADdeli->clear();
        ui->IDdeliv->clear();
        QMessageBox::warning(this, "Erreur", "Aucun client trouvé avec cet ID.");
    }}

void MainWindow::addDELIVERY(bool isConfirm) {
    if (isConfirm) {
        QString errorMessage;
        int ID_LIV = ui->IDdeliv->text().toInt();

        // Vérification des champs
        if (!ui->IDdeliv->hasAcceptableInput() || ui->IDdeliv->text().isEmpty()) {
            errorMessage += "Veuillez remplir le champ ID (doit être entre 1 et 9 chiffres).\n";
        }

        if (!ui->ADdeli->hasAcceptableInput() || ui->ADdeli->text().isEmpty()) {
            errorMessage += "Veuillez remplir le champ Adresse.\n";
        }

        float prix = ui->PRdeli->text().toFloat(); // Lire le prix comme un float
        if (prix <= 0) {
            errorMessage += "Veuillez remplir le champ Prix (doit être positif).\n";
        }

        // Vérifiez si l'ID est unique si nous ne sommes pas en train d'éditer
        if (currentIdForEditing == -1 && Livraison().idExists(ID_LIV)) {
            errorMessage += "ID existe déjà. Veuillez choisir un autre ID.\n";
        }

        // Afficher les messages d'erreur si nécessaire
        if (!errorMessage.isEmpty()) {
            QMessageBox::warning(this, "Champs manquants", errorMessage);
            return;
        }

        // Préparer les données pour la livraison
        QString nom_client = ui->FNdeli->text();
        QString prenom_client = ui->LSdeli->text();
        QString num_client = ui->NUMdeli->text();
        QString ADR_LIV = ui->ADdeli->text();
        QString etat = ui->ETdeli->currentText();
        QDate date = ui->DATEdeli->date();

        // Créer un objet Livraison avec les données
        Livraison livraisonToAddOrUpdate(ID_LIV, prenom_client, nom_client, num_client, ADR_LIV, prix, etat, date);

        if (currentIdForEditing == -1) {
            // Tenter d'ajouter la livraison
            if (livraisonToAddOrUpdate.ajouter()) {
                QMessageBox::information(this, "Succès", "Ajout réussi avec succès.");
                displayDeliveries(); // Actualiser l'affichage
            } else {
                QMessageBox::warning(this, "Échec", "L'ajout a échoué.");
            }
        } else {
            // Modifier une livraison existante
            if (livraisonToAddOrUpdate.modifier(currentIdForEditing)) {
                QMessageBox::information(this, "Succès", "Modification réussie avec succès.");
                displayDeliveries();  // Actualiser l'affichage
            } else {
                QMessageBox::warning(this, "Échec", "Échec de la modification.");
            }

            // Réinitialiser l'ID d'édition après l'opération
            currentIdForEditing = -1; // Important pour signaler que nous ne sommes plus en mode édition
        }

        clearInputFields(); // Vider les champs après l'ajout/modification
    } else {
        clearInputFields(); // Vider les champs si on annule
    }
}

void MainWindow::clearInputFields() {
    ui->IDdeliv->clear();
    ui->ID_2deliv->clear();
    ui->FNdeli->clear();
    ui->LSdeli->clear();
    ui->NUMdeli->clear();
    ui->ADdeli->clear();
    ui->PRdeli->clear();
    ui->DATEdeli->setDate(QDate::currentDate());
    ui->ETdeli->setCurrentIndex(0);
    ui->idWarningIcondeli->setVisible(false);
}

void MainWindow::displayDeliveries() {
    QTableWidget *deliveryTable = ui->tableWidgetdeli; // Pointer to your table widget
    deliveryTable->clear(); // Clear previous data
    deliveryTable->setColumnCount(8); // Set number of columns
    deliveryTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Prénom" << "Nom" << "Téléphone" << "Adresse" << "Prix" << "État" << "Date"); // Set headers

    Livraison livraison; // Create an instance of the Livraison class
    QSqlQueryModel* model = livraison.afficher(); // Call the existing method afficher
    int rowCount = model->rowCount(); // Get the number of rows from the model
    deliveryTable->setRowCount(rowCount); // Set row count in the table widget

    // Populate the table with data
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < 8; ++column) {
            QString itemText = model->data(model->index(row, column)).toString(); // Get data from the model
            if (column == 5) { // Assuming column 5 is for price
                itemText = QString::number(itemText.toFloat(), 'f', 2); // Format price to two decimal places
            }
            if (column == 7) { // Assuming column 7 is for date
                QDate date = QDate::fromString(itemText, Qt::ISODate);
                itemText = date.toString("yyyy-MM-dd"); // Format date to "YYYY-MM-DD"
            }
            deliveryTable->setItem(row, column, new QTableWidgetItem(itemText)); // Set item in the table
        }
    }

    deliveryTable->resizeColumnsToContents(); // Resize columns for better visibility
}

void MainWindow::editDelivery() {
    QTableWidget *deliveryTable = ui->tableWidgetdeli;
    int currentRow = deliveryTable->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Veuillez sélectionner une livraison à modifier.");
        return;
    }

    int oldDeliveryId = deliveryTable->item(currentRow, 0)->text().toInt();
    currentIdForEditing = oldDeliveryId;

    Livraison livraison;
    QSqlQuery query;
    query.prepare("SELECT PRENOM_CLIENT, NOM_CLIENT, NUM_CLIENT, ADR_LIV, PRIX_LIV, ETAT_LIV, DATE_LIV FROM LIVRAISON WHERE ID_LIV = :id");
    query.bindValue(":id", oldDeliveryId);

    if (query.exec() && query.next()) {
        ui->IDdeliv->setText(QString::number(oldDeliveryId));
        ui->FNdeli->setText(query.value(0).toString());
        ui->LSdeli->setText(query.value(1).toString());
        ui->NUMdeli->setText(query.value(2).toString());
        ui->ADdeli->setText(query.value(3).toString());
        ui->PRdeli->setText(QString::number(query.value(4).toFloat(), 'f', 2));
        ui->ETdeli->setCurrentText(query.value(5).toString());
        ui->DATEdeli->setDate(query.value(6).toDate());

        ui->stackedWidgetdeli->setCurrentWidget(ui->Adddeli);
        ui->idWarningIcondeli->setVisible(false);
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des détails de livraison.");
    }
}


void MainWindow::deleteDelivery() {
    QTableWidget *deliveryTable = ui->tableWidgetdeli;
    int currentRow = deliveryTable->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Veuillez sélectionner une livraison à supprimer.");
        return;
    }

    int deliveryId = deliveryTable->item(currentRow, 0)->text().toInt();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer la suppression", "Êtes-vous sûr de vouloir supprimer cette livraison?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Livraison livraison;
        if (livraison.supprimer(deliveryId)) {
            QMessageBox::information(this, "Succès", "Livraison supprimée avec succès.");
            displayDeliveries();
        } else {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la suppression de la livraison.");
        }
    }
}

void MainWindow::searchDelivery() {
    QString searchIdText = ui->SEARCHline->text();
    bool idOk;
    int searchId = searchIdText.toInt(&idOk);

    // Ensure the ID is valid
    if (!idOk || searchId <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Veuillez entrer un ID valide.");
        return;
    }

    Livraison livraison;

    // Create a query to find the delivery with the specified ID
    QSqlQuery query;
    query.prepare("SELECT ID_LIV, PRENOM_CLIENT, NOM_CLIENT, NUM_CLIENT, ADR_LIV, PRIX_LIV, ETAT_LIV, DATE_LIV FROM LIVRAISON WHERE ID_LIV = :id");
    query.bindValue(":id", searchId);

    if (query.exec() && query.next()) {
        // Clear the table and set headers
        ui->tableWidgetdeli->clear();
        ui->tableWidgetdeli->setColumnCount(8);
        ui->tableWidgetdeli->setHorizontalHeaderLabels(QStringList() << "ID" << "Prénom" << "Nom" << "Téléphone" << "Adresse" << "Prix" << "État" << "Date");

        // Populate the table with the search result
        ui->tableWidgetdeli->setRowCount(1); // Only one result expected
        for (int column = 0; column < 8; ++column) {
            QString itemText = query.value(column).toString();
            if (column == 5) { // Assuming the price is in this column
                itemText = QString::number(itemText.toFloat(), 'f', 2); // Format price
            }

            // Handle date formatting if necessary
            if (column == 7) {
                QDate date = QDate::fromString(itemText, Qt::ISODate);
                itemText = date.toString("yyyy-MM-dd");
            }

            ui->tableWidgetdeli->setItem(0, column, new QTableWidgetItem(itemText));
        }

        ui->tableWidgetdeli->resizeColumnsToContents();
    } else {
        // No results found
        QMessageBox::information(this, "Search Result", "Aucune livraison trouvée pour cet ID.");
        ui->tableWidgetdeli->clear();
    }
     ui->SEARCHline->clear();
}

void MainWindow::trie() {
    qDebug() << "trie() method called"; // Confirmation que cette méthode est appelée

    QTableWidget *deliveryTable = ui->tableWidgetdeli; // Pointeur vers votre table
    deliveryTable->clear(); // Efface les données précédentes
    deliveryTable->setColumnCount(8); // Définit le nombre de colonnes
    deliveryTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Prénom" << "Nom" << "Téléphone" << "Adresse" << "Prix" << "État" << "Date"); // Définit les en-têtes

    // Adaptation de la méthode afficher pour trier par date décroissante
    Livraison livraison; // Crée une instance de la classe Livraison
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour trier par date décroissante
    query.prepare("SELECT ID_LIV, PRENOM_CLIENT, NOM_CLIENT, NUM_CLIENT, ADR_LIV, PRIX_LIV, ETAT_LIV, DATE_LIV FROM LIVRAISON ORDER BY DATE_LIV DESC");

    if (query.exec()) {
        model->setQuery(std::move(query));
        int rowCount = model->rowCount(); // Nombre de lignes dans le modèle
        deliveryTable->setRowCount(rowCount); // Définit le nombre de lignes dans le tableau

        // Remplir le tableau avec les données
        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < 8; ++column) {
                QString itemText = model->data(model->index(row, column)).toString();
                qDebug() << "Row:" << row << "Column:" << column << "Data:" << itemText;

                if (column == 5) { // Supposons que la colonne 5 est pour le prix
                    itemText = QString::number(itemText.toFloat(), 'f', 2);
                }

                if (column == 7) { // Supposons que la colonne 7 est pour la date
                    QDate date = QDate::fromString(itemText, Qt::ISODate);
                    itemText = date.toString("yyyy-MM-dd");
                }

                deliveryTable->setItem(row, column, new QTableWidgetItem(itemText));
            }
        }
    } else {
        qDebug() << "Erreur SQL lors du tri:" << query.lastError().text();
    }

    deliveryTable->resizeColumnsToContents(); // Ajuste la taille des colonnes pour une meilleure visibilité
}

void MainWindow::displayStatistics() {
    // Verify that 'stat' is indeed a QWidget (it should hold content like charts)
    if (!ui->STATwdeli) {
        qDebug() << "'stat' widget is null!";
        return;
    }

    // Clear any existing charts or widgets in the 'stat' page
    QLayout *layout = ui->STATwdeli->layout(); // Assuming 'stat' has a layout set
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->STATwdeli); // Create layout if not exists
        ui->STATwdeli->setLayout(layout);
    }

    // Create a map to hold the status counts
    QMap<QString, int> statusCounts;
    QSqlQuery query;

    // Prepare and execute the query
    query.prepare("SELECT ETAT_LIV, COUNT(*) FROM LIVRAISON GROUP BY ETAT_LIV");
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
        QMessageBox::information(this, "Statistics", "No deliveries found.");
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
    chart->setTitle("Delivery Status Statistics");

    // Create a chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add the chart view to the stat widget
    layout->addWidget(chartView); // Add chart view to the layout of the stat widget

    // Switch to the stat page inside the stacked widget
    ui->stackedWidgetdeli->setCurrentWidget(ui->STATwdeli);  // Assuming 'stackedWidget' is the name of your QStackedWidget
}

QSqlQueryModel* MainWindow::getDeliveriesModel() {
    Livraison livraison;  // Instance de la classe Livraison
    return livraison.afficher(); // Appeler la méthode afficher définie dans votre classe Livraison
}


void MainWindow::exportPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer sous", QString(), "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    // Configurez l'écrivain PDF pour un format A4 normal
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4)); // Format A4
    writer.setResolution(300);

    // Changer l'orientation à paysage par la suite
    writer.setPageOrientation(QPageLayout::Landscape); // Utilisez l'orientation paysage

    QPainter painter(&writer);
    painter.setFont(QFont("Helvetica", 10));

    // Titre
    painter.drawText(1175, 50, "Liste des Livraisons");

    // En-têtes de colonnes avec espacement
    painter.drawText(50, 125, "ID");
    painter.drawText(400, 125, "Prénom");
    painter.drawText(750, 125, "Nom");
    painter.drawText(1000, 125, "Numéro");
    painter.drawText(1350, 125, "Adresse");
    painter.drawText(1850, 125, "Prix");
    painter.drawText(2200, 125, "État");
    painter.drawText(2500, 125, "Date");

    // Ligne de séparation
    painter.drawLine(50, 150, 3000, 150); // Ajustez la largeur de la ligne de séparation

    QSqlQueryModel* model = getDeliveriesModel();
    int rowCount = model->rowCount();

    int yOffset = 210;  // Démarrer la position Y pour les données

    for (int row = 0; row < rowCount; ++row) {
        // Récupérer les valeurs des colonnes
        QString id = model->data(model->index(row, 0)).toString();
        QString prenom = model->data(model->index(row, 1)).toString();
        QString nom = model->data(model->index(row, 2)).toString();
        QString numero = model->data(model->index(row, 3)).toString();
        QString adresse = model->data(model->index(row, 4)).toString();
        QString prix = model->data(model->index(row, 5)).toString();
        QString etat = model->data(model->index(row, 6)).toString();

        // Récupérer et formater la date
        QString dateRaw = model->data(model->index(row, 7)).toString();
        QString dateFormatted;

        if (!dateRaw.isEmpty()) {
            dateFormatted = dateRaw.mid(0, 10); // Prendre uniquement la partie YYYY-MM-DD
        }

        // Positionner et dessiner chaque colonne
        painter.drawText(50, yOffset, id);
        painter.drawText(400, yOffset, prenom);
        painter.drawText(750, yOffset, nom);
        painter.drawText(1000, yOffset, numero);
        painter.drawText(1350, yOffset, adresse);
        painter.drawText(1850, yOffset, prix);
        painter.drawText(2200, yOffset, etat);
        painter.drawText(2500, yOffset, dateFormatted); // Utiliser la date formatée

        // Incrémentez la position Y pour la prochaine ligne
        yOffset += 120; // Gardez un espacement vertical raisonnable entre les lignes
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le fichier PDF a été créé avec succès.");
}


QString MainWindow::getSelectedDeliveryClientPhoneNumber() {
    QTableWidget *deliveryTable = ui->tableWidgetdeli; // Assurez-vous que 'tableWidget' est le nom correct
    int currentRow = deliveryTable->currentRow(); // Récupérer la ligne sélectionnée

    if (currentRow < 0) {
        return ""; // Si aucune ligne n'est sélectionnée, retourner une chaîne vide
    }

    return deliveryTable->item(currentRow, 3)->text(); // Assuming the phone number is in the 4th column (index 3)
}

void MainWindow::onSmsButtonClicked() {
    QString customerPhoneNumber = getSelectedDeliveryClientPhoneNumber();
    if (customerPhoneNumber.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone du client non disponible.");
        return;
    }

    // Récupérer l'état de la livraison
    QTableWidget *deliveryTable = ui->tableWidgetdeli; // Assurez-vous que 'tableWidget' est le bon nom
    int currentRow = deliveryTable->currentRow(); // Récupérer la ligne sélectionnée

    if (currentRow < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une livraison.");
        return;
    }

    QString etat = deliveryTable->item(currentRow, 6)->text(); // Supposant que l'état est dans la 7ème colonne (index 6)
    QString message;

    // Déterminer le message selon l'état
    if (etat == "livree") {
        message = "Votre commande a été livrée avec succès.";
    } else if (etat == "en cours") {
        message = "Votre commande est en cours de livraison.";
    } else  {
        message = "Votre commande sera bientôt livrée.";
    }

    QString mobileAppUrl = "mobileconnect://";
    if (!QDesktopServices::openUrl(QUrl(mobileAppUrl))) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'application Mobile Connectée.");
        return;
    }

    // Préparer le SMS à envoyer
    QString smsUrl = QString("sms:%1?body=%2").arg(customerPhoneNumber, QUrl::toPercentEncoding(message));
    if (!QDesktopServices::openUrl(QUrl(smsUrl))) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'application de messagerie.");
    }
}




//soukeh

void MainWindow::load_list_view()
{
    Client C;
    ui->tableView_client->setModel(C.afficher());
    ui->stackedWidget_client->setCurrentWidget(ui->list_view_client);  // Switch to the list view
}

// Add a new client
void MainWindow::on_confirm_add_clicked()
{
    // Récupérer les données des champs d'entrée
    int id = ui->id_add_client->text().toInt();
    QString name = ui->Add_Nom_client->text();
    QString first_name = ui->Add_firstname_client->text();  // Champ pour le prénom

    QDate age = ui->birthdate_add_client->date(); // Use birthdate instead of age
    QString address = ui->Add_Address_client->text();
    QString region = ui->Add_region_client->text();  // Champ pour la région
    QString email = ui->Add_email_client->text();
    int phone_number = ui->Add_Phone_client->text().toInt();

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
        ui->id_add_client->clear();
        ui->Add_Nom_client->clear();
        ui->Add_firstname_client->clear();  // Effacer le prénom
        ui->Add_Phone_client->clear();
        ui->birthdate_add_client->clear();
        ui->Add_Address_client->clear();
        ui->Add_region_client->clear();  // Effacer la région
        ui->Add_email_client->clear();

        load_list_view();  // Recharger la vue de liste pour refléter l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}



// Delete a client
void MainWindow::on_delete_clicked()
{
    // Get the selected row
    QModelIndexList selectedRows = ui->tableView_client->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to delete.");
        return;
    }

    int row = selectedRows.first().row();
    int id = ui->tableView_client->model()->index(row, 0).data().toInt();  // Get ID from the first column

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
void MainWindow::on_edit_clicked()
{
    QModelIndexList selectedRows = ui->tableView_client->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to edit.");
        return;
    }

    int row = selectedRows.first().row();
    QAbstractItemModel *model = ui->tableView_client->model();

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
    ui->id_edit_client->setText(QString::number(id));
    ui->nom_edit_client->setText(name);
    ui->firstname_edit_client->setText(firstname);  // Set firstname
    ui->birthdate_edit_client->setDate(age);
    ui->adr_edit_client->setText(address);
    ui->region_edit_client->setText(region);  // Set region
    ui->tel_edit_client->setText(phone_number);
    ui->email_edit_client->setText(email);


}

// Confirm edit
void MainWindow::on_confirm_edit_clicked()
{
    // Get updated data from input fields
    int id = ui->id_edit_client->text().toInt();
    QString name = ui->nom_edit_client->text().trimmed(); // Trim whitespace
    QString firstname = ui->firstname_edit_client->text().trimmed(); // Trim whitespace
    QDate age = ui->birthdate_edit_client->date();
    QString address = ui->adr_edit_client->text().trimmed(); // Trim whitespace
    QString region = ui->region_edit_client->text().trimmed(); // Trim whitespace
    QString email = ui->email_edit_client->text().trimmed(); // Trim whitespace
    int phone_number = ui->tel_edit_client->text().toInt();


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
void MainWindow::recherche_emp()
{
    int id = ui->Search_line_edit_client->text().toInt();

    // Validate ID
    if (id == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid ID.");
        return;
    }

    Client C;
    QSqlQueryModel *model = C.search(id);

    if (model->rowCount() > 0) {
        ui->tableView_client->setModel(model);
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

    QAbstractItemModel* model = ui->tableView_client->model();
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


void MainWindow::on_Sort_Button_clicked() {
    // Get the sort criterion from the user input (e.g., ComboBox or LineEdit)
    QString sortBy = ui->sort_criterion_client->currentText();  // Assuming a QComboBox is used

    // Prepare the SQL query to fetch all clients from the database
    QSqlQuery query;
    QString sortOrder = "ASC";  // Default sort order (ascending)

    if (sortBy == "Nom") {
        query.prepare("SELECT * FROM CLIENTS ORDER BY NOM_C " + sortOrder);
    } else if (sortBy == "ID") {
        query.prepare("SELECT * FROM CLIENTS ORDER BY ID_C " + sortOrder);
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
            ui->tableView_client->setModel(model);
        }
    } else {
        // If the query fails, show the error message
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + query.lastError().text());
    }
}

void MainWindow::on_cancel_search_button_clicked()
{
    ui->Search_line_edit_client->clear();
    Client C;
    ui->tableView_client->setModel(C.afficher());

}
void MainWindow::displayStatisticsreg() {
    // Verify that 'Stat' is indeed a QWidget (it should hold content like charts)
    if (!ui->Stat_client) {
        qDebug() << "'Stat' widget is null!";
        return;
    }

    // Clear any existing charts or widgets in the 'Stat' page
    QLayout *layout = ui->Stat_client->layout(); // Assuming 'Stat' has a layout set
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0))) {
            if (item->widget()) delete item->widget();
            delete item;
        }
    } else {
        layout = new QVBoxLayout(ui->Stat_client); // Create layout if not exists
        ui->Stat_client->setLayout(layout);
    }

    // Create a map to hold the region counts
    QMap<QString, int> regionCounts;
    QSqlQuery query;

    // Prepare and execute the query
    query.prepare("SELECT REGION_C, COUNT(*) FROM CLIENTS GROUP BY REGION_C");
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
    ui->stackedWidget_client->setCurrentWidget(ui->Stat_client);
}
