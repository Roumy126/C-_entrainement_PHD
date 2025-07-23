all: gobblers

gobblers: main.o board.o
	gcc -o gobblers main.o board.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o gobblers
