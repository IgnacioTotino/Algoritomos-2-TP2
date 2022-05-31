#pragma once

#ifndef CASILLERO_H_
#define CASILLERO_H_

#include <iostream>
#include "Jugador.h"

class Jugador;

//definimos los posibles estados en los que puede encontrarse un casillero
typedef enum{
	VACIO,
	OCUPADO,
	INHABILITADO,
}Estado;

//definimos los tipos de terreno que pueden existir
typedef enum{
	AGUA,
	TIERRA,
	AIRE,
}TipoTerreno;

typedef enum{
	SOLDADO,
	AVION,
	BARCO,
	NINGUNO,
}TipoDeEjercito;

/* Dado que se pide implementar el tablero con una lista tenemos nuestros
* casilleros que representan la estructura minima de la que se compone
* el tablero. Asociamos esto con la estructura nodo para las listas.
*/
class Casillero
{
public:
	//----------- constructores y destructores -----------
	Casillero();
	Casillero(Estado);
	Casillero(Jugador *);
	Casillero(Estado, Jugador *, TipoTerreno);
	~Casillero();

	//---------- geters -----------
	//no tienen precondiciones se pueden usar siempre
	//devuelve el estado en el que se encuentra el casillero;
	Estado obtenerEstado();

	TipoDeEjercito obtenerEjercito();

	//devuelve el tipo de terreno del casillero;
	TipoTerreno obtenerTerreno();

	//devuelve un puntero al jugador propietario de ese casillero
	//si no es propiedad de nadie devuelve NULL
	Jugador *obtenerPropiedad();

	//devuelve un puntero al proximo casillero
	Casillero *obtenerProximo();

	//---------- Setters -----------
	//Pre:no tiene se tendria que poder usar siempre
	//Pos: define el estado al parametro pasado
	void definirEstado(Estado);

	//Pos: define la propiedad del casillero apuntadolo al jugador
	//	al que le pertenece
	void definirPropiedad(Jugador *jugador);

	//Pos: define el proximo casillero al parametro
	void definirProximo(Casillero *);

	//Pos: define el tipo de terreno del casillero
	void definirTerreno(TipoTerreno);

	void definirEjercito(TipoDeEjercito);

	//---------- Funcionalidad -----------
	bool existeProximo();
	void eliminarEjercito();

private:
	//cada casillero tiene un puntero al proximo casillero o NULL si es el ultimo
	Casillero *proximoCasillero;

	//estado indica en que estado se encuentra el casillero
	Estado estado;

	TipoDeEjercito ejercito;

	//terreno india el tipo de terreno al que corresponde el casillero
	TipoTerreno terreno;

	//cada casillero tiene un puntero al jugador al cual le pertenece
	//si no le pertenece a nadie el casillero se encuentra en NULL
	Jugador *propietario;
}; 

extern void Clear();


#endif