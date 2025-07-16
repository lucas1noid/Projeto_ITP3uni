#ifndef __Mapa
#define __Mapa
#include <string>

class Mapa {
private:
    int tamanho;
    float** matriz;

    float deslocamentoAleatorio(float offset);
    void diamond(int passo, float offset);
    void square(int passo, float offset);
    
    void inicializarMatriz();
    void desalocarMatriz();

public:
    Mapa(int N);
    ~Mapa();

    void gerar(float rugosidade);
    float consultar(int lin, int col) const;
    int linhas() const;
    int colunas() const;

    void salvarEmArquivo(const std::string& nome) const;
    void lerDeArquivo(const std::string& nome);
    void imprimir() const;
};

#endif
