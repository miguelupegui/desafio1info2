#include "visualizacion.h"
#include "almacenamiento.h"

#include <iostream>

using namespace std;

//PARTE 2. VISUALIZACION DEL TABLERO
void mostrarTablero(unsigned char* tablero, int F, int C){
    char juegodefichas[8] = {'*', 'x', '?', 'm', '#', '@', '_', ' '};
    cout << "   ";
    for (int h = 0; h < C; h++){
        cout<< h << "  ";
    }
    cout << endl;
    for(int i = 0; i < F; i++){
        cout<< i << "  ";
        for(int j = 0; j < C; j++){
            unsigned char ficha = tomarFicha(tablero, i, j, C);
            char fichaPareja = juegodefichas[ficha];
            cout << fichaPareja << "  ";
        }
        cout << endl;
    }
}
//ahora hay que mostrar el tablero en bits
void mostrarTableroBits(unsigned char* tablero, int bytesreservados){
    for (int i = 0; i < bytesreservados; i++){
        for (int h = 7; h >= 0; h = h -1){
            int bit = (tablero[i] >> h) & 1;
            cout << bit;

        }
        cout << " ";

    }

}