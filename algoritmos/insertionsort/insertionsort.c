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
#include "insertionsort.h"

/** Insertion Sort
* @param A - Vetor a ser ordenado
* @param n - Tamanho do Vetor
**/
void Insercao(TipoVetor A, TipoIndice n)
{ TipoIndice i, j;
  TipoItem x;
  for (i = 2; i <= n; i++) 
    { x = A[i];  j = i - 1;
      A[0] = x;  /* sentinela */
      while (x.Chave < A[j].Chave) 
        { A[j+1] = A[j];  j--;
        }
      A[j+1] = x;
    } 
}