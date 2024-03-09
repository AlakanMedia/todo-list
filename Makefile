CC = gcc

all: task_list

task_list: main.o list.o user.o misc.o
	$(CC) $^ -o $@

main.o: main.c list.h user.h misc.h
	$(CC) -c main.c

list.o: list.c list.h task.h
	$(CC) -c list.c

user.o: user.c user.h list.h misc.h
	$(CC) -c user.c

misc.o: misc.c misc.h
	$(CC) -c misc.c

clean:
	rm -rf *.o task_list
