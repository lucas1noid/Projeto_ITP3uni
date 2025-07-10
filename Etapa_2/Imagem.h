#ifndef _Imagem
#define _Imagem
#include "../Etapa_1/paleta.h"


class Imagem
{
private:
    int largura;
    int altura;
    Cor pixel[MAX][MAX];

public:
    Imagem get_Imagem(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]);
    Imagem pixel_Imagem(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]);
    Imagem change_pixel(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]);
    Imagem save_Image(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]);
};

#endif
