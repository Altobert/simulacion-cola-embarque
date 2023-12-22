#include <stdio.h>
#include <stdlib.h>

//estructura para simular cola de embarques
//representacion cola de embarques: (c 1 , c 2 , c 3 , . . . , c n ).
typedef struct colaEmbarques{
        
    //(0, X, 2X,3X, . . . )
    //X: tiempo de embarque de una carga
    //0: tiempo de embarque de una carga
    //2X: tiempo de embarque de una carga
    //3X: tiempo de embarque de una carga
    // . . . : tiempo de embarque de una carga
    int identificador;   //numero > 0 indica orden de llegada a la cola
    int instanteLlegada; //instante de llegada a la cola > a cero o menor igual que el valor que el tiempo de la simulacion        
    int estado;          // 0: pendiente, 1: realizado
    struct colaEmbarques *siguiente;
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

/*
Se le solicita a usted la construcción de un programa en lenguaje C que simule el
comportamiento de una cola de embarque. Para su programa considere:
*/


//funcion que retorna un numero aleatorio entre 0 y 1
bool embarcar(int probabilidad);

/**
 * @brief Inserta un elemento en la cola de embarques.
 * 
 * @param cola La cola de embarques.
 * @param identificador El identificador del elemento a insertar.
 * @param instanteLlegada El instante de llegada del elemento a insertar.
 * 
  */
/**
 * @brief Crea una cola de embarques.
 * 
 * @param n El tamaño de la cola de embarques.
 * @return Un puntero a la cola de embarques creada.
 */
colaEmbarques * crearColaEmbarques(int n);



