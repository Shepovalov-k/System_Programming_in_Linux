CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic -g
LDFLAGS :=

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
BIN := $(OBJ:.o=)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
	rm -rf $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ) $(BIN)