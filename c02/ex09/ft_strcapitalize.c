/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:16:52 by mijung            #+#    #+#             */
/*   Updated: 2022/05/25 16:00:20 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_str(char *str, int i, char c, char cur_c)
{
	if ((c < 'a' || 'z' < c) && (c < 'A' || 'Z' < c) && (c < '0' || '9' < c))
	{
		if ('a' <= cur_c && cur_c <= 'z')
			str[i] = cur_c - 'a' + 'A';
	}
	else if ('A' <= cur_c && cur_c <= 'Z')
		str[i] = cur_c - 'A' + 'a';
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	char	cur_c;

	i = 1;
	cur_c = str[0];
	if ('a' <= cur_c && cur_c <= 'z')
		str[0] = str[0] - 'a' + 'A';
	while (str[i] != '\0')
	{
		c = str[i - 1];
		cur_c = str[i];
		set_str(str, i, c, cur_c);
		i++;
	}
	return (str);
}
