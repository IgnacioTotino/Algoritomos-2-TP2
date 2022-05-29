#include "Jugador.h"

Jugador::Jugador(unsigned int id, size_t cantidadDeSoldados){
    this->nombre = pedirEntradaNombre(id);
    this->id = id;
    this->cantidadDeSoldados = cantidadDeSoldados;
    this->cantidadDeAviones = 0;
    this->cantidadDeBarcos =0;
}

Jugador::~Jugador(){
}

size_t Jugador::obtenerCantidadDeSoldados(){
    return this->cantidadDeSoldados;
}

size_t Jugador::obtenerCantidadDeAviones(){
    return this->cantidadDeAviones;
}

size_t Jugador::obtenerCantidadDeBarcos(){
    return this->cantidadDeBarcos;
}

std::string Jugador::obtenerNombre(){
    return this->nombre;
}

unsigned int Jugador::obtenerId(){
    return this->id;
}

std::string Jugador::pedirEntradaNombre(unsigned int id){
    std::string nombre;
    std::cout<<"ingrese el nombre del jugador "<< id <<":  ";
    std::cin >> nombre;
    return nombre;
}

Posicion Jugador::pedirEntradaPosicion(Tablero *tablero){
    Posicion posicion;
    size_t x,y,z;
    std::cout<< "Ingrese posicion 'x', 'y', 'z':" <<std::endl;

    //entrada posicion x
    std::cout<<"'x':";
    std::cin>>x;
    std::cout<<std::endl;

    //entrada posicion y
    std::cout<<"'y':";
    std::cin>>y;
    std::cout<<std::endl;

    //entrada posicion z
    std::cout<<"'z':";
    std::cin>>z;
    std::cout<<std::endl;

    //convendria hacer funcion de validacion porque se va a usar mucho
    posicion.x=x;
    posicion.y=y;
    posicion.z=z;
    if(!posicionValida(tablero, posicion)){
        throw("la posicion ingresada es invalida");
    }else{
        return posicion;
    }
}

Posicion Jugador::pedirEntradaPosicion(Tablero *tablero, std::string mensaje){
    Posicion posicion;
    size_t x,y,z;
    std::cout<< mensaje <<std::endl;

    //entrada posicion x
    std::cout<<"'x':";
    std::cin>>x;
    std::cout<<std::endl;

    //entrada posicion y
    std::cout<<"'y':";
    std::cin>>y;
    std::cout<<std::endl;

    //entrada posicion z
    std::cout<<"'z':";
    std::cin>>z;
    std::cout<<std::endl;

    //convendria hacer funcion de validacion porque se va a usar mucho
    posicion.x=x;
    posicion.y=y;
    posicion.z=z;
    if(!posicionValida(tablero, posicion)){
        throw("la posicion ingresada es invalida");
    }else{
        return posicion;
    }
}

void Jugador::aumentarSoldados(){
    this->cantidadDeSoldados++;
}

void Jugador::aumentarAviones(){
    this->cantidadDeAviones++;
}

void Jugador::aumentarBarcos(){
    this->cantidadDeBarcos++;
}

void Jugador::reducirSoldados(){
    this->cantidadDeSoldados--;
}

void Jugador::reducirAviones(){
    this->cantidadDeAviones--;
}

void Jugador::reducirBarcos(){
    this->cantidadDeBarcos--;
}
