#pragma once

#include "Tablero.h"
#include "MazoDeCartas.h"
class Juego
{
public:
	Juego(size_t);
	~Juego();
	size_t obtenerCantidadJugadores();
	bool chequearVictoria(size_t );
	//recive un puntero al tablero en el cual se juega, un puntero al mazo
	//de donde seran extraidas las cartas y un puntero al jugador
	//que realiza la jugada.
	bool jugar(Tablero *, MazoDeCartas Jugador *);

private:
	size_t cantidadDeJugadores;
};

void atacarCasillero(Tablero *,Jugador *, Posicion);
bool moverSoldado(Tablero*, Jugador *);
