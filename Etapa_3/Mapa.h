#ifndef __Mapa
#define __Mapa
#include <string>
#include "../Etapa_2/Imagem.h"

class Mapa {
private:
    int tamanho;
    float** matriz;
    
    /*
    cria um deslocamento aleatorio para a randomizacao das alturas no mapa
    @param um float chamado de offset, que eh o valor original de desvio permitido pelo deslocamento aleatório
    @return um deslocamento aleatorio a partir do meu offset determinado
    */
    float deslocamento_aleatorio(float offset);
    /*
    Passo Diamond do algoritmo Diamond-Square, pega o ponto central a partir de outros pontos distintos
    @param um float chamado de offset, mesmo a função anterior. um int chamado passo, que é a distância entre um ponto e outro que será utilizado para fazer o "Diamond".
    @return nenhum
    */
    void diamond(int passo, float offset);
    /*
    Passo Square do algoritmo Diamond-Square, pega o ponto médio das arestas
    @param mesmos da função diamond.
    @return nenhum
    */
    void square(int passo, float offset);
    /*
    Inicializa uma matriz com o ponto central sendo a média do menor e maior valores possíveis para as alturas (Ex: Alturas entre 0.0 e 2.0, inicializa matriz com ponto central 1.0)
    @param nenhum
    @return nenhum
    */
    void inicializar_matriz();
    /*
    Deleta a matriz para liberar memória
    @param nenhum
    @return nenhum    
    */
    void desalocar_matriz();

public:
    /*
    Construtor, para criar um mapa de dimensões (2^n +1) por (2^n +1)
    @param esse int N que será usado para criar as dimensões do mapa
    @return nenhum
    */
    Mapa(int N);
    /*Destrutor, para limpar o mapa
    @param nenhum
    @return nenhum
    */
    ~Mapa();

    /*
    Gera um mapa, utilizando as funções diamond square
    @param um float rugosidade, quanto maior o seu valor, mais irregular será o terreno
    @return nenhum
    */
    void gerar(float rugosidade);
    /*
    A paritr de uma dada coordenada(linha e coluna), diz qual o valor da altura nesse ponto
    @param int linha, coluna que são as coordenadas do ponto
    @return o valor da altura nesse ponto
    */
    float consultar(int lin, int col) const;
    /*
    Essas duas funções retornam as dimensões do mapa criado, sem parametros ou return
    */
    int linhas() const;
    int colunas() const;

    /*
    Cria um arquivo de texto com os dados atuais da matriz (tamanho e valores).
    @param nome do arquivo a ser criado
    @return nenhum
    */
    void salvar_em_arquivo(const std::string& nome) const;
    /*
    Carrega uma matriz a partir de um arquivo gerado por salvar_em_arquivo
    @param nome do arquivo a ser lido
    @return nenhum
    */
    void ler_de_arquivo(const std::string& nome);
    /*
    Imprime no terminal um modelo, exatamente igual ao arquivo, que contem o tamanho e os valores
    @param nenhum
    @return nenhum
    */
    void imprimir() const;

    /*
    Relaciona cada altura a uma cor da paleta já criada. Ex(Altura entre x e y terá cor z)
    @param paleta já criada anteriormente e que será usada como comparação às alturas
    @return nenhum*/
    void pintar(Paleta& paleta);
    
    /*
    adiciona sombra a um pixel caso o pixel ao seu noroeste seja maior que ele mesmo
    @param a imagem que vai receber as alteracoes de sombreamento a partir do mapa de alturas
    @return nenhum
    */
    void sombreador(Imagem& image);
};

#endif
