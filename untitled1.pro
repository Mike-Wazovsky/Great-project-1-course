QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    second_main.cpp \
    settingswindow.cpp \
    uml.cpp \
    view.cpp \
    windowwithgame.cpp

HEADERS += \
    controller.h \
    game.h \
    game_fwd.h \
    global_struct_of_game.h \
    json.hpp \
    mainwindow.h \
    second_main.h \
    settingswindow.h \
    uml.h \
    view.h \
    windowwithgame.h

FORMS += \
    mainwindow.ui \
    settingswindow.ui \
    windowwithgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc
