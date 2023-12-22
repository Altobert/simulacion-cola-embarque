#include <stdio.h>
#include <stdlib.h>
#include "tda_gruaCarga.h"

// La funcion debe retornar, con cierta probabilidad, un 1 si se puede embarcar o un 0 si no se puede embarcar
int embarcar(int probabilidad){
    int embarcar = 0;
    int probabilidad = 0;
    int probabilidad = rand() % 100;
    if (probabilidad <= 50){
        embarcar = 1;
    }
    else{
        embarcar = 0;
    }
    return embarcar;
}

// Crear cola de embarque
colaEmbarques * crearColaEmbarques(int n){
    colaEmbarques *cola = NULL;
    cola = (colaEmbarques *)malloc(sizeof(colaEmbarques));
    if(cola == NULL){
        printf("No se pudo crear la cola de embarques");
        exit(1);
    }
    cola->identificador = 0;
    cola->instanteLlegada = 0;
    cola->estado = 0;
    cola->siguiente = NULL;
    return cola;
}


