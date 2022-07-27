/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:20 by mijung            #+#    #+#             */
/*   Updated: 2022/06/06 16:05:24 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ex05_putstr(char *str);
void	ex05_strcpy(char *dest, char *src);
void	ex05_ft_putnbr(int nb);
int		ex05_ft_atoi(char *str);
int		ex05_add(int value1, int value2);
int		ex05_sub(int value1, int value2);
int		ex05_mul(int value1, int value2);
int		ex05_div(int value1, int value2);
int		ex05_mod(int value1, int value2);

int	ex05_func_ptr_array(int value1, int value2, char operater)
{
	int	num;
	int	(*fp[5])(int, int);

	fp[0] = ex05_add;
	fp[1] = ex05_sub;
	fp[2] = ex05_mul;
	fp[3] = ex05_div;
	fp[4] = ex05_mod;
	if (operater == '+')
		num = fp[0](value1, value2);
	if (operater == '-')
		num = fp[1](value1, value2);
	if (operater == '*')
		num = fp[2](value1, value2);
	if (operater == '/')
		num = fp[3](value1, value2);
	if (operater == '%')
		num = fp[4](value1, value2);
	return (num);
}

int	ex05_jud_operater(char *operater, int value2)
{
	if ((operater[0] != '+' && operater[0] != '-' && operater[0] != '*'
			&& operater[0] != '/' && operater[0] != '%') || operater[1] != '\0')
	{
		ex05_putstr("0\n");
		return (-1);
	}
	if (operater[0] == '/' && value2 == 0)
	{
		ex05_putstr("Stop : division by zero\n");
		return (-1);
	}
	if (operater[0] == '%' && value2 == 0)
	{
		ex05_putstr("Stop : modulo by zero\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		result;
	int		value1;
	int		value2;
	char	operater[1000];

	if (argc != 4)
		return (0);
	value1 = ex05_ft_atoi(argv[1]);
	value2 = ex05_ft_atoi(argv[3]);
	ex05_strcpy(operater, argv[2]);
	if (ex05_jud_operater(operater, value2) == -1)
		return (-1);
	result = ex05_func_ptr_array(value1, value2, operater[0]);
	ex05_ft_putnbr(result);
	ex05_putstr("\n");
}
