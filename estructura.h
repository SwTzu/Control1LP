#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    char* nombre;
    int puede_reabastecer;
} Galaxia;

typedef struct {
    Galaxia* galaxia1;
    Galaxia* galaxia2;
    int peso;
} Ruta;

typedef struct {
    Galaxia* ubicacion_actual;
    int combustible;
} Nave;

Galaxia* crear_galaxia(char* nombre, int puede_reabastecer);
Ruta* crear_ruta(Galaxia* galaxia1, Galaxia* galaxia2, int peso);
Nave* crear_nave(Galaxia* ubicacion_inicial, int combustible_inicial);
void modificar_peso_ruta(Ruta* ruta, int nuevo_peso);

Galaxia* buscar_galaxia(char* nombre);

#endif
