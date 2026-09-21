#include "generacion.h"
#include "almacenamiento.h"

#include <cstdlib>
#include <ctime>

//las fichas van del 1 al 6, el 0 queda para la posicion vacia y el 7 no se usa
//como ficha para poder reservarlo como estado especial
unsigned char generarFicha()
{
    return static_cast<unsigned char>((rand() % 6) + 1);
}

void llenarTablero(unsigned char* tablero, int filas, int columnas, int desplazamiento)
{
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            unsigned char ficha =
                tomarFicha(tablero, fila, columna, columnas, desplazamiento);

            if (ficha == 0)
            {
                modificarficha(
                    tablero,
                    fila,
                    columna,
                    columnas,
                    desplazamiento,
                    generarFicha()
                    );
            }
        }
    }
}