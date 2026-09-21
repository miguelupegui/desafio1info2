#include "juego.h"
#include "deteccion.h"
#include "reorganizarTablero.h"
#include "generacion.h"
#include "almacenamiento.h"

void eliminarFicha(
    unsigned char* tablero,
    int fila,
    int columna,
    int columnas,
    int desplazamiento
    )
{
    modificarficha(tablero, fila, columna, columnas, desplazamiento, 0);
}

//esta funcion se llama cuando el tablero ya esta lleno otra vez.
//cada vuelta del while en la que si aparecieron combinaciones cuenta como
//una cascada, porque fue el acomodo anterior el que las produjo.
void procesarCascadas(
    unsigned char* tablero,
    int filas,
    int columnas,
    int desplazamiento,
    int& cascadas,
    int& fichasEliminadas,
    int& combinaciones
    )
{
    cascadas = 0;
    fichasEliminadas = 0;
    combinaciones = 0;

    //tablero auxiliar con el mismo formato de 3 bits para anotar las marcas
    unsigned char* marcas = nullptr;
    int bytesMarcas = 0;
    creartablero(marcas, filas, columnas, bytesMarcas);
    int despMarcas = calcularDesplazamiento(filas, columnas, bytesMarcas);

    while (true)
    {
        int encontradas = 0;

        encontradas += detectarHorizontal(tablero, marcas, filas, columnas, desplazamiento, despMarcas);
        encontradas += detectarVertical(tablero, marcas, filas, columnas, desplazamiento, despMarcas);

        if (encontradas == 0)
        {
            break;
        }

        fichasEliminadas += eliminarCombo(tablero, marcas, filas, columnas, desplazamiento, despMarcas);

        combinaciones += encontradas;
        cascadas++;

        reorganizarTablero(tablero, filas, columnas, desplazamiento);

        llenarTablero(tablero, filas, columnas, desplazamiento);
    }

    liberartablero(marcas, bytesMarcas);
}