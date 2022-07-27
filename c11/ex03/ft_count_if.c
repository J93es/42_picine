/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:26:02 by mijung            #+#    #+#             */
/*   Updated: 2022/06/06 23:51:38 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	tab_pos;

	cnt = 0;
	tab_pos = 0;
	while (tab_pos < length)
	{
		if (f(tab[tab_pos++]) != 0)
			cnt++;
	}
	return (cnt);
}
