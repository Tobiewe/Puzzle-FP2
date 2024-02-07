#pragma once
#ifndef COORDENADAS_H
#define COORDENADAS_H
#include "UtilidadesSYS.h"

using namespace std;

typedef struct {
	int coorf;
	int coorc;
	uint8 color;
}tCoor;

bool operator== (tCoor c1, tCoor c2); // Operador de igualdad de dos coordenadas
bool operator!= (tCoor c1, tCoor c2); // Operador de desigualdad de dos coordenadas
tCoor operator+ (tCoor c1, tCoor c2); // Calcula la suma de dos coordenadas


#endif

