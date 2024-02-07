// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include <iostream>
#include"coordenada.h"


bool operator == (tCoor c1, tCoor c2) {		// Operador de igualdad de dos coordenadas
	bool iguales = false;

	if (c1.color == c2.color) {	// Son iguales cuando sus colores lo sean
		iguales = true;
	}

	return iguales;
}

bool operator != (tCoor c1, tCoor c2) {		// Operador de desigualdad de dos coordenadas
	bool distintas = false;

	if (c1.color != c2.color) {	// Son distintas cuando los colores lo sean
		distintas = true;
	}

	return distintas;
}

tCoor operator + (tCoor c1, tCoor c2) {		// Calcula la suma de dos coordenadas
	tCoor coordenada;

	coordenada.coorf = c1.coorf + c2.coorf;		// Suma la primera componente de las coordenadas
	coordenada.coorc = c1.coorc + c2.coorc;		// Suma la segunda componente de las coordenadas

	return coordenada;
}


