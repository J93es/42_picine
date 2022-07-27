/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:39:11 by mijung            #+#    #+#             */
/*   Updated: 2022/06/06 13:45:26 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ex03_c_in_str(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ex03_totalsize(char *str, char *charset)
{
	int	i;
	int	totalsize;

	i = 0;
	totalsize = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			totalsize++;
		while (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 0)
			i++;
	}
	return (totalsize);
}

int	ex03_wordsize(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 0)
		i++;
	return (i);
}

char	*ex03_strcpy(char *src, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ex03_wordsize(src, charset) + 1));
	while (src[i] != '\0' && ex03_c_in_str(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		dest_pos;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (ex03_totalsize(str, charset) + 1));
	if (dest == 0)
		return ((char **)malloc(sizeof(char *)));
	i = 0;
	dest_pos = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 1)
			i++;
		if (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 0)
			dest[dest_pos++] = ex03_strcpy(&str[i], charset);
		while (str[i] != '\0' && ex03_c_in_str(str[i], charset) == 0)
			i++;
	}
	dest[dest_pos] = 0;
	return (dest);
}
