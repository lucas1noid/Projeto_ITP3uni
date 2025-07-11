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
    Cor get_pixel(int linha, int coluna);
    void change_pixel(int linha, int coluna, Cor cor);
    void save_Image(const char* nomeArquivo, int largura, int altura, Cor** matrizPixels);
};

#endif
