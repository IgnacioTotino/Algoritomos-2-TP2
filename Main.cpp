// TP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include "Tablero.h"
#include "Juego.h"
#include "Jugador.h"

class Tablero;
class Jugador;

using namespace std;

int main()
{
    Tablero *tablero;
    vector<Jugador *> jugadores;
    
    size_t cantidadDeJugadores;
    size_t cantidadDeSoldados;
    unsigned int filas, columnas, niveles;

    cout<<"---------!!! COMIENZA EL JUEGO !!!----------" <<endl<<endl;

    MazoDeCartas *mazo = new MazoDeCartas(1,1,1,1,1,1);
    
    //pedimos ingreso de la cantidad de jugadores N
    cout<<"Ingrese la cantidad de jugadores que participaran:";
    cin>>cantidadDeJugadores;
    Clear();

    //pedimos el ingreso de la cantidad de soldados que cada jugador tendra M
    cout<<"Ingrese la cantidad de soldados de los que dispondra cada jugador:";
    cin>>cantidadDeSoldados;
    Clear();

    //pedimos el ingreso de las dimensiones del tablero
    cout<<"Seleccione las dimensiones del tablero"<<endl;
    cout<<"Cantidad de filas (x):";
    cin>>filas;
    cout<<"Cantidad de columnas (y):";
    cin>>columnas;
    cout<<"Cantidad de niveles:";
    cin>>niveles;
    Clear();
    cout<<endl<<"OK! creando las estructuras correspondientes"<<endl<<endl;

    //creamos el juego
    Juego *juego = new Juego(cantidadDeJugadores);
    //creamos y inicializamos los objetos correspondientes;
    tablero = new Tablero(filas,columnas,niveles);
    //usamos el tipo de dato vector para almacenar los punteros a los jugadores...
    //quiza es dificil de ver/entender pero tiene sentido sino se complica
    //creamos estructura auxiliar para el puntero del jugador creado
    Jugador *jugadorAux;
    for(size_t i=0; i < cantidadDeJugadores; i++){
        jugadorAux = new Jugador(i,cantidadDeSoldados);
        jugadores.push_back(jugadorAux);
        try{
            juego->colocarSoldados(tablero,jugadorAux,cantidadDeSoldados);
        }catch (...){
            std::cout<<"error cargue nuevamente la posicion del soldado"<<std::endl;
            juego->colocarSoldados(tablero,jugadorAux,cantidadDeSoldados);
        }
     }
    std::cout<<"Estructuras creadas! procedemos a jugar"<<std::endl;
    tablero->imprimirTablero();
    size_t contadorDeTurnos=0;

    while(!juego->jugar(tablero,jugadores,mazo,jugadores[contadorDeTurnos])){
        contadorDeTurnos++;
        if(contadorDeTurnos == cantidadDeJugadores){
            contadorDeTurnos = 0;
        }
    };

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
