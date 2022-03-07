##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile for world
##

SRC	=	sources/first.c				\
		sources/world_init.c		\
		sources/world_cursor.c		\
		sources/bs_world.c			\
		sources/draw_loops.c		\
		sources/window.c 			\
		sources/main.c				\
		sources/main_func.c			\
		sources/init_sprites.c		\
		sources/create_sprites.c 	\
		sources/draw_sprites.c		\
		sources/button.c			\
		sources/cond_button.c		\
		sources/cond_s_button.c		\
		sources/cond_t_button.c		\
		sources/cond_f_button.c		\
		sources/cond_fi_button.c	\
		sources/cond_si_button.c	\
		sources/func_button.c		\
		sources/part_func_button.c	\
		sources/detect_button.c		\
		sources/circle.c			\
		sources/sec_bs_world.c		\
		sources/color.c				\
		sources/save_map.c			\
		sources/mouse_up.c			\
		sources/event_key.c

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
