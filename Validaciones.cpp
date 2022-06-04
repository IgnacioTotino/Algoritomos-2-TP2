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

bool movimientoValido(Posicion posicionOrigen, Posicion posicionDestino){
    //si las coordenadas son validas entonces tendran el mismo modulo en las
    //componentes que sean distintas de cero.
    Posicion distancia;
    distancia.x = abs(posicionDestino.x - posicionOrigen.x);
    distancia.y = abs(posicionDestino.y - posicionOrigen.y);
    distancia.z = abs(posicionDestino.z - posicionOrigen.z);
    size_t aux[3] = {distancia.x, distancia.y, distancia.z};
    
    if(aux[0]==0){

    }else if(aux[2]==0){

    }
    //no se me ocurrio algo mas bonito y bueno preferible que funcione


    if(aux[0]==0){ //si x=0
        if(aux[1]==0){ //si y=0
            if(aux[2]==0){ //si z=0
                throw("Coordenanas incorrectas(distancia 0)");
                return false;
            } 
            return true; //x=0,y=0,z!=0;
            //se mueve en un unico eje siempre sera valido;

        }else{ //cuando x=0, y!=0
            return aux[1]==aux[2]; //devuelvo resultado de y=z;
        }

    }else{ //si x != 0
        if(aux[1] == 0){ //si y=0
            if(aux[2] == 0){ // si z=0
                return true; // x!=0, y=0, z=0 se mueve en un unico eje
            }
            return aux[0] == aux[2];// x!=0, y!=0, z=0
        }
        //aca tenemos x,y,z != 0
        if(aux[0]==aux[1]){ //si x=y devuelvo resultado de z=x
            return aux[0]==aux[2];
        }else{
            return false; //vemos que x != y no puede ser valido
        };
    }

}