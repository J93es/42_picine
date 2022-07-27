/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:15:23 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 14:42:13 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	ft_error(t_map s_table)
{
	write(2, "map error\n", 10);
	free_result(s_table);
}

void	ft_pipeline(t_map s_table)
{
	t_answer	s_result;

	if (map_check(&s_table))
	{
		s_table = initialize(s_table);
		s_result = bsq_logic(s_table);
		if (s_result.score == 0)
		{
			ft_error(s_table);
			return ;
		}
		s_table = make_result(s_table, s_result);
		write_result(s_table);
		free_result(s_table);
	}
	else
		ft_error(s_table);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_map		s_table;
	int			open_result;

	i = 0;
	if (argc == 1)
	{
		open_result = open_file_1(&s_table, 0, 0);
		if (open_result == 1)
			ft_pipeline(s_table);
		if (open_result == -1)
			write(2, "map error\n", 10);
	}
	while (++i < argc)
	{
		open_result = open_file_1(&s_table, argv[i], 1);
		if (open_result == 1)
			ft_pipeline(s_table);
		if (open_result == -1)
			write(2, "map error\n", 10);
	}
	return (0);
}
