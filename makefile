CC=gcc
OPCOES_COMPILADOR=-lm
TODOS_ARQUIVOS_PONTOH = modelos/item/item.h algoritmos/selectionsort/selectionsort.h algoritmos/insertionsort/insertionsort.h algoritmos/bubblesort/bubblesort.h
TODOS_ARQUIVOS_OBJ = main.o algoritmos/selectionsort/selectionsort.o algoritmos/insertionsort/insertionsort.o algoritmos/bubblesort/bubblesort.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o ordenacao.out $^ $(OPCOES_COMPILADOR)
	gcc -o gerador.out gerador.c

clean:
	rm *.o algoritmos/*/*.o *.out