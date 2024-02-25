all: program

program: main.o list.o user_interaction.o misc_funtions.o
	gcc -o todo_list main.o list.o user_interaction.o misc_funtions.o

main.o: main.c list.h user_interaction.h misc_funtions.h
	gcc -c main.c

list.o: list.c list.h todo_element.h misc_funtions.h
	gcc -c list.c

user_interaction.o: user_interaction.c user_interaction.h
	gcc -c user_interaction.c

misc_funtions.o: misc_funtions.c misc_funtions.h
	gcc -c misc_funtions.c

clean:
	rm -f *.o todo_list
