/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Comparação entre os diferentes algoritmos de ordenação
Data: 10/11/2017
************************************************/

#define MAXTAM 1000000

typedef int TipoChave;
typedef struct TipoItem {
    TipoChave Chave;
    /* outros componentes */
} TipoItem;

typedef int TipoIndice;
typedef TipoItem * TipoVetor; 