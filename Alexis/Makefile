##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

GCC=            gcc

SRC=		map.c\
			errors.c\
			positions_errors.c\
			square.c\
			main.c\
			boats.c

LIB=		-Llib/my/ -lmy

INC=            -I./include

CSFML=		-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

OBJ=            $(SRC:.c)

NAME=          	navy

all:            $(NAME)

$(NAME):
		make -C ./lib/my
		$(GCC) -g $(SRC) $(LIB) $(INC) $(CSFML) -o $(NAME)

clean:
		rm -f *~ *#

fclean:         clean
		rm $(NAME) libmy.a

re:	fclean all clean
