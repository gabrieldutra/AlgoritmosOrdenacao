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
* @param vetorDestino - Ponteiro para o primeiro item do vetor carregado na memória
* @return int - Tamanho do vetor destino
**/
int carregaVetor(char *nomeArquivo, TipoVetor vetorDestino){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(!arquivo){
        printf("Não foi possível abrir o arquivo!\n");
        return 0;
    }
    int n, contador=0;
    while(fscanf(arquivo,"%d",&n) != EOF){
        contador++;
        vetorDestino[contador].Chave = n;
    }
    fclose(arquivo);
    printf("%d números carregados.\n",contador);
    return contador;
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
            char localArquivo[100];

            // Formata o local do arquivos
            sprintf(localArquivo, "%s/%s", argv[1],listarDiretorio->d_name);

            printf("Carregando '%s'\n",listarDiretorio->d_name);

            TipoVetor vetor = malloc(sizeof(TipoItem)*(MAXTAM+1)); // Aloca o vetor com tamanho MAXTAM+1
            int tamanhoVetor = carregaVetor(localArquivo, vetor);
        }
    }

    closedir(diretorio);
    return 0;
}