#pragma once

#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include "Casillero.h"
#include "Validaciones.h"
#include "bitmap_image.hpp"

class Casillero;

//definimos una estructura simple posicion para el manejo interno
// de la lista como si fuera una matriz. En alto nivel no se tendria
// que notar esta abtraccion.
class Posicion{
    public:
        size_t x;
        size_t y;
        size_t z;
};

class Tablero
{
    private:
        //Se implementa el tablero como una lista
        //tiene un puntero al primer casillero del tablero.
        Casillero *primerCasillero;
        //atributos de dimensiones, dimension total = filas*columnas*niveles
        //los 3 toman valores mayores a 1
        //Las implementaciones consideran 0,0,0 como la fila,columna,nivel=1,1,1
        unsigned int filas;
        unsigned int columnas;

        //niveles indica la altura que tendra nuestro tablero
        unsigned int niveles;
        
        //la dimension del tablero sera D = filas*columnas*niveles;

    public:

    //---------- Constructores y Destructores ----------
    /* Constructor:
    *Pre:
    *Pos: Devuelve un puntero al espacio de memoria en el que se almacena
    *   el primer nodo de la lista. Los nodos ya se encuentran inicializados
    *   al correspondiente valor de proximoCasillero, estado y propiedad.
    *   Se remarca que el casillero (0,0,0) siempre sera tierra(x ahora) 
    */
    Tablero(unsigned int, unsigned int, unsigned int);

    //Destructor: destruye el obtejo trablero que se creo
    ~Tablero();

    //---------- Getters y Setters ----------
    unsigned int obtenerCantidadFilas();
    unsigned int obtenerCantidadColumnas();
    unsigned int obtenerCantidadNiveles();
    unsigned int obtenerDimension();

    Casillero *obtenerCasillero(Posicion posicion);


    //---------- Funcionalidad ----------
    void imprimirTablero();
};

#endif