#ifndef JUEGO_H
#define JUEGO_H

void procesarCascadas(
    unsigned char* tablero,
    int filas,
    int columnas,
    int& cascadas,
    int& fichasEliminadas
    );

void eliminarFicha(
    unsigned char* tablero,
    int fila,
    int columna,
    int columnas
    );

#endif