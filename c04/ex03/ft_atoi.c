/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:09:33 by mijung            #+#    #+#             */
/*   Updated: 2022/05/31 16:18:55 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex03_ft_remove_space_return_pos(char *str)
{
	int	str_pos;

	str_pos = 0;
	while (str[str_pos] == '\t' || str[str_pos] == '\n' || str[str_pos] == '\v'
		|| str[str_pos] == '\f' || str[str_pos] == ' ' || str[str_pos] == '\r')
		str_pos++;
	return (str_pos);
}

int	ft_atoi(char *str)
{
	int			str_pos;
	long long	result;
	long long	plma;

	plma = 1;
	result = 0;
	str_pos = ex03_ft_remove_space_return_pos(str);
	while (str[str_pos] == '-' || str[str_pos] == '+')
	{
		if (str[str_pos++] == '-')
			plma *= -1;
	}
	while ('0' <= str[str_pos] && str[str_pos] <= '9')
		result = result * 10 + (str[str_pos++] - '0');
	result *= plma;
	return ((int)(result));
}
