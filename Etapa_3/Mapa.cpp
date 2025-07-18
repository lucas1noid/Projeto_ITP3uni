#include "Mapa.h"
#include "../Etapa_1/paleta.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <algorithm> // necessário para std::clamp

Mapa::Mapa(int N) {
    tamanho = pow(2, N) + 1;
    inicializar_matriz();
}

Mapa::~Mapa() {
    desalocar_matriz();
}

float Mapa::deslocamento_aleatorio(float offset) {
    return ((float)rand() / RAND_MAX * 2 - 1) * offset;
}

void Mapa::inicializar_matriz() {
    matriz = new float*[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        matriz[i] = new float[tamanho];
        for (int j = 0; j < tamanho; ++j) {
            matriz[i][j] = 1.0f; // valor central dentro da faixa 0–2.0
        }
    }
}

void Mapa::desalocar_matriz() {
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
            float suavizacao = offset * (float(metade) / tamanho);
            matriz[y][x] = std::clamp(media + deslocamento_aleatorio(suavizacao), 0.0f, 2.0f);
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

            float suavizacao = offset * (float(metade) / tamanho);
            matriz[y][x] = std::clamp((soma / cont) + deslocamento_aleatorio(suavizacao), 0.0f, 2.0f);
        }
    }
}

void Mapa::gerar(float rugosidade) {
    srand(time(0));
    matriz[0][0] = 1.0f;
    matriz[0][tamanho - 1] = 1.0f;
    matriz[tamanho - 1][0] = 1.0f;
    matriz[tamanho - 1][tamanho - 1] = 1.0f;

    int passo = tamanho - 1;
    float offset = 0.5f; // ajustado para limitar dentro de 0–2.0

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
    return -1.0f;
}

int Mapa::linhas() const {
    return tamanho;
}

int Mapa::colunas() const {
    return tamanho;
}

void Mapa::salvar_em_arquivo(const std::string& nome) const {
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

void Mapa::ler_de_arquivo(const std::string& nome) {
    std::ifstream arquivo(nome);
    if (!arquivo.is_open()) return;

    int novoTamanho;
    arquivo >> novoTamanho;

    desalocar_matriz();
    tamanho = novoTamanho;
    inicializar_matriz();

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

void Mapa::pintar(Paleta& palet){
    Imagem image (tamanho, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            Cor color = palet.consultar_cor(matriz[i][j]);
            image.mudar_pixel(j, i, color); // x = col = j, y = lin = i
        
        }
        
    }
    
    sombreador(image);

    image.salvar_Imagem("imagem.ppm");
}

void Mapa::sombreador(Imagem& image) {
    for (int i = 1; i < tamanho; ++i) {
        for (int j = 1; j < tamanho; ++j) {
            float alturaAtual = matriz[i][j];
            float alturaNoroeste = matriz[i - 1][j - 1];

            if (alturaNoroeste > alturaAtual) {
                Cor pixel = image.consultar_pixel(j, i);  // x = col = j, y = lin = i
                pixel.R = std::max(0, (int)(pixel.R / 1.25));
                pixel.G = std::max(0, (int)(pixel.G / 1.25));
                pixel.B = std::max(0, (int)(pixel.B / 1.25));
                image.mudar_pixel(j, i, pixel);
            }
        }
    }
}
