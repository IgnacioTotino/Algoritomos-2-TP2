#include "bitmap_image.hpp"

typedef struct{
    float r,g,b;
}Color;

void dibujarSoldado(bitmap_image &imagen, int x0, int y0, int x, int y){
    int cx = x0+(x-x0)/2;
    int cy = y0 +(y-y0)/2;
    image_drawer draw(imagen);
    draw.rectangle(x0,y0,x,y);
    for(int i=5; i!= 0; i--){
        draw.pen_color(0,0,0);
        draw.pen_width(2);
        draw.circle(cx,cy-cy/2,i);
    }
    draw.line_segment(cx,cy-cy/2,cx,cy+cy/5);
    draw.line_segment(cx,cy+cy/5,cx-cx/5,cy+cy/2);
    draw.line_segment(cx,cy+cy/5,cx+cx/5,cy+cy/2);
    draw.line_segment(cx-cx/5,cy,cx+cx/5,cy); 
}

void dibujarAvion(bitmap_image &imagen,int x0, int y0, int x, int y, int *color){
    image_drawer draw(imagen);
    int width = x0+(x-x0)/2;
    int heigh = y0+(y-y0)/2;
    draw.rectangle(x0,y0,x,y);
    //draw.triangle(width/2,heigh/2-heigh/3,width/2,heigh/2,width/2-width/3,heigh/2);
}
void dibujarBarco(bitmap_image &imagen, int width, int heigh, int *color){
    image_drawer draw(imagen);
    draw.pen_color(0,0,0);
    for(int x=0.1*width,y=0.8*heigh; y>0.6*heigh; x+=2,y--){
        draw.line_segment(width/2-x,y,width/2+x,y);
    }
    for(int x=0.4*width; x<0.6*width; x++){
        draw.line_segment(x,0.5*heigh,x,0.8*heigh);
    }
    draw.line_segment(0.6*width,0.4*heigh,0.6*width,0.6*heigh);
    for(int y=0.3*heigh; y<0.4*heigh; y++){
        draw.line_segment(0.6*width,y,0.7*width,y);
    }
}

void pintarInhabilitado(bitmap_image &imagen, int x0, int y0, int x, int y){
    image_drawer draw(imagen);
    draw.pen_color(255,0,0);
    for(int i=x0; i<x; i++){
        draw.line_segment(i,y0,i,y);
    }
}
void pintarTierra(bitmap_image &imagen, int x0, int y0, int x, int y){
    image_drawer draw(imagen);
    draw.pen_color(50,50,0);
    for(int i=x0; i<x; i++){
        draw.line_segment(i,y0,i,y);
    }
}
void pintarAgua(bitmap_image &imagen, int x0, int y0, int x, int y){
    image_drawer draw(imagen);
    draw.pen_color(0,0,200);
    for(int i=x0; i<x; i++){
        draw.line_segment(i,y0,i,y);
    }
    draw.pen_color(0,200,0);
    draw.rectangle(x0,y0,x,y);
}
void pintarCielo(bitmap_image &imagen, int x0, int y0, int x, int y){
    image_drawer draw(imagen);
    draw.pen_color(200,200,200);
    for(int i=x0; i<x; i++){
        draw.line_segment(i,y0,i,y);
    }
}


void pintarNivel(bitmap_image &imagen,int filas, int columnas, int x0, int y0, int x, int y){
   image_drawer draw(imagen);
    int color[3]={255,255,255};
    for(int i=x0; i<x ; i+=(x-x0)/filas){
        for(int j=y0; j<y; j+=(y-y0)/columnas){
            pintarAgua(imagen,i,j,i+(x-x0)/filas,j+(y-y0)/filas);
            dibujarSoldado(imagen,i,j,i+(x-x0)/filas,j+(y-y0)/columnas);
        }
    }
}
int main()
{

    bitmap_image soldado(51,51);
    soldado.set_all_channels(255,255,255);
    int color[3]={255,255,255};
    //dibujarAvion(soldado,10,10,50,50,color);
    //dibujarBarco(soldado, 50,50,color);
    pintarNivel(soldado,3,3,0,0,50,50);


    soldado.save_image("output.bmp");
    return 0;
}