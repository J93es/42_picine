/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:35:41 by mijung            #+#    #+#             */
/*   Updated: 2022/06/05 15:58:01 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ex05_ft_print_int(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	ex05_ft_print_int(nb / 10);
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
		ex05_ft_print_int(nb);
	}
	else if (nb == 0)
		write (1, "0", 1);
	else
		ex05_ft_print_int(nb);
}

int	ex05_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, ex05_strlen(par[i].str));
		write(1, "\n", 1);
		ex05_ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ex05_strlen(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
