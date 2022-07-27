/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:59:53 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 12:23:18 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ex04_check_base_return_len(char *base)
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

int	ex04_check_c_in_base_return_index(char c, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i] != '\0')
	{
		if (base_from[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ex04_set_str_base(long long lnum, char *str,
		char *base_to, int base_to_tool[2])
{
	int			str_pos;
	int			base_to_len;
	long long	temp;

	temp = lnum;
	base_to_len = base_to_tool[0];
	str_pos = base_to_tool[1];
	while (temp > 0)
	{
		temp /= base_to_len;
		str_pos++;
	}
	str[str_pos--] = '\0';
	while (lnum > 0)
	{
		str[str_pos--] = base_to[lnum % base_to_len];
		lnum /= base_to_len;
	}
}
