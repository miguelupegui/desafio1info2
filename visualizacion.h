#ifndef VISUALIZACION_H
#define VISUALIZACION_H

void mostrarTablero(unsigned char* tablero, int F, int C, int desplazamiento);

void mostrarTableroBits(unsigned char* tablero, int F, int C,
                        int bytesreservados, int desplazamiento);

void mostrarEstadoJuego(int F, int C, int eliminaciones, int fichasEliminadas,
                        int combinaciones, int cascadas, int puntuacion,
                        int bytesreservados);

#endif