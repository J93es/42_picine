/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:17:39 by mijung            #+#    #+#             */
/*   Updated: 2022/05/26 10:45:47 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 32 || 127 <= c)
			return (0);
		i++;
	}
	return (1);
}
