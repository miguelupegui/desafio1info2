#ifndef MODIFICACION_H
#define MODIFICACION_H

int memoriaNueva(int Fnuevo, int Cnuevo, int bytesactuales);

void nuevaFila(unsigned char*& tablero, int& F, int& C,
               int& bytesreservados, int& desplazamiento, int posicion);

void borrarFila(unsigned char*& tablero, int& F, int& C,
                int& bytesreservados, int& desplazamiento, int posicion);

void nuevaColumna(unsigned char*& tablero, int& F, int& C,
                  int& bytesreservados, int& desplazamiento, int posicion);

void borrarColumna(unsigned char*& tablero, int& F, int& C,
                   int& bytesreservados, int& desplazamiento, int posicion);

#endif