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
#include "selectionsort.h"

/** Selection Sort
* @param A - Vetor a ser ordenado
* @param n - Tamanho do Vetor
**/
void Selecao(TipoVetor A, TipoIndice n)
{ TipoIndice i, j, Min;
  TipoItem x;
  for (i = 1; i <= n - 1; i++) 
    { Min = i;
      for (j = i + 1; j <= n; j++) 
        if (A[j].Chave < A[Min].Chave) Min = j;
      x = A[Min]; A[Min] = A[i]; A[i] = x;
    }
}
