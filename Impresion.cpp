#include "bitmap_image.hpp"

typedef struct{
    float r,g,b;
}Color;


void imprimirTablero(){
    int ancho=100, alto=100;
    int niveles = 1;
    int columnas = 4;
    int filas = 3;

    bitmap_image image(ancho, alto); 
    // set background to orange
    image.set_all_channels(255,255,255);
    Color color;
    color.r = 200;
    color.b=100;
    color.g=50;
    image_drawer draw(image);
    for(size_t k=0; k<niveles; k++){
        for(size_t j=0; j<filas; j++){
            for(size_t i=0; i<columnas; i++){
                draw.plot_pen_pixel(1,10);
                draw.rectangle(i*ancho/columnas ,j*alto/filas, i*ancho/columnas+ancho/columnas,j*alto/filas+alto/filas);
                for(size_t h=j*alto/filas; h<j*alto/filas+alto/filas; h++){
                    for(size_t w=i*ancho/columnas; w<i*ancho/columnas+ancho/columnas; w++){
                        if(j%2==0 && i%2==0){
                            draw.pen_color(0,100,0);
                            draw.plot_pen_pixel(w,h);
                        }else{
                            draw.pen_color(0,0,100);
                            draw.plot_pen_pixel(w,h);

                        }
                    }
               }
            }
        }
    }
    image.save_image("output.bmp"); 
}


int main()
{
    imprimirTablero();
    return 0;
}