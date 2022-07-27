/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_judge_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:22:11 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 14:18:41 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_variable.h"

int	judge_row_num(int arr[9][9], int col_pos, int row_pos)
{
	int	i;
	int	num;

	i = 0;
	num = arr[col_pos][row_pos];
	while (i < row_pos)
	{
		if (num == arr[col_pos][i])
			return (0);
		i++;
	}
	return (1);
}

int	judge_row_left(int arr[9][9], int col_pos)
{
	int	row_pos;
	int	left_cnt;
	int	temp;

	row_pos = 0;
	left_cnt = 1;
	temp = arr[col_pos][row_pos];
	while (row_pos < g_size - 1)
	{
		if (temp < arr[col_pos][++row_pos])
		{
			temp = arr[col_pos][row_pos];
			left_cnt++;
		}
	}
	if (left_cnt == g_case[2 * g_size + col_pos])
		return (1);
	return (0);
}

int	judge_row_right(int arr[9][9], int col_pos)
{
	int	row_pos;
	int	right_cnt;
	int	temp;

	row_pos = g_size - 1;
	right_cnt = 1;
	temp = arr[col_pos][row_pos];
	while (row_pos > 0)
	{
		if (temp < arr[col_pos][--row_pos])
		{
			temp = arr[col_pos][row_pos];
			right_cnt++;
		}
	}
	if (right_cnt == g_case[3 * g_size + col_pos])
		return (1);
	return (0);
}
