NAME 	= so_long
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I -lm $(INCLUDE)
include ./Src/Libft/Makefile

SRC =	Src/Moves/moves.c	\
		Src/Map/create_map.c
OBJ = $(SRC:.c=.o)

all: libft_all $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) main.c $(LIBFT_NAME) -o $(NAME)
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
