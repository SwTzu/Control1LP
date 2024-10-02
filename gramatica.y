%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

// Definimos los prototipos de las funciones
void yyerror(const char* s);
int yylex();
%}

// Definición de los tokens que serán usados por Flex
%token GALAXIA RUTA NAVE PESO COMBUSTIBLE REABASTECER

// Aquí añadimos el tipo para los tokens
%token <num> NUMERO
%token <str> IDENTIFICADOR

// Definimos los tipos de los valores semánticos
%union {
    char* str;  // Para nombres de galaxias (identificadores)
    int num;    // Para números (peso, combustible, etc.)
}

// Definición de los tipos de las variables semánticas
%type <str> nombre_galaxia
%type <num> numero

%%

// Definición de las reglas de producción
inicio:
    definiciones
    ;

definiciones:
    definicion_galaxia definiciones
    | definicion_ruta definiciones
    | definicion_nave definiciones
    | /* vacío */
    ;

definicion_galaxia:
    GALAXIA nombre_galaxia REABASTECER numero {
        Galaxia* g = crear_galaxia($2, $4);
        printf("Galaxia creada: %s\n", g->nombre);
    }
    ;

definicion_ruta:
    RUTA nombre_galaxia nombre_galaxia PESO numero {
        Galaxia* g1 = buscar_galaxia($2);
        Galaxia* g2 = buscar_galaxia($3);
        if (g1 != NULL && g2 != NULL) {
            Ruta* r = crear_ruta(g1, g2, $5);
            printf("Ruta creada entre %s y %s, peso: %d\n", g1->nombre, g2->nombre, $5);
        }
    }
    ;

definicion_nave:
    NAVE nombre_galaxia COMBUSTIBLE numero {
        Galaxia* g = buscar_galaxia($2);
        if (g != NULL) {
            Nave* n = crear_nave(g, $4);
            printf("Nave creada en %s con %d unidades de combustible\n", g->nombre, $4);
        }
    }
    ;

nombre_galaxia:
    IDENTIFICADOR { $$ = strdup($1); }
    ;

numero:
    NUMERO { $$ = $1; }
    ;

%%

// Manejo de errores
void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
