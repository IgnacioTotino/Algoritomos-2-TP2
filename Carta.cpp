#include "Carta.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Carta::Carta(CartaAJugar cartaNueva) {

	this->tipoDeCarta = cartaNueva;

	switch (this->getCarta())
	{
	case CARTAAVION:
		this->descripcionCarta = "Condicion {Necesita estar en el aire}\n Dispara 2 veces mas mientras este en el campo.";
		this->funcionCarta = funcionAvion;
		break;

	case CARTABARCO:
		this->descripcionCarta = "Condicion {Necesita estar en el agua}\n Lanza un misil por cada turno";
		this->funcionCarta = funcionBarco;
		break;

	case MISIL:
		this->descripcionCarta = "Al usarla destrulle 27 casilleros del campo.";
		this->funcionCarta = funcionMisil;
		break;

	case BOMBANUCLEAR:
		this->descripcionCarta = "Al jugar esta carta destruye todo el campo de juego.\n Ganas la partida.";
		this->funcionCarta = funcionBombaNuclear;
		break;

	case INUTILIDAD:
		this->descripcionCarta = "Elimina el mazo del siguiente jugador";
		this->funcionCarta = funcionEliminarTurno;
		break;

	case REVIVIRSOLDADO:
		this->descripcionCarta = "Revive un soldado y puedes posicionarlo donde quieras";
		this->funcionCarta = funcionAvion;
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

void Carta::ejecutarFuncion(Tablero *tablero, Jugador *jugador){
	this->funcionCarta(tablero,jugador);
}
void funcionAvion(Tablero *tablero,Jugador *jugador){
		Posicion posicion;
		Casillero *aux;
		std::cout<<"Le toca posicionar un avion"<<std::endl;
		posicion=jugador->pedirEntradaPosicion(tablero, "Ingrese la posicion del avion:");
		aux = tablero->obtenerCasillero(posicion);
		aux->definirEjercito(AVION);
		aux->definirEstado(OCUPADO);
		aux->definirPropiedad(jugador);
		std::cout<<"Esta es la funcion de avion ataque 2 veces mas"<<std::endl;
		for(int i=0; i<2; i++){
			posicion = jugador->pedirEntradaPosicion(tablero,"Ingrese la posicion que desea atacar:");
			atacarCasillero(tablero, jugador, posicion);
		}
}

void funcionBarco(Tablero *tablero, Jugador *jugador){
		Posicion posicion;
		Casillero *aux;
		std::cout<<"Le toca posicionar un barco"<<std::endl;
		posicion=jugador->pedirEntradaPosicion(tablero, "Ingrese la posicion del barco:");
		aux = tablero->obtenerCasillero(posicion);
		aux->definirEjercito(BARCO);
		aux->definirEstado(OCUPADO);
		aux->definirPropiedad(jugador);
		funcionMisil(tablero,jugador);
}

void funcionMisil(Tablero *tablero, Jugador *jugador){
	Posicion posicion,aux;
	std::cout<<"Le toca posicionar un barco"<<std::endl;
	posicion=jugador->pedirEntradaPosicion(tablero,"ingrese la posicion donde va a tirar el misil:");
	//se necesita que sea una posicion que no este ene l borde del tablero
	for(int z=-1; z<2;z++){
		for(int y=-1; y<2;y++){
			for(int x=-1; x<2; x++){
				aux=posicion;
				aux.x +=x;
				aux.y +=y;
				aux.z +=z;
				atacarCasillero(tablero,jugador,aux);
			}
		}
	}
}

void funcionBombaNuclear(Tablero *tablero, Jugador *jugador){
	std::cout<<"Tirando bomba atomica!!!"<<std::endl;
	Posicion posicion;
	Casillero *aux;
	for(int z=0; z<tablero->obtenerCantidadNiveles(); z++){
		for(int y=0; y<tablero->obtenerCantidadFilas(); y++){
			for(int x=0; x<tablero->obtenerCantidadColumnas();x++){
				posicion.x=x;
				posicion.y=y;
				posicion.z=z;
				atacarCasillero(tablero, jugador,posicion);
			}
		}
	}
}

void funcionRevivi(Tablero *tablero, Jugador *jugador){
	Posicion posicion;
	Casillero *aux;
	std::cout<<"Le toca colocar un soldado:"<<std::endl;
	posicion=jugador->pedirEntradaPosicion(tablero,"ingrese la posicion donde va a colocar el soldado:");
	aux = tablero->obtenerCasillero(posicion);
	aux->definirEjercito(SOLDADO);
	aux->definirEstado(OCUPADO);
	aux->definirPropiedad(jugador);

}

void funcionEliminarTurno(Tablero *tablero,Jugador *jugador){
	std::cout<<"falta implementacion ..."<<std::endl;
}