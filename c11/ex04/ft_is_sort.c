/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:26:14 by mijung            #+#    #+#             */
/*   Updated: 2022/06/07 12:42:05 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex04_jud_ascend(int *tab, int length, int (*f)(int, int))
{
	int	tab_pos;

	tab_pos = 0;
	while (tab_pos < length - 1)
	{
		if (f(tab[tab_pos], tab[tab_pos + 1]) > 0)
			return (0);
		tab_pos++;
	}
	return (1);
}

int	ex04_jud_descend(int *tab, int length, int (*f)(int, int))
{
	int	tab_pos;

	tab_pos = 0;
	while (tab_pos < length - 1)
	{
		if (f(tab[tab_pos], tab[tab_pos + 1]) < 0)
			return (0);
		tab_pos++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	plma;
	int	tab_pos;

	plma = 0;
	tab_pos = 0;
	if (length == 0)
		return (1);
	while (plma == 0 && tab_pos < length - 1)
	{
		plma = f(tab[tab_pos], tab[tab_pos + 1]);
		tab_pos++;
	}
	if (plma == 0)
		return (1);
	else if (plma > 0)
		return (ex04_jud_descend(tab, length, f));
	else
		return (ex04_jud_ascend(tab, length, f));
}
