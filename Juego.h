// Hecho por Helena Ant�n Navarro y Antonio Trenado Mart�n

#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "matriz.h"
#include "ListaPuzzle.h"

using namespace std;

typedef struct {
	int numMax;
	int mov;
	string modo;
	tMatrizChar matrizInicial;
	tMatrizChar matrizFinal;
}tJuegoPM;



int menu(); //men� para seleccionar el tipo de juego (1, 2 o  3) o salir (0).
bool iniciar(tJuegoPM& jpm); //inicia los par�metros del juego que correspondan y llama a la funci�n cargar definida a continuaci�n.
void mainPuzzlesReunidos(tPuzzle& jpm); // funcion princiapl del juego




#endif