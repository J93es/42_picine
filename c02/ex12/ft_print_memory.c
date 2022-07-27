/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:07:29 by mijung            #+#    #+#             */
/*   Updated: 2022/05/26 11:48:56 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_first(unsigned long long addr_num, int depth, char *six)
{
	if (addr_num > 0)
	{
		print_first(addr_num / 16, depth + 1, six);
		write (1, &six[addr_num % 16], 1);
		return ;
	}
	while (depth++ < 16)
		write (1, "0", 1);
}

void	print_middle(unsigned char str[], unsigned int pos, int len, char *six)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write (1, &six[str[pos + i] / 16], 1);
		write (1, &six[str[pos + i] % 16], 1);
		if (i % 2 == 1)
			write (1, " ", 1);
		i++;
	}
	while (16 - len > 0)
	{
		if (len % 2 == 1)
			write (1, " ", 1);
		write (1, "  ", 2);
		len++;
	}
}

void	print_end(unsigned char *str, unsigned int pos, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[pos + i] < 32 || 127 <= str[pos + i])
			write (1, ".", 1);
		else
			write(1, &str[pos + i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				*six;
	unsigned int		pos;
	unsigned int		len;
	unsigned long long	addr_num;

	pos = 0;
	six = "0123456789abcdef";
	while (pos < size)
	{
		addr_num = (unsigned long long)(addr + pos);
		if (pos + 16 > size)
			len = size - pos;
		else
			len = 16;
		print_first(addr_num, 0, six);
		write (1, ": ", 2);
		print_middle((unsigned char *)addr, pos, len, six);
		print_end((unsigned char *)addr, pos, len);
		write (1, "\n", 1);
		pos += 16;
	}
	return (addr);
}
