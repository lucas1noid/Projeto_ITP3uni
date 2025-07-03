#include <iostream>
using namespace std;

struct Cor
{
    int R, G, B;
};

class Paleta
{
private:
    int quantidade;
    Cor cores[100];
    double alturas[100];
public:
    Paleta (){
        quantidade = 2;
        for (int i = 0; i < quantidade; i++)
        {
            alturas[i] = 0;
            cores[i] = {0, 0, 0};
        }
    }    
    void get_paleta (int qtd, Cor a[], double valores[]){
        quantidade = qtd;
        for (int i = 0; i < qtd; i++)
        {
            alturas[i] = valores[i];
            cores[i] = a[i];
        }        
    }
};

int main(){

int quanti = 3;

Cor cores[] = {
    { 255, 0, 0 },
     { 0, 255, 0 },
     { 0, 0, 255 }
};

double alturas[] = {
    10, 100, 200
};

Paleta paletinha;
    
paletinha.get_paleta (quanti, cores, alturas);

}
