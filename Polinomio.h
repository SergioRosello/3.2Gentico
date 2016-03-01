#pragma once
#include "SolucionParcial.h"

class Polinomio
{
public:
	Polinomio();

	Polinomio(int, float*);
	//recibe el valor de x y nos devuelve el valor del polinomio para esa x...
	float evaluar(float);
	SolucionParcial obtenerMaximo();
	SolucionParcial obtenerMaximo(SolucionParcial);
	float calculoAleatorio();
	~Polinomio();

private:
	int gradoPolinomio;
	float *coeficientesPolinomio;
};

