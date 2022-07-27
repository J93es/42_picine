/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:38:24 by mijung            #+#    #+#             */
/*   Updated: 2022/06/01 10:03:19 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ex03_ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	u_s1;
	unsigned char	u_s2;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		u_s1 = (unsigned char)s1[i];
		u_s2 = (unsigned char)s2[i];
		if (u_s1 != u_s2)
			return (u_s1 - u_s2);
		i++;
	}
	return (0);
}

int	ex03_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp[1000];

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ex03_ft_strcmp(argv[i], argv[j]) > 0)
			{
				*temp = argv[i];
				argv[i] = argv[j];
				argv[j] = *temp;
			}
			j++;
		}
		write(1, argv[i], ex03_ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}
