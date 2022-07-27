/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:27:08 by mijung            #+#    #+#             */
/*   Updated: 2022/05/31 22:11:27 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	re_print_comb(char arr[], char cur_num, int arr_pos, int n)
{
	arr[arr_pos] = cur_num;
	if (arr_pos == n - 1)
	{
		write (1, arr, n);
		if (arr[0] != 10 - n + '0')
			write (1, ", ", 2);
		return ;
	}
	while (cur_num < '9')
		re_print_comb(arr, ++cur_num, arr_pos + 1, n);
}

void	ft_print_combn(int n)
{
	char	i;
	char	arr[10];

	i = '0';
	while (i <= '9')
		re_print_comb(arr, i++, 0, n);
}
