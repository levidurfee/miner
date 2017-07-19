CC=gcc
CFLAGS=-lcrypto -lssl -fopenmp
OPTIMIZE=-O2
BUG=-g -pg -O0

hash:
	$(CC) ./src/main.c ./src/miner.c $(CFLAGS) $(OPTIMIZE) -o ./build/main

debug:
	$(CC) ./src/main.c ./src/miner.c $(CFLAGS) $(BUG) -o ./build/main

clean:
	rm -Rf ./build/*