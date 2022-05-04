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
        //dimension del tablero es de filas x columnas.
        //filas y columnas no pueden tomar valor 0.
        unsigned int filas;
        unsigned int columnas;

    public:

    //---------- Constructores y Destructores ----------
    Tablero(unsigned int, unsigned int);
    ~Tablero();

    //---------- Getters y Setters ----------
    unsigned int obtenerCantidadFilas();
    unsigned int obtenerCantidadColumnas();
    unsigned int obtenerDimension();
    Casillero *obtenerCasillero();

    //---------- Funcionalidad ----------
    bool modificarCasillero(usngined int, unsigned int);
    bool chequearPropiedadCasillero(unsigned int, unsigned int, unsigned int);
    bool atacarCasillero(unsigned int, unsigned int);
};

#endif