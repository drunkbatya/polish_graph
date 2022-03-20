CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: graph

graph: graph.o lib_io.o lib_graph.o lib_stack.o lib_parse.o
	$(CC) $(CFLAGS) graph.o lib_io.o lib_graph.o lib_stack.o lib_parse.o -o $(OUT_DIR)/graph

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c -o graph.o

lib_io.o: lib_io.c lib_io.h
	$(CC) $(CFLAGS) -c lib_io.c -o lib_io.o

lib_graph.o: lib_graph.c lib_graph.h
	$(CC) $(CFLAGS) -c lib_graph.c -o lib_graph.o

lib_stack.o: lib_stack.c lib_stack.h
	$(CC) $(CFLAGS) -c lib_stack.c -o lib_stack.o

lib_parse.o: lib_parse.c lib_parse.h
	$(CC) $(CFLAGS) -c lib_parse.c -o lib_parse.o

mock.o: mock.c graph.h
	$(CC) $(CFLAGS) -c mock.c -o mock.o

mock: mock.o lib_io.o lib_graph.o lib_stack.o lib_parse.o
	$(CC) $(CFLAGS) mock.o lib_io.o lib_graph.o lib_stack.o lib_parse.o -o $(OUT_DIR)/mock

clean:
	rm -f *.o $(OUT_DIR)/*
