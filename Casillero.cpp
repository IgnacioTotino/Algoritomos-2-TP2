#include "Casillero.h"


//---------- Constructores ----------
Casillero::Casillero(){
    this->estado = VACIO;
    this->propietario = NULL;
    this->proximoCasillero = NULL;
    this->ejercito = NINGUNO;
    this->terreno = TIERRA;

}

Casillero::Casillero(Estado estado){
    this->proximoCasillero = NULL;
    this->estado = estado;
    this->ejercito = NINGUNO;
    this->propietario = NULL;
    this->terreno = TIERRA;
}

Casillero::Casillero(Jugador *propietario){
    this->proximoCasillero = NULL;
    this->ejercito = NINGUNO;
    this->propietario = propietario;
    this->estado = VACIO;
    this->terreno = TIERRA;
}

Casillero::Casillero(Estado estado, Jugador *propietario, TipoTerreno terreno){
    this->proximoCasillero = NULL;
    this->ejercito = NINGUNO;
    this->estado = estado;
    this->propietario = propietario;
    this->terreno = terreno;
}

//---------- Destructores ----------
Casillero::~Casillero(){
    delete this;
}

//---------- Getters ----------
Estado Casillero::obtenerEstado(){
    return this->estado;
}

Jugador *Casillero::obtenerPropiedad(){
    return this->propietario;
}

TipoTerreno Casillero::obtenerTerreno(){
    return this->terreno;
}

Casillero *Casillero::obtenerProximo(){
    return this->proximoCasillero;
}

TipoDeEjercito Casillero::obtenerEjercito(){
    return this->ejercito;
}

//---------- Setters ----------
void Casillero::definirEstado(Estado estado){
    this->estado=estado;
}

void Casillero::definirPropiedad(Jugador *propietario){
    this->propietario = propietario;
}

void Casillero::definirProximo(Casillero *proximoCasillero){
    this->proximoCasillero = proximoCasillero;
}

void Casillero::definirTerreno(TipoTerreno terreno){
    this->terreno = terreno;
}

void Casillero::definirEjercito(TipoDeEjercito ejercito){
    this->ejercito = ejercito;
}

//---------- Funcionalidad ----------
bool Casillero::existeProximo(){
    if(this->proximoCasillero){
        return true;
    }
    return false;
}

void Casillero::eliminarEjercito(){
    Jugador *jugadorAtacado = this->obtenerPropiedad();
    switch (this->obtenerEjercito()){
        AVION:
            jugadorAtacado->reducirAviones();
        BARCO:
            jugadorAtacado->reducirBarcos();
        SOLDADO:
            jugadorAtacado->reducirSoldados();
    }
    this->definirEstado(INHABILITADO);
    this->definirPropiedad(NULL);
}

extern void Clear()
{

#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}