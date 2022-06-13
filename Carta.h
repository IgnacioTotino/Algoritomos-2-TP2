#pragma once

#ifndef CARTA_H_
#define CARTA_H_

#include <string>
#include <vector>
#include "Tablero.h"
#include "Jugador.h"
#include "Juego.h"

class Tablero;
class Jugador;
class Juego;

enum CartaAJugar {
	misil,
	avion,
	barco,
	bombaNuclear,
	eliminarMazoSiguienteJugador,
	revivirSoldado
};



class Carta
{
	
private:
	CartaAJugar tipoDeCarta;
	std::string descripcionCarta;
	void (*funcionCarta)(Tablero *, Juego*, Jugador*);
public:
	
	Carta(CartaAJugar tipoDeCarta);
	/*
	PRE:  ....
	POST: Asigna una carta a jugar.
	*/

	CartaAJugar getCarta();
	/*
	PRE:  ....
	POST: Devuevle la carta a jugar
	*/

	std::string getDescripcionCarta();
	/*
	PRE:  ....
	POST: Devuelve la descripccion de la carta
	*/

	void ejecutarFuncion(Tablero *, Juego *, Jugador *);

};

void funcionAvion(Tablero *, Jugador *);
#endif