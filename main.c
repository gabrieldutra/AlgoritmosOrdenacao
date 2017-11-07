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
#include <sys/time.h>
#include "modelos/item/item.h"


#include "algoritmos/bubblesort/bubblesort.h"
#include "algoritmos/selectionsort/selectionsort.h"
#include "algoritmos/insertionsort/insertionsort.h"
#include "algoritmos/quicksort/quicksort.h"
#include "algoritmos/mergesort/mergesort.h"

/** Carrega Vetor - carrega um vetor de um arquivo para a memória
* @param arquivo - String com a localização do arquivo a ser carregado
* @param vetorDestino - Ponteiro para o primeiro item do vetor carregado na memória
* @return int - Tamanho do vetor destino
**/
int carregaVetor(char *nomeArquivo, TipoVetor vetorDestino){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(!arquivo){
        return 0;
    }
    int n, contador=0;
    while(fscanf(arquivo,"%d",&n) != EOF){
        contador++;
        vetorDestino[contador].Chave = n;
    }
    fclose(arquivo);
    return contador;
}

/** Copia Vetor - copia um vetor para outro
* @param origem - Vetor de origem
* @param destino - Vetor destino
* @param tamanho - Tamanho do vetor
**/
void copiaVetor(TipoVetor origem, TipoVetor destino, int tamanho){
    int i;
    for(i=1; i<=tamanho; i++){
        destino[i].Chave = origem[i].Chave;
    }
}

/** Verifica ordenação - verifica se um vetor está ordenado
* @param vetor - vetor a ser verificado
* @param tamanho - Tamanho do vetor
**/
void verificaOrdenacao(TipoVetor vetor, int tamanho){
    int i;
    for(i=1; i<tamanho; i++){
        if(vetor[i].Chave > vetor[i+1].Chave){
            printf("O vetor não foi ordenado!\n");
            break;
        }
    }
}

/** Tempo Atual
* @return double - Tempo atual em milisegundos
**/
double tempoAtual(){
    struct timeval te; 
    gettimeofday(&te, NULL);
    double milliseconds = te.tv_sec*1000LL + (double)te.tv_usec/1000;
    return milliseconds;
}

int main(int argc, char *argv[]){
    DIR *diretorio;
    struct dirent **listarDiretorio;

    if(argc < 2){
        printf("Ops, você não passou todos os parâmetros!\nUso: %s [Pasta do dataset]\n", argv[0]);
        return 0;
    }

    diretorio = opendir(argv[1]);

    printf("Arquivo\tN\tBubbleSort(ms)\tSelectionSort(ms)\tInsertionSort(ms)\tQuickSort(ms)\tMergeSort(ms)\n");
    int numeroDiretorios = scandir(argv[1], &listarDiretorio, 0, alphasort);
    int count=0;
    // Percorre todos os arquivos do diretório passado como parâmetro
    while(count < numeroDiretorios){
        char *extensaoTxt = strstr(listarDiretorio[count]->d_name, ".txt");
        // Verifica se contém ".txt" como extensão
        if(extensaoTxt != NULL && strlen(extensaoTxt) == 4){
            char localArquivo[100];

            // Formata o local do arquivos
            sprintf(localArquivo, "%s/%s", argv[1],listarDiretorio[count]->d_name);

            TipoVetor vetor = malloc(sizeof(TipoItem)*(MAXTAM+1)); // Aloca o vetor com tamanho MAXTAM+1
            int tamanhoVetor = carregaVetor(localArquivo, vetor);

            TipoVetor vetorCopia = malloc(sizeof(TipoItem)*(tamanhoVetor+1));
            double tempoInicio, tempoFim;

            printf("%s\t%d\t",listarDiretorio[count]->d_name, tamanhoVetor);

            // Bubble Sort
            copiaVetor(vetor, vetorCopia, tamanhoVetor);
            tempoInicio = tempoAtual();
            Bubblesort(vetorCopia, tamanhoVetor);
            tempoFim = tempoAtual()-tempoInicio;
            verificaOrdenacao(vetorCopia, tamanhoVetor); // Confere se não ocorreu erros na ordenação (Teste dos algoritmos)
            printf("%-5.2f\t",tempoFim);

            // Selection Sort
            copiaVetor(vetor, vetorCopia, tamanhoVetor);
            tempoInicio = tempoAtual();
            Selecao(vetorCopia, tamanhoVetor);
            tempoFim = tempoAtual()-tempoInicio;
            verificaOrdenacao(vetorCopia, tamanhoVetor); // Confere se não ocorreu erros na ordenação (Teste dos algoritmos)
            printf("%-5.2f\t",tempoFim);

            // Insertion Sort
            copiaVetor(vetor, vetorCopia, tamanhoVetor);
            tempoInicio = tempoAtual();
            Insercao(vetorCopia, tamanhoVetor);
            tempoFim = tempoAtual()-tempoInicio;
            verificaOrdenacao(vetorCopia, tamanhoVetor); // Confere se não ocorreu erros na ordenação (Teste dos algoritmos)
            printf("%-5.2f\t",tempoFim);

            // Quick Sort
            copiaVetor(vetor, vetorCopia, tamanhoVetor);
            tempoInicio = tempoAtual();
            QuickSort(vetorCopia, tamanhoVetor);
            tempoFim = tempoAtual()-tempoInicio;
            verificaOrdenacao(vetorCopia, tamanhoVetor); // Confere se não ocorreu erros na ordenação (Teste dos algoritmos)
            printf("%-5.2f\t",tempoFim);

            // Merge Sort
            copiaVetor(vetor, vetorCopia, tamanhoVetor);
            tempoInicio = tempoAtual();
            Mergesort(vetorCopia, 1, tamanhoVetor);
            tempoFim = tempoAtual()-tempoInicio;
            verificaOrdenacao(vetorCopia, tamanhoVetor); // Confere se não ocorreu erros na ordenação (Teste dos algoritmos)
            printf("%-5.2f\n",tempoFim);
        }
        count++;
    }
    int i;
    for(i=0; i < numeroDiretorios; i++) free(listarDiretorio[i]);
    free(listarDiretorio);

    closedir(diretorio);
    return 0;
}