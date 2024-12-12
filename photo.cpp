void MainWindow::on_pic_2_clicked()
{
    // Open file dialog to select an image
    QString fileName = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.bmp *.jpeg)");

    if (fileName.isEmpty()) {
        return; // No file selected, exit
    }

    // Read the image file into QByteArray
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open image file:" << fileName;
        return; // Failed to open file
    }
    QByteArray imageData = file.readAll();
    file.close();

    // Retrieve the service ID from the line edit
    QString id_service = ui->lineEdit_5->text();
    if (id_service.isEmpty()) {
        qDebug() << "Service ID is empty. Please provide a valid ID.";
        return; // Ensure the ID is not empty
    }

    // Upload image to database
    service serviceObj; // Assuming service is the class handling your database
    if (!serviceObj.uploadImage(id_service, imageData)) {
        qDebug() << "Failed to upload image to database.";
        return; // Image upload failed
    }

    qDebug() << "Image uploaded successfully to the database.";
    on_display_clicked(); // Optionally refresh the UI
}

bool Client::uploadImage(const QString &id , const QByteArray &imageData)
{
    if (imageData.isEmpty()) {
        qDebug() << "Image data is empty. Cannot upload.";
        return false; // Image data must not be empty
    }

    // Prepare SQL query to update the image in the database
    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET image = :imageData WHERE ID_C = :id");
    query.bindValue(":imageData", imageData);
    query.bindValue(":id", id_service);

    // Execute the query and handle any errors
    if (!query.exec()) {
        qDebug() << "Failed to update image in database:" << query.lastError().text();
        return false; // Query execution failed
    }

    return true; // Successfully uploaded image
}

void MainWindow::on_disimage_clicked()
{
    QString id_service = ui->lineEdit_5->text();
       if (id_service.isEmpty()) {
           qDebug() << "Service ID is empty. Please provide a valid ID.";
           return; // Ensure the ID is not empty
       }

       // Prepare SQL query to retrieve image data based on the service ID
       QSqlQuery query;
       query.prepare("SELECT image FROM SERVICE WHERE ID_SERVICE = :id");
       query.bindValue(":id", id_service);

       // Execute the query and handle errors
       if (!query.exec()) {
           qDebug() << "Failed to retrieve image data from database:" << query.lastError().text();
           return; // Query execution failed
       }

       // Check if the query returned any data
       if (!query.next()) {
           qDebug() << "No image found for the given service ID.";
           return; // No image found for the provided ID
       }

       // Retrieve the image data from the query result
       QByteArray imageData = query.value("image").toByteArray();

       // Load the image from the data
       QPixmap pixmap;
       if (!pixmap.loadFromData(imageData)) {
           qDebug() << "Failed to load image from database data.";
           return; // Failed to load the image
       }

       // Display the image in the QTableView
       displayImageInTable(pixmap);
   }
void MainWindow::displayImageInTable(const QPixmap &pixmap)
{
    // Ensure the widget (where the image will be displayed) exists
    if (!ui->widgetph) {
        qDebug() << "Widget not found!";
        return;
    }

    // Create or find the QLabel where the image will be displayed
    QLabel imageLabel = ui->widgetph->findChild<QLabel>("imageLabel");

    // If no QLabel exists, create one
    if (!imageLabel) {
        imageLabel = new QLabel(ui->widgetph);
        imageLabel->setObjectName("imageLabel"); // Assign an object name for future references
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // Ensure it resizes with the widget
    }

    // Set the pixmap to the QLabel
    imageLabel->setPixmap(pixmap);
    imageLabel->setScaledContents(true); // Ensure the image scales to fit the label's size
}
