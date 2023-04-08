#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}


Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    loginA=ui->lineEdit->text();
    Mdp=ui->lineEdit_2->text();
}

QString Login::getMdp() const
{
    return Mdp;
}

QString Login::getLoginA() const
{
    return loginA;
}

