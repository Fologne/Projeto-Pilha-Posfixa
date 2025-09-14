/* 
    Projeto: Avaliação 3
    Arquivo: func.h ->  biblioteca de funções
    Nome: Gabriel Foloni
    Data: 20/12/2024
*/

typedef struct mudkip{
    float variaveis;
    char letra;
    int existencia;
}Valores;



void definir(char s[]);
Valores *valores(char s[]);
float avaliar(char s[], Valores *v, int quant);