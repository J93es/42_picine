/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:59:19 by mijung            #+#    #+#             */
/*   Updated: 2022/05/30 17:16:01 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex07_func_print(long divider, int nb, int option)
{
	int	writer;

	while (divider >= 10)
	{
		writer = 48 + (nb % divider) / (divider / 10);
		if (writer != '0' && option == 0)
			option = 1;
		if (option == 1)
			write (1, &writer, 1);
		divider /= 10;
	}
}

void	ft_putnbr(int nb)
{
	long	divider;
	int		option;

	option = 0;
	divider = 10000000000;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
	{
		write (1, "0", 1);
		return ;
	}
	ex07_func_print(divider, nb, option);
}
