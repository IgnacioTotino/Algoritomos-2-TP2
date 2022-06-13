#pragma once

#include <vector>
#include "Tablero.h"
#include "MazoDeCartas.h"

class Tablero;
class Jugador;
class MazoDeCartas;
class Posicion;

class Juego
{
public:
	Juego(size_t);
	~Juego();
	size_t obtenerCantidadJugadores();
	bool chequearVictoria(std::vector<Jugador *>);
	//recive un puntero al tablero en el cual se juega, un puntero al mazo
	//de donde seran extraidas las cartas y un puntero al jugador
	//que realiza la jugada.
	bool jugar(Tablero *, std::vector<Jugador *>, MazoDeCartas *, Jugador *);
	void colocarSoldados(Tablero *, Jugador *, size_t);

private:
	size_t cantidadDeJugadores;
};

void atacarCasillero(Tablero *,Jugador *, Posicion);
void moverUnidad(Tablero*, Jugador *);
