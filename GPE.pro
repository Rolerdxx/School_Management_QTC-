QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    etucher.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    procherche.cpp

HEADERS += \
    dbmanager.h \
    etucher.h \
    login.h \
    mainwindow.h \
    procherche.h

FORMS += \
    etucher.ui \
    login.ui \
    mainwindow.ui \
    procherche.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    reds.qrc

RC_ICONS = icon1.ICON

win32 {
    RC_FILE = winadmin.rc
}

