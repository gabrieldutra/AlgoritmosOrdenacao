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
#include "quicksort.h"

/** Particao - Rearranja o Vetor A[Esq..Dir] */
void Particao(TipoIndice Esq, TipoIndice Dir, TipoIndice *i, TipoIndice *j, TipoVetor A){ 
    TipoItem x, w;
    *i = Esq;  *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while (x.Chave > A[*i].Chave) (*i)++;
        while (x.Chave < A[*j].Chave) (*j)--;
        if (*i <= *j){
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

/** Ordena - Ordena o Vetor A[Esq..Dir] por meio de partições */
void Ordena(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
    TipoIndice i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

/** QuickSort - Ordena usando o quicksort
* @param A - Vetor a ser ordenado
* @param n - Tamanho do vetor
*/
void QuickSort(TipoVetor A, TipoIndice n){
    Ordena(1, n, A); 
}