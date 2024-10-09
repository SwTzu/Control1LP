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

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(YACC_C) $(LEX_C)
	$(CC) $(CFLAGS) $(YACC_C) $(LEX_C) -o $(TARGET) $(LDFLAGS)

# Generar el analizador sintáctico con Bison
$(YACC_C) $(YACC_H): $(YACC_FILE)
	bison -d $(YACC_FILE)

# Generar el analizador léxico con Flex
$(LEX_C): $(LEX_FILE) $(YACC_H)
	flex $(LEX_FILE)

# Regla para limpiar los archivos generados
clean:
	@echo "Limpiando archivos generados..."
	rm -f $(YACC_C) $(YACC_H) $(LEX_C) $(TARGET)

# Regla para ejecutar el programa leyendo desde un archivo
run:
	./$(TARGET) < comandos.txt

.PHONY: all clean run
