CC = gcc
CFLAGS = -Wall -std=gnu11
TARGET = main
OBJS = main.o funciones.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c src/funciones.h
	$(CC) $(CFLAGS) -c main.c

funciones.o: src/funciones.c src/funciones.h
	$(CC) $(CFLAGS) -c src/funciones.c

clean:
	rm -f $(OBJS) $(TARGET)

clean-obj:
	rm -f $(OBJS)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

.PHONY: all clean clean-obj run rebuild help