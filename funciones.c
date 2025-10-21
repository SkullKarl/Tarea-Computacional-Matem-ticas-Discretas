#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "funciones.h"

// Función algoritmo de Dijkstra (Encuentra el camino más corto entre dos vertices dada la matriz de adyacencia de un grafo)
void dijkstra(int n, int grafo[n][n], int origen, int destino) {
    int distancia[n];
    bool visto[n];
    int padre[n];

    // Inicializamos el algoritmo con distancias al infinito, sin visitar ningun vertice y por lo tanto sin vertice padre
    for (int i = 0; i < n; i++) {
        distancia[i] = INT_MAX;
        visto[i] = false;
        padre[i] = -1;
    }

    // La distancia del origen a el mismo es 0
    distancia[origen] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min_distancia = INT_MAX;
        int u = -1;

        // Se selecciona el vertice no visitado con menor distancia conocida
        for (int v = 0; v < n; v++) {
            if (!visto[v] && distancia[v] < min_distancia) {
                min_distancia = distancia[v];
                u = v;
            }
        }

        // Si no se puede alcanzar ningun vertice, salimos del bucle
        if (u == -1) {
            break;
        }

        // Marcamos a u como visitado
        visto[u] = true;

        // 
        for (int v = 0; v < n; v++) {
            if (!visto[v] && grafo[u][v] != 0 && distancia[u] != INT_MAX) {
                int alt = distancia[u] + 1; // peso = 1
                if (alt < distancia[v]) {
                    distancia[v] = alt;
                    padre[v] = u; // registrar al padre sirve para reconstruir el camino más adelante
                }
            }
        }
    }

    // El destino no se puede alcanzar desde el origen
    if (distancia[destino] == INT_MAX) {
        printf("No existe un camino desde el vértice '%c' hasta el vértice '%c'\n", origen + 'a', destino + 'a');
        return;
    } else {
        // Se imprime la distancia minima y luego se construye el camino usando el arreglo padre
        printf("La distancia mínima desde el vértice '%c' hasta el vértice '%c' es: %d\n", origen + 'a', destino + 'a', distancia[destino]);
        int camino[n];
        int indice = 0;
        for (int v = destino; v != -1; v = padre[v]) {
            camino[indice++] = v;
        }
        printf("Camino: ");
        for (int i = indice - 1; i >= 0; i--) {
            printf("%c", camino[i] + 'a');
            if (i > 0) printf(" -> ");
        }
        printf("\n");
    }
}