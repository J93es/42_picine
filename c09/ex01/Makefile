A = srcs
NAME = libft.a
SRCS = $(A)/ft_strlen.c $(A)/ft_strcmp.c $(A)/ft_putchar.c $(A)/ft_swap.c $(A)/ft_putstr.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re $(NAME)

all: $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $@ -Iincludes

$(NAME): $(OBJS)
	ar rscv $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re : fclean all
