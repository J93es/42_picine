CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCDIR = srcs
HEADER = includes
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)
.PHONY: make

all: $(NAME)
.PHONY: all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)
.PHONY: clean

fclean: clean
	rm -rf $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
