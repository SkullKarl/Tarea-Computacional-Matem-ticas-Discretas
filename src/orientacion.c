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

void orientarPorGrado(int n, int **graph, int matriz[n][n]) {
    //guardar el grado de cada nodo
    int grados[n];
    for (int i = 0; i < n; i++) {
        grados[i] = 0;
        //suma los 1 en la fila i
        for (int j = 0; j < n; j++) {
            grados[i] += graph[i][j];
        }
    }
    //limpiar matriz de destino
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;
    //orientar segun grado
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //si existe una arista no dirigida:
            if (graph[i][j] == 1) {
                //orientar de menor a mayor grado
                if (grados[i] < grados[j]) {
                    matriz[i][j] = 1; // i -> j
                } else if (grados[j] < grados[i]) {
                    matriz[j][i] = 1; // j -> i
                } else {
                    //si los grados son iguales, orientación ascendente
                    matriz[i][j] = 1; // i -> j
                }
            }
        }
    }

}

void orientarPorCentro(int n, int **graph, int matriz[n][n]) {
    //definimos el centro como el nodo medio
    int centro = n / 2;
    //limpiar matriz de destino
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;
    //orientar segun el centro
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //si existe una arista no dirigida:
            if (graph[i][j] == 1) {
                //si alguno de los nodos es el centro
                if (j == centro && i != j) {
                    matriz[i][j] = 1; // i -> j
                } else if (i == centro && j != i) {
                    matriz[j][i] = 1; // j -> i
                } else if (i < centro && j < centro) { //si ambos nodos son menores al centro
                    matriz[i][j] = 1; // i -> j
                } else if (i > centro && j > centro) { //si ambos nodos son mayores al centro
                    matriz[j][i] = 1; // j -> i 
                } else if (i < centro && j > centro) { //i menor al centro y j mayor al centro
                    matriz[i][j] = 1; // i -> j 
                } else {
                    matriz[j][i] = 1; // j -> i
                }
            }
        }
    }
}


void orientarGrafo(int n, int **graph, int matriz[n][n], int tipo) {
    switch (tipo) {
        case 1: orientarAscendente(n, graph, matriz);  break;
        case 2: orientarDescendente(n, graph, matriz); break;
        case 3: orientarPorGrado(n, graph, matriz);   break;
        case 4: orientarPorCentro(n, graph, matriz);   break;
        default: orientarAscendente(n, graph, matriz); break;
    }
}