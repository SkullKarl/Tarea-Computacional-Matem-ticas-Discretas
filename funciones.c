#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "funciones.h"

void dijkstra(int n, int grafo[n][n], int origen, int destino) {
    int distancia[n];
    bool visto[n];
    int padre[n];

    for (int i = 0; i < n; i++) {
        distancia[i] = INT_MAX;
        visto[i] = false;
        padre[i] = -1;
    }

    distancia[origen] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min_distancia = INT_MAX;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!visto[v] && distancia[v] < min_distancia) {
                min_distancia = distancia[v];
                u = v;
            }
        }

        if (u == -1) {
            // No remaining reachable vertices
            break;
        }

        visto[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visto[v] && grafo[u][v] != 0 && distancia[u] != INT_MAX) {
                int alt = distancia[u] + 1; // peso = 1
                if (alt < distancia[v]) {
                    distancia[v] = alt;
                    padre[v] = u;
                }
            }
        }
    }

    if (distancia[destino] == INT_MAX) {
        printf("No hay camino desde el nodo %d hasta el nodo %d\n", origen, destino);
        return;
    } else {
        printf("La distancia mínima desde el vertice '%c' hasta el vertice '%c' es: %d\n", origen + 'a', destino + 'a', distancia[destino]);
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