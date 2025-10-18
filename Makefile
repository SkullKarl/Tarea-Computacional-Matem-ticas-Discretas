CC = gcc
CFLAGS = -Wall
TARGET = main
OBJS = main.o funciones.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

funciones.o: funciones.c 
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -f $(OBJS) $(TARGET)

clean-obj:
	rm -f $(OBJS)

run: $(TARGET)
	./$(TARGET)

rebuild: clean all

.PHONY: all clean clean-obj run rebuild help