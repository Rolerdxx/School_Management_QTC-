#include "dbmanager.h"
#include <QDebug>


DbManager::DbManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("D:/QtPrejects/GPE/dbgpe.db");
}

bool DbManager::conn()
{
    if(m_db.open()){
        return true;
    }else{
        return false;
    }
}

void DbManager::disc()
{
    m_db.close();
}

QSqlDatabase DbManager::getDb()
{
    return m_db;
}



bool DbManager::addLogin(const QString &logname, const QString &mdp, const QString &Ref)
{
    bool success = false;
       QSqlQuery query;
       query.prepare("INSERT INTO Login (LoginA, Mdp, Ref_A) VALUES (:login, :mdp, :ref)");
       query.bindValue(":login", logname);
       query.bindValue(":mdp", mdp);
       query.bindValue(":ref", Ref);
       qDebug() << "Executing " << logname;
       if(query.exec())
       {
           success = true;
       }
       else
       {
            qDebug() << "addPerson error:"
                     << query.lastError();
       }

       return success;
}

bool DbManager::Loginn(const QString &logname,const QString &mdp)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM Login WHERE LoginA =:log AND Mdp=:mm");
    query.bindValue(":log", logname);
    query.bindValue(":mm", mdp);

    if (query.exec())
    {
       if (query.next())
       {
          qDebug() << "Kayn";
          return true;
       }
    }
    return false;
}

bool DbManager::delLogin(const QString &ref)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Login WHERE Ref_A =:ref");
    query.bindValue(":ref", ref);

    if(query.exec()){
        return true;
    }
    return false;
}

bool DbManager::modLogin(const QString &logname, const QString &mdp, const QString &Ref)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Login SET LoginA=:ll,Mdp=:mm WHERE Ref_A=:rr");

    query.bindValue(":ll", logname);
    query.bindValue(":mm", mdp);
    query.bindValue(":rr", Ref);

    if(query.exec()){
        return true;
    }
    qDebug() << "modlog error:"
                     << query.lastError();
    return false;
}

QString DbManager::proCher(const QString &nom)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT Cin_P FROM Professeur WHERE Nom_Complet=:nn");
    query.bindValue(":nn", nom);

    if(query.exec()){
        if(query.next()){
            return query.value(0).toString();
        }
    }
    return "";
}

bool DbManager::addPro(const QString &cin, const QString &nom, const int &tel, const QString &ad)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Professeur VALUES(:cc, :nn, :tt, :dd)");
    query.bindValue(":cc",cin);
    query.bindValue(":nn",nom);
    query.bindValue(":tt",tel);
    query.bindValue(":dd",ad);
    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
    }
    return false;
}

bool DbManager::delPro(const QString &cin)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Professeur WHERE Cin_P=:cc");
    query.bindValue(":cc",cin);

    if(query.exec()){
        return true;
    }
    return false;
}

bool DbManager::modPro(const QString &cin, const QString &nom, const int &tel, const QString &ad)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Professeur SET Adresse=:aa, Nom_Complet=:nn, Num_Tel=:tt WHERE Cin_P=:cc");
    query.bindValue(":cc",cin);
    query.bindValue(":aa",ad);
    query.bindValue(":nn",nom);
    query.bindValue(":tt",tel);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::addFill(const int &code, const QString &lab, const QString &type)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Filliere VALUES(:cc, :ll, :tt)");
    query.bindValue(":cc",code);
    query.bindValue(":ll",lab);
    query.bindValue(":tt",type);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }

}

bool DbManager::delFill(const int &code)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Filliere WHERE Code_F=:cc");
    query.bindValue(":cc",code);

    if(query.exec()){
        return true;
    }
    return false;
}

bool DbManager::modFill(const int &code, const QString &lab, const QString &type)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Professeur SET Libelle=:ll, Type_F=:tt WHERE Code_=:cc");
    query.bindValue(":ll",lab);
    query.bindValue(":tt",type);
    query.bindValue(":cc",code);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::addMat(const int &code, const QString &lib, const int &coeff, const QString &Cin, const int &codef)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Matiere VALUES(:cc, :lib, :co, :cin, :codef)");
    query.bindValue(":cc",code);
    query.bindValue(":lib",lib);
    query.bindValue(":co",coeff);
    query.bindValue(":cin",Cin);
    query.bindValue(":codef",codef);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::delMat(const int &code)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Matiere WHERE Code_M=:cc");
    query.bindValue(":cc",code);

    if(query.exec()){
        return true;
    }
    return false;
}

bool DbManager::modMat(const int &code, const QString &lib, const int &coeff, const QString &Cin, const int &codef)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Matiere SET Libelle_M=:lib, Coeff=:co, Cin_P=:cin, Code_F=:codef WHERE Code_M=:cc");
    query.bindValue(":cc",code);
    query.bindValue(":lib",lib);
    query.bindValue(":co",coeff);
    query.bindValue(":cin",Cin);
    query.bindValue(":codef",codef);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::addEtu(const int &code, const QString &NomC, const QString &cin, const QString &date, const int &num, const QString &ad, const int &CodeF)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Etudiant VALUES(:cc, :nn, :cin, :date, :num, :ad, :codef)");
    query.bindValue(":cc",code);
    query.bindValue(":nn",NomC);
    query.bindValue(":cin",cin);
    query.bindValue(":date",date);
    query.bindValue(":num",num);
    query.bindValue(":ad",ad);
    query.bindValue(":codef",CodeF);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::modEtu(const int &code, const QString &NomC, const QString &cin, const QString &date, const int &num, const QString &ad, const int &CodeF)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Etudiant SET Nom_Complet=:nn, CIN=:cin, Date_N=:date, Numero=:num, Adresse=:ad, Code_F=:codef WHERE Code_E=:cc");
    query.bindValue(":cc",code);
    query.bindValue(":nn",NomC);
    query.bindValue(":cin",cin);
    query.bindValue(":date",date);
    query.bindValue(":num",num);
    query.bindValue(":ad",ad);
    query.bindValue(":codef",CodeF);

    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::delEtu(const int &code)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Etudiant WHERE Code_E=:cc");
    query.bindValue(":cc",code);

    if(query.exec()){
        return true;
    }
    return false;
}

int DbManager::cherEtu(const QString &NomC)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT Code_E FROM Etudiant WHERE Nom_Complet=:nn");
    query.bindValue(":nn", NomC);

    if(query.exec()){
        if(query.next()){
            return query.value(0).toInt();
        }
    }
    return 0;
}

bool DbManager::addEva(const int &codeEV, const int &codeE, const int &codeM, const float &note)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO Evaluation VALUES(:ceva, :ce, :cm, :nn)");
    query.bindValue(":ceva",codeEV);
    query.bindValue(":ce",codeE);
    query.bindValue(":cm",codeM);
    query.bindValue(":nn",note);


    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}

bool DbManager::delEva(const int &codeEV)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Evaluation WHERE CodeEv=:cc");
    query.bindValue(":cc",codeEV);

    if(query.exec()){
        return true;
    }
    return false;
}

bool DbManager::modEva(const int &codeEV, const int &codeE, const int &codeM, const float &note)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE Evaluation SET Code_E=:ce, Code_M=:cm, note=:nn WHERE CodeEv=:cve");
    query.bindValue(":cve",codeEV);
    query.bindValue(":ce",codeE);
    query.bindValue(":cm",codeM);
    query.bindValue(":nn",note);


    if(query.exec()){
        return true;
    }else{
        qDebug() << query.lastError();
        return false;
    }
}






