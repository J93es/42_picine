/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:36:25 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 15:38:10 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ex05_c_in_str(char c, char *charset)
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

int	ex05_totalsize(char *str, char *charset)
{
	int	i;
	int	totalsize;

	i = 0;
	totalsize = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			totalsize++;
		while (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 0)
			i++;
	}
	return (totalsize);
}

int	ex05_wordsize(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 0)
		i++;
	return (i);
}

char	*ex05_strcpy(char *src, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ex05_wordsize(src, charset) + 1));
	while (src[i] != '\0' && ex05_c_in_str(src[i], charset) == 0)
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

	dest = (char **)malloc(sizeof(char *) * (ex05_totalsize(str, charset) + 1));
	if (dest == 0)
		return ((char **)malloc(sizeof(char *)));
	i = 0;
	dest_pos = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 1)
			i++;
		if (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 0)
			dest[dest_pos++] = ex05_strcpy(&str[i], charset);
		while (str[i] != '\0' && ex05_c_in_str(str[i], charset) == 0)
			i++;
	}
	dest[dest_pos] = 0;
	return (dest);
}
