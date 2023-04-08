#include "procherche.h"
#include "ui_procherche.h"

ProCherche::ProCherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProCherche)
{
    ui->setupUi(this);
}

ProCherche::~ProCherche()
{
    delete ui;
}

QString ProCherche::getNomC() const
{
    return nomC;
}

void ProCherche::on_buttonBox_accepted()
{
    nomC=ui->lineEdit->text();
}

