/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:28:07 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 20:22:02 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex05_recursive_sqrt(long long nb, long long i)
{
	if (i * i > nb)
		return (0);
	if (i * i == nb)
		return (i);
	return (ex05_recursive_sqrt(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	return (ex05_recursive_sqrt((long long)nb, 1));
}
