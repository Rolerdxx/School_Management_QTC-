#ifndef ETUCHER_H
#define ETUCHER_H

#include <QDialog>

namespace Ui {
class EtuCher;
}

class EtuCher : public QDialog
{
    Q_OBJECT

public:
    explicit EtuCher(QWidget *parent = nullptr);
    ~EtuCher();

    QString getNom() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EtuCher *ui;
    QString nom;
};

#endif // ETUCHER_H
