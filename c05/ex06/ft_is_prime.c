/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:28:15 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 20:48:14 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex06_recursive_is_prime(long long nb, long long i)
{
	if (nb % i == 0)
		return (0);
	if (i * i > nb)
		return (1);
	return (ex06_recursive_is_prime(nb, i + 1));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	return (ex06_recursive_is_prime((long long)nb, 2));
}
