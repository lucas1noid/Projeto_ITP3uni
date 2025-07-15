#ifndef _Imagem
#define _Imagem
#include "paleta.h"


class Imagem
{
private:
    int largura;
    int altura;
    Cor pixel[255][255];

public:
    Imagem(int l, int a);
    Cor get_pixel(int linha, int coluna);
    void change_pixel(int linha, int coluna, Cor cor);
    void save_Image(std::string nomeArquivo);
};

#endif
