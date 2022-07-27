/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:39:20 by mijung            #+#    #+#             */
/*   Updated: 2022/05/28 09:36:53 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ex05_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	i = 0;
	src_len = ex05_strlen(src);
	dest_len = ex05_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && size > dest_len + i + 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
