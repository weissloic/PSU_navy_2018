##
## EPITECH PROJECT, 2018
## makefile Lib
## File description:
## make
##

NAME	=	libmy.a

SRC	=	my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_getnbr.c			\
		getnextline.c \
		my_isneg.c			\
		my_is_prime.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_showmem.c			\
		my_showstr.c			\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_swap.c\
		display_basics.c		\
		convert_base.c			\
		my_printf.c			\
		my_put_unbr.c			\
		display_flags.c			\
		my_put_lnbr.c			\
		my_put_ustr.c 			\
		my_put_longbase_nbr.c 	\
		getnextline2.c 			\
		getnextline3.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean
