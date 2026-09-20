#include "generacion.h"
#include "almacenamiento.h"

#include <cstdlib>
#include <ctime>

unsigned char generarFicha()
{
    return static_cast<unsigned char>((rand() % 6) + 1);
}

void llenarTablero(unsigned char* tablero, int filas, int columnas)
{
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            unsigned char ficha =
                tomarFicha(tablero, fila, columna, columnas);

            if (ficha == 0)
            {
                modificarficha(
                    tablero,
                    fila,
                    columna,
                    columnas,
                    generarFicha()
                    );
            }
        }
    }
}