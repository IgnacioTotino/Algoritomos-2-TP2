// TP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include "Tablero.h"
#include "Juego.h"
#include "Jugador.h"

int main()
{
    Tablero *tablero;
    vector<Jugador *> Jugadores;
    
    size_t cantidadDeJugadores;
    size_t cantidadDeSoldados;
    unsigned int filas, columnas, niveles;

    std::cout<<"---------!!! COMIENZA EL JUEGO !!!----------" <<std::endl<<std::endl;

    //pedimos ingreso de la cantidad de jugadores N
    std::cout<<"Ingrese la cantidad de jugadores que participaran:";
    std::cin>>cantidadDeJugadores;
    Clear();

    //pedimos el ingreso de la cantidad de soldados que cada jugador tendra M
    std::cout<<"Ingrese la cantidad de soldados de los que dispondra cada jugador:";
    std::cin>>cantidadDeSoldados;
    Clear();

    //pedimos el ingreso de las dimensiones del tablero
    std::cout<<"Seleccione las dimensiones del tablero"<<std::endl;
    std::cout<<"Cantidad de filas (x):";
    std::cin>>filas;
    std::cout<<"Cantidad de columnas (y):";
    std::cin>>columnas;
    std::cout<<"Cantidad de niveles:";
    std::cin>>niveles;
    Clear();
    std::cout<<std::endl<<"OK! creando las estructuras correspondientes"<<std::endl<<std::endl;

    //creamos y inicializamos los objetos correspondientes;
    tablero = new Tablero(filas,columnas,niveles);
    //usamos el tipo de dato vector para almacenar los punteros a los jugadores...
    //quiza es dificil de ver/entender pero tiene sentido sino se complica
    for(size_t i=0; i < cantidadDeJugadores; i++){
        (jugadores+i) = new Jugador(i,cantidadDeSoldados);
    }
    std::cout<<"Estructuras creadas! procedemos a jugar"<<std::endl;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
