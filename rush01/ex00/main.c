/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:25:24 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 21:13:06 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "building.h"
#include "general_variable.h"

int		ft_set_g_case(char *src);
void	ft_set_size(char *str, int *total_size);

int	main(int argc, char **argv)
{
	int	i;
	int	total_size;
	int	arr[9][9];

	i = 1;
	ft_set_size(argv[1], &total_size);
	if (argc == 2 && g_size > 3 && total_size
		== 4 * g_size && ft_set_g_case(argv[1]) != 0)
	{
		while (i < g_size + 1)
		{
			if (ft_building(arr, 0, 0, i++) == 1)
				return (0);
		}
	}
	ft_put_str("Error\n");
}

void	ft_set_size(char *str, int *total_size)
{
	int	i;

	i = 0;
	g_size = 0;
	*total_size = 0;
	while (str[i] != '\0')
	{
		if ('0' < str[i] && str[i] <= '9')
			*total_size += 1;
		i++;
	}
	g_size = *total_size / 4;
}

int	ft_set_g_case(char *src)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 8 * g_size - 1)
	{
		if (i % 2 == 0)
		{
			if ('0' < src[i] && src[i] <= g_size + '0')
				g_case[cnt++] = src[i] - '0';
			else
				return (0);
		}
		else if (src[i] != ' ')
			return (0);
		i++;
	}
	if (src[i] != '\0')
		return (0);
	return (cnt);
}
