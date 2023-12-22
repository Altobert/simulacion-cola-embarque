#include <stdio.h>
#include <stdlib.h>

//estructura de datos para registrar los datos de la grua
typedef struct gruaCarga{
    int id;
    char *nombre;
    int capacidad;
    int estado; // 0: disponible, 1: ocupado
}gruaCarga;


//estructura para simular cola de embarques
//representacion cola de embarques: (c 1 , c 2 , c 3 , . . . , c n ).
typedef struct colaEmbarques{
    int identificador; //numero > 0 indica orden de llegada a la cola
    
    //(0, X, 2X,3X, . . . )
    int instanteLlegada; //instante de llegada a la cola > a cero o menor igual que el valor que el tiempo de la simulacion
    int idBarco;
    int peso;
    int estado; // 0: pendiente, 1: realizado
}colaEmbarques;

/*
En cada unidad de tiempo se debe verificar si se deben embarcar las cargas,
para esto se debe esperar una orden indicando que los barcos están dispuestos en
cierto orden en el puerto y que se puede iniciar un periodo de embarque.
*/

/*
Al momento
de ser recibida la orden, se deben embarcar todas las cargas que estén esperando en
ese instante, asumiendo un tiempo de embarque de una unidad de tiempo por cada
carga. En caso de que durante un perı́odo de embarque arribe una nueva carga a la
cola, esta no será embarcada, teniendo que esperar en la cola hasta que se active el siguiente perı́odo de embarque.
*/
