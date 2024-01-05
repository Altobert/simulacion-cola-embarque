// Bibliotecas
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

// Estructura Carga 
struct carga {
  int id;
  int tiempo_llegada;
  int tiempo_embarque;  
};

// Nodo de la cola
struct nodo {
   struct carga dato;
   struct nodo* sig; 
};

// Punteros a frente y fin de la cola
struct nodo* frente = NULL;
struct nodo* fin = NULL;


// Encola una carga
void encolar(struct carga c) {
  
  struct nodo* nuevo = malloc(sizeof(struct nodo));
  nuevo->dato = c;
  nuevo->sig = NULL;  

  if(frente == NULL) {
    frente = nuevo;
  } else {
    fin->sig = nuevo;
  }

  fin = nuevo;  

}

// Saca carga de la cola  
struct carga desencolar() {

  struct carga c = frente->dato;  
  struct nodo* temp = frente;

  frente = frente->sig;  

  if(frente == NULL){
    fin = NULL;
  }

  free(temp);    
  return c;

}


// Función probabilidad de embarque
bool embarcar(float probabilidad) {  
  
  bool embarque;
  
  float valor_aleatorio = rand() / (float)RAND_MAX;
  
  if(valor_aleatorio <= probabilidad) {
    embarque = true;
  } else {
    embarque = false;
  }

  return embarque;  
}


void main() {

  // Variables 
  int tiempo_total = 1000;
  int intervalo_llegada = 10;
  float prob_embarque = 0.1;  
  
  int tiempo_actual = 0;
  int num_cargas = 50;
  int total_embarcadas = 0;
  float suma_tiempos_cola = 0;
  
  struct carga c; 
  
  // Bucle principal
  while(tiempo_actual < tiempo_total) {

    // Verificar llegada de cargas
    if(tiempo_actual % intervalo_llegada == 0) {
    
      c.id = num_cargas;
      c.tiempo_llegada = tiempo_actual;
              
      encolar(c);
      num_cargas++;    
    }
    
    // Intentar embarques
    if(embarcar(prob_embarque)) {
      
      while(frente != NULL) {
       
        c = desencolar();
        
        c.tiempo_embarque = tiempo_actual; 
        
        int tiempo_en_cola = tiempo_actual - c.tiempo_llegada;
        
        suma_tiempos_cola += tiempo_en_cola;
        
        total_embarcadas++;
        
      }
      
    }
   
    tiempo_actual++;
    
  } 
  
  // Estadísticas
  float promedio_cola = suma_tiempos_cola / total_embarcadas;  
  
  printf("Resumen:\n");
  printf("Tiempos en cola: %.2f (prom.)\n", promedio_cola);
  printf("Total embarcadas: %d\n", total_embarcadas);

  //return 0;  
}

