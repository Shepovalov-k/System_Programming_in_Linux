CC := gcc
CFLAGS := -g
LDFLAGS := 

BINS := change_integer

all: $(BINS)

change_integers: change_integer.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

change_integers.o: change_integer.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BINS) *.o

.PHONY: all clean