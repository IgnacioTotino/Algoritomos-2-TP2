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

bool Juego::chequearVictoria(std::vector<Jugador *> jugadores){
    bool jugadorVivo = false;
    size_t cantidadDeSoldados;
    size_t dimension = jugadores.size();//cantidad de elementos
    for(size_t i=0; i<dimension; i++){
        cantidadDeSoldados = jugadores[i]->obtenerCantidadDeSoldados();
        if(cantidadDeSoldados > 0){ //el jugador todavia continua en juego
            if(jugadorVivo != true){ //si esta en true entonces es el primer jugador
                jugadorVivo = true; //por ser el primero seteamos la flag, hay 1 vivo
            }
            else{ //en este punto hay otro jugador con mas de un soldado en el tablero
                return false; //devuelvo false y el juego continua
            }
        }
    }
    if(jugadorVivo == false){
        throw("No queda ningun soldado en el tablero");
    }
    std::cout<<"SE TERMINO EL JUEGO!!!";
    return true; //en este caso hay un unico jugador con soldados
}

void Juego::colocarSoldados(Tablero *tablero, Jugador *jugador, size_t cantidadDeSoldados){
    Posicion posicion;
    Casillero *casillero;
    for(size_t i=0; i<cantidadDeSoldados; i++){
        std::cout<<"Soldado numero "<< i+1 << ":"<<std::endl;
        posicion = jugador->pedirEntradaPosicion(tablero, "ingrese la posicion de su soldado:");
        casillero = tablero->obtenerCasillero(posicion);
        if(casillero->obtenerEstado() != OCUPADO){ //es el primer turno no va a haber inhabilitados
            casillero->definirEstado(OCUPADO);
            casillero->definirPropiedad(jugador);
            casillero->definirEjercito(SOLDADO);
        }else{
            throw("Posicion ingresada invalida");
            i--;
        }
    }       
}

bool Juego::jugar(Tablero *tablero,std::vector<Jugador *> jugadores, /*MazoDeCartas *mazo,*/ Jugador *jugador){
    if(jugador->obtenerCantidadDeSoldados() == 0){
        std::cout<<"!!!!!el jugador "<< jugador->obtenerNombre()<<" ya perdio!!!!";
        return false;
    }
    Carta *cartaObtenida;
    Posicion posicion;
    Posicion posicionOrigen;
    Posicion posicionDestino;
    bool moverUnSoldado;

    //comienza el turno retirando una carta
    std::cout<< "jugador "<<jugador->obtenerNombre()<<"es su turno! (PARTE DE CARTA COMENTADA)"<<std::endl;
    //cartaObtenida = mazo->repartirCarta();
    Clear();

    //fase de ataque del jugador
    std::cout<<jugador->obtenerNombre()<<" Decida donde quiere atacar"<<std::endl;
    posicion = jugador->pedirEntradaPosicion(tablero);
    atacarCasillero(tablero, jugador, posicion);
    Clear();
    
    //fase de movimiento del jugador puede optar por mover o no
    std::cout<<"Ahora tiene la posibilidad de mover un soldado, desea hacerlo? (NO=0, SI=1)"<<std::endl;
    std::cin>>moverUnSoldado;
    if(moverUnSoldado){
        moverUnidad(tablero, jugador);
    }
    Clear();

    //fase de jugar la carta
    std::cout <<"Momento de jugar su carta!(PARTE DE CARTA COMENTADA)"<<std::endl;
    //cartaObtenida->ejecutarFuncion();
    Clear();

    return this->chequearVictoria(jugadores);
}

void moverUnidad(Tablero *tablero, Jugador *jugador){
    std::cout << "Comienza movimiento de soldado"<<std::endl;
    Posicion posicionOrigen, posicionDestino;
    posicionOrigen = jugador->pedirEntradaPosicion(tablero, "Ingrese la posicion del soldado que desea mover:");
    if(!posicionValida(tablero, posicionOrigen)){
        throw ("Coordenada origen invalida(1)");
    } 
    std::cout<<std::endl;
    posicionDestino = jugador->pedirEntradaPosicion(tablero, "ingrese la posicion de la casilla donde desea mover el soldado:");
    if(!posicionValida(tablero, posicionDestino)){
        throw("Coordenada destino invalida(1)");
    }
    //ahora las posiciones ingresadas minimanete se encuentran en el talbero
    //agregamos las condiciones en las que no se podria mover el soldado
    Casillero *casilleroOrigen = tablero->obtenerCasillero(posicionOrigen);
    Casillero *casilleroDestion = tablero->obtenerCasillero(posicionDestino);
    if( //comencemos por condiciones a cumplir del casillero origen
        casilleroOrigen->obtenerEstado() == INHABILITADO || //no puede estar inhabilitado
        casilleroOrigen->obtenerPropiedad() != jugador //no puede no ser del jugador
    ){
        throw ("coordenada origen invalida(2)");

    }
    if(
        casilleroDestion->obtenerEstado() == INHABILITADO
    ){
        throw("coordenada destino invalida(2)");
    }
    if(movimientoValido(posicionOrigen, posicionDestino)){
        if(casilleroDestion->obtenerEstado() == VACIO){
            casilleroDestion->definirEjercito(casilleroOrigen->obtenerEjercito());
            casilleroDestion->definirEstado(OCUPADO);
            casilleroDestion->definirPropiedad(jugador);

            casilleroOrigen->definirEjercito(NINGUNO);
            casilleroOrigen->definirEstado(VACIO);
            casilleroOrigen->definirPropiedad(NULL);
        }
        else{
            atacarCasillero(tablero, jugador, posicionDestino);
            atacarCasillero(tablero, casilleroDestion->obtenerPropiedad(), posicionOrigen);
        }
    }    
}

