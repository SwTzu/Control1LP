#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Galaxia
typedef struct {
    char* nombre;
    int puede_reabastecer;
} Galaxia;

// Definición de la estructura Ruta
typedef struct {
    Galaxia* galaxia1;
    Galaxia* galaxia2;
    int peso;
} Ruta;

// Definición de la estructura Nave
typedef struct {
    Galaxia* ubicacion_actual;
    int combustible;
} Nave;

// Función para crear una nueva galaxia
Galaxia* crear_galaxia(char* nombre, int puede_reabastecer) {
    Galaxia* nueva_galaxia = (Galaxia*)malloc(sizeof(Galaxia));
    nueva_galaxia->nombre = strdup(nombre);
    nueva_galaxia->puede_reabastecer = puede_reabastecer;
    return nueva_galaxia;
}

// Función para crear una nueva ruta entre dos galaxias
Ruta* crear_ruta(Galaxia* galaxia1, Galaxia* galaxia2, int peso) {
    Ruta* nueva_ruta = (Ruta*)malloc(sizeof(Ruta));
    nueva_ruta->galaxia1 = galaxia1;
    nueva_ruta->galaxia2 = galaxia2;
    nueva_ruta->peso = peso;
    return nueva_ruta;
}

// Función para crear la nave
Nave* crear_nave(Galaxia* ubicacion_inicial, int combustible_inicial) {
    Nave* nueva_nave = (Nave*)malloc(sizeof(Nave));
    nueva_nave->ubicacion_actual = ubicacion_inicial;
    nueva_nave->combustible = combustible_inicial;
    return nueva_nave;
}

// Función para modificar el peso de una ruta
void modificar_peso_ruta(Ruta* ruta, int nuevo_peso) {
    ruta->peso = nuevo_peso;
}

// Función para mostrar información de una galaxia
void mostrar_galaxia(Galaxia* galaxia) {
    printf("Galaxia: %s, Puede reabastecer: %s\n", galaxia->nombre, galaxia->puede_reabastecer ? "Sí" : "No");
}

// Función para mostrar la ruta entre dos galaxias
void mostrar_ruta(Ruta* ruta) {
    printf("Ruta entre %s y %s, Peso: %d\n", ruta->galaxia1->nombre, ruta->galaxia2->nombre, ruta->peso);
}

// Función para mostrar el estado de la nave
void mostrar_nave(Nave* nave) {
    printf("La nave está en %s con %d unidades de combustible.\n", nave->ubicacion_actual->nombre, nave->combustible);
}

int main() {
    // Crear galaxias
    Galaxia* galaxiaA = crear_galaxia("Galaxia A", 1);  // Puede reabastecer
    Galaxia* galaxiaB = crear_galaxia("Galaxia B", 0);  // No puede reabastecer

    // Crear ruta entre galaxias
    Ruta* rutaAB = crear_ruta(galaxiaA, galaxiaB, 50);  // Peso 50

    // Crear la nave en Galaxia A con 100 de combustible
    Nave* nave = crear_nave(galaxiaA, 100);

    // Mostrar información
    mostrar_galaxia(galaxiaA);
    mostrar_galaxia(galaxiaB);
    mostrar_ruta(rutaAB);
    mostrar_nave(nave);

    // Modificar el peso de la ruta
    modificar_peso_ruta(rutaAB, 30);
    printf("\nDespués de modificar el peso de la ruta:\n");
    mostrar_ruta(rutaAB);

    // Liberar memoria (opcional)
    free(galaxiaA->nombre);
    free(galaxiaA);
    free(galaxiaB->nombre);
    free(galaxiaB);
    free(rutaAB);
    free(nave);

    return 0;
}
