NAME 	= so_long
INCLUDE	= include
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -I -lm $(INCLUDE)
include ./Src/Libft/Makefile

MINILIBX_PATH =./minilibx-linux
MINIFLAGS=-L$(MINILIBX_PATH) -lmlx -lXext -lX11 -opengl -lm -lbsd
MINILIBX= $(MINILIBX_PATH)/libmlx.a

SRC =	Src/Controls/ennemy_move.c	\
		Src/Controls/kill_or_be_killed.c	\
		Src/Controls/on_press.c	\
		Src/Controls/player_move.c	\
		Src/Display/display_ennemy.c	\
		Src/Display/display_player.c	\
		Src/Display/display_wall.c	\
		Src/Display/display.c	\
		Src/Ennemies_utilities/get_ennemies.c	\
		Src/Exit_error/delete_sprites.c	\
		Src/Exit_error/delete_textures.c	\
		Src/Exit_error/exit_error.c	\
		Src/Game_end/game_end.c	\
		Src/Map_utilities/display_in_terminal.c	\
		Src/Map_utilities/dup_map.c	\
		Src/Map_utilities/free_map.c	\
		Src/Map_utilities/free_tabstr.c	\
		Src/Map_utilities/get_map_height.c	\
		Src/Map_utilities/get_map.c	\
		Src/Map_utilities/get_nb_coins.c	\
		Src/Parsing/are_coins_reachable.c	\
		Src/Parsing/check_characters.c	\
		Src/Parsing/check_walls.c	\
		Src/Parsing/is_exit_reachable.c	\
		Src/Parsing/is_rectangular.c	\
		Src/Parsing/parsing.c	\
		Src/Player_utilities/get_player.c	\
		Src/Textures_utilities/get_ennemies_sprites.c	\
		Src/Textures_utilities/get_player_sprites.c	\
		Src/Textures_utilities/get_textures.c	\
		Src/Window_utilities/destroy_window.c	\
		Src/Window_utilities/init_window.c	\
		Src/main.c
OBJ = $(SRC:.c=.o)

all: libft_all $(MINILIBX) $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(MINIFLAGS) $(LIBFT_NAME) -o $(NAME)
	@clear
	@echo "Compilation done!"

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

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
