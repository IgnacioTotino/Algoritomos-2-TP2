#pragma once

#ifndef MCARTA_H_
#define MCARTA_H_

#include"Carta.h"
#include "Cola.h"
#include<cstdlib>


class Carta;

class MazoDeCartas
{
private:
	Cola<Carta*>* mazo;

public:

	MazoDeCartas(int cantidadCartasMisil, int cantidadCartasAvion, int cantidadCartasBarco, int cantidadCartasBombaNuclear, int cantidadCartasEliminarMazo, int cantidadCartasX);
	/*
	PRE:  ....
	POST: Crea una instancia de Mazo con las cantidades de cartas indicadas en los par�metros.
	*/

	Cola<Carta*>* getMazoDeCartas();

	Carta* acolarCarta(Carta* carta);
	/*
	PRE: Recibe puntero a carta ( Carta* carta = new Carta*; ) creada de otra parte.
	POST: Acola la carta en la Cola del MAZO.
	*/

	Carta* repartirCarta();
	/*
	PRE: ...
	POST: Genera un numero entre 0 y 5 inclusive, y con estos numeros devuelve el enum de CartaEspecial correspondiente.
	*/

	bool elMazoEstaVacio();
	/*
	PRE:  ....
	POST: Devuelve 'true' si el Mazo est� vac�o. En caso contrario, devuelve 'false'.
	*/

	CartaAJugar generarNumero();
	/*
	PRE:  ....
	POST: Destruye el Mazo, liberando los recursos que ocupaba la estructura de datos.
		
	*/

	~MazoDeCartas();
	/*
	PRE:  ....
	POST: Destruye el Mazo, liberando los recursos que ocupaba la estructura de datos.
	*/

};

#endif