#include <iostream>
#include <fstream>
#include "Etapa_1/paleta.h"
#include "Etapa_2/Imagem.h"
#include "Etapa_3/Mapa.h"
using namespace std;

int main() {
 

Paleta paleta;
    Paleta* minhaPaleta = &paleta;

    paleta.ler_arquivo("paleta.cor", minhaPaleta);

    Mapa mapa(8);
    
    mapa.gerar(1.5f);
    mapa.salvar_em_arquivo("alturas");
    mapa.imprimir();

    mapa.paint(paleta);

return 0;
}
