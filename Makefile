##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC 	= 	main.c 				\
			src/sprite.c 		\
			src/linked_list.c   \
			src/tools.c         \
			src/ship.c          \
			src/fish.c          \
			src/file_score.c    \
			src/tools2.c        \
			src/init_data.c     \
			src/main_function.c

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_hunter

RM 		=	rm -rf

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a

CFLAGS	= 	-lm -Wextra

CLFLAGS = -L lib/my/ -lmy

CSFML   = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	@make re -C lib/my/ && gcc $(SRC) -o $(NAME) $(CFLAGS) $(CSFML) $(CLFLAGS)

clean:
	$(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)
	cd lib/my/ && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all
