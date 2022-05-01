#include "Casillero.h"

Casillero::Casillero(){
    this = new Casillero;
    this->proximoCasillero = NULL;
    return this;
}

Casillero::Casillero(Estado estado){
    this = new Casillero;
    this->proximoCasillero = NULL;
    this->estado = estado;
}

Casillero::Casillero(unsigned int propiedad){
    this = new Casillero;
    this->proximoCasillero = NULL;
    this->propiedad = propiedad;
}

Casillero::Casillero(Estado estado, unsigned int propiedad){
    this = new Casillero;
    this->proximoCasillero = NULL;
    this->estado = estado;
    this->propiedad = propiedad;
}

Casillero::~Casillero(){
    delete this->casillero;
}

Estado Casillero::obtenerEstado(){
    return this->estado;
}
Casillero::Casillero(Estado estado, unsigned int propiedad){
    this = new Casillero;
    this->proximoCasillero = NULL;
    this->estado = estado;
    this->propiedad = propiedad;
}

Casillero::~Casillero(){
    delete this->casillero;
}

Estado Casillero::obtenerEstado(){
    return this->estado;
}

unsigned int Casillero::obtenerPropiedad(){
    return this->propiedad;
}

void Casillero::definirEstado(Estado estado){
    this->estado=estado;
}

void Casillero::definirPropie(unsigned int propiedad){
    this->propiedad=propiedad;
}

Casillero::~Casillero(){
    delete this->casillero;
}

Estado Casillero::obtenerEstado(){
    return this->estado;
}

unsigned int Casillero::obtenerPropiedad(){
    return this->propiedad;
}

void Casillero::definirEstado(Estado estado){
    this->estado=estado;
}

void Casillero::definirPropie(unsigned int propiedad){
    this->propiedad=propiedad;
}

void Casillero::definirProximo(Casillero *proximoCasillero){
    this->proximoCasillero = proximoCasillero;
}

