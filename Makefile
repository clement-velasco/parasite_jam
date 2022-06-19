##
## EPITECH PROJECT, 2021
## generique
## File description:
## Makefile
##

CC  = gcc -g3

SRC     =       src/main.c				\
				src/parasite.c			\
				src/intro_scene.c		\
				src/init_info_intro.c	\
				src/clock_management_intro.c	\
				src/management_evt.c	\
				src/main_menu.c			\
				src/init_obj_intro.c	\
				src/game_management.c	\
				src/analyse_events.c	\
				src/set_obj.c			\
				src/free_obj.c			\
				src/display_obj.c		\
				src/init_obj.c			\
				src/is_overlap.c		\
				src/search_info.c		\
				src/set_nb_in_tab.c		\
				src/free_info.c			\
				src/pause_menu.c		\
				src/int_to_string.c		\
				src/display_interlude.c	\
				src/calc_rand_nb.c		\
				src/fonc_move_enemy.c	\
				src/touch_enemy.c		\

SRC_DEBUG		=		src/main.c				\
						src/parasite.c			\
						src/main_menu.c			\
						src/game_management.c	\
						src/analyse_events.c	\
						src/clock_management_intro.c	\
						src/management_evt.c	\
						src/set_obj.c			\
						src/free_obj.c			\
						src/display_obj.c		\
						src/init_obj.c			\
						src/intro_scene.c		\
						src/init_info_intro.c	\
						src/init_obj_intro.c	\
						src/clock_management.c	\
						src/is_overlap.c		\
						src/search_info.c		\
						src/set_nb_in_tab.c		\
						src/free_info.c			\
						src/init_collider.c		\
						src/mouve_map.c			\
						src/pause_menu.c		\
						src/init_quest.c		\
						src/quest_princ_one.c	\
						src/test_cond_quest.c	\
						src/init_enemy.c		\
						src/free_text.c			\
						src/attack_fonc.c		\
						src/fight_scene_one.c	\
						src/int_to_string.c		\
						src/init_obj_fight_one.c	\
						src/test_lose.c			\
						src/move_rect_cho.c		\
						src/display_interlude.c	\
						src/calc_rand_nb.c		\
						src/fonc_move_enemy.c	\
						src/touch_enemy.c		\

SRC_UNIT		=		

OBJ     =       $(SRC:.c=.o)

OBJ_DEBUG		=		$(SRC_DEBUG:.c=.o)

OBJ_UNIT		=		$(SRC_UNIT:.c=.o)

NAME    =       parasite

NAME_DEBUG		=		debug

NAME_UNIT		=		tests_run

CPPFLAGS	=	-I ./include -Wall -Wextra -l csfml-audio -l csfml-graphics \
				-l csfml-system -lcsfml-window

UNIT_TEST	=	--coverage -lcriterion

DEBUG	=	-g3

LIB	=	-L ./lib -lmy

all:    $(NAME)

$(NAME):        $(OBJ)
				@$(MAKE) -C ./lib
				@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

$(NAME_UNIT):   $(OBJ_UNIT)
				@$(MAKE) -C ./lib
				@$(CC) -o $(NAME_UNIT) $(CFLAGS) $(CPPFLAGS) $(SRC_UNIT) \
				$(UNIT_TEST) $(LIB)
				./tests_run

$(NAME_DEBUG):	$(OBJ_DEBUG)
				@$(MAKE) -C ./lib
				@$(CC) -o $(NAME_DEBUG) $(DEBUG) $(CPPFLAGS) $(OBJ_DEBUG) \
				$(LIB)

clean:
		@$(MAKE) clean -C ./lib
		@$(RM) -f $(OBJ)
		@$(RM) -f $(OBJ_DEBUG)
		@$(RM) -f $(OBJ_UNIT)
		@$(RM) -f *~
		@$(RM) -f *.gcno
		@$(RM) -f *.gcda
		@$(RM) -f ./*~
		@$(RM) -f ./*.gcno
		@$(RM) -f ./*.gcda

fclean: clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(NAME_DEBUG)
		@$(RM) -f $(NAME_UNIT)
		@$(MAKE) fclean -C ./lib


re:     fclean all
