%{
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

#ifdef _WIN32
#define strdup _strdup
#endif
%}


%%

"crear_galaxia"            { return CREAR_GALAXIA; }
"conectar_galaxias"        { return CONECTAR_GALAXIAS; }
"establecer_peso"          { return ESTABLECER_PESO; }
"crear_nave"               { return CREAR_NAVE; }
"combustible_inicial"      { return COMBUSTIBLE_INICIAL; }
"ubicacion"                { return UBICACION; }
"set_destino"              { return SET_DESTINO; }
"mover_autonomo"           { return MOVER_AUTONOMO; }
"modo_viaje"               { return MODO_VIAJE; }
"menor_combustible"        { return MENOR_COMBUSTIBLE; }
"menor_galaxias"           { return MENOR_GALAXIAS; }
[a-zA-Z_][a-zA-Z0-9_]*     { yylval.str = strdup(yytext); return IDENTIFICADOR; }
[0-9]+                     { yylval.num = atoi(yytext); return NUMERO; }
[ \t\r\n]+                 { /* Ignorar espacios y saltos de línea */ }
";"                        { return ';'; }
.                          { return yytext[0]; }

%%

int yywrap(void) {
    return 1;
}
