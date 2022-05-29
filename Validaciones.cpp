#include "Validaciones.h"

bool posicionValida(Tablero *tablero, Posicion posicion){
    if(posicion.x == 0||
        posicion.y == 0||
        posicion.z == 0){
            return false;
        }
    if(tablero->obtenerCantidadFilas() < posicion.x ||
        tablero->obtenerCantidadColumnas() < posicion.y ||
        tablero->obtenerCantidadNiveles() < posicion.z){
            return false;
        }
    return true;
}

bool dimensionesValidas(unsigned int x, unsigned int y, unsigned int z){
    if(x==0 ||
        y==0||
        z==0){
            return false;
        }
    return true;
}