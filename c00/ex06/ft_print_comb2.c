/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:41:14 by mijung            #+#    #+#             */
/*   Updated: 2022/05/22 14:34:00 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	func_write(int num1, int num2)
{
	char	num;

	num = num1 / 10 + '0';
	write (1, &num, 1);
	num = num1 % 10 + '0';
	write (1, &num, 1);
	write (1, " ", 1);
	num = num2 / 10 + '0';
	write (1, &num, 1);
	num = num2 % 10 + '0';
	write (1, &num, 1);
	if (num1 != 98 || num2 != 99)
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 != 100)
	{
		num2 = num1 + 1;
		while (num2 != 100)
			func_write(num1, num2++);
		num1++;
	}
}
