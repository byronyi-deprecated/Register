TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Menu.cpp \
    Database.cpp \
    Task.cpp \
    Utils.cpp

HEADERS += \
    Menu.h \
    Database.h \
    Task.h \
    Record.h \
    HashTable.h \
    DoublyLinkedList.h \
    Utils.h

