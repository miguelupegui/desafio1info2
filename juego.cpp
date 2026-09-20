#include "juego.h"
#include "deteccion.h"
#include "reorganizarTablero.h"
#include "generacion.h"
#include "almacenamiento.h"

void eliminarFicha(
    unsigned char* tablero,
    int fila,
    int columna,
    int columnas
    )
{
    modificarficha(tablero, fila, columna, columnas, 0);
}

static int contarMarcadas(
    unsigned char* tablero,
    int filas,
    int columnas
    )
{
    int cantidad = 0;

    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            if (tomarFicha(tablero, fila, columna, columnas) == 7)
            {
                cantidad++;
            }
        }
    }

    return cantidad;
}

void procesarCascadas(
    unsigned char* tablero,
    int filas,
    int columnas,
    int& cascadas,
    int& fichasEliminadas
    )
{
    cascadas = 0;
    fichasEliminadas = 0;

    while (true)
    {
        detectarHorizontal(tablero, filas, columnas);
        detectarVertical(tablero, filas, columnas);

        int marcadas =
            contarMarcadas(tablero, filas, columnas);

        if (marcadas == 0)
        {
            break;
        }

        eliminarCombo(tablero, filas, columnas);

        fichasEliminadas += marcadas;
        cascadas++;

        reorganizarTablero(tablero, filas, columnas);

        llenarTablero(tablero, filas, columnas);
    }
}