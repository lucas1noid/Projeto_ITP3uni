#include <iostream>
#include "../Etapa_1/paleta.h"
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
     void Imagem::get_Imagem(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]){
        largura = Clargura;
        altura = Caltura;
        for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            pixel[i][j].R =;
        }
        
    };
}
    void Imagem::pixel_Imagem(int Clargura, int Caltura, Cor Cpixel[MAX][MAX]){
       cout << Cpixel[Clargura][Caltura].R << " ";
       cout << Cpixel[Clargura][Caltura].G << " ";
       cout << Cpixel[Clargura][Caltura].B << endl;
    };
    Cor Imagem::change_pixel (int Clargura, int Caltura, double alturas[MAX]){
        return 0;
    };
