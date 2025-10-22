#include <stdlib.h>
#include "orientacion.h"

void orientarAscendente(int n, int **graph, int matriz[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] == 1)
                matriz[i][j] = 1;  // u<v => u->v
}

void orientarDescendente(int n, int **graph, int matriz[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] == 1)
                matriz[j][i] = 1;  // u<v => v->u
}


// aqui otra orientacion (numero 3)


// aqui otra orientacion (numero 4)


void orientarGrafo(int n, int **graph, int matriz[n][n], int tipo) {
    switch (tipo) {
        case 1: orientarAscendente(n, graph, matriz);  break;
        case 2: orientarDescendente(n, graph, matriz); break;
        //case 3: orientarPedrito(n, graph, matriz);   break;
        //case 4: orientarJuanito(n, graph, matriz);   break;
        default: orientarAscendente(n, graph, matriz); break;
    }
}