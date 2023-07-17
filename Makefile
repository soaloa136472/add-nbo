#Makefile
all: add-nbo

add-nbo: read_uint32.o main.o
	gcc -o add-nbo read_uint32.o main.o

main.o: main.h main.c

read_uint32.o: main.h read_uint32.c

clean:
	rm -f add-nbo
	rm -f *.o

