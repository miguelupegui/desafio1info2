#include "almacenamiento.h"

//se hace la funcion de calcular los bytes del tablero
int calcularbytes(int F, int C){
    int totalbits = 3 * F * C;
    return (totalbits + 7) / 8;
}

//cantidad de bits que sobran y que el desafio pide dejar agrupados a la izquierda
//de toda la trama, es decir antes de la primera ficha
int calcularDesplazamiento(int F, int C, int bytesreservados){
    return bytesreservados * 8 - 3 * F * C;
}

//crear el tablero
void creartablero(unsigned char*& tablero, int F, int C, int& bytesreservados){
    bytesreservados = calcularbytes(F, C);
    tablero = new unsigned char[bytesreservados];

    for (int i = 0; i < bytesreservados; i++){
        tablero[i] = 0;
    }
}

//funcion de saber donde empieza la ficha exactamente
//los bits sobrantes van al comienzo, por eso se suma el desplazamiento
void fichacomienza(int fila, int columna, int C, int desplazamiento, int& byteindex, int& byteoffset){
    int indice = fila * C + columna;
    int bitinicial = desplazamiento + indice * 3;
    byteindex = bitinicial / 8;
    byteoffset = bitinicial % 8;
}

//funcion de tomar la ficha para analizar el caso de una ficha en dos bytes
unsigned char tomarFicha(unsigned char* tablero, int fila, int columna, int C, int desplazamiento){
    int byteindex;
    int byteoffset;
    fichacomienza(fila, columna, C, desplazamiento, byteindex, byteoffset);

    unsigned char valor;

    if (byteoffset <= 5) {
        // Caso 1: la ficha cabe completa en un solo byte
        int resultado = tablero[byteindex] >> (7 - (byteoffset + 2));
        valor = resultado & 0x07;
    } else {
        // Caso 2: la ficha se reparte entre tablero[byteindex] y tablero[byteindex + 1]
        int n1 = 8 - byteoffset;
        int n2 = 3 - n1;

        int parte1 = tablero[byteindex] & ((1 << n1) - 1);
        int parte2 = tablero[byteindex + 1] >> (8 - n2);

        valor = (parte1 << n2) | parte2;
    }

    return valor;
}
//declaracion de la funcion modificarficha()
//propósito: modifica el valor de una ficha especifica, sin tocar otras fichas
void modificarficha(unsigned char* tablero, int fila, int columna, int C, int desplazamiento, unsigned char valor){
    int byteindex;
    int byteoffset;
    fichacomienza(fila, columna, C, desplazamiento, byteindex, byteoffset);

    if (byteoffset <= 5) {
        // Caso 1: la ficha cabe completa en un solo byte
        int shift = 7 - (byteoffset + 2);
        unsigned char maskLimpia = ~(0x07 << shift);

        tablero[byteindex] = (tablero[byteindex] & maskLimpia) | ((valor & 0x07) << shift);

    } else {
        // Caso 2: la ficha se reparte entre tablero[byteindex] y tablero[byteindex + 1]
        int n1 = 8 - byteoffset;
        int n2 = 3 - n1;

        unsigned char mascaraLimpia1 = ~((1 << n1) - 1);
        unsigned char mascaraLimpia2 = (1 << (8 - n2)) - 1;

        tablero[byteindex]     = (tablero[byteindex] & mascaraLimpia1) | ((valor >> n2) & ((1 << n1) - 1));
        tablero[byteindex + 1] = (tablero[byteindex + 1] & mascaraLimpia2) | ((valor & ((1 << n2) - 1)) << (8 - n2));
    }
}
//liberar la memoria del tablero
//se tiene que liberar el bloque completo que reservó creartablero()

void liberartablero(unsigned char*& tablero, int& bytesreservados){
    delete[]tablero;
    tablero = nullptr;
    bytesreservados = 0;
}