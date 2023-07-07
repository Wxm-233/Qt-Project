QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    choppingblock.cpp \
    cookingbench.cpp \
    dish.cpp \
    food.cpp \
    globalFuns.cpp \
    item.cpp \
    main.cpp \
    game.cpp \
    map.cpp \
    mapblock.cpp \
    orders.cpp \
    plate.cpp \
    pot.cpp \
    receiver.cpp \
    repository.cpp \
    scoreboard.cpp \
    start_window.cpp \
    table.cpp \
    trashcan.cpp

HEADERS += \
    character.h \
    choppingblock.h \
    cookingbench.h \
    dish.h \
    enums.h \
    food.h \
    game.h \
    item.h \
    map.h \
    mapblock.h \
    orders.h \
    plate.h \
    pot.h \
    receiver.h \
    repository.h \
    scoreboard.h \
    start_window.h \
    table.h \
    trashcan.h

FORMS += \
    game.ui \
    start_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
