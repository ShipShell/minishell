CC = gcc
CFLAG = -Wall -Wextra -Werror

all : 
	make re -C ./libdir
	$(CC) -L libdir -lft -I ./libdir -I ./include ./exec_src/*.c ./parsing_src/*.c main.c
run : all
	./a.out
clean :
	rm -rf *.o
fclean : clean
	rm -rf a.out
re : fclean all
