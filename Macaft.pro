QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    Global.cpp \
    Sapermain.cpp \
    arithmetic_problem.cpp \
    controller.cpp \
    game.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    minigame.cpp \
    resultwindow.cpp \
    sapermain.cpp \
    second_main.cpp \
    settingswindow.cpp \
    uml.cpp \
    view.cpp \
    windowwithgame.cpp

HEADERS += \
    Button.h \
    Global.h \
    arithmetic_problem.h \
    controller.h \
    game.h \
    game_fwd.h \
    gamewindow.h \
    global_struct_of_game.h \
    json.hpp \
    mainwindow.h \
    minigame.h \
    resultwindow.h \
    sapermain.h \
    second_main.h \
    settingswindow.h \
    uml.h \
    view.h \
    windowwithgame.h

FORMS += \
    GameWindow.ui \
    mainwindow.ui \
    minigame.ui \
    resultwindow.ui \
    settingswindow.ui \
    windowwithgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target