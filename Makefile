CC=gcc
CFLAGS=-lcrypto -lssl -fopenmp -O2

hash:
	$(CC) main.c $(CFLAGS) -o bin/main

clean:
	rm -Rf bin/*