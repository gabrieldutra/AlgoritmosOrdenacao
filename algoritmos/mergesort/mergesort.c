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
#include "mergesort.h"

/** Merge - intercala A[i..m] e A[m+1..j] em A[i..j] 
* @param A - Vetor a ser intercalado
* @param i - Posição inicial
* @param m - Posição central
* @param j - Posição final
*/
void Merge(TipoVetor A, int i, int m, int j){
    TipoVetor B = (TipoVetor) malloc(sizeof(TipoItem)*(MAXTAM+1));
    int x;
    int k = i;
    int l = m+1;

    for (x=i;x<=j;x++) B[x] = A[x];
    x = i;
        while (k<=m && l<=j ) {
        if (B[k].Chave <= B[l].Chave)
            A[x++].Chave = B[k++].Chave;
        else
            A[x++].Chave = B[l++].Chave;
    }

    while (k<=m) A[x++].Chave = B[k++].Chave;

    while (l<=j) A[x++].Chave = B[l++].Chave;
    
    free(B);

}

/** Mergesort - consiste na intercalação recursiva de vetores ordenados
* @param A - Vetor a ser ordenado
* @param i - Posição inicial
* @param j - Posição final
*/
void Mergesort(TipoVetor A, int i, int j){
    int m;
    if (i < j){
        m = (i + j - 1) / 2;
        Mergesort(A, i, m);      
        Mergesort(A, m + 1, j); 
        Merge(A,  i,  m, j); /*Intercala A[i..m] e A[m+1..j] em A[i..j] */
    }
}