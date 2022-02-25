##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for runner
##

SRC	=	sources/first.c	\
		sources/world_init.c	\
		sources/world_cursor.c	\
		sources/bs_world.c	\
		sources/draw_loops.c

LIB = -l csfml-graphics -O2 -lm -l csfml-audio	\
		-l csfml-system -l csfml-window -Wall

NAME	=	my_world

OBJ	=	$(SRC:.c=.o)

all: ${NAME}

$(NAME): $(OBJ)
	gcc  -o $(NAME) sources/*.o $(LIB)

debug :
	gcc -g sources/*.c $(LIB)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

git : fclean
	git add *
	git commit -m "norme and little fix"
	git push

re:	fclean all
