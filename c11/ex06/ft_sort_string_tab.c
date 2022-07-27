/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:37:43 by mijung            #+#    #+#             */
/*   Updated: 2022/06/07 01:30:38 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex06_ft_strcmp(char *s1, char *s2)
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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp[1000];

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (j < i)
		{
			if (ex06_ft_strcmp(tab[j], tab[i]) > 0)
			{
				*temp = tab[i];
				tab[i] = tab[j];
				tab[j] = *temp;
			}
			j++;
		}
		i++;
	}
}
