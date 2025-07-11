#include <iostream>
#include "paleta.h"
#include "Imagem.h"
#include <fstream>
using namespace std;

    void Imagem::save_Image(const char* nomeArquivo, int largura, int altura, Cor** matrizPixels) {
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
            arquivo << matrizPixels[i][j].R << " "
                    << matrizPixels[i][j].G << " "
                    << matrizPixels[i][j].B
                     << " ";
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

   
