/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:27:49 by mijung            #+#    #+#             */
/*   Updated: 2022/06/01 10:19:21 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex03_recursive_return_output(int nb, int power, long long output)
{
	if (power == 0)
		return (output);
	else
		return (ex03_recursive_return_output(nb, power - 1, output * nb));
}

int	ft_recursive_power(int nb, int power)
{
	long long	output;

	output = 1;
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (ex03_recursive_return_output(nb, power - 1, output * nb));
}
