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
#include "bubblesort.h"

/** Bubble Sort
* @param A - Vetor a ser ordenado
* @param n - Tamanho do Vetor
**/
void Bubblesort(TipoVetor A, TipoIndice n)
{
    int i, j;
    int aux;
    for(j=1; j<=n-1; j++){
        for(i=1; i<=n-j; i++){
            if(A[i].Chave > A[i+1].Chave){
                aux = A[i].Chave;
                A[i].Chave = A[i+1].Chave;
                A[i+1].Chave = aux;
            }
        }
    }
}