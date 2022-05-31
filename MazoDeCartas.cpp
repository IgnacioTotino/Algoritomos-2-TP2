#include "MazoDeCartas.h"
#include<iostream>
using namespace std;

MazoDeCartas::MazoDeCartas(int cantidadCartasMisil, int cantidadCartasAvion, int cantidadCartasBarco, int cantidadCartasBombaNuclear, int cantidadCartasEliminarMazo, int cantidadCartasX) {

	this->mazo = new Cola<Carta*>();

	int cantidadTotalCartas = cantidadCartasMisil + cantidadCartasAvion + cantidadCartasBarco + cantidadCartasBombaNuclear + cantidadCartasEliminarMazo + cantidadCartasX;
	int contadorMisil = 0, contadorAvion = 0, contadorBarco = 0, contadorNuclear = 0, contadorEM =0, contadorX = 0;
	int cantidadCartas = 0;

	while (cantidadCartas < cantidadTotalCartas)
	{
		CartaAJugar cartaAleatoria = this->generarNumero();

		if (cartaAleatoria == misil) {
			if (contadorMisil < cantidadCartasMisil) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorMisil++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == avion) {
			if (contadorAvion < cantidadCartasAvion) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorAvion++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == barco) {
			if (contadorBarco < cantidadCartasBarco) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorBarco++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == eliminarMazoSiguienteJugador) {
			if (contadorEM < cantidadCartasEliminarMazo) {
				this->acolarCarta(new Carta(cartaAleatoria));
				contadorEM++, cantidadCartas++;
			}
		}
		else if (cartaAleatoria == cartaAdefinir1) {
			//completar
		}
		else if (cartaAleatoria == bombaNuclear) {
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
			tipoDeCarta = misil;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 1:
		if (porcentaje) {
			cout << "Te toco la carta tipo Avion" << endl;
			tipoDeCarta = avion;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 2:
		if (porcentaje) {
			cout << "Te toco la carta tipo Barco" << endl;
			tipoDeCarta = barco;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 3:
		if (porcentaje) {
			cout << "Te toco la carta tipo Eliminar mazo del jugador contrario" << endl;
			tipoDeCarta = eliminarMazoSiguienteJugador;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 4:
		if (porcentaje) {
			cout << "Te toco la carta tipo ..." << endl;
			tipoDeCarta = cartaAdefinir1;
		}
		else {
			cout << "No te toco una carta este turno" << endl;
		}
		break;

	case 5:
		if(porcentaje < 98) {
			cout << "Te toco la carta tipo Bomba Nuclear" << endl;
			tipoDeCarta = bombaNuclear;
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