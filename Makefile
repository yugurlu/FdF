
FRAEMWORKS = -framework OpenGL -framework AppKit -g
FLAGS = -Werror -Wextra -Wall
NAME = fdf
SRC = src/colours_menu.c \
	src/control.c \
	src/fdf.c \
	src/illustration.c \
	src/read_map.c \
	src/utils.c \
	src/utils2.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

INCLUDES = ft_printf/libftprintf.a minilibx_macos/libmlx.a

YELLOW := \033[1;45m
RED := \033[1;41m

all:
	@make -C ./ft_printf
	@make -C ./minilibx_macos
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)
	@echo "$(YELLOW)Compile Completed!"

clean:
	@make clean -C ./ft_printf
	@make clean -C ./minilibx_macos
	@echo "$(RED)Cleaning Completed!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re
