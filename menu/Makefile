##
## EPITECH PROJECT, 2021
## runner
## File description:
## runner
##

SRC	=	sources/window.c 	\
		sources/main.c		\
		sources/main_func.c	\
		sources/init_sprites.c	\
		sources/create_sprites.c 	\
		sources/draw_sprites.c		\
		sources/button.c

OBJ	=    $(SRC:.c=.o)

CFLAGS += -g

FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME	=    my_world

all:    	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	gcc -o $(NAME) $(OBJ) $(FLAGS)