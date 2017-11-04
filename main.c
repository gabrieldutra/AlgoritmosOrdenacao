/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Comparação entre os diferentes algoritmos de ordenação
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "modelos/item/item.h"

/** Carrega Vetor - carrega um vetor de um arquivo para a memória
* @param arquivo - String com a localização do arquivo a ser carregado
* @return TipoItem* - Ponteiro para o primeiro item do vetor carregado na memória
**/
TipoItem *carregaVetor(char *arquivo){
    // TODO
    return NULL;
}

int main(int argc, char *argv[]){
    DIR *diretorio;
    struct dirent *listarDiretorio;

    if(argc < 2){
        printf("Ops, você não passou todos os parâmetros!\nUso: %s [Pasta do dataset]\n", argv[0]);
        return 0;
    }

    diretorio = opendir(argv[1]);

    // Percorre todos os arquivos do diretório passado como parâmetro
    while((listarDiretorio = readdir(diretorio)) != NULL){
        char *extensaoTxt = strstr(listarDiretorio->d_name, ".txt");
        // Verifica se contém ".txt" como extensão
        if(extensaoTxt != NULL && strlen(extensaoTxt) == 4){
            printf("%s\n",listarDiretorio->d_name);
        }
    }

    closedir(diretorio);
    return 0;
}