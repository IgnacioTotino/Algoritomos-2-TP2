#include "Tablero.h"


//---------- Constructores ----------
Tablero::Tablero(unsigned int filas, unsigned int columnas, unsigned int niveles){
    this->primerCasillero = new Casillero();
    Casillero *aux = NULL, *actual = NULL;
    this->filas = filas;
    this->columnas = columnas;
    this->niveles = niveles;
    size_t dimensionMatriz = this->obtenerDimension();
    for(size_t i=0; i<dimensionMatriz; i++){
        while(actual->existeProximo()){
            actual = actual->obtenerProximo();
        }
        aux = new Casillero();
        actual->definirProximo(aux);
    }
}

//---------- Destructores ----------
Tablero::~Tablero(){
    Casillero *aux = NULL, *actual = this->primerCasillero;
    while(actual->existeProximo()){
        aux = actual->obtenerProximo();
        delete actual;
        actual = aux->obtenerProximo();
    }
    delete actual;
}

//---------- Getters ----------
unsigned int Tablero::obtenerCantidadFilas(){
    return this->filas;
}

unsigned int Tablero::obtenerCantidadColumnas(){
    return this->columnas;
}

unsigned int Tablero::obtenerCantidadNiveles(){
    return this->niveles;
}

unsigned int Tablero::obtenerDimension(){
    unsigned int filas = this->obtenerCantidadFilas();
    unsigned int columnas = this->obtenerCantidadColumnas();
    unsigned int niveles = this->obtenerCantidadNiveles();
    return filas*columnas*niveles;
}

Casillero *Tablero::obtenerCasillero(unsigned int fila, unsigned int columna){
    if(!this->primerCasillero){
        std::cout<<"El tablero se encuentra vacio."<<std::endl;
        return NULL;
    }

    Casillero *obtenido = this->primerCasillero;
    for(size_t i=0; i<fila-1; i++){
        for(size_t j=0; j<columna-1; j++){
            for(size_t k=0; k<niveles-1; k++){
                obtenido = obtenido->obtenerProximo();
            }
        }
    }
    return obtenido;
}
