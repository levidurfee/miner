CC=gcc
CFLAGS=-lcrypto -lssl -fopenmp
OPTIMIZE=-O2
BUG=-g -pg

hash:
	$(CC) main.c $(CFLAGS) $(OPTIMIZE) -o bin/main

debug:
	$(CC) main.c $(CFLAGS) $(BUG) -o bin/main

clean:
	rm -Rf bin/*