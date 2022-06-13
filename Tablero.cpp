#include "Tablero.h"

//---------- Constructores ----------
Tablero::Tablero(unsigned int filas, unsigned int columnas, unsigned int niveles){
    if(!dimensionesValidas(filas,columnas,niveles)){
        throw("alguna de las dimensiones es invalida");
    }
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
    this->primerCasillero = new Casillero(VACIO, 0, TipoTerreno(rand()%2));
    actual = this->primerCasillero;

 
    //construimos el resto de los casilleros para la lista y los inicializamos
    for(size_t i=1; i<dimensionMatriz; i++){
        while(actual->existeProximo()){
            actual = actual->obtenerProximo();
        }
        TipoTerreno nuevoTerreno=AIRE;
        if(i<= filas*columnas){
            nuevoTerreno=TipoTerreno(rand()%2);
        }
        aux = new Casillero(VACIO,0,nuevoTerreno);
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

Casillero *Tablero::obtenerCasillero(Posicion posicion){
    if(!posicionValida(this, posicion)){
        throw("posicion invalida");
    }
    if(!this->primerCasillero){
        std::cout<<"El tablero se encuentra vacio."<<std::endl;
        return NULL;
    }

    Casillero *obtenido = this->primerCasillero;
    for(size_t i=0; i<posicion.z; i++){
        for(size_t j=0; j<posicion.y; j++){
            for(size_t k=0; k<posicion.x; k++){
                obtenido = obtenido->obtenerProximo();
            }
        }
    }
    return obtenido;
}

//---------- Funcionalidad ----------

//hacemos que cada casillero sea de 50x50

void dibujarEjercito(bitmap_image &imagen, Casillero *casillero, int x0, int y0){
    image_drawer draw(imagen);

    switch(casillero->obtenerEjercito()){
        case SOLDADO:
            for(int r=0; r<10; r++){
                draw.circle(x0+25,y0+10,r);
            }
            draw.pen_width(2);
            draw.line_segment(x0+25,y0+10,x0+25,y0+20);
            draw.line_segment(x0+25,y0+20,x0+15,y0+40);
            draw.line_segment(x0+25,y0+20,x0+35,y0+40);
        case AVION:
            for(int x=30; x>0; x--){
                draw.rectangle(x0+25-x,y0+10+x,x0+25+x,y0+10+x);
            }
        case BARCO:
            for(int x=30; x>0; x--){
                draw.rectangle(x0+25-x,y0+50+x,x0+25+x,y0+50+x);
            } 
        case NINGUNO:
            break;
    }

}

void imprimirCasillero(bitmap_image &imagen, Casillero *casillero, int x0, int y0){
    image_drawer draw(imagen);
    switch (casillero->obtenerTerreno()){
        case TIERRA:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(255,0,0);
            }else{
                draw.pen_color(130,90,44);
            }
            for(int y=0; y<50; y++){
                for(int x=0; x<50; x++){
                    draw.rectangle(x0,y0,x0+50-x,y0+50-y);
                }
            }
        case AGUA:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(255,0,0);
            }else{
                draw.pen_color(5,100,0);
                for(int y=0; y<50; y++){
                    for(int x=0; x<50; x++){
                        draw.rectangle(x0,y0,x0+50-x,y0+50-y);
                    }
                }
                for(int r=0; r<40; r++){
                    draw.circle(x0+25,y0+25,r);
                }
            }
            for(int y=0; y<50; y++){
                for(int x=0; x<50; x++){
                    draw.rectangle(x0,y0,x0+50-x,y0+50-y);
                }
            }


        case AIRE:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(255,0,0);
            }else{
                draw.pen_color(238, 238, 238);
            }
            for(int y=0; y<50; y++){
                for(int x=0; x<50; x++){
                    draw.rectangle(x0,y0,x0+50-x,y0+50-y);
                }
            }
    }
}

void Tablero::imprimirTablero(){

    Posicion posicion;
    Casillero *casilleroAux;

    int niveles = this->obtenerCantidadNiveles();
    int filas = this->obtenerCantidadFilas();
    int columnas = this->obtenerCantidadColumnas();

    bitmap_image image(50*columnas,50*filas*niveles);
    image_drawer draw(image);

    int pasoColumna = 50;
    int pasoFilas = 50;
    int x0 = 0;
    int y0 = 0;

    for(int z=0; z<niveles; z++){
        x0=0;
        for(int espacio=0; espacio<5; espacio++,y0++){
            draw.horiztonal_line_segment(0,50,y0);
        }
        for(int y=0; y<filas; y++,y0+=pasoFilas){
            for(int x=0; x<columnas; x++,x0+=pasoColumna){
                posicion.x = x;
                posicion.y = y;
                posicion.z = z;
                casilleroAux = this->obtenerCasillero(posicion);
                imprimirCasillero(image,casilleroAux,x0,y0);
            }
        }
    }
    image.save_image("imagenTablero.bmp");
    std::cout<<"Se imprimio el Tablero, ver imagenTablero.bmp"<<std::endl;
}