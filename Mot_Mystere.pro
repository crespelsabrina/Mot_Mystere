QT       += core gui widgets qml quick

TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
# CONFIG -= qt

SOURCES += cpp/main.cpp \
    cpp/mycontext.cpp \
    cpp/MM.cpp \
    cpp/utile.cpp

HEADERS += \
    cpp/mycontext.h \
    cpp/MM.h \
    cpp/utile.h

DISTFILES += \
    qml/main.qml

FORMS +=
