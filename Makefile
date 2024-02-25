all: program

program: main.o list.o user_interaction.o
	gcc -o todo_list main.o list.o user_interaction.o

main.o: main.c list.h user_interaction.h
	gcc -c main.c

list.o: list.c list.h todo_element.h
	gcc -c list.c

user_interaction.o: user_interaction.c user_interaction.h
	gcc -c user_interaction.c

clean:
	rm -f *.o todo_list
