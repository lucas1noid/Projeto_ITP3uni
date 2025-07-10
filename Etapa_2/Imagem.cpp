#include <iostream>
#include "paleta.h"
#include "Imagem.h"
#include <fstream>

using namespace std;

void Imagem::save_Imagem(const char* nomeArquivo, int largura, int altura, Cor** matrizPixels) {
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
            arquivo << matrizPixels[i][j].r << " "
                    << matrizPixels[i][j].g << " "
                    << matrizPixels[i][j].b << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    std::cout << "Arquivo " << nomeArquivo << " salvo com sucesso.\n";
}
Imagem::get_Imagem(int Clargura, int Caltura, Cor Cpixel[1000][1000]){
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
