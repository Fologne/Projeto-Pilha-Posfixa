/* 
    Projeto: Avaliação 3
    Arquivo: pilha.h ->  biblioteca da pilha
    Nome: Gabriel Foloni
    Data: 20/12/2024
*/

typedef char Itemp;

typedef struct pilha{
    int max;
    int topo;
    Itemp *item;
}*Pilha;

Pilha criar_pilha(int tamanho);
int vaziap (Pilha p);
int cheiap (Pilha p);
void empilha (Itemp x, Pilha p);
Itemp desempilha (Pilha p);
Itemp topo (Pilha p);
void destroip (Pilha *p);