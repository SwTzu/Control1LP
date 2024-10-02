all: programa

programa: lexer.o gramatica.tab.o estructuras.o
	gcc -o programa lexer.o gramatica.tab.o estructuras.o -lfl

lexer.o: lexer.l gramatica.tab.h
	flex lexer.l
	gcc -c lex.yy.c -o lexer.o

gramatica.tab.o gramatica.tab.h: gramatica.y
	bison -d gramatica.y
	gcc -c gramatica.tab.c -o gramatica.tab.o

estructuras.o: estructuras.c
	gcc -c estructuras.c -o estructuras.o

clean:
	rm -f *.o lex.yy.c gramatica.tab.* programa
