/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangminh <sangminh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:42:05 by sangminh          #+#    #+#             */
/*   Updated: 2022/05/23 10:21:50 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	num;
	int	cnt;
	int	multi;

	num = 0;
	cnt = 0;
	multi = 1;
	while (str[cnt])
		cnt++;
	while (cnt-- > 0)
	{
		num += (str[cnt] - '0') * multi;
		multi *= 10;
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
