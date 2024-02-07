// Hecho por Helena Antón Navarro y Antonio Trenado Martín

#include "Juego.h"
#include "Puzzle.h"
#include <iomanip>
#include <fstream>
#include <stdio.h>




void mainPuzzle(tPuzzle& jpm) {

;
	tJuegoPM jpm1;



	bool error = false;
	error = iniciar(jpm1);
	while (jpm.numMax != 0) // Bucle mientras el numero de movimientos sea distinto de cero entra y se queda hastq e ganes o pierdas 
	{
		borrar(); // llama a la funcion borrar
		mostrar(jpm); // llama a la funcion mostrar
		cout << endl;
		jugar(jpm); // llama a la funcion jugar
		accion(jpm); // llama a la funcion accion
		pausa(); // llama a la funcion pausa
		if (jpm.numMax == 0 || jpm.matrizFinal == jpm.matrizInicial) // si el muerno de movimientas es 0 entra, tambien entra si las dos matrices son iguales
		{
			borrar(); // llama a la funcion borrar
			mostrar(jpm); // llama a la funcion mostrar
			pausa(); // llama a la funcion pausa
			borrar(); // llama a la funcion borrar

		}
		if (jpm.matrizInicial == jpm.matrizFinal)  // Si las matrices son iguales entra aqui
		{
			cout << endl;
			cout << "Has ganado" << endl;
			cout << endl;
			pausa(); // llama a la funcion pausa
			borrar(); // llama a la funcion borrar
			jpm.numMax = 0;
		}
		if (jpm.matrizFinal != jpm.matrizInicial && jpm.numMax == 0)  // Si las matrices son distintas salen de aqui
		{
			cout << endl;
			cout << "Has perdido" << endl;
			cout << endl;
			pausa(); // llama a la funcion pausa
			borrar(); // llama a la funcion borrar
			jpm.numMax = 0;
		}


	}
} /* */  /*   */    /*   */
/*Función que resuelve un puzzle. Corresponde a la antigua
función mainJuegoPM. Dependiendo de la implementación realizada por el alumno en
la primera parte puede necesitar algún pequeño ajuste en el código.*/

bool cargar(tPuzzle& jpm, string tipo) {

	bool leido = false;

	ifstream carpeta;

	carpeta.open(jpm.archivo); // abre el archivo que hemos leidos en datospuzzle.txt

	leido = cargar(jpm.matrizInicial, carpeta); // Cargar matriz inicial
	leido = cargar(jpm.matrizFinal, carpeta); // cargar la matriz final

	carpeta >> jpm.numMax; // leer el num max de movimientos

	carpeta.close(); // cerrar el archivo leido

	return leido;
}
/* Abre el fichero que corresponda y
llama a la función cargar del módulo Matriz. */

void mostrar(const tPuzzle& jpm) {
	int matrizfinal;
	cout << " -Matriz inicial:" << endl;
	cout << endl;

	cout << "    "; // imprimir los numeros encima de la matriz
	for (int i = 0; i < jpm.matrizInicial.contador_f; i++) //ver el numero de contador de la fila para imprimir los numeros
	{

		for (int j = 0; j < jpm.matrizInicial.contador_c; j++) //ver el numero de contador de la columna y imprimir los numeros
		{

			if (i == 0 && j < jpm.matrizInicial.contador_c) {
				cout << j % 20; // divido el numero entre veinte para quedarme con el resto y asi poder imprimir de menor a mayor el numero
			}
			if (i == 0) {

				if (j >= 10) { //si el numero es mayor que diez no imprime espacio entre los numeros

					cout << "";
				}
				else { // si el numero es menor que diez imprime un hueco entre los numeros
					cout << " ";
				}
			}
		}
	}

	cout << endl;
	for (int i = 0; i < jpm.matrizInicial.contador_f; i++) { // mira las filas de la matriz inicial

		cout << " ";

		for (int j = 0; j < jpm.matrizInicial.contador_c; j++) { // mira las columnas de la matriz inicial

			if (j == 0 && i < jpm.matrizInicial.contador_f) { // imprime los numneros de los latelares
				cout << i % 20; // divido el numero entre veinte para quedarme con el resto y asi poder imprimir de menor a mayor el numero
			}
			if (j == 0) {

				if (i >= 10) { //si el numero es mayor que diez  imprime un espacio entre los numeros

					cout << " ";
				}
				else { // si el numero es menor que diez imprime dos huecos entre los numeros

					cout << "  ";

				}
			}

			colorCTA(15, int(jpm.matrizInicial.matriz[i][j].color) - int('0')); // imprime el color de la matriz
			cout << setw(2) << " "; // deja dos espacio para cada pixel del puzzle para que quede simetrico y no aplastado
			colorCTA(15, 0); // Imprime el color
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;

	cout << " -Matriz final:" << endl;

	cout << endl;

	cout << "    "; // imprimir los numeros encima de la matriz
	for (int i = 0; i < jpm.matrizFinal.contador_f; i++) { //ver el numero de contador de la fila para imprimir los numeros

		for (int j = 0; j < jpm.matrizFinal.contador_c; j++) { // divido el numero entre veinte para quedarme con el resto y asi poder imprimir de menor a mayor el numero


			if (i == 0 && j < jpm.matrizFinal.contador_c) {
				cout << j % 20; // divido el numero entre veinte para quedarme con el resto y asi poder imprimir de menor a mayor el numero
			}
			if (i == 0) {

				if (j >= 10) {

					cout << ""; //si el numero es mayor que diez no imprime espacio entre los numeros
				}
				else {
					cout << " "; // si el numero es menor que diez imprime un hueco entre los numeros
				}
			}
		}
	}

	cout << endl;

	for (int i = 0; i < jpm.matrizFinal.contador_f; i++) { // mira las filas de la matriz final

		cout << " ";

		for (int j = 0; j < jpm.matrizFinal.contador_c; j++) { // mira las columnas de la matriz final


			if (j == 0 && i < jpm.matrizFinal.contador_f) { // imprime los numneros de los latelares
				cout << i % 20; // divido el numero entre veinte para quedarme con el resto y asi poder imprimir de menor a mayor el numero
			}
			if (j == 0) {
				if (i >= 10) {//si el numero es mayor que diez  imprime un espacio entre los numeros

					cout << " ";
				}
				else {// si el numero es menor que diez imprime un hueco entre los numeros

					cout << "  ";

				}
			}


			colorCTA(15, int(jpm.matrizFinal.matriz[i][j].color) - int('0')); // imprime el color de la matriz
			cout << setw(2) << " "; // deja dos espacio para cada pixel del puzzle para que quede simetrico y no aplastado
			colorCTA(15, 0); // Imprime el color


		}
		cout << endl;
	}

}
/* Muestra el estado del puzzle utilizando las
facilidades del módulo utilidadesSYS. Debe mostrar primero la imagen que se está
modificando y a continuación la imagen objetivo. Debe mostrar también el número de
intentos que quedan */

bool jugar(tPuzzle& jpm) //permite realizar las acciones necesarias para jugar y controla si se ha llegado al límite de acciones permitidas;
{



	cout << "Numero de intentos restantes: " << jpm.numMax << endl; // imprime en pantalla el número de intentos que te queda

	cout << endl;
	cout << " Elija una opcion: " << endl;

	if (jpm.tipo == "1D") //si el modo es 1D hace las funciones del 1D
	{
		do {
			cout << "1 - Para intercambiar dos filas del puzzle inserte 1 (SF)" << endl; // intercambiar las filas
			cout << "2 - Para intercambiar dos columanas del puzzle inserte 2 (SC)" << endl; // intercambiar las columnas
			cout << "3 - Para intercambiar dos diagonales del puzzle inserte 3 (SD)" << endl; // intercambiar las diagonales 
			cout << "4 - Para voltear una fila inserte 4 (VF)" << endl; // voltear la fila 
			cout << "5 - Para voltear una columna inserte 5 (VC)" << endl; // voltear la columna 
			cout << "6 - Para voltear la diagonal inserte 6 (VD)" << endl; //voltear la diagonal
			cin >> jpm.mov; //movimiento que eliges
			if (jpm.mov < 1 || jpm.mov > 6) { //si el modo no esta entre los permitidos te pide una opcion valida
				cout << endl;
				cout << "Debes introducir una accion para jugar " << endl;
				cout << endl;
			}
		} while (jpm.mov < 1 || jpm.mov > 6); // se queda aqui si el movimiento esta entre 6 y 1
	}

	if (jpm.tipo == "2D")  // si el modo es 2D hec las funciones de 2D
	{
		do {
			cout << "1 - Para voltear respecto a la vertical inserte 1 (VV)" << endl; // voltear respecto a la vertical
			cout << "2 - Para voltear respecto a la horizontal inserte 2 (VH)" << endl; // voltear respecto  a la horizontal
			cout << "3 - Para rotar a la derecha la imagen inserte 3 (RD)" << endl; // rotar a la derecha la imagen
			cout << "4 - Para intercambiar las posiciones inserte 4 (SA)" << endl; // intercambiar lasintercambiar las posiciones vecinas de las posiciones
			cout << "5 - Para voltear respecto a la diagonal principal inserte 5 (VD)" << endl; // voltear respecto a la diagonal principal 
			cin >> jpm.mov; //movimiento que eliges
			if (jpm.mov < 1 || jpm.mov > 5) { //si el modo no esta entre los permitidos te pide una opcion valida
				cout << endl;
				cout << "Debes introducir una accion para jugar " << endl;
				cout << endl;
			}
		} while (jpm.mov < 1 || jpm.mov > 5); // se queda aqui si el movimiento esta entre 5 y 1
	}

	if (jpm.matrizInicial == jpm.matrizFinal) { // si las matrices son iguales iguala el numero de movimientos a 0
		jpm.numMax = 0;
	}
	else {
		jpm.numMax = jpm.numMax - 1; // si las matrices no son iguales resta uno al numero de movimientos maximo
	}

	return jpm.mov; // me devuelve el movimeinto
}
/* Permite realizar las acciones necesarias para jugar
y controla si se ha llegado al límite de acciones permitidas; */

void accion(tPuzzle& jpm) 
	{


		int mover = 0; // creo este int para declarar el primer movimiento para que se vea reflejado en la consola
		int mover1 = 0; // creo este int para declarar el segundo movimiento para que se vea reflejado en la consola


		if (jpm.tipo == "1D" && jpm.mov == 1) // si el modo es 1D y el movimiento dicho por el usuario es 1 hace la funcion de intercambiar dos filas de la matriz
		{

			cout << "Introduzca la primera fila que desea cambiar: "; //imprime en pantalla la frase para q eligas la fila q quieres cambiar
			cin >> mover; cout << endl; //pide la primera fila q quieres cambiar 
			cout << "Introduzca la segunda fila que desea cambiar: "; //imprime en pantalla la frase para q eligas la fila q quieres cambiar
			cin >> mover1; cout << endl; // pide la segunda fila q quieres cambiar 
			swapF(jpm.matrizInicial, mover, mover1); // llama a swapF para intercambiar filas
		}

		else if (jpm.tipo == "1D" && jpm.mov == 2) // si el modo es 1D y el movimiento dicho por el usuario es 2
		{

			cout << "Introduzca la primera columna que desea cambiar: "; //imprime en pantalla la frase para q eligas la columna q quieres cambiar 
			cin >> mover; cout << endl; //pide la primera columna q quieres cambiar
			cout << "Introduzca la segunda columna que desea cambiar: "; //imprime en pantalla la frase para q eligas la columna q quieres cambiar
			cin >> mover1; cout << endl; //pide la segunda columna q quieres cambiar
			swapC(jpm.matrizInicial, mover, mover1); // llama a swapC para cambiar las columnas
		}

		else if (jpm.tipo == "1D" && jpm.mov == 3) // si el modo es 1D y el movimiento dicho por el usuario es 
		{

			cout << "Introduzca la diagonal que desea cambiar: ";  //imprime en pantalla la frase para q eligas la diagonal q quieres cambiar
			cin >> mover; cout << endl; // pide la diagonal q quieres cambiar
			swapD(jpm.matrizInicial, mover); //llama a swapD para cambair la diagonal
		}

		else if (jpm.tipo == "1D" && jpm.mov == 4) // si el modo es 1D y el movimiento dicho por el usuario es 
		{

			cout << "Introduzca la fila que desea voltear: ";  //imprime en pantalla la frase para q eligas la fila q quieres voltear
			cin >> mover; cout << endl; // pide la fila q quieres voltear
			voltearF(jpm.matrizInicial, mover); //llama a voltearF para voltear la fila
		}

		else if (jpm.tipo == "1D" && jpm.mov == 5) // si el modo es 1D y el movimiento dicho por el usuario es 
		{

			cout << "Introduzca la columna que desea voltear: "; //imprime en pantalla la frase para q eligas la columna q quieres voltear
			cin >> mover; cout << endl;  // pide la columna q quieres voltear
			voltearC(jpm.matrizInicial, mover); //llama a voltearC para voltear la columna
		}

		else if (jpm.tipo == "1D" && jpm.mov == 6) // si el modo es 1D y el movimiento dicho por el usuario es 
		{

			cout << "Introduzca la diagonal que desea voltear: "; //imprime en pantalla la frase para q eligas la diagonal q quieres voltear
			cin >> mover; cout << endl; // pide la diagonal q quieres voltear
			voltearD(jpm.matrizInicial, mover); //llama a la funcion voltearD para voltar la diagonal
		}

		else if (jpm.tipo == "2D" && jpm.mov == 1) // si el modo es 1D y el movimiento dicho por el usuario es 
		{

			voltearV(jpm.matrizInicial); //llama a la funcion voltearV para voltar la  la imagen completa con respecto a su eje vertical central.

		}

		else if (jpm.tipo == "2D" && jpm.mov == 2) // si el modo es 2D y el movimiento dicho por el usuario es 
		{

			voltearH(jpm.matrizInicial); // llama a la funcion voltarH  para dar la vuelta a la imagen completa con respecto a su eje horizontal central.
		}

		else if (jpm.tipo == "2D" && jpm.mov == 3) // si el modo es 2D y el movimiento dicho por el usuario es 
		{

			rotarD(jpm.matrizInicial); //llama a la funcion rotarD para rotar una imagen 90 grados en el sentido de las agujas del reloj.

		}

		else if (jpm.tipo == "2D" && jpm.mov == 4) // si el modo es 2D y el movimiento dicho por el usuario es 
		{

			tCoor p1, p2; // pide las coordenadas para cambiar las celdas vecinas

			cout << "Indroduzca la coordenada de la primera fila : "; //imprime en pantalla la frase para q eligas la primera fila de la coordenada q quieres cambiar las celdas vecinas
			cin >> p1.coorf; cout << endl;  // pide la primera fila de la coordenada para cambiar las celdas vecinas
			cout << "Indroduzca la coordenada de la primera columna: "; //imprime en pantalla la frase para q eligas la primera columna de la coordenada q quieres cambiar las celdas vecinas
			cin >> p1.coorc; cout << endl; // pide la primera columna de la coordenada para cambiar las celdas vecinas
			cout << "Indroduzca la coordenada de la segunda fila : "; //imprime en pantalla la frase para q eligas la segunda fila de la coordenada q quieres cambiar las celdas vecinas
			cin >> p2.coorf; cout << endl; // pide la segunda fila de la coordenada de la para cambiar las celdas vecinas
			cout << "Indroduzca la coordenada de la segunda columna: "; //imprime en pantalla la frase para q eligas la segunda columna de la coordenada q quieres cambiar las celdas vecinas
			cin >> p2.coorc; cout << endl; // pide la segunda columna de la coordenada para cambiar las celdas vecinas
			swapAdy(jpm.matrizInicial, p1, p2);

		}

		else if (jpm.tipo == "2D" && jpm.mov == 5) // si el modo es 2D y el movimiento dicho por el usuario es 
		{

			voltearID(jpm.matrizInicial); // llama a la funcion voltearID para Voltear la imagen completa respecto a la diagonal principal

		}

	}
	/* según el comando de acción tecleado por el
usuario, llama a la acción correspondiente definida en el módulo Matriz; */
