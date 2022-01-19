# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g
BINS = a.out lib_mytreesstatic.a static_a.out lib_mytreesdynamic.so dynamic_a.out   

all:$(BINS) 

BinarySearchTree.o: BinarySearchTree.c 
	$(CC) $(CFLAGS) -c $^

lib_mytreesstatic.a: BinarySearchTree.o
	ar rcs $@ $^ 

lib_mytreesdynamic.so: *.o 
	$(CC) $(CFLAGS) -fpic -shared -o $@ $^

main.o : main.c
	$(CC) $(CFLAGS) -c $^ -o $@

a.out: main.o BinarySearchTree.o
	$(CC) $(CFLAGS) -o $@ $^

static_a.out: main.o
	$(CC) $(CFLAGS) -o $@ $^ -L. -l_mytreesstatic

dynamic_a.out: main.o
	$(CC) $(CFLAGS) -o $@ $^ -L. -l_mytreesdynamic

clean: 
	rm *.h.gch *.o $(BINS)