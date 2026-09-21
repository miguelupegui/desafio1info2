#include "reorganizarTablero.h"
#include "almacenamiento.h"

void reorganizarTablero(unsigned char* tablero, int filas, int columnas, int desplazamiento)
{
    for (int columna = 0; columna < columnas; columna++)
    {
        for (int fila = filas - 1; fila >= 0; fila--)
        {
            unsigned char fichaActual =
                tomarFicha(tablero, fila, columna, columnas, desplazamiento);

            if (fichaActual == 0)
            {
                for (int busqueda = fila - 1; busqueda >= 0; busqueda--)
                {
                    unsigned char ficha =
                        tomarFicha(tablero, busqueda, columna, columnas, desplazamiento);

                    if (ficha != 0)
                    {
                        modificarficha(
                            tablero,
                            fila,
                            columna,
                            columnas,
                            desplazamiento,
                            ficha
                            );

                        modificarficha(
                            tablero,
                            busqueda,
                            columna,
                            columnas,
                            desplazamiento,
                            0
                            );

                        break;
                    }
                }
            }
        }
    }
}