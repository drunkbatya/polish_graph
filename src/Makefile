CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: graph

graph: graph.o lib_io.o
	$(CC) $(CFLAGS) graph.o lib_io.o -o $(OUT_DIR)/graph

graph.o: graph.c
	$(CC) $(CFLAGS) -c graph.c -o graph.o

lib_io.o: lib_io.c
	$(CC) $(CFLAGS) -c lib_io.c -o lib_io.o

clean:
	rm -f *.o $(OUT_DIR)/*
