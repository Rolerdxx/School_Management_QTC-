#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "dbmanager.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void LoginRef();
    void ProRef();
    void FillRef();
    void MatRef();
    void EtuRef();
    void EvaRef();

    void ComboPRef();
    void ComboFRef();
    void ComboF2Ref();

    void ComboE1Ref();
    void ComboM1Ref();

private slots:

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_5_clicked(const QModelIndex &index);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_tableView_66_clicked(const QModelIndex &index);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::MainWindow *ui;
    DbManager db;
};

#endif // MAINWINDOW_H
