all: program

program: main.o list.o
	gcc -o todo_list main.o list.o

main.o: main.c list.h
	gcc -c main.c

list.o: list.c list.h todo_element.h
	gcc -c list.c

clean:
	rm -f *.o todo_list
