#ifndef MATRIZ_H
#define MATRIZ_H
#include"coordenada.h"
#include <iostream>

using namespace std;

const int DIM_MAX = 64;
typedef tCoor tCoordenadas[DIM_MAX][DIM_MAX];
typedef struct {
	tCoordenadas matriz;
	int contador_f;
	int contador_c;
}tMatrizChar;

bool cargar(tMatrizChar& mat, ifstream& ent);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);// Indica si dos matrices son iguales
bool operator != (tMatrizChar const& mat1, tMatrizChar const& mat2);// Indica si dos matrices son distintas
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2); // Intercambia dos coordenadas de una matriz
bool swapF(tMatrizChar& mat, int f1, int f2); // Intercambia dos filas de una matriz
bool swapC(tMatrizChar& mat, int c1, int c2); // Intercambia dos columnas de una matriz
bool swapD(tMatrizChar& mat, int d); // Intercambia dos diagonales de una matriz, d(Diagonal positiva) y -d(Diagonal negativa)
bool voltearF(tMatrizChar& mat, int f); // Da la vuelta a la fila f con respecto al eje vertical central de la imagen
bool voltearC(tMatrizChar& mat, int c); // Da la vuelta a la columna c con respecto al eje horizontal central de la imagen
bool voltearD(tMatrizChar& mat, int d); // Da la vuelta a la diagonal d con respecto al centro de eje perpendicular de dicha diagonal
void voltearV(tMatrizChar& mat); // Da la vuelta a la imagen completa con respecto a su eje vertical central
void voltearH(tMatrizChar& mat); // Da la vuelta a la imagen completa con respecto a su eje horizontal central
void rotarD(tMatrizChar& mat); // Rota la una imagen 90 grados en el sentido de las agujas del reloj
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2); //  Intercambia las celdas vecinas o adyacentes de las posiciones pos1 y pos2
bool voltearID(tMatrizChar& mat); // Voltea la imagen completa respecto a la diagonal principal



#endif
