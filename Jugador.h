#pragma once

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>
#include <string>
#include "Tablero.h"

class Tablero;
class Posicion;

class Jugador 
{
public:
	//--------- Constructores y destructores ---------
	Jugador(unsigned int, size_t);
	~Jugador();

	//--------- Getters ---------
	size_t obtenerCantidadDeSoldados();
	size_t obtenerCantidadDeBarcos();
	size_t obtenerCantidadDeAviones();
	std::string obtenerNombre();
	unsigned int obtenerId();

	//--------- Setters---------
	//la cantidad de soldados que es el unico valor a definir se define
	//en la construccion del jugador, despues solo deberia ser posible
	//cambiar estos valores aumentando o decrementando en 1 la cantidad
	//tampoco tendria que ser posible cambiar el id y el nombre. x eso 
	//no tiene setter.
	void reducirSoldados();
	void aumentarSoldados();
	void reducirAviones();
	void aumentarAviones();
	void reducirBarcos();
	void aumentarBarcos();
	
	//--------- Funcionalidad ---------
	std::string pedirEntradaNombre(unsigned int);
	Posicion pedirEntradaPosicion(Tablero *);
	Posicion pedirEntradaPosicion(Tablero *, std::string);//sobrecarga

private:
	//nombre con el que se identifica el jugador
	std::string nombre;
	//el id asignado nos permite identificarlo dentro del programa
	unsigned int id;
	//la cantidad de soldados que tiene el jugador, comienza con M soldados
	// esa cantidad de M soldados se define en la construccion del juego
	size_t cantidadDeSoldados;
	//asumo como estamos haciendo que los jugadores pueden tener mas de
	//un barco o avion... se considerara que tiene mas de un barco pero
	// se usara uno solo por ejemplo si tiene 4 barcos, al final del turno
	//se ejecutara la accion correspondiente a tener unicamente 1 barco.
	size_t cantidadDeBarcos;
	size_t cantidadDeAviones;
};

#endif