# Algoritmos de Ordenação

## Descrição
Este repositório é o código-fonte do Trabalho Prático 2 da disciplina AEDS - CEFET/MG 2017/2. Algoritmos Implementados:
- Não eficientes:
  - Bubble Sort;
  - Insertion Sort;
  - Selection Sort;
- Eficientes:
  - Quick Sort;
  - Heap Sort;
  - Merge Sort;

## Compilação
- `make` - Compila o código
- `make clean` - Apaga todos os arquivos compilados e executáveis

## Gerando arquivos de teste
  - `./gerador.out [Pasta destino] [N] [Tipo de dados]`
  
  Tipos de dados: 
  1 - Ordenados; 
  2 - Inversamente ordenados; 
  3 - Quase ordenados; 
  4 - Aleatórios.

  Exemplo: `./gerador.out dataset 100 4` gera um arquivo de teste com 100 números aleatórios na pasta `dataset`

  O nome do arquivo de saída será: `[N]-[crescente|decrescente|quaseordenado|aleatorio].txt`. No exemplo acima o nome seria: `100-aleatorio.txt`.

  Obs.: O gerador de teste gera um vetor de tamanho N ordenado (1 até N) e, de acordo com o tipo de dado escolhido, imprime as N linhas do vetor no arquivo destino.

## Execução
- `./ordenacao.out [Pasta do dataset]`
- Exemplo: - `./ordenacao.out dataset` executa os testes para todos os arquivos na pasta `dataset`
