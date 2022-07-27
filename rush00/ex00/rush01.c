/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangminh <sangminh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:42:26 by sangminh          #+#    #+#             */
/*   Updated: 2022/05/22 10:35:08 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush01_print_first_end(int x, char first, char middle, char end)
{
	int	x_pos;

	ft_putchar(first);
	x_pos = 1;
	while (++x_pos < x)
		ft_putchar(middle);
	if (x > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush01_print_middle(int x, int y, char middle)
{
	int	x_pos;
	int	y_pos;

	y_pos = 1;
	while (++y_pos < y)
	{
		ft_putchar(middle);
		x_pos = 1;
		while (++x_pos < x)
			ft_putchar(' ');
		if (x > 1)
			ft_putchar(middle);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	rush01_print_first_end(x, '/', '*', '\\');
	rush01_print_middle(x, y, '*');
	if (y > 1)
		rush01_print_first_end(x, '\\', '*', '/');
}