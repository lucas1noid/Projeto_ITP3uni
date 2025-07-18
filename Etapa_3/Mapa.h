#ifndef __Mapa
#define __Mapa
#include <string>
#include "../Etapa_2/imagem.h"

class Mapa {
private:
    int tamanho;
    float** matriz;
    
    /**
    cria um deslocamento aleatorio para a randomizacao das alturas no mapa
    @param um float chamado de offset, que eh o valor original de desvio permitido pelo deslocamento aleatório
    @return um deslocamento aleatorio a partir do meu offset determinado
    */
    float deslocamento_aleatorio(float offset);
    /**
    */
    void diamond(int passo, float offset);
    /**
    */
    void square(int passo, float offset);
    
    void inicializar_matriz();
    void desalocar_matriz();

public:
    Mapa(int N);
    ~Mapa();

    void gerar(float rugosidade);
    float consultar(int lin, int col) const;
    
    int linhas() const;
    int colunas() const;

    void salvar_em_arquivo(const std::string& nome) const;
    void ler_de_arquivo(const std::string& nome);
    void imprimir() const;

    void paint(Paleta& paleta);
    
    /**
    adiciona sombra a um pixel caso o pixel ao seu noroeste seja maior que ele mesmo
    @param a imagem que vai receber as alteracoes de sombreamento a partir do mapa de alturas
    @return nenhum
    */
    void sombreador(Imagem& image);
};

#endif
