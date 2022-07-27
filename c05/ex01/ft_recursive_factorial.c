/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:27:34 by mijung            #+#    #+#             */
/*   Updated: 2022/06/01 10:06:40 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	long long	output;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	output = nb * ft_recursive_factorial(nb - 1);
	return ((int)output);
}
