#include "Casillero.h"


//---------- Constructores ----------
Casillero::Casillero(){
    this->estado = VACIO;
    this->propiedad = 0;
    this->proximoCasillero = NULL;
}

Casillero::Casillero(Estado estado){
    this->proximoCasillero = NULL;
    this->estado = estado;
    this->propiedad = 0;
}

Casillero::Casillero(unsigned int propiedad){
    this->proximoCasillero = NULL;
    this->propiedad = propiedad;
    this->estado = VACIO;
}

Casillero::Casillero(Estado estado, unsigned int propiedad){
    this->proximoCasillero = NULL;
    this->estado = estado;
    this->propiedad = propiedad;
}

//---------- Destructores ----------
Casillero::~Casillero(){
    delete this;
}

//---------- Getters ----------
Estado Casillero::obtenerEstado(){
    return this->estado;
}

unsigned int Casillero::obtenerPropiedad(){
    return this->propiedad;
}

Casillero *Casillero::obtenerProximo(){
    return this->proximoCasillero;
}


//---------- Setters ----------
void Casillero::definirEstado(Estado estado){
    this->estado=estado;
}

void Casillero::definirPropiedad(unsigned int propiedad){
    this->propiedad=propiedad;
}

void Casillero::definirProximo(Casillero *proximoCasillero){
    this->proximoCasillero = proximoCasillero;
}

//---------- Funcionalidad ----------
bool Casillero::existeProximo(){
    if(!this->proximoCasillero){
        return true;
    }
    return false;
}

