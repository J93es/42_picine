/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:20:56 by mijung            #+#    #+#             */
/*   Updated: 2022/06/04 20:18:08 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ex04_check_base_return_len(char *base);
extern int	ex04_check_c_in_base_return_index(char c, char *base_from);
int			ex04_atoi_base(char *nbr, char *base_form, int base_from_len);
extern void	ex04_set_str_base(long long lnbr, char *str,
				char *base_to, int *base_to_tool);
void		ex04_make_str(int num, char *str, char *base_to, int base_to_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_from_len;
	int		base_to_len;
	char	*str;

	str = (char *)malloc(10000);
	base_from_len = ex04_check_base_return_len(base_from);
	base_to_len = ex04_check_base_return_len(base_to);
	if (base_from_len < 2 || base_to_len < 2)
		return (0);
	num = ex04_atoi_base(nbr, base_from, base_from_len);
	ex04_make_str(num, str, base_to, base_to_len);
	return (str);
}

int	ex04_atoi_base(char *nbr, char *base_from, int base_from_len)
{
	int			nbr_pos;
	long long	plma;
	long long	result;

	plma = 1;
	result = 0;
	nbr_pos = 0;
	while (nbr[nbr_pos] == '\t' || nbr[nbr_pos] == '\n' || nbr[nbr_pos] == '\v'
		|| nbr[nbr_pos] == '\f' || nbr[nbr_pos] == ' ' || nbr[nbr_pos] == '\r')
		nbr_pos++;
	while (nbr[nbr_pos] == '-' || nbr[nbr_pos] == '+')
	{
		if (nbr[nbr_pos] == '-')
			plma *= -1;
		nbr_pos++;
	}
	while (ex04_check_c_in_base_return_index(nbr[nbr_pos], base_from) != -1)
	{
		result = result * base_from_len
			+ ex04_check_c_in_base_return_index(nbr[nbr_pos++], base_from);
	}
	result *= plma;
	return ((int)result);
}

void	ex04_make_str(int num, char *str, char *base_to, int base_to_len)
{
	int			i;
	int			base_to_tool[2];
	long long	lnum;

	i = 0;
	base_to_tool[0] = base_to_len;
	base_to_tool[1] = 0;
	lnum = (long long)num;
	if (num == 0)
	{
		str[0] = base_to[0];
		str[1] = '\0';
		return ;
	}
	else if (num < 0)
	{
		lnum *= -1;
		str[0] = '-';
		base_to_tool[1]++;
	}
	ex04_set_str_base(lnum, str, base_to, base_to_tool);
}
