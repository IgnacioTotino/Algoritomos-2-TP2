#include "Carta.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Carta::Carta(CartaAJugar cartaNueva) {

	this->tipoDeCarta = cartaNueva;

	switch (this->getCarta())
	{
	case avion:
		this->descripcionCarta = "Condicion {Necesita estar en el aire}\n Dispara 2 veces mas mientras este en el campo.";
		break;

	case barco:
		this->descripcionCarta = "Condicion {Necesita estar en el agua}\n Lanza un misil por cada turno";
		break;

	case misil:
		this->descripcionCarta = "Al usarla destrulle 27 casilleros del campo.";
		break;

	case bombaNuclear:
		this->descripcionCarta = "Al jugar esta carta destruye todo el campo de juego.\n Ganas la partida.";
		break;

	case eliminarMazoSiguienteJugador:
		this->descripcionCarta = "Elimina el mazo del siguiente jugador";
		break;

	case cartaAdefinir1:
		this->descripcionCarta = "asd";
		break;

	default:
		cout << "no ingreso en ninguan opccion" << endl;
		break;
	}
}

CartaAJugar Carta::getCarta() {
	return this->tipoDeCarta;
}

std::string Carta::getDescripcionCarta() {
	return this->descripcionCarta;
}