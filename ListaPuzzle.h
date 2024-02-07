// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#ifndef LISTADEPUZZLES_H
#define LISTADEPUZZLES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Puzzle.h"

using namespace std;

const int MAX_PUZZLES = 100;
const int MAX_PUZZLESTIPOS = 2;

typedef tPuzzle *tPuzzles[MAX_PUZZLES];

typedef struct {

	tPuzzles puzzles;
	int contador;

}tListaPuzzles;

typedef tListaPuzzles tPuzzlesReunidos[MAX_PUZZLESTIPOS];


void inicializar(tPuzzlesReunidos& jr);
bool cargar(tPuzzlesReunidos& jr);
void guardar(const tPuzzlesReunidos& listas);
int elegirPuzzle(tListaPuzzles& lp);
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p);
bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos);
void cargarmatriz(int elegir, tListaPuzzles& lp, tPuzzle& jpm);
void liberar(tPuzzlesReunidos& jr);

#endif
