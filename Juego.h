// Hecho por Helena Antón Navarro y Antonio Trenado Martín

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



int menu(); //menú para seleccionar el tipo de juego (1, 2 o  3) o salir (0).
bool iniciar(tJuegoPM& jpm); //inicia los parámetros del juego que correspondan y llama a la función cargar definida a continuación.
void mainPuzzlesReunidos(tPuzzle& jpm); // funcion princiapl del juego




#endif