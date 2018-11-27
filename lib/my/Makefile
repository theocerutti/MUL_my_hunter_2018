##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- Lib compilation
##

SRC		=	my_putchar.c \
			my_putstr.c  \
			my_put_float.c \
			my_put_nbr.c \
			my_strcat.c

NAME	= 	libmy.a

OBJ		=	$(SRC:.c=.o)

RM 		=	@rm -rf

CFLAGS	= -pedantic -Wall -Wextra -W

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) *#
	$(RM) *.~

fclean: clean
	$(RM) $(NAME)

re: fclean all
