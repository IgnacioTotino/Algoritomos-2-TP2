#include "Juego.h"

Juego::Juego(size_t cantidadDeJugadores){
    this->cantidadDeJugadores = cantidadDeJugadores;
}

Juego::~Juego(){

}

size_t Juego::obtenerCantidadJugadores(){
    return this->cantidadDeJugadores;
}

void atacarCasillero(Tablero* tablero, Jugador* jugador, Posicion posicion){
    if(!posicionValida(tablero,posicion)){
        throw("La posicion ingresada es invalida");
    }
    Casillero *casilleroAtacado = tablero->obtenerCasillero(posicion);
    if(casilleroAtacado->obtenerPropiedad() == jugador){
        throw("El casillero le pertenece, no puede atacarlo");
    }
    if(casilleroAtacado->obtenerEstado() == OCUPADO){
        casilleroAtacado->eliminarEjercito();
    }
}

bool Juego::chequearVictoria(size_t i){
    return false;
}

bool Juego::jugar(Tablero *tablero, MazoDeCartas *mazo, Jugador *jugador){
    Carta *cartaObtenida;
    Posicion posicion;
    Posicion posicionOrigen;
    Posicion posicionDestino;
    bool moverUnSoldado;

    //comienza el turno retirando una carta
    std::cout<< "jugador "<<jugador->obtenerNombre()<<"es su turno!"<<std::endl;
    cartaObtenida = mazo->repartirCarta();
    Clear();

    //fase de ataque del jugador
    std::cout<<"Decida donde quiere atacar"<<std::endl;
    posicion = jugador->pedirEntradaPosicion(tablero);
    atacarCasillero(tablero, jugador, posicion);
    Clear();
    
    //fase de movimiento del jugador puede optar por mover o no
    std::cout<<"Ahora tiene la posibilidad de mover un soldado, desea hacerlo? (NO=0, SI=1)"<<std::endl;
    if(moverUnSoldado){
        std::cout<<"Ingrese las posiciones del soldado que desea mover:";
        posicionOrigen = jugador->pedirEntradaPosicion(tablero, "Ingrese la posicion 'x','y','z' del soldado que desea mover.");
        posicionDestino = jugador->pedirEntradaPosicion(tablero, "Ingrese la posicion 'x','y','z' donde desea mover el soldado.");
        moverSoldado(tablero, jugador, posicionOrigen, posicionDestino);
    }
    Clear();

    //fase de jugar la carta
    std::cout <<"Momento de jugar su carta!"<<std::endl;
    cartaObtenida->ejecutarFuncion();
    Clear();

    if(this->chequearVictoria(this->cantidadDeJugadores)){
        return false;
    }
    return true;
}
bool moverSoldado(Tablero *tablero, Jugador *jugador, Posicion posicionOrigen, Posicion PosicionDestino){
    return true;
}

