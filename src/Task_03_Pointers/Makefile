CC := gcc
CFLAGS := -g
LDFLAGS := 

BINS := change_integer the_second 

all: $(BINS)

change_integers: change_integer.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

the_second: the_second.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

change_integers.o: change_integer.c
	$(CC) $(CFLAGS) -c $<

the_second.o: the_second.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BINS) *.o

.PHONY: all clean