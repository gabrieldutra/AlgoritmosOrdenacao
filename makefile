CC=gcc
OPCOES_COMPILADOR=-lm
TODOS_ARQUIVOS_PONTOH = modelos/item/item.h
TODOS_ARQUIVOS_OBJ = main.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o ordenacao.out $^ $(OPCOES_COMPILADOR)

clean:
	rm *.o algoritmos/*/*.o *.out