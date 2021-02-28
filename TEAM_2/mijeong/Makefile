CC = gcc
CFLAG = -Wall -Wextra -Werror

all : 
	$(CC) -L libdir -lft -I ./libdir *.c *.h 

run : all
	./a.out
clean :
	rm -rf *.o
fclean : clean
	rm -rf a.out
re : fclean all
