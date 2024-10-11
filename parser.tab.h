/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    /* Definición de 'Ruta' */
    typedef struct Ruta {
        char *galaxia;
        struct Ruta *siguiente;
    } Ruta;

#line 57 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CREAR_GALAXIA = 258,           /* CREAR_GALAXIA  */
    CONECTAR_GALAXIAS = 259,       /* CONECTAR_GALAXIAS  */
    ESTABLECER_PESO = 260,         /* ESTABLECER_PESO  */
    CREAR_NAVE = 261,              /* CREAR_NAVE  */
    COMBUSTIBLE_INICIAL = 262,     /* COMBUSTIBLE_INICIAL  */
    UBICACION = 263,               /* UBICACION  */
    SET_DESTINO = 264,             /* SET_DESTINO  */
    MOVER_AUTONOMO = 265,          /* MOVER_AUTONOMO  */
    MODO_VIAJE = 266,              /* MODO_VIAJE  */
    MENOR_COMBUSTIBLE = 267,       /* MENOR_COMBUSTIBLE  */
    MENOR_GALAXIAS = 268,          /* MENOR_GALAXIAS  */
    RUTA = 269,                    /* RUTA  */
    IDENTIFICADOR = 270,           /* IDENTIFICADOR  */
    NUMERO = 271,                  /* NUMERO  */
    REABASTECIBLE = 272,           /* REABASTECIBLE  */
    SUB_GALAXIA = 273,             /* SUB_GALAXIA  */
    GUIADO = 274,                  /* GUIADO  */
    REABASTECER = 275,             /* REABASTECER  */
    LISTAR_VECINOS = 276,          /* LISTAR_VECINOS  */
    MOVER_A = 277                  /* MOVER_A  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    char *str;
    int num;
    Ruta *ruta;
    struct {
        int reabastece;
        int sub_galaxia;
    } opciones;

#line 106 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
