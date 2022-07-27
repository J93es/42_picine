/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:46:55 by mijung            #+#    #+#             */
/*   Updated: 2022/05/28 12:16:10 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex04_strncmp(char *str, char *to_find, int size)
{
	int	i;

	i = 0;
	while (i < size && (str[i] != '\0' || to_find[i] != '\0'))
	{
		if (str[i] - to_find[i] != 0)
			return (str[i] - to_find[i]);
		i++;
	}
	return (0);
}

int	ex04_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	size;
	int	str_pos;

	str_pos = 0;
	size = ex04_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[str_pos] != '\0')
	{
		if (ex04_strncmp(&str[str_pos], to_find, size) == 0)
			return (str + str_pos);
		str_pos++;
	}
	return (0);
}
