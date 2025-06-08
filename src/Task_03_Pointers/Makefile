CC := gcc
CFLAGS := -g
LDFLAGS := 

BINS := change_integer the_second the_third the_fourth

all: $(BINS)

change_integers: change_integer.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

the_second: the_second.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

the_third: the_third.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

the_fourth: the_fourth.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

change_integers.o: change_integer.c
	$(CC) $(CFLAGS) -c $<

the_second.o: the_second.c
	$(CC) $(CFLAGS) -c $<

the_third.o: the_third.c
	$(CC) $(CFLAGS) -c $<

the_fourth.o: the_fourth.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(BINS) *.o

.PHONY: all clean