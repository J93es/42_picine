/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:27:52 by mijung            #+#    #+#             */
/*   Updated: 2022/06/05 13:29:32 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	ex04_free_str(t_stock_str *result, int i, int opt)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j].str);
		free(result[j].copy);
		j++;
	}
	if (opt == 1)
		free(result[j].str);
	free(result);
}

int	ex04_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ex04_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ex04_strlen(src) + 1));
	if (dest == 0)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_stock_str	*ex04_set_result(t_stock_str *result, int ac, char **av, int i)
{
	while (i < ac)
	{
		result[i].str = ex04_strdup(av[i]);
		if (result[i].str == 0)
		{
			ex04_free_str(result, i, 0);
			return (0);
		}
		result[i].copy = ex04_strdup(result[i].str);
		if (result[i].copy == 0)
		{
			ex04_free_str(result, i, 1);
			return (0);
		}
		result[i].size = ex04_strlen(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	return (ex04_set_result(result, ac, av, 0));
}
