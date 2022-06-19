##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	my/my_compute_power_rec.c			\
		my/free_array.c						\
		my/init_tab.c						\
		my/my_compute_square_root.c			\
		my/my_find_prime_sup.c				\
		my/my_getnbr.c						\
		my/my_isneg.c						\
		my/my_put_nbr.c						\
		my/open_file.c						\
		my/my_putchar.c						\
		my/my_putstr.c						\
		my/my_revstr.c						\
		my/my_showstr.c						\
		my/my_sort_int_array.c				\
		my/my_str_isalpha.c					\
		my/my_str_islower.c					\
		my/my_str_isnum.c					\
		my/my_str_isprintable.c				\
		my/my_str_isupper.c					\
		my/my_strcapitalize.c				\
		my/my_strcat.c						\
		my/my_strcmp.c						\
		my/my_strcpy.c						\
		my/my_strdup.c						\
		my/my_strlen.c						\
		my/my_strlowcase.c					\
		my/my_strncat.c						\
		my/my_strncmp.c						\
		my/my_strncpy.c						\
		my/my_strstr.c						\
		my/my_strupcase.c					\
		my/my_swap.c						\
		my/concat_strings.c					\
		my/my_str_to_word_array.c			\
		my/test_my_getnbr.c					\
		my_printf/src/my_printf.c			\
		my_printf/src/my_nblen.c			\
		my_printf/src/print_arg.c			\
		my_printf/flags/flags_c.c			\
		my_printf/flags/flags_d.c			\
		my_printf/flags/flags_s.c			\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS 	=	-I ../include -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@$(RM) -f *.o

clean:
	@$(RM) -f $(OBJ)
	@$(RM) -f $(OBJ_UNIT)
	@$(RM) -f *~
	@$(RM) -f *.gcno
	@$(RM) -f *.gcda
	@$(RM) -f ./*~
	@$(RM) -f ./*.gcno
	@$(RM) -f ./*.gcda

fclean:	clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(NAME_UNIT)

re:	fclean all
