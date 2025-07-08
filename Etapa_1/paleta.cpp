#include <iostream>
#include <fstream>
using namespace std;

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
    int ler_arquivo(const char* nome_arquivo, Paleta* paleta){
        ifstream arquivo(nome_arquivo);

        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir o arquivo!\n";
            return 0;
        }

        int qtd;
        arquivo >> qtd;

        Cor cores[MAX];
        double valores[MAX];

        for (int i = 0; i < qtd; i++)
        {
            double valor;
            int R, G, B;

            if (!(arquivo >> valor >> R >> G >> B))
            {
                cout << "Erro na leitura da linha " << i+2 << endl;
                //i + 2 = começa do 0, a primeira linha somente a qtd de cores
                return 0;
            }
            
            valores[i] = valor;
            cores[i] = { R, G, B };
        }
        
        paleta -> get_paleta(qtd, cores, valores);

        arquivo.close();
        return 1;
    }
};

int main(){

    int qtd = 3;

    Cor cores[] = {
        { 255, 0, 0 },
        { 0, 255, 0 },
        { 0, 0, 255 }
    };

    double alturas[] = { 10, 100, 200 };

    Paleta minhaPaleta;
    Paleta* palet = &minhaPaleta;

    if (minhaPaleta.ler_arquivo("colors.cor", palet) == 1) cout << "CORRETO!\n";
    else cout << "INCORRETO\n";

    return 0;
}
