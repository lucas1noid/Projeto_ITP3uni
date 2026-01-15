# MAP_generator 🌍
![imagem_teste](imagem_teste.png)

> Projeto desenvolvido para a disciplina de Introdução às Técnicas de Programação (ITP) pela **UFRN**.

Este projeto implementa um gerador de mapas de altura (heightmaps) utilizando o algoritmo **Diamond-Square**. O sistema converte a matriz de alturas gerada em uma imagem visualizável (`.ppm`) aplicando uma paleta de cores personalizada e sombreamento para efeito de relevo.

---

## 🛠️ Como Compilar e rodar

Certifique-se de ter um compilador C++ instalado (g++ ou clang).

### Via Terminal (Linux/WSL)
Na raiz do projeto, execute:

```bash
g++ main.cpp Etapa_1/Paleta.cpp Etapa_2/Imagem.cpp Etapa_3/Mapa.cpp -o gerador_terreno

#logo após:

./gerador_terreno