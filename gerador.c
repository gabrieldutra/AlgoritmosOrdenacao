/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Gabriel Dutra Dias
Matricula: 201622040198
Descricao do programa: Comparação entre os diferentes algoritmos de ordenação
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    
    if(argc < 4){
        printf("Ops, você não passou todos os parâmetros!\nUso: %s [Pasta destino] [N] [Tipo de dados]\n", argv[0]);
        printf("Tipos de dados: 1 - Ordenados; 2 - Inversamente ordenados; 3 - Quase ordenados; 4 - Aleatórios\n");
        return 0;
    }

    char *pastaDestino = argv[1];
    int n = atoi(argv[2]);
    int tipo = atoi(argv[3]);

    srand((unsigned)time(NULL));

    if(n < 1 || n > 1000000){
        printf("O N deve ser um valor entre 1 e 1.000.000!\n");
        return 0;
    }

    if(tipo < 1 || tipo > 4){
        printf("Tipo inválido! [1-4]\n");
        return 0;
    }

    int *vetor = (int *) malloc(sizeof(int)*n); // Aloca um vetor com n elementos
    
    int i;
    for(i=0; i<n; i++){ // Preenche o vetor de maneira crescente
        vetor[i] = i+1;
    }

    char nomeArquivo[200];
    char nomeTipo[20];
    if(tipo == 1) sprintf(nomeTipo, "crescente");
    if(tipo == 2) sprintf(nomeTipo, "decrescente");
    if(tipo == 3) sprintf(nomeTipo, "quaseordenado");
    if(tipo == 4) sprintf(nomeTipo, "aleatorio");
    sprintf(nomeArquivo, "%s/%d-%s.txt", pastaDestino, n, nomeTipo);

    // Criação do arquivo
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(!arquivo){
        printf("Erro ao escrever arquivo!\n");
        return 0;
    }

    // Tipo ordenado
    if(tipo == 1){
        for(i=0; i<n; i++){
            fprintf(arquivo, "%d",vetor[i]);
            if(i != n-1) fprintf(arquivo, "\n");
        }
    }

    // Tipo inversamente ordenado
    if(tipo == 2){
        for(i=0; i<n; i++){
            fprintf(arquivo, "%d",vetor[(n-1)-i]);
            if(i != n-1) fprintf(arquivo, "\n");
        }
    }

    // Tipo quase ordenado
    if(tipo == 3){
        for(i=0; i<n; i++){
            int aleatorio = rand()%(n)+1; // Sorteia um número aleatório de 1 a n
            
            if(aleatorio%10 == 0 && i != n-1){ // Caso o número seja divisivel por 10, troca ele com uma das próximas posições
                int posicaoAleatoria = rand()%(n-i-1)+i+1; // Aproximadamente 10% dos números serão aleatórios
                int aux = vetor[i];
                vetor[i] = vetor[posicaoAleatoria];
                vetor[posicaoAleatoria] = aux;
            }
            fprintf(arquivo, "%d",vetor[i]);
            if(i != n-1) fprintf(arquivo, "\n");
        }
    }

    // Tipo aleatório
    if(tipo == 4){
        for(i=0; i<n; i++){
            int numeroAleatorio = rand()%(n*2)+1;
            fprintf(arquivo, "%d",numeroAleatorio); // Número aleatório de 1 a 2n
            if(i != n-1) fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);

    printf("Arquivo de teste criado: '%s'\n",nomeArquivo);

    return 0;
}