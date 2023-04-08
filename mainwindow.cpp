#include "mainwindow.h"
#include "login.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QSqlDatabase>
#include "dbmanager.h"
#include "procherche.h"
#include "etucher.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->tabWidget->hide();
    QPixmap doge("://image.png");
    ui->label_3->setPixmap(doge);
    QMenu * fileMenu = menuBar()->addMenu("Connexion");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(600,400);

    LoginRef();
    ProRef();
    FillRef();
    MatRef();
    EtuRef();
    EvaRef();

    ComboPRef();
    ComboFRef();
    ComboF2Ref();
    ComboE1Ref();
    ComboM1Ref();



    QAction * login = new QAction("Login");
    QAction * desc = new QAction("Deconnecte");
    connect(desc,&QAction::triggered,this,[=](){
        ui->tabWidget->setVisible(false);
        ui->label_3->setVisible(true);
        setFixedSize(600,400);
        fileMenu->removeAction(desc);
        fileMenu->addAction(login);
    });


    connect(login,&QAction::triggered,this,[=](){

        Login * l=new Login(this);
        int res = l->exec();
        if(res == QDialog::Accepted){
            QString loginA = l->getLoginA();
            QString mdp = l->getMdp();
            db.conn();

            qDebug() << loginA;
            if(db.Loginn(loginA,mdp)){
                ui->label_3->setVisible(false);
                ui->tabWidget->setVisible(true);
                setFixedSize(800,700);
                fileMenu->removeAction(login);
                fileMenu->addAction(desc);
                statusBar()->showMessage("Bienvenu!!!!!!!",3000);
            }else{
                qDebug() << "no";
                statusBar()->showMessage("MOT DE PASSE ERRONE",3000);
            }
            db.disc();

        } else if(res == QDialog::Rejected){
            qDebug() << "no";
        }
    });

    fileMenu->addAction(login);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::LoginRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Login");
    model->setHeaderData(0, Qt::Horizontal, "LoginA");
    model->setHeaderData(1, Qt::Horizontal, "Mdp");
    model->setHeaderData(2, Qt::Horizontal, "Ref_A");
    ui->tableView->setModel(model);
    db.disc();
}

void MainWindow::ProRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Professeur");
    model->setHeaderData(0, Qt::Horizontal, "Cin_P");
    model->setHeaderData(1, Qt::Horizontal, "Nom_Complet");
    model->setHeaderData(2, Qt::Horizontal, "Num_Tel");
    model->setHeaderData(2, Qt::Horizontal, "Adresse");
    ui->tableView_2->setModel(model);
    db.disc();
}

void MainWindow::FillRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Filliere");
    model->setHeaderData(0, Qt::Horizontal, "Code_F");
    model->setHeaderData(1, Qt::Horizontal, "Libelle");
    model->setHeaderData(2, Qt::Horizontal, "Type_F");
    ui->tableView_3->setModel(model);
    db.disc();
}

void MainWindow::MatRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Matiere");
    model->setHeaderData(0, Qt::Horizontal, "Code_M");
    model->setHeaderData(1, Qt::Horizontal, "Libelle_M");
    model->setHeaderData(2, Qt::Horizontal, "Coeff");
    model->setHeaderData(3, Qt::Horizontal, "Cin_P");
    model->setHeaderData(4, Qt::Horizontal, "Code_F");
    ui->tableView_4->setModel(model);
    db.disc();
}

void MainWindow::EtuRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Etudiant");
    model->setHeaderData(0, Qt::Horizontal, "Code_E");
    model->setHeaderData(1, Qt::Horizontal, "Nom_Complet");
    model->setHeaderData(2, Qt::Horizontal, "CIN");
    model->setHeaderData(3, Qt::Horizontal, "Date_N");
    model->setHeaderData(4, Qt::Horizontal, "Numero");
    model->setHeaderData(5, Qt::Horizontal, "Adresse");
    model->setHeaderData(6, Qt::Horizontal, "Code_F");
    ui->tableView_5->setModel(model);
    db.disc();
}

void MainWindow::EvaRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Evaluation");
    model->setHeaderData(0, Qt::Horizontal, "CodeEva");
    model->setHeaderData(1, Qt::Horizontal, "Code_E");
    model->setHeaderData(2, Qt::Horizontal, "Code_M");
    model->setHeaderData(3, Qt::Horizontal, "note");
    ui->tableView_66->setModel(model);
    db.disc();
}

void MainWindow::ComboPRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Cin_P FROM Professeur");
    ui->cinpp->setModel(model);
    db.disc();
}

void MainWindow::ComboFRef()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Code_F FROM Filliere");
    ui->codeff->setModel(model);
    db.disc();
}

void MainWindow::ComboF2Ref()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Code_F FROM Filliere");
    ui->FilCom->setModel(model);
    db.disc();
}

void MainWindow::ComboE1Ref()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Code_E FROM Etudiant");
    ui->codeeL->setModel(model);
    db.disc();
}

void MainWindow::ComboM1Ref()
{
    db.conn();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT Code_M FROM Matiere");
    ui->codemL->setModel(model);
    db.disc();
}






void MainWindow::on_pushButton_clicked()
{
    if(ui->login1->text()!="" && ui->login2->text()!="" && ui->login3->text()!=""){
        db.conn();
        db.addLogin(ui->login1->text(),ui->login2->text(),ui->login3->text());
        LoginRef();
        db.disc();
    }

}





void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->login1->setText(ui->tableView->model()->index(index.row(),0).data().toString());
    ui->login2->setText(ui->tableView->model()->index(index.row(),1).data().toString());
    ui->login3->setText(ui->tableView->model()->index(index.row(),2).data().toString());
}


void MainWindow::on_pushButton_3_clicked()
{

    if(ui->login3->text()!=""){
        db.conn();
        db.delLogin(ui->login3->text());

        LoginRef();
        db.disc();
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->login1->text()!="" && ui->login2->text()!="" && ui->login3->text()!=""){
        db.conn();
        qDebug()<<db.modLogin(ui->login1->text(),ui->login2->text(),ui->login3->text());
        LoginRef();
        db.disc();
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    ProCherche *p=new ProCherche(this);
    int res=p->exec();
    if(res==QDialog::Accepted){
        db.conn();
        QString np=db.proCher(p->getNomC());

        for (int var = 0; var < ui->tableView_2->verticalHeader()->count(); ++var) {
            if(np==ui->tableView_2->model()->index(var,0).data().toString()){
                ui->cinl->setText(ui->tableView_2->model()->index(var,0).data().toString());
                ui->nomcl->setText(ui->tableView_2->model()->index(var,1).data().toString());
                ui->tell->setText(ui->tableView_2->model()->index(var,2).data().toString());
                ui->adressel->setText(ui->tableView_2->model()->index(var,3).data().toString());
                ui->tableView_2->selectRow(var);
                statusBar()->showMessage("Trouvez!!!!!!",3000);
            }
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->cinl->text()!=""&&ui->nomcl->text()!=""&&ui->tell->text()!=""&&ui->adressel->text()!=""){
        db.conn();
        db.addPro(ui->cinl->text(),ui->nomcl->text(),ui->tell->text().toInt(),ui->adressel->text());
        ProRef();
        db.disc();
    }
}


void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->cinl->setText(ui->tableView_2->model()->index(index.row(),0).data().toString());
    ui->nomcl->setText(ui->tableView_2->model()->index(index.row(),1).data().toString());
    ui->tell->setText(ui->tableView_2->model()->index(index.row(),2).data().toString());
    ui->adressel->setText(ui->tableView_2->model()->index(index.row(),3).data().toString());
}


void MainWindow::on_pushButton_5_clicked()
{
    if(ui->cinl->text()!=""){
        db.conn();
        if(db.delPro(ui->cinl->text())){
            ProRef();
            statusBar()->showMessage("Supprimer!!!!!!",3000);
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(ui->cinl->text()!=""&&ui->nomcl->text()!=""&&ui->tell->text()!=""&&ui->adressel->text()!=""){
        db.conn();
        db.modPro(ui->cinl->text(),ui->nomcl->text(),ui->tell->text().toInt(),ui->adressel->text());
        ProRef();
        statusBar()->showMessage("Modifier!!!!!!",3000);
        db.disc();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(ui->codeF->text()!=""&&ui->LibL->text()!=""&&ui->TypeF->text()!=""){
        db.conn();
        db.addFill(ui->codeF->text().toInt(),ui->LibL->text(),ui->TypeF->text());
        statusBar()->showMessage("Ajouter!!!!!!",3000);
        FillRef();
        db.disc();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if(ui->codeF->text()!=""){
        db.conn();
        if(db.delFill(ui->codeF->text().toInt())){
            FillRef();
            statusBar()->showMessage("Supprimer!!!!!!",3000);
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    if(ui->codeF->text()!=""&&ui->LibL->text()!=""&&ui->TypeF->text()!=""){
        db.conn();
        db.modFill(ui->codeF->text().toInt(),ui->LibL->text(),ui->TypeF->text());
        FillRef();
        statusBar()->showMessage("Modifier!!!!!!",3000);
        db.disc();
    }
}


void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    ui->codeF->setText(ui->tableView_3->model()->index(index.row(),0).data().toString());
    ui->LibL->setText(ui->tableView_3->model()->index(index.row(),1).data().toString());
    ui->TypeF->setText(ui->tableView_3->model()->index(index.row(),2).data().toString());
}


void MainWindow::on_pushButton_13_clicked()
{
    if(ui->codem->text()!=""&&ui->libll->text()!=""&&ui->coeff->text()!=""){
        db.conn();
        db.addMat(ui->codem->text().toInt(),ui->libll->text(),ui->coeff->text().toInt(),ui->cinpp->currentText(),ui->codeff->currentText().toInt());
        statusBar()->showMessage("Ajouter!!!!!!",3000);
        MatRef();
        db.disc();
    }
}


void MainWindow::on_tableView_4_clicked(const QModelIndex &index)
{
    ui->codem->setText(ui->tableView_4->model()->index(index.row(),0).data().toString());
    ui->libll->setText(ui->tableView_4->model()->index(index.row(),1).data().toString());
    ui->coeff->setText(ui->tableView_4->model()->index(index.row(),2).data().toString());

    for (int var = 0; var < ui->cinpp->count(); ++var) {
        ui->cinpp->setCurrentIndex(var);
        if(ui->cinpp->currentText()==ui->tableView_4->model()->index(index.row(),3).data().toString()){
            break;
        }
    }

    for (int var = 0; var < ui->cinpp->count(); ++var) {
        ui->codeff->setCurrentIndex(var);
        if(ui->codeff->currentText()==ui->tableView_4->model()->index(index.row(),4).data().toString()){
            break;
        }
    }

}


void MainWindow::on_pushButton_12_clicked()
{
    if(ui->codem->text()!=""){
        db.conn();
        if(db.delMat(ui->codem->text().toInt())){
            MatRef();
            statusBar()->showMessage("Supprimer!!!!!!",3000);
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if(ui->codem->text()!=""&&ui->libll->text()!=""&&ui->coeff->text()!=""){
        db.conn();
        db.modMat(ui->codem->text().toInt(),ui->libll->text(),ui->coeff->text().toInt(),ui->cinpp->currentText(),ui->codeff->currentText().toInt());
        MatRef();
        statusBar()->showMessage("Modifier!!!!!!",3000);
        db.disc();
    }
}


void MainWindow::on_tableView_5_clicked(const QModelIndex &index)
{
    ui->codee->setText(ui->tableView_5->model()->index(index.row(),0).data().toString());
    ui->NomComm->setText(ui->tableView_5->model()->index(index.row(),1).data().toString());
    ui->cinnn->setText(ui->tableView_5->model()->index(index.row(),2).data().toString());
    ui->Date_N->setText(ui->tableView_5->model()->index(index.row(),3).data().toString());
    ui->NUmero->setText(ui->tableView_5->model()->index(index.row(),4).data().toString());
    ui->AdresseE->setText(ui->tableView_5->model()->index(index.row(),5).data().toString());

    for (int var = 0; var < ui->FilCom->count(); ++var) {
        ui->FilCom->setCurrentIndex(var);
        if(ui->FilCom->currentText()==ui->tableView_5->model()->index(index.row(),6).data().toString()){
            break;
        }
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    EtuCher *p=new EtuCher(this);
    int res=p->exec();
    if(res==QDialog::Accepted){
        db.conn();
        int np=db.cherEtu(p->getNom());
        qDebug() << np;
        for (int var = 0; var < ui->tableView_5->verticalHeader()->count(); ++var) {
            if(np==ui->tableView_5->model()->index(var,0).data()){
                ui->cinl->setText(ui->tableView_5->model()->index(var,0).data().toString());
                ui->nomcl->setText(ui->tableView_5->model()->index(var,1).data().toString());
                ui->tell->setText(ui->tableView_5->model()->index(var,2).data().toString());
                ui->adressel->setText(ui->tableView_5->model()->index(var,3).data().toString());
                ui->adressel->setText(ui->tableView_5->model()->index(var,4).data().toString());
                ui->adressel->setText(ui->tableView_5->model()->index(var,5).data().toString());
                ui->tableView_5->selectRow(var);
                statusBar()->showMessage("Trouvez!!!!!!",3000);
            }
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    if(ui->codee->text()!=""&&ui->NomComm->text()!=""&&ui->cinnn->text()!=""&&ui->Date_N->text()!=""&&ui->NUmero->text()!=""&&ui->AdresseE->text()!=""){
        db.conn();
        db.addEtu(ui->codee->text().toInt(),ui->NomComm->text(),ui->cinnn->text(),ui->Date_N->text(),ui->NUmero->text().toInt(),ui->AdresseE->text(),ui->FilCom->currentText().toInt());
        statusBar()->showMessage("Ajouter!!!!!!",3000);
        EtuRef();
        db.disc();
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    if(ui->codee->text()!=""&&ui->NomComm->text()!=""&&ui->cinnn->text()!=""&&ui->Date_N->text()!=""&&ui->NUmero->text()!=""&&ui->AdresseE->text()!=""){
        db.conn();
        db.modEtu(ui->codee->text().toInt(),ui->NomComm->text(),ui->cinnn->text(),ui->Date_N->text(),ui->NUmero->text().toInt(),ui->AdresseE->text(),ui->FilCom->currentText().toInt());
        statusBar()->showMessage("Modifier!!!!!!",3000);
        EtuRef();
        db.disc();
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    if(ui->codee->text()!=""){
        db.conn();
        if(db.delEtu(ui->codee->text().toInt())){
            EtuRef();
            statusBar()->showMessage("Supprimer!!!!!!",3000);
        }
        db.disc();
    }
}


void MainWindow::on_tableView_66_clicked(const QModelIndex &index)
{
    ui->codeva->setText(ui->tableView_66->model()->index(index.row(),0).data().toString());
    ui->note->setText(ui->tableView_66->model()->index(index.row(),3).data().toString());

    for (int var = 0; var < ui->codeeL->count(); ++var) {
        ui->codeeL->setCurrentIndex(var);
        if(ui->codeeL->currentText()==ui->tableView_66->model()->index(index.row(),1).data().toString()){
            break;
        }
    }

    for (int var = 0; var < ui->codemL->count(); ++var) {
        ui->codemL->setCurrentIndex(var);
        if(ui->codemL->currentText()==ui->tableView_66->model()->index(index.row(),2).data().toString()){
            break;
        }
    }
}


void MainWindow::on_pushButton_18_clicked()
{
    if(ui->codeva->text()!=""&&ui->note->text()!=""){
        db.conn();
        db.addEva(ui->codeva->text().toInt(),ui->codeeL->currentText().toInt(),ui->codemL->currentText().toInt(),ui->note->text().toFloat());
        statusBar()->showMessage("Ajouter!!!!!!",3000);
        EvaRef();
        db.disc();
    }
}


void MainWindow::on_pushButton_19_clicked()
{
    if(ui->codeva->text()!=""){
        db.conn();
        if(db.delEva(ui->codeva->text().toInt())){
            EtuRef();
            statusBar()->showMessage("Supprimer!!!!!!",3000);
        }
        db.disc();
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    if(ui->codeva->text()!=""&&ui->note->text()!=""){
        db.conn();
        db.modEva(ui->codeva->text().toInt(),ui->codeeL->currentText().toInt(),ui->codemL->currentText().toInt(),ui->note->text().toFloat());
        statusBar()->showMessage("Ajouter!!!!!!",3000);
        EvaRef();
        db.disc();
    }
}

