// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include <iostream>
#include "juego.h"
#include"matriz.h"
#include"coordenada.h"
#include "UtilidadesSYS.h"

int main()
{
	chcp1252();
	setlocale(LC_ALL, "");
	borrar(); // llama a la funcion borrar
	tPuzzle jpm;
	mainPuzzlesReunidos(jpm); // llama al juego


	return 0;
}
