/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:04:35 by mijung            #+#    #+#             */
/*   Updated: 2022/05/21 20:19:41 by sangminh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ex05_func_write(char n1, char n2, char n3)
{
	write (1, &n1, 1);
	write (1, &n2, 1);
	write (1, &n3, 1);
	if (n1 != '7')
		write (1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	num1;
	char	num2;
	char	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				ex05_func_write(num1, num2, num3);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}
