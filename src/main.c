#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "LoadGraph.h"
#include "orientacion.h"

int main(int argc, char *argv[]) {
    
    //codigo para depuracion (ver si estan bien los argumentos de entrada para ejecutar el programa)
    //printf("argc = %d\n", argc);
    //for (int i = 0; i < argc; i++) {
    //    printf("argv[%d] = %s\n", i, argv[i]);
    //}
    if (argc < 4) {
        fprintf(stderr, "Uso: %s <origen> <destino> <archivo_grafo> [nodir|dir] [1..4]\n", argv[0]);
        return 1;
    }

    char origenChar = argv[1][0];
    char destinoChar = argv[2][0];
    const char *filename = argv[3];

    //para codigo de orientacion.c
    int isDirigido = 0;
    int orientacion = 1;
    if (argc >= 5 && strcmp(argv[4], "dir") == 0) isDirigido = 1;
    if (argc >= 6) {
        orientacion = atoi(argv[5]);
        if (orientacion < 1 || orientacion > 4) orientacion = 1;
    }

    //
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
    if (!isDirigido){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
             matriz[i][j] = graph[i][j];
    }else {
        orientarGrafo(n, graph, matriz, orientacion);
    }
    
    dijkstra(n, matriz, origen, destino);

    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);

    return 0;
}