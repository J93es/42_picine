/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:16:00 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 14:42:46 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	set_table_len(t_map *s_table)
{
	char	c;

	s_table->first_col_len = 0;
	s_table->col_len = 0;
	s_table->temp_pos = 0;
	c = 100;
	while (c != '\n' && c != '\0')
	{
		c = s_table->temp[s_table->temp_pos++];
		s_table->first_col_len++;
	}
	s_table->first_col_len -= 1;
	if (c == '\0')
		return (-1);
	c = 100;
	while (c != '\n' && c != '\0')
	{
		c = s_table->temp[s_table->temp_pos++];
		s_table->col_len++;
	}
	if (c == '\0')
		return (-1);
	s_table->col_len -= 1;
	return (1);
}

int	open_file_1(t_map *s_table, char *f_name, int fd)
{
	int			i;
	int			fd1;

	i = 1;
	if (fd == 0)
		fd1 = fd;
	else
		fd1 = open(f_name, O_RDONLY);
	if (fd1 < 0)
		return (0);
	s_table->temp_pos = 0;
	s_table->temp = (char *)malloc(200000000);
	if (s_table->temp == 0)
		return (0);
	if (read (fd1, s_table->temp, 200000000) < 0)
		return (0);
	i = set_table_len(s_table);
	if (i == -1)
		return (-1);
	if (fd != 0)
		if (close(fd1) != 0)
			return (0);
	return (open_file_2(s_table));
}
