#pragma once

#include <iostream>
#include "Casillero.h"

#ifndef TABLERO_H_
#define TABLERO_H_

class Tablero
{
    private:
        //Se implementa el tablero como una lista
        //tiene un puntero al primer casillero del tablero.
        Casillero *primerCasillero;

        //atributos para cantidad de filas y columnas
        //filas y columnas no pueden tomar valor 0.
        unsigned int filas;
        unsigned int columnas;

        //niveles indica la altura que tendra nuestro tablero
        unsigned int niveles;
        
        //la dimension del tablero sera D = filas*columnas*niveles;

    public:

    //---------- Constructores y Destructores ----------
    Tablero(unsigned int, unsigned int);
    ~Tablero();

    //---------- Getters y Setters ----------
    unsigned int obtenerCantidadFilas();
    unsigned int obtenerCantidadColumnas();
    unsigned int obtenerCantidadNiveles();
    unsigned int obtenerDimension();
    Casillero *obtenerCasillero();

    //---------- Funcionalidad ----------
    bool modificarCasillero(usngined int, unsigned int, unsigned int);
    bool chequearPropiedadCasillero(unsigned int, unsigned int, unsigned int, unsigned int);
    bool atacarCasillero(unsigned int, unsigned int, unsigned int);
};

#endif