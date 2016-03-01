#include "Polinomio.h"
#include "SolucionParcial.h"
#include <cstdlib>
#include <random>
#include <cstdbool>
#include <iostream>
using namespace std;

Polinomio::Polinomio()
{
}

Polinomio::Polinomio(int gradoPolinomio, float *miPolinomio){
	coeficientesPolinomio = (float*)malloc(sizeof(float)*(gradoPolinomio + 1));
	memcpy(coeficientesPolinomio, miPolinomio, (gradoPolinomio + 1)*sizeof(float));
	this->gradoPolinomio = gradoPolinomio;
}

float Polinomio::evaluar(float equisAEvaluar)
{
	float resultado = 0;
	for (int i = 0; i < this->gradoPolinomio+1; i++){
		resultado += this->coeficientesPolinomio[i] * (pow(equisAEvaluar, i));
	}
	return resultado;
}

SolucionParcial Polinomio::obtenerMaximo()
{
	//Se decide el numero de hijos (entre 3 y 5)
	int numeroDeHijos = rand() % 3 + 3;

	//creamos el padre
	SolucionParcial solucion;

	//Calculamos hijo por hijo a ver cual está más cerca de 0
	float mejorEquis = solucion.x;
	//Creamos el padre con solucionParcial.x = 0;
	float mejorResultado = evaluar(solucion.x);
	//bool mejorEvolucion = false;
	solucion = obtenerMaximo(solucion);
	cout << "\n\nSalimos de la llamada recursiva." << endl << "Mejor x: " << solucion.x << endl << "resultado de la mejor x (solucion.y): " << solucion.y << endl;


	//cout << "Primera generacion acabada. el mejor resultado en la primera iteracion es: " << mejorEquis << " resultado: " << mejorResultado << endl;
	//obtenerMaximo();

	//if (mejorEvolucion) mejorResultado = obtenerMaximo(mejorResultado);
	//Ningun hijo es mejor que el padre.
	cout << "Ningun hijo ha sido mejor que el padre, por tanto acaba el programa." << endl;
	return solucion;
}

SolucionParcial Polinomio::obtenerMaximo(SolucionParcial resultadoTemporal)
{

	//Se decide el numero de hijos (entre 3 y 5)
	int numeroDeHijos = rand() % 3 + 3;

	//Calculamos hijo por hijo a ver cual está más cerca de 0
	SolucionParcial mejorHijo = resultadoTemporal;

	//Flag para detectár si hay algún hijo del padre que le mejora el resultado
	bool mejorEvolucion = false;

	/*
	1. Crear un hijo
	1.1 Asignarle a SolucionParcial.x su mutación
	2. Comparar su mutación con la más buena
	2.1 Si su mutacion es la mejor, establecer esa como la mejor mutación y por tanto guardar su valor de SolucionParcial.x en mejorEquis
	2.2 Si su mutacion no es la mejor, despreciar su resultado.
	3. Volver al paso 1
	*/
	for (int i = 0; i < numeroDeHijos; i++)
	{

		resultadoTemporal.x = mejorHijo.x + calculoAleatorio();
		//Evaluamos el hijo actual y le asugnamos el resultado a SolucionParcial.y
		resultadoTemporal.y = evaluar(resultadoTemporal.x);
		cout << "La solucion del hijo numero " << i << " con x = " << resultadoTemporal.x << " es de: " << resultadoTemporal.y << endl;
		cout << "El mejor resultado hasta ahora es: " << mejorHijo.y << endl;
		//Comparamos su resultado con el más bueno hasta ahora.
		if (resultadoTemporal.y > mejorHijo.y) {
			mejorHijo = resultadoTemporal;
			mejorEvolucion = true;
		}
		cout << "Despues del if:" << endl << "mejorResultado = " << mejorHijo.y << endl << "Mejor x = " << mejorHijo.x << endl;
	}

	//Una vez acabada la generacion de hijos y calculada la mejor, si la hay, llama recursivamente al mejor hijo.
	//Si el padre ha sido el mejor de la iteracion, acaba la iteracion ahi.
	cout << "\n\nEntramos en la llamada recursiva." << endl << "Mejor x: " << mejorHijo.x << endl << "resultado de la mejor x (solucion.y): " << mejorHijo.y << endl;
	if (mejorEvolucion) mejorHijo = obtenerMaximo(mejorHijo);
	cout << "\n\nSalimos de la llamada recursiva: " << endl << "Mejor x: " << mejorHijo.x << endl << "resultado de la mejor x (solucion.y): " << mejorHijo.y << endl;

	//cout << "generacion acabada. La mejor x en la iteracion es: " << mejorEquis << " resultado: " << mejorResultado << endl;
	//obtenerMaximo();

	//Ningun hijo es mejor que el padre.
	//cout << "Ningun hijo ha sido mejor que el padre, por tanto acaba el programa." << endl;
	cout << "Salimos de la recursiva" << endl;
	return mejorHijo;
}

float Polinomio::calculoAleatorio()
{
	//Cálculo de la desviación normal:
	float aleatorio = 0;
	for (int i = 0; i < 12; i++)
		aleatorio += (rand() / (float)RAND_MAX);
	return (aleatorio -= 6);
}

Polinomio::~Polinomio()
{
}