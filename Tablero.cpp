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
    for(int z=0; z<niveles; z++){
        for(int y=0; y<filas; y++){
            for(int x=0; x<columnas; x++){
            while(actual->existeProximo()){
                actual = actual->obtenerProximo();
            }
            TipoTerreno nuevoTerreno=AIRE;
            if(z<1){
                nuevoTerreno=TipoTerreno(rand()%2);
            }
            aux = new Casillero(VACIO,0,nuevoTerreno);
            actual->definirProximo(aux);
            }
        }
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
    //iteramos un nivel entero
    for(int z=1; z<posicion.z;z++){
        for(int i=0; i<filas*columnas; i++){
            obtenido = obtenido->obtenerProximo();
        }
    }
    //aca nos aseguramos de estar en el nivel correcto
    //iteramos en filas
    for(int y=1; y<posicion.y; y++){
        for(int i=0; i<columnas; i++){
            obtenido = obtenido->obtenerProximo();
        }
    }
    for(int x=1; x<=posicion.x; x++){
        obtenido=obtenido->obtenerProximo();
    }
    //nos falta iterar en las columnas
    return obtenido;
}

//---------- Funcionalidad ----------

//hacemos que cada casillero sea de 50x50

void dibujarEjercito(bitmap_image &imagen, Casillero *casillero, int x0, int y0){
    image_drawer draw(imagen);
    draw.pen_width(2);

    switch(casillero->obtenerEjercito()){
        case SOLDADO:
            for(int r=0; r<5; r++){
                draw.circle(x0+25,y0+10,r);
            }
            draw.pen_width(2);
            draw.line_segment(x0+25,y0+10,x0+25,y0+30);
            draw.line_segment(x0+25,y0+30,x0+15,y0+40);
            draw.line_segment(x0+25,y0+30,x0+35,y0+40);
            draw.horiztonal_line_segment(x0+20,x0+30,y0+25);
            break;
        case AVION:
            for(int x=10; x>0; x--){
                draw.rectangle(x0+25-x,y0+20+x,x0+25+x,y0+20+x);
            }
            draw.vertical_line_segment(y0+10,y0+40,x0+25);
            break;
        case BARCO:
            for(int i=0; i<=50; i++){
                draw.rectangle(x0+10,y0+35,x0+40-i,y0+50-i);
            }
            draw.vertical_line_segment(y0+35,y0+25,x0+25);
            break;
        case NINGUNO:
            break;
    }

}

void imprimirCasillero(bitmap_image &imagen, Casillero *casillero, int x0, int y0, int color[][3]){
    image_drawer draw(imagen);
    switch (casillero->obtenerTerreno()){
        case TIERRA:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(color[0][0],color[0][1],color[0][2]);
            }else{
                draw.pen_color(color[1][0],color[1][1],color[1][2]);
                for(int i=0; i<=50; i++){
                    draw.rectangle(x0,y0,x0+50-i,y0+50-i);
                }
                dibujarEjercito(imagen,casillero,x0,y0);
            }
            break;

        case AGUA:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(color[0][0],color[0][1],color[0][2]);
            }else{
                draw.pen_color(color[2][0],color[2][1],color[2][2]);
                for(int i=0; i<=50; i++){
                    draw.rectangle(x0,y0,x0+50-i,y0+50-i);
                    }
                draw.pen_color(color[3][0],color[3][1],color[3][2]);
                draw.pen_color(0,0,100);
                for(int r=0; r<20; r++){
                    draw.circle(x0+25,y0+25,r);
                }
                dibujarEjercito(imagen,casillero,x0,y0);
            }
            break;


        case AIRE:
            if(casillero->obtenerEstado() == INHABILITADO){
                draw.pen_color(color[0][0],color[0][1],color[0][2]);
            }else{
                for(int i=0; i<=50; i++){
                    draw.pen_color(color[4][0]-i,color[4][1]-i,color[4][2]-i);
                    draw.rectangle(x0,y0,x0+50-i,y0+50-i);
                }
                dibujarEjercito(imagen,casillero,x0,y0);
            }
            break;
    }
}

void imprimirEspacio(bitmap_image &imagen, int x0, int &y0, int color[3]){
    image_drawer draw(imagen);
    draw.pen_width(2);
    draw.pen_color(color[0],color[1],color[2]);
    int lim = y0+10;
    for(int i=y0; i<lim; i++, y0++){
        draw.horiztonal_line_segment(0,x0,i);
    }
}

void imprimirRectangulo(bitmap_image &imagen,int x0, int y0, int color[][3]){
    image_drawer draw(imagen);
    for(int i=0; i<=50; i++){
        draw.pen_color(color[i][0],color[i][1],color[i][2]);
        draw.rectangle(x0,y0,x0+50-i,y0+50-i);
    }

}

void Tablero::imprimirTablero(){

    Posicion posicion;
    Casillero *casilleroAux;

    int niveles = this->obtenerCantidadNiveles();
    int filas = this->obtenerCantidadFilas();
    int columnas = this->obtenerCantidadColumnas();

    bitmap_image image(50*columnas,50*filas*niveles);
    image.set_all_channels(255,255,255);

    int pasoColumna = 50;
    int pasoFilas = 50;
    int x0 = 0;
    int y0 = 0;
    
    int color[5][3]={{255,0,0},{96,60,20},{0,90,0},{0,0,255},{203,203,203}};
    int negro[3] = {0,0,0};
    for(int z=1; z<=niveles; z++){
        imprimirEspacio(image,50*columnas,y0,negro);
        for(int y=1; y<=filas; y++,y0+=pasoFilas,x0=0){
            for(int x=1; x<=filas; x++,x0+=pasoFilas){
                posicion.x = x;
                posicion.y = y;
                posicion.z = z;
                casilleroAux = this->obtenerCasillero(posicion);
                    imprimirCasillero(image,casilleroAux,x0,y0,color);
                    //imprimirRectangulo(image,x0, y0, color);
           }
        }
    }
    
    image.save_image("imagenTablero.bmp");
    std::cout<<"Se imprimio el Tablero, ver imagenTablero.bmp"<<std::endl;
}