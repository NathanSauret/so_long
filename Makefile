NAME 	= so_long
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I -lm $(INCLUDE)
include ./Src/Libft/Makefile

SRC =	Src/Exit_error/exit_error.c	\
		Src/Map_utilities/get_map.c	\
		Src/Parsing/are_coins_reachable.c	\
		Src/Parsing/check_characters.c	\
		Src/Parsing/check_walls.c	\
		Src/Parsing/is_exit_reachable.c	\
		Src/Parsing/is_rectangular.c	\
		Src/Parsing/parsing.c	\
		Src/Player_utilities/moves.c	\
		Src/main.c
OBJ = $(SRC:.c=.o)

SRC_DEBUG =	Debug/display_in_terminal.c
OBJ_DEBUG = $(SRC_DEBUG:.c=.o)

all: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

debug: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(SRC_DEBUG) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

clean: libft_clean
	@rm -f $(LIBFT_OBJ) $(OBJ)
	@clear
	@echo "cleaning done!"

fclean: libft_fclean
	@rm -f $(LIBFT_OBJ) $(OBJ)
	@rm -f $(NAME)
	@rm -rf .vscode
	@clear
	@echo "full cleaning done!"

re:
	make fclean
	make all
	@clear
	@echo "Re:Zero - Re:Clean and compile again."

.PHONY: all tester clean fclean re
