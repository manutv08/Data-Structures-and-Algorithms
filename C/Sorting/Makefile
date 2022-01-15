# -*- MakeFile -*-

a.out: main.o QuickSort.o InsertionSort.o RadixSort.o
	gcc main.o QuickSort.o InsertionSort.o RadixSort.o

main.o: main.c mySorting.h
	gcc -c main.c

QuickSort.o: QuickSort.c
	gcc -c QuickSort.c

InsertionSort.o: InsertionSort.c
	gcc -c InsertionSort.c

RadixSort.o: RadixSort.c
	gcc -c RadixSort.c

clean:
	rm -f *.o a.out