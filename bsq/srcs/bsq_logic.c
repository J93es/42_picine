/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:15:40 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 09:15:42 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_min(long long **copy, int i, int j)
{
	long long		min;

	min = copy[i - 1][j - 1];
	if (copy[i - 1][j] < min)
		min = copy[i - 1][j];
	if (copy[i][j - 1] < min)
		min = copy[i][j - 1];
	return (min);
}

t_answer	result_update(t_answer s_result, int i, int j, t_map s_table)
{
	if (s_table.copy[i][j] > s_result.score)
	{
		s_result.x = j;
		s_result.y = i;
		s_result.score = s_table.copy[i][j];
	}
	return (s_result);
}

t_answer	bsq_logic(t_map s_table)
{
	long long		i;
	long long		j;
	t_answer		s_result;

	s_result.score = 0;
	i = -1;
	j = 0;
	while (++i < s_table.row_len)
	{
		j = 0;
		while (j < s_table.col_len)
		{
			if (i == 0 || j == 0)
			{
				s_result = result_update(s_result, i, j, s_table);
				j++;
				continue ;
			}
			else if (s_table.copy[i][j] > 0)
				s_table.copy[i][j] = check_min(s_table.copy, i, j) + 1;
			s_result = result_update(s_result, i, j, s_table);
			j++;
		}
	}
	return (s_result);
}
