#include "visualizacion.h"
#include "almacenamiento.h"

#include <iostream>

using namespace std;

//PARTE 2. VISUALIZACION DEL TABLERO
void mostrarTablero(unsigned char* tablero, int F, int C, int desplazamiento){
    char juegodefichas[8] = {'_', '*', 'x', '?', 'm', '#', '@', ' '};
    cout << "   ";
    for (int h = 0; h < C; h++){
        cout<< h << "  ";
    }
    cout << endl;
    for(int i = 0; i < F; i++){
        cout<< i << "  ";
        for(int j = 0; j < C; j++){
            unsigned char ficha = tomarFicha(tablero, i, j, C, desplazamiento);
            char fichaPareja = juegodefichas[ficha];
            cout << fichaPareja << "  ";
        }
        cout << endl;
    }
}
//ahora hay que mostrar el tablero en bits
//se muestran todos los bytes que estan reservados de verdad. los bits que no
//pertenecen a ninguna ficha quedan al principio y se muestran entre corchetes.
void mostrarTableroBits(unsigned char* tablero, int F, int C,
                        int bytesreservados, int desplazamiento){

    if (desplazamiento > 0){
        cout << "[";
    }

    for (int i = 0; i < bytesreservados; i++){
        for (int h = 7; h >= 0; h = h -1){

            int posicion = i * 8 + (7 - h);

            if (posicion == desplazamiento && desplazamiento > 0){
                cout << "]";
            }

            int bit = (tablero[i] >> h) & 1;
            cout << bit;
        }
        cout << " ";
    }

    cout << endl;
    cout << "Bytes reservados: " << bytesreservados;
    cout << " | bytes minimos necesarios: " << calcularbytes(F, C);
    cout << " | bits de fichas: " << (3 * F * C);
    cout << " | bits invalidos: " << desplazamiento << endl;
}

void mostrarEstadoJuego(int F, int C, int eliminaciones, int fichasEliminadas,
                        int combinaciones, int cascadas, int puntuacion,
                        int bytesreservados){
    cout << endl;
    cout << "----- ESTADO DEL JUEGO -----" << endl;
    cout << "Dimensiones del tablero: " << F << " x " << C << endl;
    cout << "Memoria usada por el tablero: " << bytesreservados << " bytes" << endl;
    cout << "Eliminaciones hechas por el usuario: " << eliminaciones << endl;
    cout << "Fichas eliminadas en total: " << fichasEliminadas << endl;
    cout << "Combinaciones detectadas: " << combinaciones << endl;
    cout << "Cascadas de la jugada actual: " << cascadas << endl;
    cout << "Puntuacion: " << puntuacion << endl;
    cout << "----------------------------" << endl;
}