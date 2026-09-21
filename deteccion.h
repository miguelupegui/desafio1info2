#ifndef DETECCION_H
#define DETECCION_H

int detectarHorizontal(unsigned char* tablero, unsigned char* marcas,
                       int F, int C, int desplazamiento, int despMarcas);

int detectarVertical(unsigned char* tablero, unsigned char* marcas,
                     int F, int C, int desplazamiento, int despMarcas);

int eliminarCombo(unsigned char* tablero, unsigned char* marcas,
                  int F, int C, int desplazamiento, int despMarcas);

#endif