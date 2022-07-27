/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:43:01 by mijung            #+#    #+#             */
/*   Updated: 2022/06/07 13:21:20 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex07_find_length(char **tab)
{
	int	length;

	length = 0;
	while (tab[length] != 0)
		length++;
	return (length);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		length;
	char	*temp[1000];

	i = 0;
	length = ex07_find_length(tab);
	while (i < length)
	{
		j = 0;
		while (j < length - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				*temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = *temp;
			}
			j++;
		}
		i++;
	}
}
