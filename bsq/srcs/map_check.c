/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:17:29 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 12:37:47 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ob_vog_check(t_map *s_table)
{
	int		i;
	int		j;
	char	current;
	char	ob;
	char	vog;

	ob = s_table->ob;
	vog = s_table->vog;
	i = 0;
	while (i < s_table->row_len)
	{
		j = 0;
		while (j < s_table->col_len)
		{
			current = s_table->field[i][j];
			if (current != s_table->ob && current != s_table->vog)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	len_check(t_map *s_table)
{
	int	i;

	i = 0;
	while (i < s_table->row_len)
	{
		if (len(s_table->field[i]) != s_table->col_len)
			return (0);
		i++;
	}
	if (i != s_table->row_len)
		return (0);
	return (1);
}

int	duplicate_or_nonable_check(t_map *s_table)
{
	if (s_table->vog == s_table->ob)
		return (0);
	if (s_table->vog == s_table->full)
		return (0);
	if (s_table->ob == s_table->full)
		return (0);
	if (s_table->vog <= 31)
		return (0);
	if (s_table->vog >= 127)
		return (0);
	if (s_table->ob <= 31)
		return (0);
	if (s_table->ob >= 127)
		return (0);
	if (s_table->full <= 31)
		return (0);
	if (s_table->full >= 127)
		return (0);
	return (1);
}

int	map_check(t_map *s_table)
{
	if (!s_table->col_len || !s_table->row_len)
		return (0);
	if (!ob_vog_check(s_table))
		return (0);
	if (!len_check(s_table))
		return (0);
	if (!duplicate_or_nonable_check(s_table))
		return (0);
	return (1);
}
