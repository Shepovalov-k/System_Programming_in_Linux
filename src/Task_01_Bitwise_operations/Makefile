CC = gcc
CFLAGS = -Werror -Wextra -Wall
TARGET = decimal2binary

decimal2binary.o: decimal2binary.c
	$(CC) $(CFLAGS) -c $(TARGET).c -o $(TARGET).o

$(TARGET): decimal2binary.o
	$(CC) $(CFLAGS) $(TARGET).o -o $(TARGET)
	rm -rf *.o

all: $(TARGET)
clean:
	rm -rf *.o decimal2binary
