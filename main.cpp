#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile st("D:/QtPrejects/GPE/Irrorater.qss");
    st.open(QFile::ReadOnly);
    QString style = QLatin1String(st.readAll());
    a.setStyleSheet(style);
    MainWindow w;
    w.show();
    return a.exec();
}
