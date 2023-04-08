#ifndef PROCHERCHE_H
#define PROCHERCHE_H

#include <QDialog>

namespace Ui {
class ProCherche;
}

class ProCherche : public QDialog
{
    Q_OBJECT

public:
    explicit ProCherche(QWidget *parent = nullptr);
    ~ProCherche();

    QString getNomC() const;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ProCherche *ui;
    QString nomC;
};

#endif // PROCHERCHE_H
