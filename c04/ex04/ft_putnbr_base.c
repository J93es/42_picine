/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:22:17 by mijung            #+#    #+#             */
/*   Updated: 2022/06/02 11:56:24 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ex04_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (i);
}

void	ex04_put_num_base(long long lnbr, int base_len, char *base)
{
	if (lnbr > 0)
	{
		ex04_put_num_base(lnbr / base_len, base_len, base);
		write (1, &base[lnbr % base_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			num;
	long long	lnbr;

	i = 0;
	num = ex04_check_base(base);
	lnbr = (long long)nbr;
	if (num < 2)
		return ;
	if (nbr == 0)
		write (1, &base[0], 1);
	else if (nbr < 0)
	{
		lnbr *= -1;
		write (1, "-", 1);
	}
	ex04_put_num_base(lnbr, num, base);
}
