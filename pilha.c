/* 
    Projeto: Avaliação 3
    Arquivo: pilha.c ->  funções da pilha
    Nome: Gabriel Foloni
    Data: 15/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "pilha.h"
    
Pilha criar_pilha(int tamanho){
    Pilha p = malloc (tamanho *sizeof(Pilha));
    p->max = tamanho;
    p->topo = -1;
    p->item = malloc (tamanho*sizeof(Itemp));
    return p;
}

int vaziap (Pilha p){
    if (p->topo == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int cheiap (Pilha p){
    if(p->topo == p->max-1){
        return 1;
    }
    else{
        return 0;
    }
}

void empilha (Itemp x, Pilha p){
    if (cheiap(p)){
        printf ("Pilha cheia!\n");
        return;
    }
    else{
        p->topo++;
        p->item[p->topo] = x;
        return;
    }
}

Itemp desempilha (Pilha p){
    if (vaziap(p)){
        printf ("Pilha vazia!\n");
        return 0;
    }
    else{
        Itemp x = p->item[p->topo];
        p->topo--;
        return x;
    }
}

Itemp topo (Pilha p){
    if (vaziap (p)){
        printf ("Pilha vazia!\n");
        return 0;
    }
    return p->item[p->topo];
}

void destroip (Pilha *p){
    free ((*p)->item);
    free (*p);
    *p = NULL;
}