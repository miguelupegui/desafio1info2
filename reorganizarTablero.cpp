#include "reorganizarTablero.h"

void reorganizarTablero(unsigned char* tablero, int filas, int columnas)
{
    for (int columna = 0; columna < columnas; columna++)
    {
        for (int fila = filas - 1; fila >= 0; fila--)
        {
            for (int busqueda = fila - 1; busqueda >= 0; busqueda--)
            {
                // Aqui vamos a tomar y modificar la ficha
            }
        }
    }
}