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
    Paleta aa(){
        3, //quantidade de cores
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}}, //cores
        {0, 10, 20} //valores associados as cores
    };
    void get_paleta (int qtd, Cor a[], float valores[]){
        quantidade = qtd;
        for (int i = 0; i < qtd; i++)
        {
            alturas[i] = valores[i];
            cores[i] = a[i];
        }        
    }
};

int main(){

Cor cores[] = {
    {{ 255, 0, 0 },
     { 0, 255, 0 },
     { 0, 0, 255 }}
};

double alturas[] = {
    10, 100
};

Paleta paleta = {
    3,
    cores,
    alturas
};
    
}