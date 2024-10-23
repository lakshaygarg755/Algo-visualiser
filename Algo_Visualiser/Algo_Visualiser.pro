QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fcfs.cpp \
    leaky.cpp \
    main.cpp \
    mainwindow.cpp \
    roundrobin.cpp \
    token.cpp \
    wroundrobin.cpp

HEADERS += \
    fcfs.h \
    leaky.h \
    mainwindow.h \
    roundrobin.h \
    token.h \
    wroundrobin.h

FORMS += \
    fcfs.ui \
    leaky.ui \
    mainwindow.ui \
    roundrobin.ui \
    token.ui \
    wroundrobin.ui

TRANSLATIONS += \
    Algo_Visualiser_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
