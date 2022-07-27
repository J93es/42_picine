/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:12 by mijung            #+#    #+#             */
/*   Updated: 2022/06/06 16:05:14 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex05_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void	ex05_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ex05_print_int(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	ex05_print_int(nb / 10);
	c = nb % 10 + '0';
	write (1, &c, 1);
}

void	ex05_ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		ex05_print_int(nb);
	}
	else if (nb == 0)
		write (1, "0", 1);
	else
		ex05_print_int(nb);
}

int	ex05_ft_atoi(char *str)
{
	int			str_pos;
	long long	result;
	long long	plma;

	plma = 1;
	result = 0;
	str_pos = 0;
	while (str[str_pos] == '\t' || str[str_pos] == '\n' || str[str_pos] == '\v'
		|| str[str_pos] == '\f' || str[str_pos] == ' ' || str[str_pos] == '\r')
		str_pos++;
	while (str[str_pos] == '-' || str[str_pos] == '+')
	{
		if (str[str_pos++] == '-')
			plma *= -1;
	}
	while ('0' <= str[str_pos] && str[str_pos] <= '9')
		result = result * 10 + (str[str_pos++] - '0');
	result *= plma;
	return ((int)(result));
}
