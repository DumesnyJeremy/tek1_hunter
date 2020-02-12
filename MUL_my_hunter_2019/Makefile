##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## oui
##

NAME	=	my_hunter

SRC	=	src/change_pix.c \
		src/clock.c \
		src/csfml.c \
		src/sprite.c \
		src/score.c \
		src/crea_sprite.c \
		src/init_struct.c \
		src/draw.c \
		src/life.c \
		src/create_play.c \
		src/event.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME) :	$(OBJ)
		gcc $(SRC) -o $(NAME) -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re	:	fclean all
