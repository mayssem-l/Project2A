#ifndef FACEDATA_H
#define FACEDATA_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QByteArray>

class FaceData {
    QString id;         // Identifiant unique de la personne
    QByteArray image;    // Données de l'image en BLOB

public:
    // Constructeurs
    FaceData() {}
    FaceData(QString id, QByteArray img);

    // Getters
    QString getid() { return id; }
    QByteArray getImage() { return image; }

    // Setters
    void setCIN(QString id) { ID_C = id; }
    void setImage(QByteArray img) { image = img; }

    // Méthodes CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString cin);
    QByteArray chercherImage(QString id);
};

#endif // FACEDATA_H
