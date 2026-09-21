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
        modificacion.cpp \
        reorganizarTablero.cpp \
        visualizacion.cpp

HEADERS += \
    almacenamiento.h \
    deteccion.h \
    generacion.h \
    juego.h \
    modificacion.h \
    reorganizarTablero.h \
    visualizacion.h