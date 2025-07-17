#include <iostream>
#include <fstream>
#include "../Etapa_1/paleta.h"
#include "../Etapa_2/Imagem.h"
#include "Mapa.h"
using namespace std;

int main () {

    Paleta paleta;
    Paleta* minhaPaleta;

    paleta.ler_arquivo("paleta.cor", minhaPaleta);

    Mapa mapa(3);
    
    mapa.gerar(2.0);
    mapa.salvar_em_arquivo("alturas");
    mapa.imprimir();

    mapa.paint(paleta);

    return 0;
}
