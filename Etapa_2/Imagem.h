#ifndef _Imagem
#define _Imagem
#include "../Etapa_1/Paleta.h"


class Imagem
{
private:
    int largura;
    int altura;
    Cor** pixel;

public:
    /**
    Construtor para criar uma imagem preta
    @param int l (largura da imagem), int a (altura da imagem)
    @return nenhum
    */
    Imagem(int l, int a);
    /**
    Destrutor para limpar pixels da imagem 
    @param nenhum
    @return nenhum
    */
    ~Imagem();
    /**
    salva os dados de uma imagem no formato PPM(P3)
    @param string nomeArquivo .ppm a ser salvo
    @return nenhum
    */
    void save_Image(std::string nomeArquivo);
    
    /**
    Consultar um pixel qualquer na imagem
    @param linha que se encontra o pixel, coluna onde se encontra o pixel
    @return um pixel Tipo Cor
    */
    Cor get_pixel(int linha, int coluna) const;
    
    /**
    mudar apenas 1 pixel na imagem
    @param linha onde se encontra o pixel, coluna onde se encontra o pixel e a cor que o usuário deseja inserir.
    @return nenhum
    */
    void change_pixel(int linha, int coluna, Cor cor);
};

#endif
