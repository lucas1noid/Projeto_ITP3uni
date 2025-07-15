#include <iostream>
#include "paleta.h"
#include "Imagem.h"
#include <fstream>
using namespace std;


    Imagem::Imagem(int l, int a){
        largura = l;
        altura = a;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < a; j++)
            {
                pixel[i][j] = {0, 0, 0};
            }
        }       
    }

    void Imagem::save_Image(string nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    // Cabeçalho PPM
    arquivo << "P3" << "\n";
    arquivo << largura << " " << altura << "\n";
    arquivo << "255" << "\n";

    // Escrever pixels
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            arquivo << pixel[i][j].R << " "
                    << pixel[i][j].G << " "
                    << pixel[i][j].B << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    std::cout << "Arquivo " << nomeArquivo << " salvo com sucesso.\n";
}

    Cor Imagem::get_pixel(int linha, int coluna){
       return pixel[linha][coluna];
    };
    void Imagem::change_pixel(int linha, int coluna, Cor cor){
       pixel[linha][coluna] = cor;
    };



int main(){

    Imagem img(100, 50);

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            img.change_pixel(i, j, {255, 0, 0});
        }
    }
    
    
    img.save_Image("teste.ppm");
 
    return 0;
}
