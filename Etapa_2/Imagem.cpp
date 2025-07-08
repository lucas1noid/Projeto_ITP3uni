#include <iostream>

struct Cor
{
    int R, G, B;
};

class Imagem
{
private:
    int largura;
    int altura;
    Cor pixel[1000][1000];

public:
    Imagem(){
    largura = 1;
    altura = 1;
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            pixel[i][j] = {0, 0, 0};
        }
    }
    cout << "Construtor usado! Objeto criado." << endl;
    };
    ~Imagem(){
    cout << "Destrutor usado! Objeto destruido." << endl;
    };
    Imagem get_Imagem(int Clargura, int Caltura, Cor Cpixel[1000][1000]){
        largura = Clargura;
        altura = Caltura;
        for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            pixel[i][j] = Cpixel[i][j];
        }
        
    }
    };
    Imagem cout_Imagem(Imagem img){
        cout << largura << endl;
        cout << altura << endl;
    };
};

int main () {

return 0;
}
