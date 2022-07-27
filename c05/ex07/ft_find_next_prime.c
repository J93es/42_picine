/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:28:42 by mijung            #+#    #+#             */
/*   Updated: 2022/06/01 16:12:52 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex07_recursive_is_prime(long long nb, long long i)
{
	if (nb % i == 0)
		return (0);
	if (i * i > nb)
		return (1);
	return (ex07_recursive_is_prime(nb, i + 1));
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (ex07_recursive_is_prime((long long)nb, 2) == 0)
		nb++;
	return (nb);
}
