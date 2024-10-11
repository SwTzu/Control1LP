# Makefile para el proyecto de galaxias

# Nombre del ejecutable
TARGET = galaxia

# Archivos fuente
LEX_FILE = lexer.l
YACC_FILE = parser.y

# Archivos generados por Bison y Flex
YACC_C = parser.tab.c
YACC_H = parser.tab.h
LEX_C = lex.yy.c

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function -std=c99 -D_POSIX_C_SOURCE=200809L
LDFLAGS = -lfl
	
all:
	bison -d $(YACC_FILE)
	flex $(LEX_FILE)
	$(CC) $(CFLAGS) $(YACC_C) $(LEX_C) -o $(TARGET) $(LDFLAGS)
	./$(TARGET) < comandos.txt
	@echo "\n"
	@echo "\n"
	@echo "Ejecutando comandos1.txt..."
	./$(TARGET) < comandos1.txt
	@echo "\n"
	@echo "\n"
	@echo "Ejecutando comandos2.txt..."
	./$(TARGET) < comandos2.txt
	@echo "\n"
	@echo "\n"
	@echo "Ejecutando comandos3.txt..."
	./$(TARGET) < comandos3.txt

# Regla para limpiar los archivos generados
clean:
	@echo "Limpiando archivos generados..."
	rm -f $(YACC_C) $(YACC_H) $(LEX_C) $(TARGET)

# Regla para ejecutar el programa leyendo desde un archivo

.PHONY: all clean run
