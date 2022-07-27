/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:16:13 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 15:29:13 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	set_field(t_map *s_table, long long i)
{
	long long	j;

	j = 0;
	while (j < s_table->col_len + 1)
		s_table->field[i][j++] = s_table->temp[s_table->temp_pos++];
	if (s_table->field[i][j - 1] != '\n')
		return (-1);
	return (1);
}

int	set_table(t_map *s_table, long long num)
{
	long long	i;
	long long	result;

	i = 0;
	result = 0;
	s_table->temp_pos = 0;
	while (i < s_table->first_col_len + 1)
		s_table->first_col[i++] = s_table->temp[s_table->temp_pos++];
	i--;
	s_table->full = s_table->first_col[--i];
	s_table->ob = s_table->first_col[--i];
	s_table->vog = s_table->first_col[--i];
	num = i;
	i = -1;
	while (++i < num)
	{
		if ('0' <= s_table->first_col[i] && s_table->first_col[i] <= '9')
			result = 10 * result + s_table->first_col[i] - '0';
		else
			return (-1);
	}
	s_table->row_len = result;
	return (1);
}

int	make_table(t_map *s_table)
{
	int	i;
	int	num;

	i = 0;
	s_table->field = mallocing_char(s_table);
	s_table->copy = mallocing_long_long(s_table);
	if (s_table->field == 0 || s_table->copy == 0)
		return (0);
	while (i < s_table->row_len)
	{
		num = set_field(s_table, i++);
		if (num != 1)
			return (num);
	}
	if (s_table->temp[s_table->temp_pos++] != '\0')
		return (-1);
	return (1);
}

int	open_file_2(t_map *s_table)
{
	int	num;

	s_table->first_col = (char *)malloc(s_table->first_col_len + 1);
	if (s_table->first_col == 0)
	{
		free(s_table->temp);
		return (0);
	}
	num = set_table(s_table, 0);
	if (num <= 0)
		return (num);
	num = make_table(s_table);
	if (num <= 0)
		return (num);
	return (1);
}
