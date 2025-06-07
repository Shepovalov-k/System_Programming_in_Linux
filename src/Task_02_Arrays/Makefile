CC := gcc
CFLAGS := -fsanitize=address -g

matrix: matrix.o
	$(CC) $(CFLAGS) $^ -o $@

revseq: revseq.o
	$(CC) $(CFLAGS) $^ -o $@ $(CFLAGS)

triangle: triangle.o
	$(CC) $(CFLAGS) $^ -o $@ $(CFLAGS)

matrix.o: matrix.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAGS)

revseq.o: revseq.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAGS)

triangle.o: triangle.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(CFLAG)

clean:
	rm -f *.o matrix revseq triangle snale