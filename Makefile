NAME = so_long

FLAGS = cc -Wall -Werror -Wextra

X_FLAGS = -lX11 -lXext -lmlx

MAKE_LIBFT = libft.a

SRC = so_long.c images_controls.c \
		map_controls.c game_events.c \
	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MAKE_LIBFT)
		 $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib  -Imlx_linux libft/$(MAKE_LIBFT) $(X_FLAGS) -L ./ -o $(NAME)

%.o: %.c
		$(FLAGS) -I/usr/include -c $< -o $@
	
$(MAKE_LIBFT):
		make -C libft/

re: fclean all

fclean: clean
		rm -rf $(NAME)

clean:
		rm -rf *.o

.PHONY: all clean fclean re
