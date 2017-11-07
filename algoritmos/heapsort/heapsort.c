/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Comparação entre os diferentes algoritmos de ordenação
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../modelos/item/item.h"
#include "heapsort.h"

/** Refaz - Refaz o Heap nas posições passadas
* @param Esq - índice da esquerda
* @param Dir - índice da direita
* @param A - Vetor a ser refeito
*/
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoVetor A){
    TipoIndice i = Esq;
    int j;
    TipoItem x;
    j = i * 2;
    x = A[i];
    while (j <= Dir){
        if (j < Dir){
            if (A[j].Chave < A[j+1].Chave) j++;
        }
        if (x.Chave >= A[j].Chave) break;
        A[i] = A[j];
        i = j;  j = i * 2;
    }
    A[i] = x;
}
/** Constroi - Constroi o Heap
* @param A - Vetor a ser construido
* @param n - Tamanho do Vetor
*/
void Constroi(TipoVetor A, TipoIndice n){
    TipoIndice Esq;
    Esq = n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, n, A);
    }
}

/** Heapsort - Ordenação pelo heapsort
* @param A - Vetor a ser ordenado
* @param n - Tamanho do vetor
*/
void Heapsort(TipoVetor A, TipoIndice n){
    TipoIndice Esq, Dir;
    TipoItem x;
    Constroi(A, n);  /* constroi o heap */
    Esq = 1;  Dir = n;
    while (Dir > 1){ /* ordena o vetor */
        x = A[1];  A[1] = A[Dir];  A[Dir] = x;  Dir--; 
        Refaz(Esq, Dir, A);
    }
}