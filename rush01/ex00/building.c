/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:21:18 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 15:26:38 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sub_judge_col.h"
#include "sub_judge_row.h"
#include "general_variable.h"

int		ft_judge_center(int arr[9][9], int col_pos, int row_pos);
void	ft_print_arr(int arr[9]);
void	ft_put_str(char *str);
void	ft_set_pos(int *col_pos, int *row_pos);

int	ft_building(int arr[9][9], int col_pos, int row_pos, int num)
{
	int	i;

	i = 0;
	arr[col_pos][row_pos] = num;
	if (ft_judge_center(arr, col_pos, row_pos) == 0)
		return (0);
	if (col_pos == g_size - 1 && row_pos == g_size - 1)
	{
		while (i < g_size)
			ft_print_arr(arr[i++]);
		return (1);
	}
	i = 1;
	ft_set_pos(&col_pos, &row_pos);
	while (i < g_size + 1)
	{
		if (ft_building(arr, col_pos, row_pos, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_judge_center(int arr[9][9], int col_pos, int row_pos)
{
	if (judge_col_num(arr, col_pos, row_pos) == 0
		|| judge_row_num(arr, col_pos, row_pos) == 0)
		return (0);
	if (col_pos == g_size - 1)
	{
		if (judge_col_up(arr, row_pos) == 0
			|| judge_col_down(arr, row_pos) == 0)
			return (0);
	}
	if (row_pos == g_size - 1)
	{
		if (judge_row_left(arr, col_pos) == 0
			|| judge_row_right(arr, col_pos) == 0)
			return (0);
	}
	return (1);
}

void	ft_print_arr(int arr[9])
{
	int		i;
	char	c;

	i = 0;
	while (i < g_size)
	{
		c = arr[i] + '0';
		write (1, &c, 1);
		if (i < g_size - 1)
			write (1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_set_pos(int *col_pos, int *row_pos)
{
	if (*col_pos == g_size - 1)
	{
		*row_pos += 1;
		*col_pos = 0;
	}
	else
		*col_pos += 1;
}
