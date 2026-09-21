#include "deteccion.h"
#include "almacenamiento.h"

//las combinaciones no se borran de una vez sobre el tablero, se anotan en un
//tablero aparte llamado marcas (1 = la ficha se va, 0 = se queda).
//esto se hizo asi porque si borraramos de una vez en horizontal, la busqueda
//vertical ya no podria ver el valor original y se perderian los cruces.

int detectarHorizontal(unsigned char* tablero, unsigned char* marcas,
                       int F, int C, int desplazamiento, int despMarcas)
{
    int combinaciones = 0;

    for (int i = 0; i < F; i++)
    {
        int inicio = 0;
        int contador = 1;

        unsigned char fichaRef = tomarFicha(tablero, i, 0, C, desplazamiento);

        for (int j = 1; j < C; j++)
        {
            unsigned char actual = tomarFicha(tablero, i, j, C, desplazamiento);

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
                        modificarficha(marcas, i, k, C, despMarcas, 1);
                    }
                    combinaciones++;
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
                modificarficha(marcas, i, k, C, despMarcas, 1);
            }
            combinaciones++;
        }
    }

    return combinaciones;
}


int detectarVertical(unsigned char* tablero, unsigned char* marcas,
                     int F, int C, int desplazamiento, int despMarcas)
{
    int combinaciones = 0;

    for (int j = 0; j < C; j++)
    {
        int inicio = 0;
        int contador = 1;

        unsigned char fichaRef = tomarFicha(tablero, 0, j, C, desplazamiento);

        for (int i = 1; i < F; i++)
        {
            unsigned char actual = tomarFicha(tablero, i, j, C, desplazamiento);

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
                        modificarficha(marcas, k, j, C, despMarcas, 1);
                    }
                    combinaciones++;
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
                modificarficha(marcas, k, j, C, despMarcas, 1);
            }
            combinaciones++;
        }
    }

    return combinaciones;
}


//borra del tablero todas las posiciones marcadas y deja el tablero de marcas
//limpio para la siguiente vuelta. devuelve cuantas fichas se eliminaron.
int eliminarCombo(unsigned char* tablero, unsigned char* marcas,
                  int F, int C, int desplazamiento, int despMarcas)
{
    int eliminadas = 0;

    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (tomarFicha(marcas, i, j, C, despMarcas) == 1)
            {
                modificarficha(tablero, i, j, C, desplazamiento, 0);
                modificarficha(marcas, i, j, C, despMarcas, 0);
                eliminadas++;
            }
        }
    }

    return eliminadas;
}