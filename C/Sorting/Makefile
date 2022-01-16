# -*- MakeFile -*-

CFLAGS= -g 
BINS=a.out lib_mysort.so runtime_a.out lib_mysortstatic.a static_a.out
all: $(BINS)

a.out: main.o QuickSort.o InsertionSort.o RadixSort.o
	gcc main.o QuickSort.o InsertionSort.o RadixSort.o

main.o: main.c mySorting.h
	gcc $(CFLAGS) -c main.c

QuickSort.o: QuickSort.c
	gcc $(CFLAGS) -c QuickSort.c

InsertionSort.o: InsertionSort.c
	gcc $(CFLAGS) -c InsertionSort.c

RadixSort.o: RadixSort.c
	gcc $(CFLAGS) -c RadixSort.c

#LD_LIBRARY_PATH=.
lib_mysort.so: InsertionSort.c QuickSort.c RadixSort.c
	gcc $(CFLAGS) -fPIC -shared -o $@ $^

lib_mysortstatic.a: QuickSort.o InsertionSort.o RadixSort.o
	ar rcs lib_mysortstatic.a QuickSort.o InsertionSort.o RadixSort.o

runtime_a.out: main.c
	gcc $(CFLAGS) -o $@ $^ -L. -l_mysort

static_a.out: main.c
	gcc $(CFLAGS) -o $@ $^ -L. -l_mysortstatic
clean:
	rm -f *.o $(BINS)