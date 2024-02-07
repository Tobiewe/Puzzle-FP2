// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include "juego.h"
#include <iomanip>
#include <fstream>
#include <stdio.h>



int menu() // menú para seleccionar el tipo de juego (1 o 2) o salir (0)
{
	int modo = 0;

	cout << endl;
	cout << " Elija una opcion: " << endl;
	cout << endl;

	do // te hace eleguir una opcion 1(modo 1D), 2(modo 2D), 3 salir
	{
		cout << " 1 - Modo 1D. " << endl;
		cout << " 2 - Modo 2D. " << endl;
		cout << " 3 - Añadir un puzzle al catalogo " << endl;
		cout << " 0 - Salir " << endl;
		cout << endl;
		cout << "Opcion elegida : ";cin >> modo;
		if (modo < 0 || modo > 3) // si el modo es mayor q tres o menor q 0 te pide q ingreses un modo valido
		{
			cout << "Debes introducir una de estas tres opciones " << endl;
		}
		borrar(); // llama a la funcion borrar
	}while (modo < 0 || modo > 3); // se queda mientras el modo este entre los permitidos

	return modo;
		
} 

bool iniciar(tJuegoPM& jpm) //inicia los parámetros del juego que correspondan y llama a la función cargar definida a continuación.

{
	bool error = false;
	string tipo = jpm.modo;
	tPuzzle puzzle;

	error = cargar(puzzle, tipo); // iguala la funcion cargar a un bool error para ver si se hace


	for (int i = 0; i < jpm.matrizInicial.contador_f; i++) // Sirve para selaionar la matriz
	{

		for (int j = 0; j < jpm.matrizInicial.contador_c; j++) {

			jpm.matrizInicial.matriz[i][j].coorc = j; // coordenadas i de la matriz inicial
			jpm.matrizInicial.matriz[i][j].coorf = i; // coordenadas j de la matriz inicial

		}
		
	}


	return error;
}

void mainPuzzlesReunidos(tPuzzle& jpm) {

	int tipo, elegir;
	tPuzzlesReunidos jr;
	tListaPuzzles lp;

	do {
		borrar();
		tipo = menu();

		if (tipo == 1) //Si el modo es 1D entra aqui
		{
			
				jpm.tipo = "1D"; // igualo el tipo del array a 1D
				inicializar(jr); // inicializo las dos listas de puzzles
				cargar(jr); // cargo la lista de puzzles
				lp.contador = jr[0].contador; // igualo el contadore de la lista ala contador de 
				for (int i = 0; i < lp.contador; i++) { //recorro todo el array y llevo todo lo q hay en la primera lista de puzzles al struxt tpzzules
					lp.puzzles[i] = jr[0].puzzles[i];
				}
			do {

				elegir = elegirPuzzle(lp);// eligo la version del puzzle que voya  ha hacer


				if (elegir > 0 && elegir <= lp.contador) { // si elegir esta dentro de los parametros que se establecen entra aqui


					cargarmatriz(elegir, lp, jpm); // carga la matriz
					mainPuzzle(jpm); //llamo a la funcion main puzzle

				}

				if (elegir == -1) { // si elegir es -1 ordeno de menor a mayor

					cargarmatriz(elegir, lp, jpm);
					borrar();


				}

				if (elegir == -2) { // si elegir es -2 ordeno de meyor a menor

					cargarmatriz(elegir, lp, jpm);
					borrar();


				}
			} while ((elegir == -2  || elegir == -1 || elegir > lp.contador) && elegir != 0);

		}
		else if (tipo == 2) //Si el modo es 2D entra aqui
		{
			
				jpm.tipo = "2D"; // igualo el tipo del array a 2D
				inicializar(jr); //inicializo las varibales
				cargar(jr); //  cargo la lista de puzzles
				lp.contador = jr[1].contador; // igualo el contador de la lista al array tPuzzles
				for (int i = 0; i < lp.contador; i++) { // igualo todo el array lista a tpuzzles
					lp.puzzles[i] = jr[1].puzzles[i];
				}
			do {
				elegir = elegirPuzzle(lp); //igualo elegir a elegir puzzles
			
				if (elegir > 0 && elegir <= lp.contador) { // si elegir esta dentro de las parametros entra aqui

					cargarmatriz(elegir, lp, jpm); // cargo la matriz seleccionada
					mainPuzzle(jpm);

				}

				if (elegir == -1) { //si el eligo -1 ordeno la matriz de menor a mayor

					cargarmatriz(elegir, lp, jpm);
					borrar();

				}

				if (elegir == -2) { // si el eligo es -2 ordeno la matriz de mayor a menor

					cargarmatriz(elegir, lp, jpm);
					borrar();


				}
			}while ((elegir == -2 || elegir == -1 || elegir > lp.contador) && elegir != 0);
		}

		else if (tipo == 3) //Si el modo es 3 entra aqui y permite añadir un puzzle
		{
			tPuzzle p;
			string nombre, archivo, archivo1;
			string modo;
			char aux;

			inicializar(jr); //inicializo eel max de puzzles
			cargar(jr); // cargo la lista

			cout << endl;

			cout << "Juegos 1D" << endl; // escribo la lista 1D en pantalla

			cout << endl;

			for (int i = 0; i < jr[0].contador; i++) {

				tPuzzle jpm;
				string tipo = "Tipo";

				jpm.archivo = jr[0].puzzles[i]->archivo;

				cargar(jpm, tipo);

				jr[0].puzzles[i]->numMax = jpm.numMax;

				cout << i + 1 << " - " << jr[0].puzzles[i]->nombre << " con un maximo de " << jr[0].puzzles[i]->numMax << " movimientos." << endl;
			}

			cout << endl;

			cout << "Juegos 2D" << endl; //escribo la lista 2D en pantalla

			cout << endl;

			for (int i = 0; i < jr[1].contador; i++) {

				tPuzzle jpm;
				string tipo = "Tipo";

				jpm.archivo = jr[1].puzzles[i]->archivo;

				cargar(jpm, tipo);

				jr[1].puzzles[i]->numMax = jpm.numMax;

				cout << i + 1 << " - " << jr[1].puzzles[i]->nombre << " con un maximo de " << jr[1].puzzles[i]->numMax << " movimientos." << endl;
			}

			cout << endl;
			cout << endl;
			cout << "Escriba el nombre del puzzle: ";
			cin.get(aux); //pido el nombre del puzzle que se desea introducir
			getline(cin, nombre);
			cout << endl;
			cout << "Escriba el nombre del fichero en que se encuentra: ";
			getline (cin,archivo);  //pido el nombre del archivo que se desea introducir



			if (archivo.find("_1D.txt") != 4294967295) { // si al escribir el archivo detecta q hay un 1D se introduce en la lista de puzzles 1 (tiene q ser distinto de el numero ya que me devueve un entero y es ese entonces cuando sea distinto e igual a 1D entra)
				
				jr[0].contador = jr[0].contador + 1; // le sumo uno al contador
				lp.contador = jr[0].contador; //igualo contadores
				p.nombre = nombre; // igualo el nombre del archivo a un tpuzzles
				p.archivo = archivo; // igualo el nombre del fichero a un tpuzzles
				string tipo = "Tipo";


				jpm.nombre = p.nombre; // igualo nombre a jpm para poder cargarlo
				jpm.archivo = p.archivo; // igualo el nombre del fichero a jpm para poder abrirlo

				cargar(jpm, tipo); // abro el fichero nuevo introducido

				jr[0].puzzles[lp.contador - 1]->numMax = jpm.numMax;  // igualo el num max para ordenarlo
				p.numMax = jr[0].puzzles[lp.contador -1 ]->numMax; // igualo el nummax para ordenarlo
				lp.puzzles[lp.contador -1 ] = jr[0].puzzles[lp.contador -1 ]; // igualo los contadores de la lista

				jr[0].puzzles[lp.contador - 1]->nombre = p.nombre; // guardo el nombre del archivo nuevo
				jr[0].puzzles[lp.contador - 1]->archivo = p.archivo; // guardo el nombre del ficchero nuevo

				for (int i = 0; i < lp.contador; i++) { // recorro y copio todo el array

					lp.puzzles[i] = jr[0].puzzles[i];

				}

				insertarOrdenado(lp, &p); //ordeno el nuevo puzzle introducido

				for (int i = 0; i < lp.contador; i++) { //guardo todos los puzzles para escribir

					 jr[0].puzzles[i] = lp.puzzles[i];

				}

				guardar(jr); // modifico el fichero introduciendo el nuevo

				borrar();
				cout << endl;

				for (int i = 0; i < jr[0].contador; i++) { // escribo el fichero modificado en pantalla

					tPuzzle jpm;
					string tipo = "Tipo";

					jpm.archivo = jr[0].puzzles[i]->archivo;

					cargar(jpm, tipo);

					jr[1].puzzles[i]->numMax = jpm.numMax;

					cout << i + 1 << " - " << jr[0].puzzles[i]->nombre << " con un maximo de " << jr[0].puzzles[i]->numMax << " movimientos." << endl;
				}

				pausa();
			}

			if (archivo.find("_2D.txt") != 4294967295) { // si al escribir el archivo detecta q hay un 2D se introduce en la lista de puzzles 2 (tiene q ser distinto de el numero ya que me devueve un entero y es ese entonces cuando sea distinto e igual a 2D entra)

				jr[1].contador = jr[1].contador + 1; // le sumo uno al contador
				lp.contador = jr[1].contador; //igualo contadores
				p.nombre = nombre; // igualo el nombre del archivo a un tpuzzles
				p.archivo = archivo; // igualo el nombre del fichero a un tpuzzles
				string tipo = "Tipo";


				jpm.nombre = p.nombre; // igualo nombre a jpm para poder cargarlo
				jpm.archivo = p.archivo; // igualo el nombre del fichero a jpm para poder abrirlo

				cargar(jpm, tipo); // abro el fichero nuevo introducido

				jr[1].puzzles[lp.contador - 1]->numMax = jpm.numMax; // igualo el num max para ordenarlo
				p.numMax = jr[1].puzzles[lp.contador - 1]->numMax;  // igualo el nummax para ordenarlo
				lp.puzzles[lp.contador - 1] = jr[1].puzzles[lp.contador - 1];  // igualo los contadores de la lista

				jr[1].puzzles[lp.contador - 1]->nombre = p.nombre; // guardo el nombre del archivo nuevo
				jr[1].puzzles[lp.contador - 1]->archivo = p.archivo; // guardo el nombre del ficchero nuevo

				for (int i = 0; i < lp.contador; i++) { // recorro y copio todo el array

					lp.puzzles[i] = jr[1].puzzles[i];

				}

				insertarOrdenado(lp, &p); //ordeno el nuevo puzzle introducido

				for (int i = 0; i < lp.contador; i++) { //guardo todos los puzzles para escribir

					jr[1].puzzles[i] = lp.puzzles[i];

				}

				guardar(jr); // modifico el fichero introduciendo el nuevo

				borrar();
				cout << endl;


				for (int i = 0; i < jr[1].contador; i++) { // escribo el fichero modificado en pantalla

					tPuzzle jpm;
					string tipo = "Tipo";

					jpm.archivo = jr[1].puzzles[i]->archivo;

					cargar(jpm, tipo);

					jr[1].puzzles[i]->numMax = jpm.numMax;

					cout << i + 1 << " - " << jr[1].puzzles[i]->nombre << " con un maximo de " << jr[1].puzzles[i]->numMax << " movimientos." << endl;
				}

				pausa();

			}

		}

		if (tipo == 0) //Si el modo es 0 entra aqui y acaba el juego
		{
			cout << endl;
			cout << "Gracias por jugar" << endl;
		}

		if (tipo != 0 && tipo != 3 && elegir > 0) //Si el modo es 3 entra aqui
		{

			mainPuzzle(jpm);

		}

		liberar(jr);

	} while ( tipo == 3 ||tipo != 0 && jpm.matrizFinal == jpm.matrizInicial || (tipo != 0 && jpm.matrizFinal != jpm.matrizInicial && jpm.numMax == 0)); // el bucle se queda aqui mientras el modo sea distinto de tres y las matrices sean iguales o mientras las matrices sean distintas y el numero de movimientos permitidos sea igual a 0



}

