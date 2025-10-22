#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "LoadGraph.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <origen> <destino> <archivo_grafo>\n", argv[0]);
        return 1;
    }

    char origenChar = argv[1][0];
    char destinoChar = argv[2][0];
    const char *filename = argv[3];
    int n;
    int **graph = LoadGraph(filename, &n);
    int origen = origenChar - 'a';
    int destino = destinoChar - 'a';
    if (origen < 0 || origen >= n || destino < 0 || destino >= n) {
        fprintf(stderr, "Error: los vértices deben estar entre 'a' y '%c'\n", 'a' + n - 1);
        for (int i = 0; i < n; i++)
            free(graph[i]);
        free(graph);
        return 1;
    }

    int matriz[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = graph[i][j];

    dijkstra(n, matriz, origen, destino);
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);

    return 0;
}