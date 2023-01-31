NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

FUNCTIONS = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			ft_printc.c \
			ft_prints.c \
			ft_printx.c \
			ft_printp.c \
			ft_printi.c \
			ft_printu.c
			
OBJS=$(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

%.o: %.c ../includes/libft.h
	@$(CC) $(FLAGS) -c $< -I../includes/ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
