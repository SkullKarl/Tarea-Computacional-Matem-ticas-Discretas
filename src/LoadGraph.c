#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int **LoadGraph(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    int temp;
    *n = 0;
    char line[1024];
    if (fgets(line, sizeof(line), file)) {
        char *ptr = line;
        while (*ptr) {
            if (*ptr == '0' || *ptr == '1') {
                (*n)++;
                while (*ptr && *ptr != ' ') ptr++;
            } else {
                ptr++;
            }
        }
    } else {
        fprintf(stderr, "Error: el archivo no es válido\n");
        fclose(file);
        exit(1);
    }

    rewind(file);
    int **graph = malloc((*n) * sizeof(int *));
    if (!graph) {
        fprintf(stderr, "Error de memoria\n");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        graph[i] = malloc((*n) * sizeof(int));
        if (!graph[i]) {
            fprintf(stderr, "Error de memoria\n");
            fclose(file);
            exit(1);
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            if (fscanf(file, "%d", &temp) != 1) {
                fprintf(stderr, "Error: formato incorrecto en la matriz.\n");
                fclose(file);
                exit(1);
            }
            graph[i][j] = temp;
        }
    }

    fclose(file);
    return graph;
}