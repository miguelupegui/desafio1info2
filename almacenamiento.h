#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

int calcularbytes(int F, int C);

void creartablero(unsigned char*& tablero, int F, int C, int& bytesreservados);

void fichacomienza(int fila, int columna, int C,
                   int& byteindex, int& byteoffset);

unsigned char tomarFicha(unsigned char* tablero,
                         int fila, int columna, int C);

void modificarficha(unsigned char* tablero,
                    int fila, int columna, int C,
                    unsigned char valor);

void liberartablero(unsigned char*& tablero,
                    int& bytesreservados);

#endif