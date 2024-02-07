// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include"matriz.h"
#include <fstream>


bool cargar(tMatrizChar& mat, ifstream& ent) { // Lee una matriz, sus filas y columnas
	bool hecho = false;

	if (ent.is_open()) {	// Si el archivo existe, se lee
		ent >> mat.contador_f >> mat.contador_c;
		for (int i = 0; i < mat.contador_f; i++) {
			for (int j = 0; j < mat.contador_c; j++) {
				ent >> mat.matriz[i][j].color;		// Leemos las filas y columnas de la matriz
			}
		}
		hecho = true;
	}

	return hecho;
}

bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) { // Indica si dos matrices son iguales
	bool iguales = true;

	if (mat1.contador_f == mat2.contador_f && mat1.contador_c == mat2.contador_c) { // Comprueba si el tamaño es el mismo
		for (int i = 0; i < mat1.contador_f && iguales == true; i++) {
			for (int j = 0; j < mat1.contador_c && iguales == true; j++) {
				if (mat1.matriz[i][j] == mat2.matriz[i][j]) {		// Comprueba si todas las coordenadas de la matriz son iguales
					iguales = true;
				}
				else {
					iguales = false;
				}
			}

		}

	}
	else {
		iguales = false;
	}
	return iguales;

}

bool operator != (tMatrizChar const& mat1, tMatrizChar const& mat2) { // Indica si dos matrices son distintas
	bool distintas = true;

	if (mat1 == mat2) {	// Comprueba si las matrices son iguales si lo son devuelve true
		distintas = false;
	}
	else { //si las matrices son distintas develve false
		distintas = true; 
	}
	return distintas;

}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) { // Intercambia dos coordenadas de una matriz
	bool pertenecen = false;
	tCoor aux = pos2;
	tMatrizChar auxMat = mat;

	if (pos1.coorc < mat.contador_c && pos1.coorf < mat.contador_f) {	// Comprueba si la primera posicion pertenece a la matriz
		if (pos2.coorc < mat.contador_c && pos2.coorf < mat.contador_f) {	// Comprueba si la segunda coordenada pertenece a la matriz
			pertenecen = true;
			mat.matriz[pos2.coorf][pos2.coorc] = mat.matriz[pos1.coorf][pos1.coorc];	// Realiza el cambio de coordenadas
			mat.matriz[pos1.coorf][pos1.coorc] = auxMat.matriz[aux.coorf][aux.coorc];
		}
	}

	return pertenecen;
}

bool swapF(tMatrizChar& mat, int f1, int f2) { // Intercambia dos filas de una matriz
	bool hecho = false;
	tMatrizChar aux;

	if (f1 < mat.contador_f && f2 < mat.contador_f) {	// Comprueba que las filas pertenecen a la matriz
		for (int i = 0; i < mat.contador_c; i++) {
			aux = mat;
			mat.matriz[f2][i] = mat.matriz[f1][i];	// Realiza el cambio de filas recorriendolas a la vez
			mat.matriz[f1][i] = aux.matriz[f2][i];
		}
		hecho = true;
	}

	return hecho;
}

bool swapC(tMatrizChar& mat, int c1, int c2) { // Intercambia dos columnas de una matriz
	bool hecho = false;
	tMatrizChar aux;

	if (c1 < mat.contador_c && c2 < mat.contador_c) { // Comprueba si las columnas pertenecen a la matriz
		for (int i = 0; i < mat.contador_f; i++) {
			aux = mat;
			mat.matriz[i][c2] = mat.matriz[i][c1];	// Realiza el intercambio de columnas recorriendolas a la vez
			mat.matriz[i][c1] = aux.matriz[i][c2];
		}
		hecho = true;
	}

	return hecho;
}

bool swapD(tMatrizChar& mat, int d) { // Intercambia dos diagonales de una matriz, d(Diagonal positiva) y -d(Diagonal negativa)
	bool posible = false;
	tMatrizChar aux = mat;

	if (mat.contador_c == mat.contador_f) {	// Comprueba que la matriz es cuadrada
		if (d > 0) {	// Se realiza si se ha dado una diagonal positiva o la principal
			int j = d;
			int i = 0;

			while (i < mat.contador_c && j < mat.contador_c) {
				mat.matriz[i][j] = aux.matriz[j][i];	// Recorre ambas diagonales y las iguala usando una matriz auxiliar
				mat.matriz[j][i] = aux.matriz[i][j];
				i++;
				j++;
			}
		}
		if (d < 0) {	// Se realiza si se ha dado una diagonal negativa
			int j = 0;
			int i = -d;
			while (i < mat.contador_c && j < mat.contador_c) {
				mat.matriz[i][j] = aux.matriz[j][i];	// Igual al procedimiento anterior
				mat.matriz[j][i] = aux.matriz[i][j];
				i++;
				j++;
			}
		}
	}

	return posible;
}

bool voltearF(tMatrizChar& mat, int f) { // Da la vuelta a la fila f con respecto al eje vertical central de la imagen
	bool hecho = false;
	tMatrizChar aux = mat;

	if (f < mat.contador_f) {
		for (int i = 0; i < mat.contador_c; i++) {	// Comprueba que la fila pertenece a la matriz
			mat.matriz[f][i] = aux.matriz[f][mat.contador_c - (i + 1)];	// Recorre la fila y la iguala a la misma recorrida al reves

		}
		hecho = true;
	}

	return hecho;
}

bool voltearC(tMatrizChar& mat, int c) { // Da la vuelta a la columna c con respecto al eje horizontal central de la imagen
	bool hecho = false;
	tMatrizChar aux = mat;

	if (c < mat.contador_c) {
		for (int i = 0; i < mat.contador_f; i++) {	// Comprueba que la columna pertenece a la matriz
			mat.matriz[i][c] = aux.matriz[mat.contador_f - (i + 1)][c];	// Recorre la columna y la iguala a la misma recorrida al reves
		}
		hecho = true;
	}

	return hecho;
}

bool voltearD(tMatrizChar& mat, int d) { // Da la vuelta a la diagonal d con respecto al centro de eje perpendicular de dicha diagonal
	bool posible = false;
	tMatrizChar aux = mat;


	if (mat.contador_c == mat.contador_f) {	// Comprueba que la matriz es cuadrada
		if (d >= 0) {	// Se realiza para las diagonales positivas y para la principal
			if (d < mat.contador_c) {
				posible = true;
				int j = d;
				int i = 0;

				while (i < mat.contador_c && j < mat.contador_c) {	// Comprueba que la diagonal pertenece a la matriz
					mat.matriz[i][j] = aux.matriz[mat.contador_c - (j + 1)][mat.contador_c - (i + 1)];	// Recorre la diagonal y la iguala con la misma pero recorrida al reves
					i++;
					j++;
				}
			}
		}
		else if (d < 0) {	// Se realiza para las diagonales negativas
			int j = -d;
			int i = 0;

			while (i < mat.contador_c && j < mat.contador_c) {	// Comprueba que la diagonal pertenece a la matriz
				mat.matriz[j][i] = aux.matriz[mat.contador_c - (i + 1)][mat.contador_c - (j + 1)]; // Realiza lo mismo que anteriormente
				i++;
				j++;
			}
		}
	}

	return posible;
}

void voltearV(tMatrizChar& mat) { // Da la vuelta a la imagen completa con respecto a su eje vertical central
	if (voltearF) { // Comprueba si se pueden voltear las filas
		for (int i = 0; i < mat.contador_c; i++) {
			voltearF(mat, i);	// Voltea todas las filas
		}
	}
}

void voltearH(tMatrizChar& mat) { // Da la vuelta a la imagen completa con respecto a su eje horizontal central
	if (voltearF) {	// Comprueba si se pueden voltear las columnas
		for (int i = 0; i < mat.contador_c; i++) {
			voltearC(mat, i);	// Voletea todas las columnas
		}
	}
}

void rotarD(tMatrizChar& mat) { // Rota la una imagen 90 grados en el sentido de las agujas del reloj
	tMatrizChar aux = mat;

	for (int i = 0; i < mat.contador_c; i++) {
		for (int j = 0; j < mat.contador_f; j++) {
			mat.matriz[i][j] = aux.matriz[mat.contador_f - (j + 1)][mat.contador_c - (i + 1)];	// Intercambia las filas por las columnas
		}
	}
	int cont_aux = mat.contador_c;	// Intercambia los contadores para voltear despues
	mat.contador_c = mat.contador_f;
	mat.contador_f = cont_aux;
	voltearH(mat);	// Volteamos la matriz para que el resultado sea el correcto
}

bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) { //  Intercambia las celdas vecinas o adyacentes de las posiciones pos1 y pos2
	bool hecho = false;
	tMatrizChar aux = mat;
	tCoor p1, p2;

	p1.coorf = pos1.coorf - 1;			// Vuelve a iniciar los valores de las filas y las columnas de los parametros
	p1.coorc = pos1.coorc - 1;
	p2.coorf = pos2.coorf - 1;
	p2.coorc = pos2.coorc - 1;

	if (p1.coorf >= 0 && p1.coorc >= 0 && p2.coorf >= 0 && p2.coorc >= 0) {		// Solo se realizara el cambio si las posiciones y las adyacentes pertenecen a la matriz
		if (p1.coorf + 2 < mat.contador_f && p1.coorc + 2 < mat.contador_c && p2.coorf + 2 < mat.contador_f && p2.coorc + 2 < mat.contador_c) {
			while (p1.coorf < mat.contador_f && p1.coorc < mat.contador_c && p2.coorf < mat.contador_f && p2.coorc < mat.contador_c) {	// Se hara mientras las coordenadas que vayan a cambiar pertenezcan a la matriz
				while (p1.coorf < pos1.coorf + 2 && p1.coorc < pos1.coorc + 2 && p2.coorf < pos2.coorf + 2 && p2.coorc < pos2.coorc + 2) {	// Se hara mientras las coordenadas que vayan a cambiar sean solo las adyacentes a las dadas
					swap(mat, p1, p2); // Llama a la funcion swap para intercambiar las coordenadas
					p1.coorf++;		// Aumenta las filas de los parametros que pasan a la funcion
					p2.coorf++;
				}
				p1.coorc++;		// Aumenta las columnas de los parametros que pasan a la funcion
				p2.coorc++;
				p1.coorf = pos1.coorf - 1;		// Vuelve a iniciar los valores de las filas
				p2.coorf = pos2.coorf - 1;
			}

			swap(mat, pos1, pos2);		// Intercambia las posiciones dadas para que solo hayan cambiado las adyacentes
			hecho = true;
		}
		else {
			hecho = false;	// Si las adyacentes no pertenecen a la matriz devolvemos false
		}
	}
	else {
		hecho = false;	// Si las adyacentes no pertenecen a la matriz devolvemos false
	}

	return hecho;
}



bool voltearID(tMatrizChar& mat) { // Voltea la imagen completa respecto a la diagonal principal
	bool posible = false;
	tMatrizChar aux = mat;

	if (mat.contador_c == mat.contador_f) {	// Comprueba que la matriz sea cuadrada
		posible = true;
		for (int i = 0; i < mat.contador_c; i++) {
			for (int j = 0; j < mat.contador_c; j++) {
				mat.matriz[i][j] = aux.matriz[j][i];	// intercambia filas por columnas
			}
		}
	}

	return posible;
}




