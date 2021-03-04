CC = gcc
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address

all : 
	make re -C ./libdir
	$(CC) $(CFLAG) -L libdir -lft -I ./libdir -I ./include ./parsing_src/*.c main.c 
	#./exec_src/*.c
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
