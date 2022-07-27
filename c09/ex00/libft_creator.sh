# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 00:42:19 by mijung            #+#    #+#              #
#    Updated: 2022/06/06 00:42:23 by mijung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash
gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c
gcc -c -Wall -Wextra -Werror ft_strlen.c ft_strcmp.c
ar rscv libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
exit
