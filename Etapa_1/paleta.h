#ifndef _Paleta
#define _Paleta

#define MAX 100

struct Cor
{
    int R, G, B;
};

class Paleta
{
private:
    int quantidade;
    Cor cores[MAX];
    double alturas[MAX];
public:
    Paleta();
    void get_paleta(int qtd, Cor a[], double valores[]);
    int ler_arquivo(const char* nome_arquivo, Paleta *paleta);
    int get_color_by_height();
};

#endif
