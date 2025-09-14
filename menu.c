/* 
    Projeto: Avaliação 3
    Arquivo: menu.c ->  menu do programa
    Nome: Gabriel Foloni
    Data: 20/12/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "menu.h"
#include "func.h"
#include "pilha.h"

void menu(){
    int escolha = 0;
    int t_var = 0;
    int t_exp = 0;
    float vlor = 0.00;
    int quant = 0;
    char s[500];
    s[0] = '\0';
    Valores *v = NULL;
    do{
        printf ("Digite\n1 para definir a expressao a ser analisada\n2 para definir os valores das variaveis\n3 para avaliar a expressao\n4 para sair\n");
        scanf ("%i", &escolha);
        quant = 0;
        switch (escolha){
        case 1:
            t_var = 0;
            printf ("Lembrando que, o programa nao aceita expressoes com Chaves ou Colchetes\n");
            printf ("Lembrando que, para exponenciacao digita ^ e para raizes digitar $ junto ao numero desejado para o grau da raiz\n");
            printf ("Atencao: SAO CONSIDERADOS OS VALORES POSITIVOS DAS RAIZES PARES\nEx: √4 = 2\n");
            definir(s);
            printf ("A expressao em sua forma posfixa: %s\n", s);
            t_exp = 1;
            break;
        case 2:
            if (t_exp == 1){
                v =  (Valores *) malloc(strlen(s)*sizeof(Valores));
            v = valores(s);
            for (int i = 0; s[i]; i++){
                if (v[i].existencia == 1){
                    quant++;
                }
            }
            printf ("Possui %i variaveis\n", quant);
            t_var = 1;
            }else{printf("Nao possui expressao\n");}
            break;
        case 3:
            if (t_var == 1){
                for (int i = 0; s[i]; i++){
                    if (v[i].existencia == 1){
                        quant++;
                    }
                }
                vlor = avaliar(s, v, quant);
                if (isnan(vlor));
                else
                    printf ("O valor da expressao eh: %.2f\n\n", vlor);
            }
            else{
                printf ("Variaveis nao definidas\n");
            }
            break;
        case 4:
            printf ("Saindo\n");
            break;
        default:
            printf ("Opcao invalida, favor\n");
            break;
        }
    }while(escolha != 4);
    free(v);
    return;
}