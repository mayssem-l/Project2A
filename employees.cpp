#include "employees.h"
#include <QSqlError>
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
Employees::Employees(int id, QString nom ,QString prenom, QString gender, QDate date, QString adresse, QString email , int tel, QString poste, QString mdp)
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
    model->setQuery("select *from EMPLOYEES");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_E"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM_E"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("SEXE_E"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE NAISSANCE"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("EMAIL_E"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("TEL_E"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("POSTE_E"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("MDP_E"));

    return model;
}

bool Employees::modifier()
{
    QSqlQuery query;
    //QString num_string=QString::number(num_reservation);

    query.prepare("update EMPLOYEES set id_emp=:id_emp,nom_emp=:nom_emp,prenom_emp=:prenom_emp,date_nais=to_date(:date_nais,'DD/MM/YYYY hh24/mi'),email_emp=:email_emp,tel_emp=:tel_emp,poste_emp=:poste_emp,mdp_emp=:mdp_emp where id_emp= :id_emp");
    query.bindValue(":id_emp",Id_E);
    query.bindValue(":nom_emp",Nom_E);
    query.bindValue(":prenom_emp",Prenom_E);
    query.bindValue(":sexe_emp",Sexe_E);
    query.bindValue(":date_nais",Date_Nais_E);
    query.bindValue(":email_emp",Email_E);
    query.bindValue(":tel_emp",Tel_E);
    query.bindValue(":poste_emp",Poste_E);
    query.bindValue(":mdp_emp",Mdp_E);

    return query.exec();

}

bool Employees::supprimer(int Id_E)
{

 QSqlQuery query;
 //QString num_string =QString::number(num);
 query.prepare("Delete from EMPLOYEES where id_emp= :id_emp ");
 query.bindValue(":id_emp",Id_E);
 return query.exec();


}
