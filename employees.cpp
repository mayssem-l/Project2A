#include "employees.h"
#include <QSqlError>
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
Employees::Employees(int id, QString nom ,QString prenom, QString gender, QDate date, QString adresse, QString email , QString tel, QString poste, QString mdp)
{
    Id_E=id;
    Nom_E=nom;
    Prenom_E=prenom;
    Sexe_E= gender;
    Date_Nais_E=date;
    Adresse_E=adresse;
    Email_E=email;
    Tel_E=tel;
    Poste_E=poste;
    Mdp_E=mdp;
}

bool Employees::ajouter()
{
  QSqlQuery query;
  //QString num_string=QString::number(num_reservation);


  query.prepare("INSERT INTO MAYSSEM.EMPLOYEES VALUES(:id_emp,:nom_emp,:prenom_emp,TO_DATE(:date_nais,'yyyy-MM-dd'),:add_emp,:email_emp,:tel_emp,:poste_emp,:mdp_emp,:sexe_emp);");
  cout<<"Id:"<<Id_E<<endl;
  cout<<"type_id:"<<typeid(Id_E).name()<<endl;
  query.bindValue(":id_emp",Id_E);
  query.bindValue(":nom_emp",Nom_E);
  query.bindValue(":prenom_emp",Prenom_E);
  query.bindValue(":date_nais",Date_Nais_E.toString("yyyy-MM-dd"));
  query.bindValue(":add_emp", Adresse_E);
  query.bindValue(":email_emp",Email_E);
  query.bindValue(":tel_emp",Tel_E);
  query.bindValue(":poste_emp",Poste_E);
  query.bindValue(":mdp_emp",Mdp_E);
  query.bindValue(":sexe_emp",Sexe_E);
  qDebug() << "Query: " << query.lastQuery();
  bool res=query.exec();
  // Execute the query and check for success
  if (!res) {
      qDebug() << "Error adding employee:" << query.lastError().text();
  }

  return res;
}

QSqlQueryModel* Employees::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select *from MAYSSEM.EMPLOYEES");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_E"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM_E"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ADRESSE_E"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("EMAIL_E"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("TEL_E"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("POSTE_E"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("MDP_E"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("SEXE_E"));
    return model;
}

bool Employees::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE MAYSSEM.EMPLOYEES SET ID_E=:id_emp,NOM_E=:nom_emp,PRENOM_E=:prenom_emp,DATE_NAISSANCE=TO_DATE(:date_nais,'yyyy-MM-dd'),ADRESSE_E=:add_emp,EMAIL_E=:email_emp,TEL_E=:tel_emp,POSTE_E=:poste_emp,MDP_E=:mdp_emp,SEXE_E=:sexe_emp where ID_E= :id_emp");
    query.bindValue(":id_emp",Id_E);
    query.bindValue(":nom_emp",Nom_E);
    query.bindValue(":prenom_emp",Prenom_E);
    query.bindValue(":sexe_emp",Sexe_E);
    query.bindValue(":date_nais",Date_Nais_E.toString("yyyy-MM-dd"));
    query.bindValue(":add_emp",Adresse_E);
    query.bindValue(":email_emp",Email_E);
    query.bindValue(":tel_emp",Tel_E);
    query.bindValue(":poste_emp",Poste_E);
    query.bindValue(":mdp_emp",Mdp_E);
    qDebug() << "Query: " << query.lastQuery();
    bool res=query.exec();
    // Execute the query and check for success
    if (!res) {
        qDebug() << "Error EDITING employee:" << query.lastError().text();
    }

    return res;

}

bool Employees::supprimer(int Id_E)
{

 QSqlQuery query;
 //QString num_string =QString::number(num);
 query.prepare("Delete from MAYSSEM.EMPLOYEES where ID_E= :id_emp ");
 query.bindValue(":id_emp",Id_E);
 return query.exec();


}
