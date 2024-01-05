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
  struct nodo * sig;
};

// Punteros a frente y fin de la cola
struct nodo * frente = NULL;
struct nodo * fin = NULL;

// Encola una carga
void encolar(struct carga c) {

  struct nodo * nuevo = malloc(sizeof(struct nodo));
  nuevo -> dato = c;
  nuevo -> sig = NULL;

  if (frente == NULL) {
    frente = nuevo;
  } else {
    fin -> sig = nuevo;
  }
  fin = nuevo;


}

// Saca carga de la cola  
struct carga desencolar() {

  struct carga c = frente -> dato;
  struct nodo * temp = frente;

  frente = frente -> sig;

  if (frente == NULL) {
    fin = NULL;
  }

  free(temp);
  return c;

}

// Función probabilidad de embarque
bool embarcar(float probabilidad) {

  bool embarque;

  float valor_aleatorio = rand() / (float) RAND_MAX;

  if (valor_aleatorio <= probabilidad) {
    embarque = true;
  } else {
    embarque = false;
  }

  return embarque;
}

void main() {

  // Variables 
  int tiempo_total = 3000;
  int intervalo_llegada = 1;
  float prob_embarque = 0.5;

  int tiempo_actual = 0;
  int num_cargas = 2000;
  int total_embarcadas = 0;
  float suma_tiempos_cola = 0;

  struct carga c;

  // Bucle principal
  while (tiempo_actual < tiempo_total) {

    // Verificar llegada de cargas
    if (tiempo_actual % intervalo_llegada == 0) {

      c.id = num_cargas;
      c.tiempo_llegada = tiempo_actual;

      printf("encola : %d ",c.id);

      encolar(c);
      num_cargas++;
    }

    // Intentar embarques
    if (embarcar(prob_embarque)) {

      while (frente != NULL) {

        c = desencolar();
        
        printf("desencola : %d ",c.id);
        //printf("carga embarcada: %d\n", total_cargas_embarcadas);

        c.tiempo_embarque = tiempo_actual;

        int tiempo_en_cola = tiempo_actual - c.tiempo_llegada;

        suma_tiempos_cola += tiempo_en_cola;

        total_embarcadas++;

      }

    }

    tiempo_actual++;

    // Estadísticas finales
    int total_cargas_embarcadas = 0;
    int total_cargas_no_embarcadas = 0;
    int tiempo_total_permanencia = 0;

    // Recorrer la cola para calcular estadísticas
    struct nodo * actual = frente;
    while (actual != NULL) {
      // Calcular estadísticas
      if (actual -> dato.tiempo_embarque != -1) {
        total_cargas_embarcadas++;
        tiempo_total_permanencia += actual -> dato.tiempo_embarque - actual -> dato.tiempo_llegada;
      } else {
        total_cargas_no_embarcadas++;
      }

      // Mover al siguiente nodo
      actual = actual -> sig;
    }

    // Calcular el tiempo promedio de permanencia
    float tiempo_promedio_permanencia = (float) tiempo_total_permanencia / total_cargas_embarcadas;

    // Mostrar estadísticas finales
    //printf("Resumen de la simulación:\n");
    printf("Tiempo total de simulación: %d unidades de tiempo\n", tiempo_total);
    //printf("Número total de cargas embarcadas: %d\n", total_cargas_embarcadas);
    //printf("Número total de cargas no embarcadas: %d\n", total_cargas_no_embarcadas);

    printf("carga embarcada: %d\n", total_cargas_embarcadas);
    printf("carga no embarcadas: %d\n", total_cargas_no_embarcadas);
    //printf("Tiempo promedio de permanencia de las cargas embarcadas: %.2f unidades de tiempo\n", tiempo_promedio_permanencia);

  }

  // Estadísticas
  float promedio_cola = suma_tiempos_cola / total_embarcadas;

  printf("Resumen General:\n");
  printf("Tiempos en cola: %.2f (prom.)\n", promedio_cola);
  printf("Total embarcadas: %d\n", total_embarcadas);

}