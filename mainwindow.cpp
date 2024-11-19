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
#include<QHeaderView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include "connection.h"
using namespace std;
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::load_list_view()
{
    Employees E;
    ui->tableView->setModel(E.afficher());
    ui->stackedWidget->setCurrentWidget(ui->list_view);

}
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{


    Connection c;
    c.createconnect();
    ui->setupUi(this);
    load_list_view();

    // Connexion des boutons aux pages correspondantes du QStackedWidget
    connect(ui->List_Button, &QPushButton::clicked, this, &MainWindow::load_list_view );

    connect(ui->Add_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Add);  // Affiche la page addemp
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
    QString Tel_E = ui->tel_add->text();
    QString Poste_E = ui->poste_add->text(); // Utilise la méthode `date()` pour récupérer une date
    QString Mdp_E = ui->mdp_add->text();
    QString Sexe_E = ui->gender_add->currentText();

    cout << Id_E << endl;
    cout<< "nom:  " << Nom_E.toStdString() << " prenom: " <<Prenom_E.toStdString()<< " adresse:  " <<Adresse_E.toStdString()<< " Email:  " <<Email_E.toStdString()<< " tel:  " <<Tel_E.toStdString()<< " poste:  "<< Poste_E.toStdString() << "mdp:  "<<Mdp_E.toStdString()<< "sexe:  "<< Sexe_E.toStdString() << std::endl;


    // Vérifier si les champs ne sont pas vides
    if (Id_E == 0 || Nom_E.isEmpty() || Prenom_E.isEmpty() || Sexe_E.isEmpty()  || Adresse_E.isEmpty() || Email_E.isEmpty() || Tel_E.isEmpty() || Poste_E.isEmpty() || Mdp_E.isEmpty() ) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
        return;
    }

    Employees E(Id_E,Nom_E,Prenom_E,Sexe_E,Date_Nais_E,Adresse_E,Email_E,Tel_E,Poste_E,Mdp_E);
    bool ajout=E.ajouter();


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
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
    load_list_view();


}

void MainWindow::on_delete_clicked()
{
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
               load_list_view();
                        }
           else {
                   QMessageBox::warning(this, "Error", "Failed to delete employee.");
               }
}

void MainWindow::on_edit_clicked()
{
    // Get the currently selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a row to edit.");
        cout<<"here_warning"<<endl;
        return;
     }

        int row = selectedRows.first().row();
        cout<<"row:"<<row<<endl;

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
        QString mdp_E = model->data(model->index(row, 8)).toString();  // Mot de passe (ninth column)
        QString sexe_E = model->data(model->index(row, 9)).toString();

        //display the edit_interface
       ui->stackedWidget->setCurrentWidget(ui->Edit);
       cout<<"here_affichage"<<endl;
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

        //update
        //on_confirm_edit_clicked();


}
void MainWindow::on_confirm_edit_clicked()
{
    //Recuperer les données encore une fois des line_edits
     int Id_E = ui->id_edit->text().toInt();
     QString Nom_E = ui->nom_edit->text();
     QString Prenom_E = ui->prenom_edit->text();
     QDate Date_Nais_E= ui->birthdate_edit->date();
       if (Date_Nais_E.isValid()) {
           cout << "date_nais=" << Date_Nais_E.toString("yyyy-MM-dd").toStdString() << endl;  // Format as 'YYYY-MM-DD'
       } else {
           qDebug() << "Invalid date!";
           cout<<"date_format_incorrect"<<endl;
       }
     QString Adresse_E = ui->adr_edit->text();
     QString Email_E = ui->email_edit->text();
     QString Tel_E = ui->tel_edit->text();
     QString Poste_E = ui->poste_edit->text(); // Utilise la méthode `date()` pour récupérer une date
     QString Mdp_E = ui->mdp_edit->text();
     QString Sexe_E = ui->gender_edit->currentText();

     cout << Id_E << endl;
     cout<< "nom:  " << Nom_E.toStdString() << " prenom: " <<Prenom_E.toStdString()<< " adresse:  " <<Adresse_E.toStdString()<< " Email:  " <<Email_E.toStdString()<< " tel:  " <<Tel_E.toStdString()<< " poste:  "<< Poste_E.toStdString() << "mdp:  "<<Mdp_E.toStdString()<< "sexe:  "<< Sexe_E.toStdString() << std::endl;
     cout<<"im here"<<endl;

     // Vérifier si les champs ne sont pas vides
     if (Id_E == 0 || Nom_E.isEmpty() || Prenom_E.isEmpty() || Sexe_E.isEmpty()  || Adresse_E.isEmpty() || Email_E.isEmpty() || Tel_E.isEmpty() || Poste_E.isEmpty() || Mdp_E.isEmpty() ) {
         QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs.");
         return;
     }
     Employees E(Id_E,Nom_E,Prenom_E,Sexe_E,Date_Nais_E,Adresse_E,Email_E,Tel_E,Poste_E,Mdp_E);
     bool edit=E.modifier();
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
     load_list_view();

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
void MainWindow::on_cancel_search_button_clicked()
{
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
    painter.drawText(0, yPos - 50, pdfWriter.width(), rowHeight, Qt::AlignCenter, "Client Table");

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


void MainWindow::on_Sort_Button_clicked()
{
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
    }
    else {
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







