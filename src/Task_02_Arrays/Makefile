CC := gcc
CFLAGS := -g

all: matrix revseq triangle snale

matrix: matrix.o
	$(CC) $(CFLAGS) $^ -o $@

revseq: revseq.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

triangle: triangle.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

snale: snale.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAGS)

revseq.o: revseq.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAGS)

triangle.o: triangle.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAG)

snale.o: snale.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAG)

clean:
	rm -f *.o matrix revseq triangle snale