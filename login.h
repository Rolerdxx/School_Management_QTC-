#ifndef LOGIN_H
#define LOGIN_H
#include <QString>

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();



    QString getLoginA() const;

    QString getMdp() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Login *ui;
    QString loginA;
    QString Mdp;
};

#endif // LOGIN_H
