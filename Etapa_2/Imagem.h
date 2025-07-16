#ifndef _Imagem
#define _Imagem
#include "../Etapa_1/paleta.h"


class Imagem
{
private:
    int largura;
    int altura;
    Cor** pixel;

public:
    Imagem(int l, int a);
    ~Imagem();
    
    Cor get_pixel(int linha, int coluna);
    void change_pixel(int linha, int coluna, Cor cor);
    void save_Image(std::string nomeArquivo);
};

#endif
