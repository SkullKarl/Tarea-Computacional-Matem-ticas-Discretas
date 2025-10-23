# Tarea 1 Matemáticas Discretas

En este repositorio se encuentra todo el código asociado a la tarea n°1 de la asignatura Matemáticas discretas, la cual consiste en la implementación en C del algoritmo de Dijkstra para encontrar el camino más corto dado unos grafos conocidos y 4 orientaciones escogidas de manera arbitraria.

## Compilación
Compilar usando el Makefile o usando gcc directamente.

Ejemplos de compilación (recomendado):

```bash
#Limpiar archivos de ejecuciones anteriores
make clean

# Compilar con make
make

# O en su defecto, compilar directamente
gcc -std=gnu11 -Wall -Isrc -o path src/main.c src/funciones.c src/LoadGraph.c src/orientacion.c

# Ejemplo de ejecución (no dirigido):
./path a l grafos_de_prueba/arbol_no_orientado.txt

# Ejemplo de ejecución (dirigido) usando orientación 2:
./path a l grafos_de_prueba/arbol_no_orientado.txt dir 2
```

### Sintaxis
```
./path <origen> <destino> <archivo_grafo> [dir] [1..4]
```
- `<origen>` y `<destino>`: letras que representan vértices ('a','b','c' ... 'z').
- `<archivo_grafo>`: ruta al archivo que contiene la matriz de adyacencia.
- `[dir]`: opcional. Si se añade la palabra `dir`, el grafo se orienta según la opción dada en `[1..4]`.
- `[1..4]`: opcional. Tipo de orientación (1 a 4). Si no se especifica, por defecto se usa la orientación 1.

Salida: se imprimen la distancia mínima (número de aristas) y la secuencia de vértices del camino en formato `a -> b -> c`.

