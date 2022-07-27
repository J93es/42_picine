/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:44:00 by mijung            #+#    #+#             */
/*   Updated: 2022/05/21 20:17:02 by sangminh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	lower_alphabet;

	lower_alphabet = 'a';
	while (lower_alphabet <= 'z')
	{
		write (1, &lower_alphabet, 1);
		lower_alphabet++;
	}
}
