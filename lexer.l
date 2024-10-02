%{
#include "gramatica.tab.h"
%}

%%

"galaxia"          { return GALAXIA; }
"ruta"             { return RUTA; }
"nave"             { return NAVE; }
"peso"             { return PESO; }
"combustible"      { return COMBUSTIBLE; }
"reabastecer"      { return REABASTECER; }

[0-9]+             { yylval.num = atoi(yytext); return NUMERO; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }

[ \t\n]+           { /* ignorar espacios y saltos de línea */ }

.                  { printf("Carácter no válido: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}