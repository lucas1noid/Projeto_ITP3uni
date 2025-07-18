#ifndef _Paleta
#define _Paleta

/**
Valor máximo definido apenas para melhor vizualização
*/
#define MAX 100

/** 
Salva toda cor como uma struct formada por 3 ints, representando respectivamente o RGB.
*/
struct Cor
{
    int R, G, B;
};

class Paleta
{
private:
    int quantidade;
    Cor cores[MAX];
    double alturas[MAX];
public:
    
    /**
    Construtor, constroe a função com parametros base caso o usuário não inicialize-os.
    @param nenhum
    @return nenhum
    */
    Paleta();
    
    /**
     * atribui valores inicializados aos valores privados, para que possamos usar em outras funções
    @param quantidade de alturas que vao ser utilizadas para separar as cores; Array de cores, que vão comparando cada altura a essa cor; valores, se relacionam com as cores, formando a paleta
    @return nenhum
    */
    void pegar_paleta(int qtd, Cor a[], double valores[]);
    
    /**
    Ler Arquivo, pega um arquivo já existente e passa os dados contidos nele para os dados privados da paleta.
    @param nome do arquivo desejado
    @return "1" para caso a leitura do arquivo for concluída, ou "0" caso contrário.
    */
    int ler_arquivo(const char* nome_arquivo, Paleta* paleta);
    
    /**
    Consulta a cor que é correspondente à altura recebida.
    @param altura que vai ser usada para encontrar sua respectiva cor na paleta.cor.
    @return uma estrutura Cor, onde é retornado os valores R G B de uma determinada altura.
    */
    Cor consultar_cor(double altura);
};

#endif
