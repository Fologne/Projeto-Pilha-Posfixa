/* 
    Projeto: Avaliação 3
    Arquivo: pfloat.h ->  biblioteca da pilha de avaliação da expressão
    Nome: Gabriel Foloni
    Data: 20/12/2024
*/

typedef float Itemf;

typedef struct pilhaf{
    int maxf;
    int topof;
    Itemf *itef;
}*Pilha_float;

Pilha_float criar_pilhaf(int tamanho);
int vaziaf (Pilha_float p);
int cheiaf (Pilha_float p);
void empilhaf (Itemf x, Pilha_float p);
Itemf desempilhaf (Pilha_float p);
Itemf topof (Pilha_float p);
void destroif (Pilha_float *p);