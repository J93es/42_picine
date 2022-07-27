/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:42:23 by mijung            #+#    #+#             */
/*   Updated: 2022/05/28 09:11:52 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	u_s1;
	unsigned char	u_s2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		u_s1 = (unsigned char)s1[i];
		u_s2 = (unsigned char)s2[i];
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		i++;
	}
	return (0);
}