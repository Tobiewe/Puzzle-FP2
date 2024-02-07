// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include "ListaPuzzle.h"
#include "Juego.h"
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>



void inicializar(tPuzzlesReunidos& jr) // inicializa las dos listas de puzzles
{
	
	tPuzzle* puzzlein1, *puzzlein2; // declaro dos tipos tpuzles para referime a cada lista
	puzzlein1 = new tPuzzle[MAX_PUZZLES]; // declaro la primera lista
	puzzlein2 = new tPuzzle[MAX_PUZZLES]; // declaro la segunda lista

	jr[0].contador = 0; // igualo el contador de la lista 0 a 0
	jr[1].contador = 0; // igualo el contador de la lista 1 a 0


	for (int i = 0; i < MAX_PUZZLES; i++) { // recoro todo el array y igualo a las listas
		jr[0].puzzles[i] = &puzzlein1[i];
		jr[1].puzzles[i] = &puzzlein2[i];

	}

}

bool cargar(tPuzzlesReunidos& jr) /*carga los datos contenidos en el fichero
datosPuzzles.txt.Los datos se encuentran ordenados en el fichero en el mismo
orden en que deben estar en la lista, en orden creciente del número de intentos máximo
para realizar el puzzle y a igualdad de intentos por orden alfabético del nombre del
puzzle */

{

	jr[0].contador = 0; // igualo el contador de la lista 1 a 0
	jr[1].contador = 0; // igualo el contador de la lista 2 a 0
	bool cargado = false; // declaro cargado a false
	ifstream carpeta; // declaro la carpeta
	carpeta.open("datosPuzzles.txt"); //abro el fichero que contiene los datos que leo para las listas 

	if (carpeta.is_open()) {// miro si se ha abierto la carpeta

		int n, n1; // declaro esto para coger el numero de puzzles de la primera lista y de la segunda lista
		string aux;

		carpeta >> n; // cogo el numero de puzzles que hay en el fichero a la hora de leer en la primera lista

		getline(carpeta, aux); // decalro un auxiliar porque coge un espacio

			for (int i = 0; i < n; i++) {
				getline(carpeta, jr[0].puzzles[i]->nombre); // declaro un getline para coger todo el nombre del puzzle
				getline(carpeta, jr[0].puzzles[i]->archivo); // declaro un getline para coger todo el nombre del fichero
				jr[0].contador++; // sumo uno mas al contador para recorrer todo el array
			}

		carpeta >> n1; // cogo el numero de puzzles que hay en el fichero a la hora de leer en la segunda lista

		getline(carpeta, aux); // decalro un auxiliar porque coge un espacio

			for (int i = 0; i < n1; i++) {
				getline(carpeta, jr[1].puzzles[i]->nombre); // declaro un getline para coger todo el nombre del puzzle
				getline(carpeta, jr[1].puzzles[i]->archivo); // declaro un getline para coger todo el nombre del fichero
				jr[1].contador++; // sumo uno mas al contador para recorrer todo el array
			}
			cargado = true;

	}




	return cargado;

}

void guardar(const tPuzzlesReunidos& listas) {
	

	ofstream carpeta;

	carpeta.open("datosPuzzles.txt"); // abro el archivo que tengo que modificar
	if (carpeta.is_open()) { // veo a ver si la carpeta esta abierta

		carpeta << listas[0].contador << endl; // cogo el contador de la lista modificada para escribirlo

		for (int i = 0; i < listas[0].contador; i++) {  // recorro todo el array

			carpeta << listas[0].puzzles[i]->nombre << endl; // escribo en el archivo el nombre del puzzle
			carpeta << listas[0].puzzles[i]->archivo << endl; // escribo en el archivo el nombre del fichero

		}


		carpeta << listas[1].contador << endl; // cogo el contador de la lista modificada para escribirlo

		for (int i = 0; i < listas[1].contador; i++) { // recorro todo el array

			carpeta << listas[1].puzzles[i]->nombre << endl; // escribo en el archivo el nombre del puzzle
			carpeta << listas[1].puzzles[i]->archivo << endl; // escribo en el archivo el nombre del fichero

		}

	}

	carpeta.close(); // cierro el archivo q leo

}

int elegirPuzzle(tListaPuzzles& lp) {

	int movp = 0; // igualo el movimiento que escogo a 0

	cout << endl;
	cout << " En esta versión están disponibles los siguientes retos " << endl;
	cout << endl;
	
		do {
			for (int i = 0; i < lp.contador; i++) { // esta funcion escribe los nombres de los puzzles

				tPuzzle jpm;
				string tipo = "Tipo";

				jpm.archivo = lp.puzzles[i]->archivo;

				cargar(jpm, tipo);

				lp.puzzles[i]->numMax = jpm.numMax;

				cout << i + 1 << " - " << lp.puzzles[i]->nombre << " con un maximo de " << lp.puzzles[i]->numMax << " movimientos." << endl;
			}
			cout << "0 - Salir" << endl;
			cout << "-1 - Ordenar la lista de mayor a menor" << endl;
			cout << "-2 - Ordenar la lista de menor a mayor" << endl;
			cout << endl;
			cout << "Elige un reto: "; cin >> movp;
			
			if ((-2 > movp) || (movp > lp.contador)) {
				cout << endl;
				cout << "Debes introducir una accion para jugar " << endl;
				cout << endl;
			}
		} while ((-2 > movp) || (movp > lp.contador) );
	

		return movp;

}

bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p) { // inserta el puzzle que hemos metido nuevo ordenado en el archivo txt

	bool insertado = false;
	string tipo = "tipo";
	tListaPuzzles  aux;

	
	for (int i = 0; i < l.contador - 1; i++) {

		for (int j = l.contador - 1; j > i; j--) {

			if (l.puzzles[j]->numMax < l.puzzles[j - 1]->numMax) {
				aux.puzzles[j] = l.puzzles[j];
				l.puzzles[j] = l.puzzles[j - 1];
				l.puzzles[j - 1] = aux.puzzles[j];

			}

		}

		insertado = true;

	}

	return insertado;
}

bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos) {

	bool buscado = false;
	int i = 0;

	while (buscado == false && i < lista.contador) {
		if (lista.puzzles[pos]->archivo == puzzle->archivo) {
			buscado = true;
		}
		i++;
	}

	return buscado;
}


void liberar(tPuzzlesReunidos& jr) { //libero la memoria que no uso

	delete[] jr[0].puzzles[0];
	delete[] jr[1].puzzles[0];


	jr[0].contador = 0;
	jr[1].contador = 0;

}


void cargarmatriz(int elegir, tListaPuzzles& lp, tPuzzle& jpm ) { // esta funcion hace lo que manda el mov -2 -1



	if (elegir == -2) { // ordeno la lista  de menor a mayor

		if (lp.puzzles[0]->numMax > lp.puzzles[lp.contador - 1 ]->numMax) {

			tListaPuzzles aux;

			for (int i = 0; i < lp.contador; i++) {

				aux.puzzles[i] = lp.puzzles[i];

			}

			for (int i = 0; i < lp.contador; i++) {

				lp.puzzles[i] = aux.puzzles[lp.contador - (i + 1)];

			}

		}



	}


	if (elegir == -1) { // ordeno la lista de mayor a menor

		if (lp.puzzles[0]->numMax < lp.puzzles[lp.contador - 1]->numMax) {

			tListaPuzzles aux;

			for (int i = 0; i < lp.contador; i++) {

				aux.puzzles[i] = lp.puzzles[i];

			}

			for (int i = 0; i < lp.contador; i++) {

				lp.puzzles[i] = aux.puzzles[lp.contador - (i + 1)];

			}

		}


	}


	if (elegir  > 0 && elegir <= lp.contador) { // abro el archivo que se seleciona previamente

		int puzzleelegido;

		puzzleelegido = elegir -1 ;

		string tipo;

		jpm.archivo = lp.puzzles[puzzleelegido]->archivo;

		cargar(jpm, tipo);

	}


}