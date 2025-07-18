#include <iostream>
#include <fstream>
#include "Paleta.h"
using namespace std;

//

    Paleta::Paleta (){
        quantidade = 2;
        cores[0]={255, 0, 0};
        cores[1]={0,255,0};
        alturas[0]=0;
        alturas[1]=10;
    }    
    //transforma os dados privados da paleta
    void Paleta::get_paleta (int qtd, Cor a[], double valores[]){
        quantidade = qtd;
        for (int i = 0; i < qtd; i++)
        {
            alturas[i] = valores[i];
            cores[i] = a[i];
        }        
    }
    int Paleta::ler_arquivo(const char* nome_arquivo, Paleta* paleta){
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
    };
    Cor Paleta::consultar_cor(double altura){
        for (int i = 0; i < quantidade - 1; i++)
        {
            if (alturas[i]<= altura && altura < alturas[i + 1])
            {
                return cores[i];
            }       
        }
        cout << "valor à ser consultado invalido\n"; 
        return {0,0,0};  
    };
