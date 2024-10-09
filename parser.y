%{
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
%}

/* Definición de tipos de datos para los tokens */
%union {
    char *str;
    int num;
}

/* Declaración de tokens con sus tipos */
%token CREAR_GALAXIA CONECTAR_GALAXIAS ESTABLECER_PESO CREAR_NAVE COMBUSTIBLE_INICIAL UBICACION
%token SET_DESTINO MOVER_AUTONOMO MODO_VIAJE MENOR_COMBUSTIBLE MENOR_GALAXIAS
%token <str> IDENTIFICADOR
%token <num> NUMERO

/* Declaración de tipos para no terminales */
%type <num> numero_opcional modo_viaje_opcional modo_viaje

/* Precedencia y asociatividad de operadores */
%left ';'

%%

/* Reglas gramaticales */
inicio:
    instrucciones
    ;

instrucciones:
    instrucciones instruccion
    | instruccion
    ;

instruccion:
    CREAR_GALAXIA IDENTIFICADOR ';' {
        agregar_galaxia($2);
    }
    | CONECTAR_GALAXIAS IDENTIFICADOR IDENTIFICADOR NUMERO ';' {
        conectar_galaxias($2, $3, $4);
    }
    | ESTABLECER_PESO IDENTIFICADOR IDENTIFICADOR NUMERO ';' {
        establecer_peso($2, $3, $4);
    }
    | CREAR_NAVE COMBUSTIBLE_INICIAL NUMERO UBICACION IDENTIFICADOR ';' {
        if (!galaxia_existe($5)) {
            printf("Error: La galaxia '%s' no existe.\n", $5);
            YYABORT;
        }
        nave.combustible = $3;
        nave.ubicacion_actual = strdup($5);
        nave.destino = NULL;
        printf("Nave creada con combustible %d en la galaxia '%s'.\n", $3, $5);
    }
    | SET_DESTINO IDENTIFICADOR ';' {
        establecer_destino($2);
    }
    | MOVER_AUTONOMO numero_opcional modo_viaje_opcional ';' {
        mover_autonomo($2, $3);
    }
    ;

numero_opcional:
    NUMERO { $$ = $1; }
    | /* vacío */ { $$ = -1; } // -1 indica avanzar hasta el destino
    ;

modo_viaje_opcional:
    MODO_VIAJE modo_viaje { $$ = $2; }
    | /* vacío */ { $$ = 1; } // Por defecto, menor combustible
    ;

modo_viaje:
    MENOR_COMBUSTIBLE { $$ = 1; }
    | MENOR_GALAXIAS  { $$ = 2; }
    ;

%%

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
    nueva->puede_reabastecer = 0; // Por defecto, no puede reabastecer
    nueva->siguiente = lista_galaxias;
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
    // Añadir la arista a la lista de aristas
    Arista *nueva = (Arista *)malloc(sizeof(Arista));
    nueva->galaxia1 = strdup(g1);
    nueva->galaxia2 = strdup(g2);
    nueva->peso = peso;
    nueva->siguiente = lista_aristas;
    lista_aristas = nueva;

    // Añadir a las listas de adyacencia
    int indice1 = obtener_indice_galaxia(g1);
    int indice2 = obtener_indice_galaxia(g2);

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

/* Función principal */
int main(void) {
    printf("Iniciando el intérprete de galaxias...\n");
    yyparse();
    return 0;
}
