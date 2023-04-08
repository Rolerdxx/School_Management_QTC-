#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QtSql>
#include <QSqlDatabase>


class DbManager
{
public:
    DbManager();
    bool conn();
    void disc();
    QSqlDatabase getDb();


    bool addLogin(const QString& logname,const QString& mdp,const QString& Ref);
    bool Loginn(const QString& logname,const QString &mdp);
    bool delLogin(const QString& ref);
    bool modLogin(const QString& logname,const QString& mdp,const QString& Ref);

    QString proCher(const QString& nom);
    bool addPro(const QString& cin,const QString& nom,const int& tel,const QString& ad);
    bool delPro(const QString& cin);
    bool modPro(const QString& cin,const QString& nom,const int& tel,const QString& ad);

    bool addFill(const int& code,const QString& lab,const QString& type);
    bool delFill(const int& code);
    bool modFill(const int& code,const QString& lab,const QString& type);

    bool addMat(const int& code,const QString& lib,const int& coeff,const QString& Cin,const int& codef);
    bool delMat(const int& code);
    bool modMat(const int& code,const QString& lib,const int& coeff,const QString& Cin,const int& codef);

    bool addEtu(const int& code,const QString& NomC,const QString& cin,const QString& date,const int& num,const QString& ad,const int& CodeF);
    bool modEtu(const int& code,const QString& NomC,const QString& cin,const QString& date,const int& num,const QString& ad,const int& CodeF);
    bool delEtu(const int& code);
    int cherEtu(const QString& NomC);

    bool addEva(const int& codeEV,const int& codeE,const int& codeM,const float& note);
    bool delEva(const int& codeEV);
    bool modEva(const int& codeEV,const int& codeE,const int& codeM,const float& note);




private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
