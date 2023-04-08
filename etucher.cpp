#include "etucher.h"
#include "ui_etucher.h"

EtuCher::EtuCher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EtuCher)
{
    ui->setupUi(this);
}

EtuCher::~EtuCher()
{
    delete ui;
}

QString EtuCher::getNom() const
{
    return nom;
}

void EtuCher::on_buttonBox_accepted()
{
    nom=ui->lineEdit->text();
}

