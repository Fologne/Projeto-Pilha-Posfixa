/* 
    Projeto: Avaliação 3
    Arquivo: func.c ->  funções gerais
    Nome: Gabriel Foloni
    Data: 15/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilha.h"
#include "pfloat.h"
#include "menu.h"
#include "func.h"

int prio(char o);

void definir(char s[]){
    int tamanho;
    int j = 0;
    char vetor[500];
    printf("Digite a expressao a ser analisada\n");
    scanf("%s", vetor);
    printf ("A expressao a ser convertida eh: %s\n", vetor);
    tamanho = strlen(vetor);
    Pilha p = criar_pilha(tamanho);
    for (int i = 0; i < tamanho; i++){
        if (vetor[i] == '('){
            empilha('(', p);
        } 
        else if (vetor[i] == ')'){
            while (topo(p) != '('){
                s[j++] = desempilha(p);
            }
            desempilha(p);
        } 
        else if (strchr("+*-/^$", vetor[i])){
            while (!vaziap(p) && prio(topo(p)) >= prio(vetor[i])){ 
                s[j++] = desempilha(p);
            }
            if (!vaziap(p) && topo(p) == '^' && vetor[i] == '^');
            else{
                empilha(vetor[i], p);
            }
        } 
        else {
            s[j++] = vetor[i];
        }
    }

    while (!vaziap(p)) {
        s[j++] = desempilha(p);
    }
    s[j] = '\0';
    destroip(&p);
}

int prio (char o){
    switch (o){
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
        case '$':
            return 3;
            break;
    }
    return -1;
}

Valores *valores(char s[]){
    Valores *v1;
    int contador = 0;
    v1 =  NULL;
    for (int i = 0; s[i]; i++){
        int exists = 0;
        if (isalpha(s[i])){
            for (int j = 0; j < contador; j++){
                if (v1[j].letra == s[i]){
                    exists = 1;
                    break;
                }
            }
            if (!exists){
                v1 = (Valores *) realloc (v1, (contador+1) * sizeof (Valores));
                v1[contador].letra = s[i];
                printf("Digite o valor da variável %c: ", s[i]);
                scanf("%f", &v1[contador].variaveis);
                v1[contador].existencia = 1;
                contador++;
            }
        }
    }
    return v1;
}

float avaliar(char s[], Valores *v, int quant){
    Pilha_float pf = criar_pilhaf(500);
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho; i++){
        if (isalpha(s[i]) && s[i] != '\0'){
            for (int j = 0; j < quant; j++){
                if (v[j].letra == s[i] && v[j].letra != '\0'){
                    empilhaf (v[j].variaveis, pf);
                    break;
                }
            }
        }
        else{
            float y = desempilhaf (pf);
            float x = desempilhaf (pf);
            switch (s[i]){
            case '+':
                empilhaf (x+y, pf);
                break;
            case '-':
                empilhaf (x-y, pf);
                break;
            case '*':
                empilhaf (x*y, pf);
                break;
            case '/':
                if (y != 0){
                    empilhaf (x/y, pf);
                }
                else{
                    printf("Divisao por zero detectada, favor, rever os valores das variaveis\n");
                    destroif (&pf);
                    return NAN;
                }
                break;
            case '^':
                empilhaf (pow(x, y), pf);
                break; 
            case '$':
                float resto = fmod(y, 2);
                if ((x < 0 && resto == 0) || y == 0){
                    printf ("Raiz indefenida, favor, rever os valores das variaveis\n");
                    return NAN;
                }
                else{
                    if (x < 0 && resto != 0){
                        empilhaf(-pow(-x, 1.0/y), pf);
                    }
                    else{
                        empilhaf(pow(x, 1.0/y), pf);
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    float z = desempilhaf(pf);
    destroif (&pf);
    return z;
}