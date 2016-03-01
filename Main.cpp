#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Polinomio.h"
#include "SolucionParcial.h"
using namespace std;

int main() {
	//Inicialización de la semilla basada en el tiempo (numero de segundos desde 1970)
	srand((unsigned int)time(NULL));
	int gradoPolinomio;
	cout << "El grado del polinomio: ";
	cin >> gradoPolinomio;
	float *miPolinomio = (float*)malloc(sizeof(float)*(gradoPolinomio + 1));
	cout << gradoPolinomio + 1 << "coeficientes, separados por espacio y ordenados de grado menor a mayor: ";
	for (int i = 0; i < (gradoPolinomio+1); i++)
	{
		cin >> miPolinomio[i];
	}
	Polinomio prueba(gradoPolinomio, miPolinomio);
	prueba.evaluar(0);
	SolucionParcial solucion = prueba.obtenerMaximo();
	cout << "resultado: " << solucion.x << endl;
	return 0;
}