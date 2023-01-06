

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c

SRCBONUS=  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
		 	  ft_lstadd_back.c \
			  ft_lstnew.c		\
			  ft_lstdelone.c	\
			  ft_lstclear.c		\
			  ft_lstiter.c		\
			  ft_lstmap.c		\

OBJ= $(SRC:.c=.o)

BONUSOBJ = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@rm -f $(NAME)

bonus: $(SRCBONUS)
	@$(CC) $(FLAGS) -c $(SRCBONUS)
	@ar -crs $(NAME) $(BONUSOBJ)

re: fclean all

.PHONY: all clean fclean re bonus
