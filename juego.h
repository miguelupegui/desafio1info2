#ifndef JUEGO_H
#define JUEGO_H

void eliminarFicha(
    unsigned char* tablero,
    int fila,
    int columna,
    int columnas,
    int desplazamiento
    );

void procesarCascadas(
    unsigned char* tablero,
    int filas,
    int columnas,
    int desplazamiento,
    int& cascadas,
    int& fichasEliminadas,
    int& combinaciones
    );

#endif