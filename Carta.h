#pragma once

#ifndef CARTA_H_
#define CARTA_H_

#include <string>

enum CartaAJugar {
	misil,
	avion,
	barco,
	bombaNuclear,
	eliminarMazoSiguienteJugador,
	cartaAdefinir1
};



class Carta
{
	
private:
	CartaAJugar tipoDeCarta;
	std::string descripcionCarta;

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

	void ejecutarFuncion();

};
#endif