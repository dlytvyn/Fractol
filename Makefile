NAME = fractol
PATH_INC = ./includes/fractol.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
BON_FL = -lmlx -framework OpenGL -framework AppKit
HEAD = ./src/fdf.h

FRACTOL =	./src/main.c\
			./src/additional.c\
			./src/burningship.c\
			./src/julia.c\
			./src/manage_keys.c\
			./src/mandelbrot.c

FRACTOL_OBJ = $(FRACTOL:.c=.o)

all: $(NAME)

$(NAME): $(FRACTOL)
	cd libft && make && cp libft.a ../
	$(CC) -o $(NAME) $(FRACTOL) $(BON_FL) libft.a
clean:
	cd src && rm -f *.o
	cd libft && make clean

fclean: clean
	cd libft && make fclean
	/bin/rm -f $(NAME)
	/bin/rm -f libft.a

re: fclean all