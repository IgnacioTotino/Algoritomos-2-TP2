#include "MazoDeCartas.h"
#include<iostream>
using namespace std;
class Carta;

MazoDeCartas::MazoDeCartas(int cantidadCartasMisil, int cantidadCartasAvion, int cantidadCartasBarco, int cantidadCartasBombaNuclear, int cantidadCartasEliminarMazo, int cantidadCartasRevivir) {

	this->mazo = new Cola<Carta*>();

	int cantidadTotalCartas = cantidadCartasMisil + cantidadCartasAvion + cantidadCartasBarco + cantidadCartasBombaNuclear + cantidadCartasEliminarMazo + cantidadCartasRevivir;
	int contadorMisil = 0, contadorAvion = 0, contadorBarco = 0, contadorNuclear = 0, contadorEM =0, contadorR = 0;
	int cantidadCartas = 0;

	while (cantidadCartas < cantidadTotalCartas)
	{
		CartaAJugar cartaAleatoria = this->generarNumero();

		if (cartaAleatoria == MISIL) {
			if (contadorMisil < cantidadCartasMisil) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorMisil++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == CARTAAVION) {
			if (contadorAvion < cantidadCartasAvion) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorAvion++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == CARTABARCO) {
			if (contadorBarco < cantidadCartasBarco) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorBarco++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == INUTILIDAD) {
			if (contadorEM < cantidadCartasEliminarMazo) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorEM++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == REVIVIRSOLDADO) {
			if(contadorR < cantidadCartasRevivir){
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorR++; cantidadCartas++;
			}
		}
		else if (cartaAleatoria == BOMBANUCLEAR) {
			if (contadorNuclear < cantidadCartasBombaNuclear) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorNuclear++, cantidadCartas++;
			}
		}

	}


}

Carta* MazoDeCartas::repartirCarta() {

	return mazo->desacolar();
}

Carta* MazoDeCartas::acolarCarta(Carta* carta) {
	
	mazo->acolar(carta);
	return carta;
}

Cola<Carta*>* MazoDeCartas::getMazoDeCartas() {

	return this->mazo;
}

bool MazoDeCartas::elMazoEstaVacio() {
	
	return this->mazo->estaVacia();
}

CartaAJugar MazoDeCartas::generarNumero() {
	
	int numeroAleatorio = rand() % 6;
	int porcentaje = rand() % 101;   //completar con el tema del segundo sorteo o calcular porcentaje.

	CartaAJugar tipoDeCarta;

	switch (numeroAleatorio)
	{
	case 0:
		if (porcentaje) {
			cout << "Te toco la carta tipo Misil" << endl;
			tipoDeCarta = MISIL;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 1:
		if (porcentaje) {
			cout << "Te toco la carta tipo Avion" << endl;
			tipoDeCarta = CARTAAVION;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 2:
		if (porcentaje) {
			cout << "Te toco la carta tipo Barco" << endl;
			tipoDeCarta = CARTABARCO;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 3:
		if (porcentaje) {
			cout << "Te toco la carta tipo Eliminar mazo del jugador contrario" << endl;
			tipoDeCarta = INUTILIDAD;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 4:
		if (porcentaje) {
			cout << "Te toco la carta tipo ..." << endl;
			tipoDeCarta = REVIVIRSOLDADO;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 5:
		if(porcentaje < 98) {
			cout << "Te toco la carta tipo Bomba Nuclear" << endl;
			tipoDeCarta = BOMBANUCLEAR;
		}
		else {
		cout << "No te toco una carta este turno" << endl;
		}
		break;

	default:
		cout << "ocurrio un error" << endl;
		break;
	}
	return tipoDeCarta;
}

MazoDeCartas::~MazoDeCartas() {
	delete mazo;
}