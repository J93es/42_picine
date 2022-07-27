/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:39:02 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 20:17:42 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ex03_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ex03_find_total_size(int size, char **strs, char *sep)
{
	int	i;
	int	total_size;

	i = 0;
	total_size = 0;
	while (i < size)
		total_size += ex03_ft_strlen(strs[i++]);
	total_size += ex03_ft_strlen(sep) * (size - 1) + 1;
	return (total_size);
}

void	ex03_set_dest(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	str_pos;
	int	dest_pos;
	int	sep_pos;

	str_pos = 0;
	dest_pos = 0;
	while (str_pos < size)
	{
		i = 0;
		while (strs[str_pos][i] != '\0')
			dest[dest_pos++] = strs[str_pos][i++];
		if (str_pos < size - 1)
		{
			sep_pos = 0;
			while (sep[sep_pos] != '\0')
				dest[dest_pos++] = sep[sep_pos++];
		}
		str_pos++;
	}
	dest[dest_pos] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_size;
	char	*dest;

	i = 0;
	if (size < 0)
	{
		dest = 0;
		return (dest);
	}
	if (size == 0)
	{
		dest = (char *)malloc(1);
		if (dest != 0)
			dest[0] = '\0';
		return (dest);
	}
	total_size = ex03_find_total_size(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * total_size);
	if (dest != 0)
		ex03_set_dest(size, strs, sep, dest);
	return (dest);
}
