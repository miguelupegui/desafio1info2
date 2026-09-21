#include "modificacion.h"
#include "almacenamiento.h"

//decide cuantos bytes va a tener el tablero despues del cambio de tamano.
//si hace falta mas memoria se pide siempre. si sobra memoria solo se devuelve
//cuando lo que se necesita queda por debajo del 65% de lo que hay reservado,
//que es la condicion que pide el desafio.
int memoriaNueva(int Fnuevo, int Cnuevo, int bytesactuales)
{
    int necesarios = calcularbytes(Fnuevo, Cnuevo);

    if (necesarios > bytesactuales)
    {
        return necesarios;
    }

    if (necesarios * 100 < bytesactuales * 65)
    {
        return necesarios;
    }

    return bytesactuales;
}

//como al cambiar el tamano cambia la posicion de casi todas las fichas dentro
//de la trama de bits, se arma un tablero nuevo y se copian las fichas una por
//una con tomarFicha y modificarficha. asi no hay que mover bits a mano.
void nuevaFila(unsigned char*& tablero, int& F, int& C,
               int& bytesreservados, int& desplazamiento, int posicion)
{
    int Fnuevo = F + 1;
    int bytesnuevos = memoriaNueva(Fnuevo, C, bytesreservados);

    unsigned char* nuevo = new unsigned char[bytesnuevos];
    for (int i = 0; i < bytesnuevos; i++)
    {
        nuevo[i] = 0;
    }

    int despnuevo = calcularDesplazamiento(Fnuevo, C, bytesnuevos);

    for (int fila = 0; fila < Fnuevo; fila++)
    {
        for (int columna = 0; columna < C; columna++)
        {
            if (fila == posicion)
            {
                modificarficha(nuevo, fila, columna, C, despnuevo, 0);
            }
            else
            {
                int filaVieja = fila;

                if (fila > posicion)
                {
                    filaVieja = fila - 1;
                }

                unsigned char ficha = tomarFicha(tablero, filaVieja, columna, C, desplazamiento);
                modificarficha(nuevo, fila, columna, C, despnuevo, ficha);
            }
        }
    }

    delete[] tablero;

    tablero = nuevo;
    F = Fnuevo;
    bytesreservados = bytesnuevos;
    desplazamiento = despnuevo;
}

void borrarFila(unsigned char*& tablero, int& F, int& C,
                int& bytesreservados, int& desplazamiento, int posicion)
{
    int Fnuevo = F - 1;
    int bytesnuevos = memoriaNueva(Fnuevo, C, bytesreservados);

    unsigned char* nuevo = new unsigned char[bytesnuevos];
    for (int i = 0; i < bytesnuevos; i++)
    {
        nuevo[i] = 0;
    }

    int despnuevo = calcularDesplazamiento(Fnuevo, C, bytesnuevos);

    for (int fila = 0; fila < Fnuevo; fila++)
    {
        for (int columna = 0; columna < C; columna++)
        {
            int filaVieja = fila;

            if (fila >= posicion)
            {
                filaVieja = fila + 1;
            }

            unsigned char ficha = tomarFicha(tablero, filaVieja, columna, C, desplazamiento);
            modificarficha(nuevo, fila, columna, C, despnuevo, ficha);
        }
    }

    delete[] tablero;

    tablero = nuevo;
    F = Fnuevo;
    bytesreservados = bytesnuevos;
    desplazamiento = despnuevo;
}

void nuevaColumna(unsigned char*& tablero, int& F, int& C,
                  int& bytesreservados, int& desplazamiento, int posicion)
{
    int Cnuevo = C + 1;
    int bytesnuevos = memoriaNueva(F, Cnuevo, bytesreservados);

    unsigned char* nuevo = new unsigned char[bytesnuevos];
    for (int i = 0; i < bytesnuevos; i++)
    {
        nuevo[i] = 0;
    }

    int despnuevo = calcularDesplazamiento(F, Cnuevo, bytesnuevos);

    for (int fila = 0; fila < F; fila++)
    {
        for (int columna = 0; columna < Cnuevo; columna++)
        {
            if (columna == posicion)
            {
                modificarficha(nuevo, fila, columna, Cnuevo, despnuevo, 0);
            }
            else
            {
                int columnaVieja = columna;

                if (columna > posicion)
                {
                    columnaVieja = columna - 1;
                }

                unsigned char ficha = tomarFicha(tablero, fila, columnaVieja, C, desplazamiento);
                modificarficha(nuevo, fila, columna, Cnuevo, despnuevo, ficha);
            }
        }
    }

    delete[] tablero;

    tablero = nuevo;
    C = Cnuevo;
    bytesreservados = bytesnuevos;
    desplazamiento = despnuevo;
}

void borrarColumna(unsigned char*& tablero, int& F, int& C,
                   int& bytesreservados, int& desplazamiento, int posicion)
{
    int Cnuevo = C - 1;
    int bytesnuevos = memoriaNueva(F, Cnuevo, bytesreservados);

    unsigned char* nuevo = new unsigned char[bytesnuevos];
    for (int i = 0; i < bytesnuevos; i++)
    {
        nuevo[i] = 0;
    }

    int despnuevo = calcularDesplazamiento(F, Cnuevo, bytesnuevos);

    for (int fila = 0; fila < F; fila++)
    {
        for (int columna = 0; columna < Cnuevo; columna++)
        {
            int columnaVieja = columna;

            if (columna >= posicion)
            {
                columnaVieja = columna + 1;
            }

            unsigned char ficha = tomarFicha(tablero, fila, columnaVieja, C, desplazamiento);
            modificarficha(nuevo, fila, columna, Cnuevo, despnuevo, ficha);
        }
    }

    delete[] tablero;

    tablero = nuevo;
    C = Cnuevo;
    bytesreservados = bytesnuevos;
    desplazamiento = despnuevo;
}