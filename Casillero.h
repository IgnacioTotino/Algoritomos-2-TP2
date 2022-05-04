#pragma once

#ifndef CASILLERO_
#define CASILLERO_

//definimos los posibles estados en los que puede encontrarse un casillero
typedef enum{
	VACIO,
	OCUPADO,
	INHABILITADO,
}Estado;

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
	Casillero(unsigned int);
	Casillero(Estado, unsigned int);
	~Casillero();

	//---------- geters -----------
	//devuelve el estado en el que se encuentra el casillero;
	Estado obtenerEstado();
	unsigned int obtenerPropiedad();
	Casillero *obtenerProximo();

	//---------- Setters -----------
	void definirEstado(Estado);
	void definirPropiedad(unsigned int);
	void definirProximo(Casillero *);

	//---------- Funcionalidad -----------
	bool existeProximo();
private:
	//cada casillero tiene un puntero al proximo casillero o NULL si es el ultimo
	Casillero *proximoCasillero;
	//estado indica en que estado se encuentra el casillero
	Estado estado;
	//propiedad indica a quien le pertenece el casillero
	//coincide con el id del jugador o 0 si no le pertenece a nadie.
	unsigned int propiedad;
}; 

#endif