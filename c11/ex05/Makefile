NAME = do-op
SRCS = main.c calculate.c tools.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
