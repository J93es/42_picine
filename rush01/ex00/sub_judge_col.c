/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_judge_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:22:03 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 14:18:34 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_variable.h"

int	judge_col_num(int arr[9][9], int col_pos, int row_pos)
{
	int	i;
	int	num;

	i = 0;
	num = arr[col_pos][row_pos];
	while (i < col_pos)
	{
		if (num == arr[i][row_pos])
			return (0);
		i++;
	}
	return (1);
}

int	judge_col_up(int arr[9][9], int row_pos)
{
	int	col_pos;
	int	up_cnt;
	int	temp;

	col_pos = 0;
	up_cnt = 1;
	temp = arr[col_pos][row_pos];
	while (col_pos < g_size - 1)
	{
		if (temp < arr[++col_pos][row_pos])
		{
			temp = arr[col_pos][row_pos];
			up_cnt++;
		}
	}
	if (up_cnt == g_case[row_pos])
		return (1);
	return (0);
}

int	judge_col_down(int arr[9][9], int row_pos)
{
	int	col_pos;
	int	down_cnt;
	int	temp;

	col_pos = g_size - 1;
	down_cnt = 1;
	temp = arr[col_pos][row_pos];
	while (col_pos > 0)
	{
		if (temp < arr[--col_pos][row_pos])
		{
			temp = arr[col_pos][row_pos];
			down_cnt++;
		}
	}
	if (down_cnt == g_case[g_size + row_pos])
		return (1);
	return (0);
}
