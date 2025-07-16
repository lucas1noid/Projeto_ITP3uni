#include <iostream>
#include "../Etapa_1/paleta.h"
#include "Imagem.h"
#include <fstream>
using namespace std;

    Imagem::Imagem(int l, int a) : largura(l), altura(a) {
        pixel = new Cor*[altura];

        for (int i = 0; i < altura; i++)
        {
            pixel[i] = new Cor[largura];
            for (int j = 0; j < largura; j++)
            {
                pixel[i][j] = {0, 0, 0};
            }           
        }        
    }

    Imagem::~Imagem(){
        for (int i = 0; i < altura; i++)
        {
            delete[] pixel[i];
        }
        delete[] pixel;
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



int main() {
    int largura = 300, altura = 150;
    Imagem img(largura, altura);

    int faixa = largura / 3;

for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
        if (j < faixa) {
            // Azul
            img.change_pixel(i, j, {0, 0, 255});
        } else if (j < 2 * faixa) {
            // Branco
            img.change_pixel(i, j, {255, 255, 255});
        } else {
            // Vermelho
            img.change_pixel(i, j, {255, 0, 0});
        }
    }
}

    img.save_Image("bandeira.ppm");

    return 0;
}
