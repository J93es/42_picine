/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:15:51 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 10:32:53 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void	free_result(t_map s_table)
{
	int		i;

	i = 0;
	while (i < s_table.row_len)
	{
		free(s_table.field[i]);
		free(s_table.copy[i]);
		i++;
	}
	free(s_table.temp);
	free(s_table.first_col);
	free(s_table.field[i]);
	free(s_table.field);
	free(s_table.copy);
}

void	ft_free_char(char **result, int i, t_map *s_table)
{
	int	j;

	j = 0;
	while (j < i)
		free(result[j++]);
	free(result);
	free(s_table->first_col);
	free(s_table->temp);
}

void	ft_free_long_long(long long **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(result[j++]);
	free(result);
}

long long	**mallocing_long_long(t_map *s_table)
{
	int			i;
	long long	**result;

	i = 0;
	result = (long long **)malloc(sizeof(long long *) * (s_table->row_len + 1));
	if (result == 0)
	{
		ft_free_char(s_table->field, s_table->row_len, s_table);
		return (0);
	}
	while (i < s_table->row_len + 1)
	{
		result[i] = (long long *)malloc(sizeof(long long)
				* (s_table->col_len + 1));
		if (result[i] == 0)
		{
			ft_free_char(s_table->field, s_table->row_len, s_table);
			ft_free_long_long(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}

char	**mallocing_char(t_map *s_table)
{
	int		i;
	char	**result;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (s_table->row_len + 1));
	if (result == 0)
	{
		free(s_table->temp);
		free(s_table->first_col);
		return (0);
	}
	while (i < s_table->row_len + 1)
	{
		result[i] = (char *)malloc(s_table->col_len + 1);
		if (result[i] == 0)
		{
			ft_free_char(result, i, s_table);
			return (0);
		}
		i++;
	}
	return (result);
}
