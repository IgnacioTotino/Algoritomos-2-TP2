#include "Tablero.h"


//---------- Constructores ----------
Tablero::Tablero(unsigned int filas, unsigned int columnas, unsigned int niveles){
    //inicializamos los atributos de Tablero
    this->filas = filas;
    this->columnas = columnas;
    this->niveles = niveles;

    //definimos variables auxiliares
    Casillero *aux = NULL, *actual = NULL;
    size_t dimensionMatriz = this->obtenerDimension();
    
    //reservamos memoria para el primer casillero y inicializamos
    //se define que el primer casillero siempre sera tierra
    //el constructor de casillero se encarga de poner el prox a NULL
    this->primerCasillero = new Casillero(VACIO, 0, rand()%2);

 
    //construimos el resto de los casilleros para la lista y los inicializamos
    for(size_t i=1; i<dimensionMatriz; i++){
        while(actual->existeProximo()){
            actual = actual->obtenerProximo();
        }
        Estado nuevoEstado=AIRE;
        if(i<= filas*columnas){
            int random = rand()%2;
            nuevoEstado=random;
        }
        aux = new Casillero(VACIO,0,TIERRA);
        actual->definirProximo(aux);
    }
    return this;
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

<<<<<<< HEAD
Casillero *Tablero::obtenerCasillero(Posicion posicion){
=======
Casillero *Tablero::obtenerCasillero(unsigned int fila, unsigned int columna, unsigned int niveles){
>>>>>>> dev
    if(!this->primerCasillero){
        std::cout<<"El tablero se encuentra vacio."<<std::endl;
        return NULL;
    }

    Casillero *obtenido = this->primerCasillero;
    for(size_t i=0; i<posicion.z; i++){
        for(size_t j=0; posicion.y; j++){
            for(size_t k=0; k<posicion.x; k++){
                obtenido = obtenido->obtenerProximo();
            }
        }
    }
    return obtenido;
}

void Tablero::modificarCasillero(Posicion posicion, Estado estado){
    Casillero *casillero = this->obtenerCasillero(posicion);
    casillero->definirEstado(estado);
}

void Tablero::imprimirTablero(){
    Posicion posicion;
    for(size_t i=1;i<this->niveles,i++){
        posicion.z=i;
        std::cout<<"nivel:  "<<i<<std::endl;
        for(size_t j=1;j<this->columnas; j++){
            posicion.y=j;
            std::cout<<std::endl;
            for(size_t k=1, k<this->filas; k++){
                posicion.x=k;
                Estado estado;
                estado = this->obtenerCasillero(posicion)->obtenerEstado();
            }
        }
    }
}