/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:29:01 by mijung            #+#    #+#             */
/*   Updated: 2022/06/01 12:41:39 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ex08_convert_plus(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	ex08_check_placed_queen(int arr[10], int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (ex08_convert_plus(arr[depth] - arr[i])
			== ex08_convert_plus(depth - i))
			return (0);
		if (arr[depth] == arr[i])
			return (0);
		i++;
	}
	return (1);
}

void	ex08_recursive_solve_puzzle(int arr[10], int depth, int *cnt)
{
	int		i;
	char	c;

	i = 0;
	if (depth == 10)
	{
		*cnt += 1;
		while (i < 10)
		{
			c = arr[i++] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		arr[depth] = i++;
		if (ex08_check_placed_queen(arr, depth) == 1)
			ex08_recursive_solve_puzzle(arr, depth + 1, cnt);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	cnt;
	int	arr[10];

	i = 0;
	cnt = 0;
	while (i < 10)
		arr[i++] = 0;
	ex08_recursive_solve_puzzle(arr, 0, &cnt);
	return (cnt);
}
