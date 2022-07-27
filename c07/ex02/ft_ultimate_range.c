/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:38:54 by mijung            #+#    #+#             */
/*   Updated: 2022/06/03 23:18:48 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	range_pos;

	i = min;
	range_pos = 0;
	if (min >= max)
		return (0);
	*range = (int *)malloc(4 * (max - min));
	if (*range == 0)
		return (-1);
	while (i < max)
		range[0][range_pos++] = i++;
	return (max - min);
}
