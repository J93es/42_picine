/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:38:45 by mijung            #+#    #+#             */
/*   Updated: 2022/06/02 23:26:19 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	arr_pos;

	if (min >= max)
		return (0);
	arr_pos = 0;
	arr = (int *)malloc(4 * (max - min));
	while (min < max)
		arr[arr_pos++] = min++;
	return (arr);
}
