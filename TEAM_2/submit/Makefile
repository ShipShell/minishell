CC = gcc
CFLAG = -Wall -Wextra -Werror

all : 
	make re -C ./libdir
	$(CC) -g3 -fsanitize=address -L libdir -lft -I ./libdir -I ./include ./exec_src/*.c main.c
run : all
	./a.out
test : 
	make re -C ./libdir
	$(CC) -g3 -fsanitize=address -L libdir -lft -I ./libdir -I ./include test.c
	./a.out
clean :
	rm -rf *.o
fclean : clean
	rm -rf a.out
re : fclean all
