#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QVBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QListView>

using namespace std;

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    Connection c;
    c.createconnect();
    ui->setupUi(this);
    load_list_view();


    // Connect navigation buttons to respective pages
    connect(ui->List_Button, &QPushButton::clicked, this, &MainWindow::load_list_view);

    connect(ui->Add_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Add);  // Navigate to the Add page
    });

    /*connect(ui->Stat_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Stat);  // Navigate to the Statistics page
    });*/

    connect(ui->Edit_Button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->Edit);  // Navigate to the Edit page
    });
    connect(ui->Delete_Button, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Confirm_Add_Button, &QPushButton::clicked, this, &MainWindow::on_confirm_add_clicked);
    connect(ui->Confirm_Edit_Button, &QPushButton::clicked, this, &MainWindow::on_confirm_edit_clicked);

    // Configure table view for row selection
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connect buttons to their respective functionalities
    connect(ui->Delete_Button, &QPushButton::clicked, this, &MainWindow::on_delete_clicked);
    connect(ui->Edit_Button, &QPushButton::clicked, this, &MainWindow::on_edit_clicked);
    connect(ui->Search_Button, &QPushButton::clicked, this, &MainWindow::recherche_emp);
    connect(ui->pdf_Button, &QPushButton::clicked, this, &MainWindow::exportTableToPDF);
    connect(ui->Sort_Button, &QPushButton::clicked, this, &MainWindow::on_Sort_Button_clicked);
    connect(ui->Stat_Button, &QPushButton::clicked, this, &MainWindow::displayStatistics);
    // In MainWindow constructor or setup function




}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Load and display the list of clients
void MainWindow::load_list_view()
{
    Client C;
    ui->tableView->setModel(C.afficher());
    ui->stackedWidget->setCurrentWidget(ui->list_view);  // Switch to the list view
}

// Add a new client
void MainWindow::on_confirm_add_clicked()
{
    // Récupérer les données des champs d'entrée
    int id = ui->id_add->text().toInt();
    QString name = ui->Add_Nom->text();
    QString first_name = ui->Add_firstname->text();  // Champ pour le prénom

    QDate age = ui->birthdate_add->date(); // Use birthdate instead of age
    QString address = ui->Add_Address->text();
    QString region = ui->Add_region->text();  // Champ pour la région
    QString email = ui->Add_email->text();
    int phone_number = ui->Add_Phone->text().toInt();

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
        ui->id_add->clear();
        ui->Add_Nom->clear();
        ui->Add_firstname->clear();  // Effacer le prénom
        ui->Add_Phone->clear();
        ui->birthdate_add->clear();
        ui->Add_Address->clear();
        ui->Add_region->clear();  // Effacer la région
        ui->Add_email->clear();

        load_list_view();  // Recharger la vue de liste pour refléter l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}



// Delete a client
void MainWindow::on_delete_clicked()
{
    // Get the selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to delete.");
        return;
    }

    int row = selectedRows.first().row();
    int id = ui->tableView->model()->index(row, 0).data().toInt();  // Get ID from the first column

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
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Selection", "Please select a client to edit.");
        return;
    }

    int row = selectedRows.first().row();
    QAbstractItemModel *model = ui->tableView->model();

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
    ui->id_edit->setText(QString::number(id));
    ui->nom_edit->setText(name);
    ui->firstname_edit->setText(firstname);  // Set firstname
    ui->birthdate_edit->setDate(age);
    ui->adr_edit->setText(address);
    ui->region_edit->setText(region);  // Set region
    ui->tel_edit->setText(phone_number);
    ui->email_edit->setText(email);


}

// Confirm edit
void MainWindow::on_confirm_edit_clicked()
{
    // Get updated data from input fields
    int id = ui->id_edit->text().toInt();
    QString name = ui->nom_edit->text().trimmed(); // Trim whitespace
    QString firstname = ui->firstname_edit->text().trimmed(); // Trim whitespace
    QDate age = ui->birthdate_edit->date();
    QString address = ui->adr_edit->text().trimmed(); // Trim whitespace
    QString region = ui->region_edit->text().trimmed(); // Trim whitespace
    QString email = ui->email_edit->text().trimmed(); // Trim whitespace
    int phone_number = ui->tel_edit->text().toInt();


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
    int id = ui->Search_line_edit->text().toInt();

    // Validate ID
    if (id == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid ID.");
        return;
    }

    Client C;
    QSqlQueryModel *model = C.search(id);

    if (model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::warning(this, "No Results", "No client found with the entered ID.");}
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

    QAbstractItemModel* model = ui->tableView->model();
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
    QString sortBy = ui->sort_criterion->currentText();  // Assuming a QComboBox is used

    // Prepare the SQL query to fetch all clients from the database
    QSqlQuery query;
    QString sortOrder = "ASC";  // Default sort order (ascending)

    if (sortBy == "Nom") {
        query.prepare("SELECT * FROM SOUKAH.CLIENT ORDER BY NOM_C " + sortOrder);
    } else if (sortBy == "ID") {
        query.prepare("SELECT * FROM SOUKAH.CLIENT ORDER BY ID_C " + sortOrder);
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
            ui->tableView->setModel(model);
        }
    } else {
        // If the query fails, show the error message
        QMessageBox::critical(this, "Database Error", "Failed to execute query: " + query.lastError().text());
    }
}

void MainWindow::on_cancel_search_button_clicked()
{
    ui->Search_line_edit->clear();
    Client C;
    ui->tableView->setModel(C.afficher());

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

    // Create a map to hold the region counts
    QMap<QString, int> regionCounts;
    QSqlQuery query;

    // Prepare and execute the query
    query.prepare("SELECT region_c, COUNT(*) FROM YASSINE.CLIENT GROUP BY region_c");
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
        QMessageBox::information(this, "Statistics", "No region found.");
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

    // Add the chart view to the stat widget
    layout->addWidget(chartView);

    // Switch to the stat page inside the stacked widget
    ui->stackedWidget->setCurrentWidget(ui->Stat);
}






