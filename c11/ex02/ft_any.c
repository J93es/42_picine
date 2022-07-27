/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:25:51 by mijung            #+#    #+#             */
/*   Updated: 2022/06/06 12:25:53 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	tab_pos;

	tab_pos = 0;
	while (tab[tab_pos] != 0)
	{
		if (f(tab[tab_pos]) != 0)
			return (1);
		tab_pos++;
	}
	return (0);
}