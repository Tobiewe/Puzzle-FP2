// Hecho por Helena Ant�n Navarro y Antonio Trenado Mart�n

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
