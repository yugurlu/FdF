

NAME = ../fdf
FRAEMWORKS = -g
FLAGS = -g -O2 -std=gnu99 -Wall -Wextra
SRC = src/colours_menu.c \
	src/control.c \
	src/fdf.c \
	src/illustration.c \
	src/read_map.c \
	src/utils.c \
	src/utils2.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

OBJ = $(SRC: .c=.o)

INCLUDES = ft_printf/libftprintf.a mlx_linux/libmlx.a

YELLOW := \033[1;45m
RED := \033[1;41m

all:
	@make -C ./ft_printf
	@make -C ./mlx_linux
	@gcc $(SRC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)
	@echo "$(YELLOW)Compile Completed!"
clean:
	@make clean -C ./ft_printf
	@make clean -C ./mlx_linux
	@echo "$(RED)Cleaning Completed!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re
