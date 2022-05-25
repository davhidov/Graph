FLAG = -Wall -Werror -Wextra -std=c11
CC=gcc

all: graph

stack.o: stack.c stack.h
	$(CC) $(FLAG) -c stack.c -lm

polish.o: polish.c polish.h
	$(CC) $(FLAG) -c polish.c -lm

polish_to_rez.o: polish_to_rez.c polish_to_rez.h
	$(CC) $(FLAG) -c polish_to_rez.c -lm

graph.o: graph.c input.h
	$(CC) $(FLAG) -c graph.c -lm

input.o:input.c input.h
	$(CC) $(FLAG) -c input.c -lm

graph: graph.o input.o stack.o polish.o polish_to_rez.o
	$(CC) -o ../build/graph graph.o input.o stack.o polish.o polish_to_rez.o -lm

clean:
	rm -rf *.o ../build/graph
