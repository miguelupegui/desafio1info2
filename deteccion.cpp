#include "deteccion.h"
#include "almacenamiento.h"

void detectarHorizontal(unsigned char* tablero, int F, int C)
{
    for (int i = 0; i < F; i++)
    {
        int inicio = 0;
        int contador = 1;

        unsigned char fichaRef = tomarFicha(tablero, i, 0, C);

        for (int j = 1; j < C; j++)
        {
            unsigned char actual = tomarFicha(tablero, i, j, C);

            if (fichaRef != 0 && fichaRef != 7 && actual == fichaRef)
            {
                contador++;
            }
            else
            {
                if (contador >= 3 && fichaRef != 0 && fichaRef != 7)
                {
                    for (int k = inicio; k < inicio + contador; k++)
                    {
                        modificarficha(tablero, i, k, C, 7);
                    }
                }

                fichaRef = actual;
                contador = 1;
                inicio = j;
            }
        }

        if (contador >= 3 && fichaRef != 0 && fichaRef != 7)
        {
            for (int k = inicio; k < inicio + contador; k++)
            {
                modificarficha(tablero, i, k, C, 7);
            }
        }
    }
}


void detectarVertical(unsigned char* tablero, int F, int C)
{
    for (int j = 0; j < C; j++)
    {
        int inicio = 0;
        int contador = 1;

        unsigned char fichaRef = tomarFicha(tablero, 0, j, C);

        for (int i = 1; i < F; i++)
        {
            unsigned char actual = tomarFicha(tablero, i, j, C);

            if (fichaRef != 0 && fichaRef != 7 && actual == fichaRef)
            {
                contador++;
            }
            else
            {
                if (contador >= 3 && fichaRef != 0 && fichaRef != 7)
                {
                    for (int k = inicio; k < inicio + contador; k++)
                    {
                        modificarficha(tablero, k, j, C, 7);
                    }
                }

                fichaRef = actual;
                contador = 1;
                inicio = i;
            }
        }

        if (contador >= 3 && fichaRef != 0 && fichaRef != 7)
        {
            for (int k = inicio; k < inicio + contador; k++)
            {
                modificarficha(tablero, k, j, C, 7);
            }
        }
    }
}


void eliminarCombo(unsigned char* tablero, int F, int C)
{
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            unsigned char ficha = tomarFicha(tablero, i, j, C);

            if (ficha == 7)
            {
                modificarficha(tablero, i, j, C, 0);
            }
        }
    }
}