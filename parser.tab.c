/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Declaraciones de funciones y estructuras */
void yyerror(const char *s);
int yylex(void);

#define MAX_GALAXIAS 100 // Máximo número de galaxias

/* Estructuras de datos */
typedef struct Galaxia {
    char *nombre;
    int puede_reabastecer;
    int sub_galaxia;
    struct Galaxia *siguiente;
} Galaxia;

typedef struct Arista {
    char *galaxia1;
    char *galaxia2;
    int peso;
    struct Arista *siguiente;
} Arista;

typedef struct NodoAdyacente {
    int indice_galaxia;
    int peso;
    struct NodoAdyacente *siguiente;
} NodoAdyacente;

typedef struct Ruta {
    char *galaxia;
    struct Ruta *siguiente;
} Ruta;

typedef struct Nave {
    int combustible;
    char *ubicacion_actual;
    char *destino;
} Nave;

/* Variables globales */
Galaxia *lista_galaxias = NULL;
Arista *lista_aristas = NULL;
Nave nave;

/* Mapeo de galaxias a índices y listas de adyacencia */
char *galaxias_indices[MAX_GALAXIAS]; // Índice a nombre de galaxia
int num_galaxias = 0;
NodoAdyacente *adyacentes[MAX_GALAXIAS]; // Lista de adyacencia para cada galaxia

/* Prototipos de funciones */
void agregar_galaxia(char *nombre);
void conectar_galaxias(char *g1, char *g2, int peso);
void establecer_peso(char *g1, char *g2, int peso);
void establecer_destino(char *nombre_galaxia);
void mover_autonomo(int pasos, int modo_viaje);
Ruta* calcular_ruta(char *origen, char *destino, int modo_viaje);
Ruta* calcular_ruta_dijkstra(char *origen, char *destino);
Ruta* calcular_ruta_bfs(char *origen, char *destino);
int obtener_consumo(char *g1, char *g2);
int galaxia_existe(char *nombre);
int obtener_indice_galaxia(char *nombre);
Galaxia* buscar_galaxia(char *nombre)
void listar_galaxias_en_radio(int radio, int origen, int *visitados, int current, int *result_count, char **result);
Ruta* crear_ruta(char *galaxia);
Ruta* agregar_ruta(Ruta *ruta, char *galaxia);
void reabastecer();
void ejecutar_viaje_guiado(Ruta *ruta);
void listar_vecinos(int radio);
void mover(char *galaxia);
void ejecutar_viaje(Ruta *ruta);


#line 150 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CREAR_GALAXIA = 3,              /* CREAR_GALAXIA  */
  YYSYMBOL_CONECTAR_GALAXIAS = 4,          /* CONECTAR_GALAXIAS  */
  YYSYMBOL_ESTABLECER_PESO = 5,            /* ESTABLECER_PESO  */
  YYSYMBOL_CREAR_NAVE = 6,                 /* CREAR_NAVE  */
  YYSYMBOL_COMBUSTIBLE_INICIAL = 7,        /* COMBUSTIBLE_INICIAL  */
  YYSYMBOL_UBICACION = 8,                  /* UBICACION  */
  YYSYMBOL_SET_DESTINO = 9,                /* SET_DESTINO  */
  YYSYMBOL_MOVER_AUTONOMO = 10,            /* MOVER_AUTONOMO  */
  YYSYMBOL_MODO_VIAJE = 11,                /* MODO_VIAJE  */
  YYSYMBOL_MENOR_COMBUSTIBLE = 12,         /* MENOR_COMBUSTIBLE  */
  YYSYMBOL_MENOR_GALAXIAS = 13,            /* MENOR_GALAXIAS  */
  YYSYMBOL_IDENTIFICADOR = 14,             /* IDENTIFICADOR  */
  YYSYMBOL_NUMERO = 15,                    /* NUMERO  */
  YYSYMBOL_REABASTECIBLE = 16,             /* REABASTECIBLE  */
  YYSYMBOL_SUB_GALAXIA = 17,               /* SUB_GALAXIA  */
  YYSYMBOL_GUIADO = 18,                    /* GUIADO  */
  YYSYMBOL_REABASTECER = 19,               /* REABASTECER  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 21,                  /* $accept  */
  YYSYMBOL_inicio = 22,                    /* inicio  */
  YYSYMBOL_instrucciones = 23,             /* instrucciones  */
  YYSYMBOL_instruccion = 24,               /* instruccion  */
  YYSYMBOL_numero_opcional = 25,           /* numero_opcional  */
  YYSYMBOL_modo_viaje_opcional = 26,       /* modo_viaje_opcional  */
  YYSYMBOL_modo_viaje = 27,                /* modo_viaje  */
  YYSYMBOL_opciones = 28                   /* opciones  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   37

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  20
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  41

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   114,   115,   119,   122,   125,   128,   138,
     141,   147,   148,   152,   153,   157,   158,   162,   163,   164,
     165
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CREAR_GALAXIA",
  "CONECTAR_GALAXIAS", "ESTABLECER_PESO", "CREAR_NAVE",
  "COMBUSTIBLE_INICIAL", "UBICACION", "SET_DESTINO", "MOVER_AUTONOMO",
  "MODO_VIAJE", "MENOR_COMBUSTIBLE", "MENOR_GALAXIAS", "IDENTIFICADOR",
  "NUMERO", "REABASTECIBLE", "SUB_GALAXIA", "GUIADO", "REABASTECER", "';'",
  "$accept", "inicio", "instrucciones", "instruccion", "numero_opcional",
  "modo_viaje_opcional", "modo_viaje", "opciones", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-13)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,    -5,    -1,     0,     5,     1,     2,    16,    -3,   -13,
     -13,     4,     6,     7,     3,   -13,     8,   -13,   -13,   -12,
       9,    10,    13,   -13,    -2,    11,    12,   -13,   -13,    14,
      15,    18,   -13,   -13,   -13,   -13,   -13,   -13,   -13,    17,
     -13
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    12,     0,     2,     4,
      17,     0,     0,     0,     0,    11,    14,     1,     3,     0,
       0,     0,     0,     9,     0,     0,    18,    19,     5,     0,
       0,     0,    15,    16,    13,    10,    20,     6,     7,     0,
       8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,   -13,   -13,    19,   -13,   -13,   -13,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    16,    25,    34,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     2,     3,     4,    26,    27,     5,     6,    28,    10,
      32,    33,    13,    11,    12,    14,    17,    15,    20,    24,
      21,    31,    22,    23,    29,    30,     0,    18,     0,    36,
       0,    35,    39,     0,    37,    38,     0,    40
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,    16,    17,     9,    10,    20,    14,
      12,    13,     7,    14,    14,    14,     0,    15,    14,    11,
      14,     8,    15,    20,    15,    15,    -1,     8,    -1,    17,
      -1,    20,    14,    -1,    20,    20,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    22,    23,    24,
      14,    14,    14,     7,    14,    15,    25,     0,    24,    28,
      14,    14,    15,    20,    11,    26,    16,    17,    20,    15,
      15,     8,    12,    13,    27,    20,    17,    20,    20,    14,
      20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    21,    22,    23,    23,    24,    24,    24,    24,    24,
      24,    25,    25,    26,    26,    27,    27,    28,    28,    28,
      28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     4,     5,     5,     6,     3,
       4,     1,     0,     2,     0,     1,     1,     0,     2,     2,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* instruccion: CREAR_GALAXIA IDENTIFICADOR opciones ';'  */
#line 119 "parser.y"
                                             {
        agregar_galaxia((yyvsp[-2].str) , (yyvsp[-1].opciones).reabastece , (yyvsp[-1].opciones).sub_galaxia);
    }
#line 1184 "parser.tab.c"
    break;

  case 6: /* instruccion: CONECTAR_GALAXIAS IDENTIFICADOR IDENTIFICADOR NUMERO ';'  */
#line 122 "parser.y"
                                                               {
        conectar_galaxias((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].num));
    }
#line 1192 "parser.tab.c"
    break;

  case 7: /* instruccion: ESTABLECER_PESO IDENTIFICADOR IDENTIFICADOR NUMERO ';'  */
#line 125 "parser.y"
                                                             {
        establecer_peso((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].num));
    }
#line 1200 "parser.tab.c"
    break;

  case 8: /* instruccion: CREAR_NAVE COMBUSTIBLE_INICIAL NUMERO UBICACION IDENTIFICADOR ';'  */
#line 128 "parser.y"
                                                                        {
        if (!galaxia_existe((yyvsp[-1].str))) {
            printf("Error: La galaxia '%s' no existe.\n", (yyvsp[-1].str));
            YYABORT;
        }
        nave.combustible = (yyvsp[-3].num);
        nave.ubicacion_actual = strdup((yyvsp[-1].str));
        nave.destino = NULL;
        printf("Nave creada con combustible %d en la galaxia '%s'.\n", (yyvsp[-3].num), (yyvsp[-1].str));
    }
#line 1215 "parser.tab.c"
    break;

  case 9: /* instruccion: SET_DESTINO IDENTIFICADOR ';'  */
#line 138 "parser.y"
                                    {
        establecer_destino((yyvsp[-1].str));
    }
#line 1223 "parser.tab.c"
    break;

  case 10: /* instruccion: MOVER_AUTONOMO numero_opcional modo_viaje_opcional ';'  */
#line 141 "parser.y"
                                                             {
        mover_autonomo((yyvsp[-2].num), (yyvsp[-1].num));
    }
#line 1231 "parser.tab.c"
    break;

  case 11: /* numero_opcional: NUMERO  */
#line 147 "parser.y"
           { (yyval.num) = (yyvsp[0].num); }
#line 1237 "parser.tab.c"
    break;

  case 12: /* numero_opcional: %empty  */
#line 148 "parser.y"
                   { (yyval.num) = -1; }
#line 1243 "parser.tab.c"
    break;

  case 13: /* modo_viaje_opcional: MODO_VIAJE modo_viaje  */
#line 152 "parser.y"
                          { (yyval.num) = (yyvsp[0].num); }
#line 1249 "parser.tab.c"
    break;

  case 14: /* modo_viaje_opcional: %empty  */
#line 153 "parser.y"
                   { (yyval.num) = 1; }
#line 1255 "parser.tab.c"
    break;

  case 15: /* modo_viaje: MENOR_COMBUSTIBLE  */
#line 157 "parser.y"
                      { (yyval.num) = 1; }
#line 1261 "parser.tab.c"
    break;

  case 16: /* modo_viaje: MENOR_GALAXIAS  */
#line 158 "parser.y"
                      { (yyval.num) = 2; }
#line 1267 "parser.tab.c"
    break;

  case 17: /* opciones: %empty  */
#line 162 "parser.y"
    {(yyval.opciones).opciones.reabastece =0; (yyval.opciones).opciones.sub_galaxia=0;}
#line 1273 "parser.tab.c"
    break;

  case 18: /* opciones: opciones REABASTECIBLE  */
#line 163 "parser.y"
                             {(yyval.opciones).opciones.reabastece = 1; (yyval.opciones).opciones.sub_galaxia = (yyvsp[-1].opciones).opciones.sub_galaxia;}
#line 1279 "parser.tab.c"
    break;

  case 19: /* opciones: opciones SUB_GALAXIA  */
#line 164 "parser.y"
                           { (yyval.opciones).opciones.sub_galaxia = 1; (yyval.opciones).opciones.reabastece = (yyvsp[-1].opciones).opciones.reabastece;}
#line 1285 "parser.tab.c"
    break;

  case 20: /* opciones: opciones REABASTECIBLE SUB_GALAXIA  */
#line 165 "parser.y"
                                         {(yyval.opciones).opciones.reabastece = 1; (yyval.opciones).opciones.sub_galaxia = 1; }
#line 1291 "parser.tab.c"
    break;


#line 1295 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 167 "parser.y"


/* Código C adicional */

/* Función para manejar errores de sintaxis */
void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

/* Función para agregar una galaxia a la lista */
void agregar_galaxia(char *nombre) {
    if (galaxia_existe(nombre)) {
        printf("Advertencia: La galaxia '%s' ya existe.\n", nombre);
        return;
    }
    Galaxia *nueva = (Galaxia *)malloc(sizeof(Galaxia));
    nueva->nombre = strdup(nombre);
    nueva->puede_reabastecer = reabastece; // Por defecto, no puede reabastecer
    nueva->siguiente = lista_galaxias;
    nueva->sub_galaxia = sub_galaxia;
    lista_galaxias = nueva;


    // Agregar al mapeo de índices
    if (num_galaxias >= MAX_GALAXIAS) {
        printf("Error: Se ha alcanzado el número máximo de galaxias.\n");
        exit(1);
    }
    galaxias_indices[num_galaxias] = nueva->nombre;
    adyacentes[num_galaxias] = NULL; // Inicializar la lista de adyacencia
    num_galaxias++;

    printf("Galaxia '%s' creada.\n", nombre);
}

/* Función para conectar dos galaxias con un peso */
void conectar_galaxias(char *g1, char *g2, int peso) {
    if (!galaxia_existe(g1) || !galaxia_existe(g2)) {
        printf("Error: Una de las galaxias no existe.\n");
        return;
    }

    Galaxia *galaxia1 = buscar_galaxia(g1);
    Galaxia *galaxia2 = buscar_galaxia(g2);

    int indice1 = obtener_indice_galaxia(g1);
    int indice2 = obtener_indice_galaxia(g2);

    NodoAdyacente *nodo = adyacentes[indice1];
    while (nodo != NULL) {
        if (nodo->indice_galaxia == indice2) {
            printf("Error: Ya existe una conexión entre '%s' y '%s'.\n", g1, g2);
            return;
        }
        nodo = nodo->siguiente;
    }

    // Añadir la arista a la lista de aristas
    Arista *nueva = (Arista *)malloc(sizeof(Arista));
    nueva->galaxia1 = strdup(g1);
    nueva->galaxia2 = strdup(g2);
    nueva->peso = peso;
    nueva->siguiente = lista_aristas;
    lista_aristas = nueva;

    // Añadir a las listas de adyacencia

    NodoAdyacente *nodo1 = (NodoAdyacente *)malloc(sizeof(NodoAdyacente));
    nodo1->indice_galaxia = indice2;
    nodo1->peso = peso;
    nodo1->siguiente = adyacentes[indice1];
    adyacentes[indice1] = nodo1;

    NodoAdyacente *nodo2 = (NodoAdyacente *)malloc(sizeof(NodoAdyacente));
    nodo2->indice_galaxia = indice1;
    nodo2->peso = peso;
    nodo2->siguiente = adyacentes[indice2];
    adyacentes[indice2] = nodo2;

    printf("Galaxias '%s' y '%s' conectadas con peso %d.\n", g1, g2, peso);
}

/* Función para establecer o modificar el peso entre dos galaxias */
void establecer_peso(char *g1, char *g2, int peso) {
    Arista *actual = lista_aristas;
    int encontrado = 0;
    while (actual != NULL) {
        if ((strcmp(actual->galaxia1, g1) == 0 && strcmp(actual->galaxia2, g2) == 0) ||
            (strcmp(actual->galaxia1, g2) == 0 && strcmp(actual->galaxia2, g1) == 0)) {
            actual->peso = peso;
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    }
    if (encontrado) {
        // Actualizar las listas de adyacencia
        int indice1 = obtener_indice_galaxia(g1);
        int indice2 = obtener_indice_galaxia(g2);

        NodoAdyacente *nodo = adyacentes[indice1];
        while (nodo != NULL) {
            if (nodo->indice_galaxia == indice2) {
                nodo->peso = peso;
                break;
            }
            nodo = nodo->siguiente;
        }

        nodo = adyacentes[indice2];
        while (nodo != NULL) {
            if (nodo->indice_galaxia == indice1) {
                nodo->peso = peso;
                break;
            }
            nodo = nodo->siguiente;
        }

        printf("Peso entre '%s' y '%s' establecido a %d.\n", g1, g2, peso);
    } else {
        printf("Error: No existe una conexión entre '%s' y '%s'.\n", g1, g2);
    }
}

/* Función para establecer el destino de la nave */
void establecer_destino(char *nombre_galaxia) {
    if (!galaxia_existe(nombre_galaxia)) {
        printf("Error: La galaxia '%s' no existe.\n", nombre_galaxia);
        return;
    }
    if (nave.destino != NULL) {
        free(nave.destino);
    }
    nave.destino = strdup(nombre_galaxia);
    printf("Destino establecido a '%s'.\n", nombre_galaxia);
}

/* Función para mover la nave de forma autónoma */
void mover_autonomo(int pasos, int modo_viaje) {
    if (nave.destino == NULL) {
        printf("Error: No se ha establecido un destino.\n");
        return;
    }
    Ruta *ruta = calcular_ruta(nave.ubicacion_actual, nave.destino, modo_viaje);
    if (ruta == NULL) {
        printf("Error: No es posible llegar al destino desde la galaxia actual.\n");
        return;
    }

    // Mostrar la ruta calculada
    printf("Ruta calculada: ");
    Ruta *temp = ruta;
    while (temp != NULL) {
        printf("%s ", temp->galaxia);
        temp = temp->siguiente;
    }
    printf("\n");

    // Si pasos es -1, avanzamos hasta el final de la ruta
    if (pasos == -1) {
        pasos = INT_MAX;
    }

    // Avanzar 'pasos' en la ruta
    Ruta *actual = ruta->siguiente; // Iniciar desde el siguiente a la ubicación actual
    int pasos_avanzados = 0;
    while (pasos_avanzados < pasos && actual != NULL) {
        int consumo = obtener_consumo(nave.ubicacion_actual, actual->galaxia);
        if (consumo == -1) {
            printf("Error: No hay conexión directa entre '%s' y '%s'.\n", nave.ubicacion_actual, actual->galaxia);
            break;
        }
        if (nave.combustible < consumo) {
            printf("Error: Combustible insuficiente para llegar a '%s'.\n", actual->galaxia);
            break;
        }
        nave.combustible -= consumo;
        nave.ubicacion_actual = actual->galaxia;
        printf("La nave se ha movido a '%s'. Combustible restante: %d.\n", nave.ubicacion_actual, nave.combustible);
        actual = actual->siguiente;
        pasos_avanzados++;
    }

    // Liberar la memoria de la ruta
    while (ruta != NULL) {
        Ruta *siguiente = ruta->siguiente;
        free(ruta->galaxia);
        free(ruta);
        ruta = siguiente;
    }
}

void reabastecer(){
    Galaxia *actual = buscar_galaxia(nave.ubicacion_actual);
    if (actual == NULL){
        printf("Error: La galaxia actual no existe.\n");
        return;
    }
    if (actual->puede_reabastecer){
        nave.combustible = 100;
        printf("La nave ha sido reabastecida en la galaxia '%s'.\n", nave.ubicacion_actual);
    } else {
        printf("Error: La galaxia '%s' no puede reabastecer.\n", nave.ubicacion_actual);
    }
}

void ejecutar_viaje_guiado(Ruta *ruta){
    if (ruta == NULL){
        printf("Error: No se ha encontrado una ruta.\n");
        return;
    }
    Ruta *actual = ruta;
    while (actual != NULL)
    {
        char *siguiente = actual->galaxia;
        if (strcmp(siguiente, nave.ubicacion_actual) == 0){
            actual = actual->siguiente;
            continue;
        }
        int consumo = obtener_consumo(nave.ubicacion_actual, siguiente);
        if (consumo == -1){
            printf("Error: No hay conexión directa entre '%s' y '%s'.\n", nave.ubicacion_actual, siguiente);
            break;
        }
        if (nave.combustible < consumo){
            printf("Error: Combustible insuficiente para llegar a '%s'.\n", siguiente);
            break;
        }
        nave.combustible -= consumo;
        free(nave.ubicacion_actual);
        nave.ubicacion_actual = strdup(siguiente);
        printf("La nave se ha movido a '%s'. Combustible restante: %d.\n", nave.ubicacion_actual, nave.combustible);
        actual = actual->siguiente;
        
    }
    printf("La nave ha llegado a su destino.\n");

    while (ruta != NULL){
        Ruta *siguiente = ruta->siguiente;
        free(ruta->galaxia);
        free(ruta);
        ruta = siguiente;
    }

}

void listar_vecinos(int radio){
    if (nave.ubicacion_actual == NULL){
        printf("Error: No se ha establecido una ubicación actual.\n");
        return;
    }
    int origen = obtener_indice_galaxia(nave.ubicacion_actual);
    if (origen == -1){
        printf("Error: La galaxia actual no existe.\n");
        return;
    }
    if (radio < 1){
        printf("Error: El radio debe ser mayor o igual a 1.\n");
        return;
    }

    int visitados[MAX_GALAXIAS] = {0};
    int result_count =0;
    char *result[MAX_GALAXIAS];

    listar_galaxias_en_radio(radio, origen, visitados,0, &result_count, result);

    printf("Galaxias en un radio de %d desde '%s':\n", radio, nave.ubicacion_actual);
    for (int i = 0; i < result_count; i++){
        printf("%s\n", result[i]);
    }
}

void listar_galaxias_en_radio(int radio, int origen ,int *visitados,int current ,int *result_count, char **result){
    if (current >radio) return;
    visitados[origen]=1;
    if(current >0){
        result[*result_count]=galaxias_indices[origen];
        (*result_count)++;
    }
    if (current == radio) return;

    NodoAdyacente *nodo = adyacentes[origen];
    while (nodo != NULL){
        if (!visitados[nodo->indice_galaxia]){
            listar_galaxias_en_radio(radio, nodo->indice_galaxia, current+1, result_count, result);
        }
        nodo = nodo->siguiente;
    }
}

void mover(char *galaxia){
    if (nave.ubicacion_actual == NULL){
        printf("Error: No se ha establecido una ubicación actual.\n");
        return;
    }

    if (!galaxia_existe(galaxia)){
        printf("Error: La galaxia '%s' no existe.\n", galaxia);
        return;
    }

    int origen = obtener_indice_galaxia(nave.ubicacion_actual);
    int destino = obtener_indice_galaxia(galaxia);

    if (origen ==-1 || destino ==-1){
        printf("Error: La galaxia origen o destino no existe.\n");
        return;
    }

    NodoAdyacente *nodo = adyacentes[origen];
    int consume =-1;
    while (nodo != NULL){
        if (nodo->indice_galaxia == destino){
            consume = nodo->peso;
            break;
        }
        nodo = nodo->siguiente;
    }

    if (consume ==-1){
        printf("Error: No hay conexión directa entre '%s' y '%s'.\n", nave.ubicacion_actual, galaxia);
        return;
    }

    if (nave.combustible < consume){
        printf("Error: Combustible insuficiente para llegar a '%s'.\n", galaxia);
        return;
    }

    nave.combustible -= consume;
    free(nave.ubicacion_actual);
    nave.ubicacion_actual = strdup(galaxia);
    printf("La nave se ha movido a '%s'. Combustible restante: %d.\n", nave.ubicacion_actual, nave.combustible);
    
}

void ejecutar_viaje(Ruta *ruta){
    if (ruta == NULL){
        printf("Error: No se ha encontrado una ruta.\n");
        return;
    }
    Ruta *actual = ruta;
    while (actual != NULL)
    {
        char *siguiente = actual->galaxia;

        if (strcmp(siguiente, nave.ubicacion_actual) == 0){
            actual = actual->siguiente;
            continue;
        }
        int consumo = obtener_consumo(nave.ubicacion_actual, siguiente);
        if (consumo == -1){
            printf("Error: No hay conexión directa entre '%s' y '%s'.\n", nave.ubicacion_actual, siguiente);
            break;
        }
        if (nave.combustible < consumo){
            printf("Error: Combustible insuficiente para llegar a '%s'.\n", siguiente);
            break;
        }
        nave.combustible -= consumo;
        free(nave.ubicacion_actual);
        nave.ubicacion_actual = strdup(siguiente);
        printf("La nave se ha movido a '%s'. Combustible restante: %d.\n", nave.ubicacion_actual, nave.combustible);
        actual = actual->siguiente;
    }
    printf("La nave ha llegado a su destino.\n");
    while (ruta!=NULL){
        Ruta *siguiente = ruta->siguiente;
        free(ruta->galaxia);
        free(ruta);
        ruta = siguiente;
    }
    
}

/* Función para calcular la ruta óptima */
Ruta* calcular_ruta(char *origen, char *destino, int modo_viaje) {
    if (modo_viaje == 1) {
        // Menor consumo de combustible (Dijkstra)
        return calcular_ruta_dijkstra(origen, destino);
    } else if (modo_viaje == 2) {
        // Menor cantidad de galaxias (BFS)
        return calcular_ruta_bfs(origen, destino);
    } else {
        printf("Error: Modo de viaje no válido.\n");
        return NULL;
    }
}

/* Implementación del algoritmo de Dijkstra */
Ruta* calcular_ruta_dijkstra(char *origen, char *destino) {
    int indice_origen = obtener_indice_galaxia(origen);
    int indice_destino = obtener_indice_galaxia(destino);

    if (indice_origen == -1 || indice_destino == -1) {
        printf("Error: Galaxia origen o destino no existe.\n");
        return NULL;
    }

    int distancias[MAX_GALAXIAS];
    int predecesores[MAX_GALAXIAS];
    int visitados[MAX_GALAXIAS] = {0};

    for (int i = 0; i < num_galaxias; i++) {
        distancias[i] = INT_MAX;
        predecesores[i] = -1;
    }
    distancias[indice_origen] = 0;

    for (int count = 0; count < num_galaxias - 1; count++) {
        int min_dist = INT_MAX;
        int u = -1;
        for (int v = 0; v < num_galaxias; v++) {
            if (!visitados[v] && distancias[v] <= min_dist) {
                min_dist = distancias[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }

        visitados[u] = 1;

        NodoAdyacente *nodo = adyacentes[u];
        while (nodo != NULL) {
            int v = nodo->indice_galaxia;
            int peso = nodo->peso;

            if (!visitados[v] && distancias[u] != INT_MAX && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
                predecesores[v] = u;
            }

            nodo = nodo->siguiente;
        }
    }

    if (distancias[indice_destino] == INT_MAX) {
        printf("Error: No hay ruta desde '%s' a '%s'.\n", origen, destino);
        return NULL;
    }

    // Reconstruir la ruta
    Ruta *ruta = NULL;
    int actual = indice_destino;
    while (actual != -1) {
        Ruta *nuevo_nodo = (Ruta *)malloc(sizeof(Ruta));
        nuevo_nodo->galaxia = strdup(galaxias_indices[actual]);
        nuevo_nodo->siguiente = ruta;
        ruta = nuevo_nodo;
        actual = predecesores[actual];
    }

    return ruta;
}

/* Implementación del algoritmo BFS */
Ruta* calcular_ruta_bfs(char *origen, char *destino) {
    int indice_origen = obtener_indice_galaxia(origen);
    int indice_destino = obtener_indice_galaxia(destino);

    if (indice_origen == -1 || indice_destino == -1) {
        printf("Error: Galaxia origen o destino no existe.\n");
        return NULL;
    }

    int visitados[MAX_GALAXIAS] = {0};
    int predecesores[MAX_GALAXIAS];
    for (int i = 0; i < num_galaxias; i++) {
        predecesores[i] = -1;
    }

    int cola[MAX_GALAXIAS];
    int inicio = 0, fin = 0;

    visitados[indice_origen] = 1;
    cola[fin++] = indice_origen;

    while (inicio < fin) {
        int u = cola[inicio++];
        if (u == indice_destino) {
            break;
        }
        NodoAdyacente *nodo = adyacentes[u];
        while (nodo != NULL) {
            int v = nodo->indice_galaxia;
            if (!visitados[v]) {
                visitados[v] = 1;
                predecesores[v] = u;
                cola[fin++] = v;
            }
            nodo = nodo->siguiente;
        }
    }

    if (!visitados[indice_destino]) {
        printf("Error: No hay ruta desde '%s' a '%s'.\n", origen, destino);
        return NULL;
    }

    // Reconstruir la ruta
    Ruta *ruta = NULL;
    int actual = indice_destino;
    while (actual != -1) {
        Ruta *nuevo_nodo = (Ruta *)malloc(sizeof(Ruta));
        nuevo_nodo->galaxia = strdup(galaxias_indices[actual]);
        nuevo_nodo->siguiente = ruta;
        ruta = nuevo_nodo;
        actual = predecesores[actual];
    }

    return ruta;
}

/* Función para obtener el consumo entre dos galaxias */
int obtener_consumo(char *g1, char *g2) {
    int indice1 = obtener_indice_galaxia(g1);
    int indice2 = obtener_indice_galaxia(g2);

    NodoAdyacente *nodo = adyacentes[indice1];
    while (nodo != NULL) {
        if (nodo->indice_galaxia == indice2) {
            return nodo->peso;
        }
        nodo = nodo->siguiente;
    }
    return -1; // No hay conexión
}

/* Función para verificar si una galaxia existe */
int galaxia_existe(char *nombre) {
    Galaxia *actual = lista_galaxias;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

/* Función para obtener el índice de una galaxia */
int obtener_indice_galaxia(char *nombre) {
    for (int i = 0; i < num_galaxias; i++) {
        if (strcmp(galaxias_indices[i], nombre) == 0) {
            return i;
        }
    }
    return -1; // No encontrado
}

Galaxia* buscar_galaxia(char *nombre){
    Galaxia *actual =lista_galaxias;
    while (actual !=NULL){
        if(strcmp(actual->nombre,nombre)==0){
            return actual;
        }
        actual=actual->siguiente
    }
    return NULL
}

Ruta* crear_ruta(char *galaxia){
    Ruta *nueva = (Ruta *)malloc(sizeof(Ruta));
    nueva->galaxia = strdup(galaxia);
    nueva->siguiente = NULL;
    return nueva;
}

Ruta* agregar_ruta(Ruta *ruta, char *galaxia){
    Ruta *nueva = crear_ruta(galaxia);
    Ruta *temp = ruta;
    while (temp->siguiente != NULL){
        temp = temp->siguiente;
    }
    temp->siguiente = nueva;
    return ruta;
}

/* Función principal */
int main(void) {
    printf("Iniciando el intérprete de galaxias...\n");
    yyparse();
    return 0;
}
