# ---- CONFIGURACIÓN ----
CC = gcc
CFLAGS = -Wall -std=gnu11 -Isrc
TARGET = path
OBJS = src/main.o src/funciones.o src/LoadGraph.o src/orientacion.o

# ---- REGLAS ----
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

src/main.o: src/main.c src/funciones.h src/LoadGraph.h src/orientacion.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/funciones.o: src/funciones.c src/funciones.h
	$(CC) $(CFLAGS) -c src/funciones.c -o src/funciones.o

src/LoadGraph.o: src/LoadGraph.c src/LoadGraph.h
	$(CC) $(CFLAGS) -c src/LoadGraph.c -o src/LoadGraph.o

src/orientacion.o: src/orientacion.c src/orientacion.h
	$(CC) $(CFLAGS) -c src/orientacion.c -o src/orientacion.o

# ---- UTILIDADES ----
clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run