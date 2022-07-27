/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:58:06 by mijung            #+#    #+#             */
/*   Updated: 2022/05/31 16:20:40 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex05_check_base_return_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == ' ' || base[i] == '\r')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (i);
}

int	ex05_set_str_return_pos(char *str)
{
	int	str_pos;

	str_pos = 0;
	while (str[str_pos] == '\t' || str[str_pos] == '\n' || str[str_pos] == '\v'
		|| str[str_pos] == '\f' || str[str_pos] == ' ' || str[str_pos] == '\r')
		str_pos++;
	return (str_pos);
}

int	ex05_check_c_in_base_return_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ex05_set_plma_return_pos(char *str, int str_pos, long long *plma)
{
	while (str[str_pos] == '-' || str[str_pos] == '+')
	{
		if (str[str_pos++] == '-')
			*plma *= -1;
	}
	return (str_pos);
}

int	ft_atoi_base(char *str, char *base)
{
	int			str_pos;
	int			base_len;
	long long	plma;
	long long	result;

	plma = 1;
	result = 0;
	base_len = ex05_check_base_return_len(base);
	if (base_len < 2)
		return (0);
	str_pos = ex05_set_str_return_pos(str);
	str_pos = ex05_set_plma_return_pos(str, str_pos, &plma);
	while (ex05_check_c_in_base_return_num(str[str_pos], base) != -1)
	{
		result = result * base_len
			+ ex05_check_c_in_base_return_num(str[str_pos++], base);
	}
	result *= plma;
	return ((int)result);
}
