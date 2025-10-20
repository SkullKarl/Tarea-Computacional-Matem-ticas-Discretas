#include <stdio.h>
#include "funciones.h"

int main() {
    int grafo[12][12] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    }; //Matriz de adyacencia del arbol dado en el enunciado a modo de ejemplo

    //int origen = 0; // 0 = a
    //int destino = 11; // 11 = l

    char origenChar;
    char destinoChar;
    printf("Ingrese vértice inicial (letra): ");
    scanf(" %c", &origenChar);
    printf("Ingrese vértice final (letra): ");
    scanf(" %c", &destinoChar);

    int origen = origenChar - 'a';
    int destino = destinoChar - 'a';


    dijkstra(12, grafo, origen, destino);
    return 0;
}