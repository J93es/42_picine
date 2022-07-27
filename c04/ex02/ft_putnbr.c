/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:44:41 by mijung            #+#    #+#             */
/*   Updated: 2022/05/30 17:12:19 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_int(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	ft_print_int(nb / 10);
	c = nb % 10 + '0';
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		ft_print_int(nb);
	}
	else if (nb == 0)
		write (1, "0", 1);
	else
		ft_print_int(nb);
}
