// MapaAltitudes.cpp
#include "Mapa.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
//construtor
Mapa::Mapa(int N) {
    tamanho = pow(2, N) + 1;
    inicializarMatriz();
}
//destrutor
Mapa::~Mapa() {
    desalocarMatriz();
}

float Mapa::deslocamentoAleatorio(float offset) {
    return ((float)rand() / RAND_MAX * 2 - 1) * offset;
}

void Mapa::inicializarMatriz() {
    matriz = new float*[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        matriz[i] = new float[tamanho];
        for (int j = 0; j < tamanho; ++j) {
            matriz[i][j] = 0.0f;
        }
    }
}

void Mapa::desalocarMatriz() {
    for (int i = 0; i < tamanho; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Mapa::diamond(int passo, float offset) {
    int metade = passo / 2;
    for (int y = metade; y < tamanho; y += passo) {
        for (int x = metade; x < tamanho; x += passo) {
            float media = (
                matriz[y - metade][x - metade] +
                matriz[y - metade][x + metade] +
                matriz[y + metade][x - metade] +
                matriz[y + metade][x + metade]
            ) / 4.0f;
            matriz[y][x] = media + deslocamentoAleatorio(offset);
        }
    }
}

void Mapa::square(int passo, float offset) {
    int metade = passo / 2;
    for (int y = 0; y < tamanho; y += metade) {
        for (int x = (y + metade) % passo; x < tamanho; x += passo) {
            float soma = 0.0f;
            int cont = 0;

            if (y - metade >= 0) {
                soma += matriz[y - metade][x];
                cont++;
            }
            if (y + metade < tamanho) {
                soma += matriz[y + metade][x];
                cont++;
            }
            if (x - metade >= 0) {
                soma += matriz[y][x - metade];
                cont++;
            }
            if (x + metade < tamanho) {
                soma += matriz[y][x + metade];
                cont++;
            }

            matriz[y][x] = (soma / cont) + deslocamentoAleatorio(offset);
        }
    }
}

void Mapa::gerar(float rugosidade) {
    srand(time(0));
    matriz[0][0] = deslocamentoAleatorio(1);
    matriz[0][tamanho - 1] = deslocamentoAleatorio(1);
    matriz[tamanho - 1][0] = deslocamentoAleatorio(1);
    matriz[tamanho - 1][tamanho - 1] = deslocamentoAleatorio(1);

    int passo = tamanho - 1;
    float offset = 1.0f;

    while (passo > 1) {
        diamond(passo, offset);
        square(passo, offset);
        passo /= 2;
        offset *= rugosidade;
    }
}

float Mapa::consultar(int lin, int col) const {
    if (lin >= 0 && lin < tamanho && col >= 0 && col < tamanho) {
        return matriz[lin][col];
    }
    //caso pontos inválidos
    return -1.0f;
}

int Mapa::linhas() const {
    return tamanho;
}

int Mapa::colunas() const {
    return tamanho;
}

void Mapa::salvarEmArquivo(const std::string& nome) const {
    std::ofstream arquivo(nome);
    arquivo << tamanho << "\n";
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << "\n";
    }
    arquivo.close();
}

void Mapa::lerDeArquivo(const std::string& nome) {
    std::ifstream arquivo(nome);
    if (!arquivo.is_open()) return;

    int novoTamanho;
    arquivo >> novoTamanho;

    desalocarMatriz();
    tamanho = novoTamanho;
    inicializarMatriz();

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            arquivo >> matriz[i][j];
        }
    }
    arquivo.close();
}

void Mapa::imprimir() const {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            std::cout << std::setw(6) << std::fixed << std::setprecision(2) << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
}

/*int main () {

Mapa mapa(3); // 9x9
    mapa.gerar(2.0f);

    std::cout << "Mapa gerado:\n";
    mapa.imprimir();

    mapa.salvarEmArquivo("altitudes.txt");

    Mapa outroMapa(0);
    outroMapa.lerDeArquivo("altitudes.txt");

    std::cout << "\nMapa lido do arquivo:\n";
    outroMapa.imprimir();


    return 0;
}*/
