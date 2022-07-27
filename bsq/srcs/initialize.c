/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:15:13 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 09:15:35 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

t_map	initialize(t_map s_table)
{
	long long		x;
	long long		y;

	x = 0;
	y = 0;
	while (y < s_table.row_len)
	{
		x = 0;
		while (x < s_table.col_len)
		{
			if (s_table.field[y][x] == s_table.ob)
				s_table.copy[y][x] = 0;
			else
				s_table.copy[y][x] = 1;
			x++;
		}
		y++;
	}
	return (s_table);
}

t_map	make_result(t_map s_table, t_answer s_result)
{
	long long		size_x;
	long long		size_y;
	long long		x;
	long long		y;

	size_x = s_result.score;
	size_y = s_result.score;
	x = s_result.x;
	y = s_result.y;
	while (size_y > 0)
	{
		x = s_result.x;
		size_x = s_result.score;
		while (size_x > 0)
		{
			s_table.field[y][x] = s_table.full;
			x--;
			size_x--;
		}
		y--;
		size_y--;
	}
	return (s_table);
}

void	write_result(t_map s_table)
{
	long long		x;
	long long		y;

	x = 0;
	y = 0;
	while (y < s_table.row_len)
	{
		x = 0;
		while (x < s_table.col_len)
		{
			write(1, &s_table.field[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
