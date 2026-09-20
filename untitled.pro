TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        almacenamiento.cpp \
        deteccion.cpp \
        generacion.cpp \
        juego.cpp \
        main.cpp \
        reorganizarTablero.cpp

HEADERS += \
    almacenamiento.h \
    deteccion.h \
    generacion.h \
    juego.h \
    reorganizarTablero.h
