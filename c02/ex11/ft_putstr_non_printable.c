/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:32:54 by mijung            #+#    #+#             */
/*   Updated: 2022/05/26 12:08:45 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_non_printable(unsigned char non_printable)
{
	char			*six;
	unsigned char	arr[3];

	six = "0123456789abcdef";
	write (1, "\\", 1);
	arr[0] = six[non_printable / 16];
	arr[1] = six[non_printable % 16];
	write (1, arr, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 32 || 127 <= c)
			write_non_printable(c);
		else
			write (1, &c, 1);
		i++;
	}
}
