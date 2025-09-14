/* 
    Projeto: Avaliação 3
    Arquivo: pfloat.c ->  funções da pilha de avaliação da expressão
    Nome: Gabriel Foloni
    Data: 15/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include "pfloat.h"
#include "menu.h"
#include "func.h"
#include "pilha.h"
    
Pilha_float criar_pilhaf(int tamanho){
    Pilha_float pf = malloc (tamanho *sizeof(Pilha_float));
    pf->maxf = tamanho;
    pf->topof = -1;
    pf->itef = malloc (tamanho*sizeof(Itemf));
    return pf;
}

int vaziaf (Pilha_float pf){
    if (pf->topof == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int cheiaf (Pilha_float pf){
    if(pf->topof == pf->maxf-1){
        return 1;
    }
    else{
        return 0;
    }
}

void empilhaf (Itemf x, Pilha_float pf){
    if (cheiaf(pf)){
        printf ("Pilha cheia!\n");
        return;
    }
    else{
        pf->topof++;
        pf->itef[pf->topof] = x;
        return;
    }
}

Itemf desempilhaf (Pilha_float pf){
    if (vaziaf(pf)){
        printf ("Pilha vazia!\n");
        return 0;
    }
    else{
        Itemf x = pf->itef[pf->topof];
        pf->topof--;
        return x;
    }
}

Itemf topof (Pilha_float pf){
    if (vaziaf(pf)){
        printf ("Pilha vazia!\n");
        return 0;
    }
    return pf->itef[pf->topof];
}

void destroif (Pilha_float *pf){
    free ((*pf)->itef);
    free (*pf);
    *pf = NULL;
}