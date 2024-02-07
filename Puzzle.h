// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include "matriz.h"


using namespace std;

typedef struct {
	int mov;
	int numMax;
	string nombre;
	string archivo;
	string tipo;
	tMatrizChar matrizInicial;
	tMatrizChar matrizFinal;
}tPuzzle;

void mainPuzzle(tPuzzle& jpm);
bool cargar(tPuzzle& jpm, string tipo);
void mostrar(const tPuzzle& jpm);
bool jugar(tPuzzle& jpm);
void accion(tPuzzle& jpm);
#endif
