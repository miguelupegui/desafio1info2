#include <iostream>
#include <cstdlib>
#include <ctime>

#include "almacenamiento.h"
#include "visualizacion.h"
#include "generacion.h"
#include "juego.h"
#include "modificacion.h"
#include "reorganizarTablero.h"

using namespace std;

//puntuacion: cada ficha que se elimina dentro de una combinacion vale 10 puntos
//y cada cascada suma 20 puntos mas, para premiar las jugadas encadenadas.
int calcularPuntuacion(int fichas, int cascadas)
{
    return fichas * 10 + cascadas * 20;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int filas = 0;
    int columnas = 0;

    cout << "Ingrese el numero de filas: ";
    cin >> filas;

    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    if (filas < 3 || columnas < 3)
    {
        cout << "El tablero debe tener al menos 3 filas y 3 columnas." << endl;
        return 0;
    }

    unsigned char* tablero = nullptr;
    int bytesreservados = 0;

    creartablero(tablero, filas, columnas, bytesreservados);

    int desplazamiento = calcularDesplazamiento(filas, columnas, bytesreservados);

    llenarTablero(tablero, filas, columnas, desplazamiento);

    //estadisticas generales de la partida
    int eliminacionesUsuario = 0;
    int fichasEliminadasTotal = 0;
    int combinacionesTotal = 0;
    int cascadasJugada = 0;
    int puntuacion = 0;

    //variables que devuelve cada jugada
    int cascadas = 0;
    int fichas = 0;
    int combinaciones = 0;

    //el tablero inicial puede salir con combinaciones por azar, se resuelven
    //antes de empezar para que el jugador arranque con un tablero estable
    procesarCascadas(tablero, filas, columnas, desplazamiento,
                     cascadas, fichas, combinaciones);

    cout << endl;
    cout << "TABLERO INICIAL" << endl;
    mostrarTablero(tablero, filas, columnas, desplazamiento);

    cout << endl;
    cout << "TABLERO EN BITS" << endl;
    mostrarTableroBits(tablero, filas, columnas, bytesreservados, desplazamiento);

    int opcion = 0;

    while (opcion != 6)
    {
        cout << endl;
        cout << "1. Eliminar una ficha" << endl;
        cout << "2. Agregar una fila" << endl;
        cout << "3. Eliminar una fila" << endl;
        cout << "4. Agregar una columna" << endl;
        cout << "5. Eliminar una columna" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (!cin)
        {
            cout << "Entrada no valida, se termina el programa." << endl;
            break;
        }

        bool hubojugada = false;

        if (opcion == 1)
        {
            int filaSeleccionada = 0;
            int columnaSeleccionada = 0;

            cout << "Seleccione una fila (0 a " << filas - 1 << "): ";
            cin >> filaSeleccionada;

            cout << "Seleccione una columna (0 a " << columnas - 1 << "): ";
            cin >> columnaSeleccionada;

            if (filaSeleccionada < 0 || filaSeleccionada >= filas ||
                columnaSeleccionada < 0 || columnaSeleccionada >= columnas)
            {
                cout << "Esa posicion no existe en el tablero." << endl;
            }
            else
            {
                eliminarFicha(tablero, filaSeleccionada, columnaSeleccionada,
                              columnas, desplazamiento);

                eliminacionesUsuario++;
                fichasEliminadasTotal++;

                //aunque la ficha borrada no forme combinacion, el hueco se tiene
                //que llenar igual: primero caen las de arriba y luego entran nuevas
                reorganizarTablero(tablero, filas, columnas, desplazamiento);
                llenarTablero(tablero, filas, columnas, desplazamiento);

                hubojugada = true;
            }
        }
        else if (opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5)
        {
            int posicion = 0;

            if (opcion == 2)
            {
                cout << "Posicion de la nueva fila (0 a " << filas << "): ";
                cin >> posicion;

                if (posicion < 0 || posicion > filas)
                {
                    cout << "Posicion no valida." << endl;
                }
                else
                {
                    nuevaFila(tablero, filas, columnas, bytesreservados,
                              desplazamiento, posicion);
                    llenarTablero(tablero, filas, columnas, desplazamiento);
                    hubojugada = true;
                }
            }
            else if (opcion == 3)
            {
                cout << "Fila que desea eliminar (0 a " << filas - 1 << "): ";
                cin >> posicion;

                if (filas <= 3)
                {
                    cout << "No se puede, el tablero debe conservar al menos 3 filas." << endl;
                }
                else if (posicion < 0 || posicion >= filas)
                {
                    cout << "Posicion no valida." << endl;
                }
                else
                {
                    borrarFila(tablero, filas, columnas, bytesreservados,
                               desplazamiento, posicion);
                    hubojugada = true;
                }
            }
            else if (opcion == 4)
            {
                cout << "Posicion de la nueva columna (0 a " << columnas << "): ";
                cin >> posicion;

                if (posicion < 0 || posicion > columnas)
                {
                    cout << "Posicion no valida." << endl;
                }
                else
                {
                    nuevaColumna(tablero, filas, columnas, bytesreservados,
                                 desplazamiento, posicion);
                    llenarTablero(tablero, filas, columnas, desplazamiento);
                    hubojugada = true;
                }
            }
            else
            {
                cout << "Columna que desea eliminar (0 a " << columnas - 1 << "): ";
                cin >> posicion;

                if (columnas <= 3)
                {
                    cout << "No se puede, el tablero debe conservar al menos 3 columnas." << endl;
                }
                else if (posicion < 0 || posicion >= columnas)
                {
                    cout << "Posicion no valida." << endl;
                }
                else
                {
                    borrarColumna(tablero, filas, columnas, bytesreservados,
                                  desplazamiento, posicion);
                    hubojugada = true;
                }
            }
        }
        else if (opcion != 6)
        {
            cout << "Opcion no valida." << endl;
        }

        if (hubojugada)
        {
            procesarCascadas(tablero, filas, columnas, desplazamiento,
                             cascadas, fichas, combinaciones);

            cascadasJugada = cascadas;
            fichasEliminadasTotal += fichas;
            combinacionesTotal += combinaciones;
            puntuacion += calcularPuntuacion(fichas, cascadas);

            cout << endl;
            cout << "TABLERO DESPUES DE LA JUGADA" << endl;
            mostrarTablero(tablero, filas, columnas, desplazamiento);

            cout << endl;
            cout << "TABLERO EN BITS" << endl;
            mostrarTableroBits(tablero, filas, columnas, bytesreservados, desplazamiento);

            mostrarEstadoJuego(filas, columnas, eliminacionesUsuario,
                               fichasEliminadasTotal, combinacionesTotal,
                               cascadasJugada, puntuacion, bytesreservados);
        }
    }

    liberartablero(tablero, bytesreservados);

    cout << "Juego terminado. Puntuacion final: " << puntuacion << endl;

    return 0;
}