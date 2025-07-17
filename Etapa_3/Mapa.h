#ifndef __Mapa
#define __Mapa
#include <string>
#include "../Etapa_2/imagem.h"

class Mapa {
private:
    int tamanho;
    float** matriz;

    float deslocamento_aleatorio(float offset);
    void diamond(int passo, float offset);
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
};

#endif
