/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:45:54 by mijung            #+#    #+#             */
/*   Updated: 2022/05/30 17:12:37 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rev_alphabet;

	rev_alphabet = 'z';
	while (rev_alphabet >= 'a')
	{
		write (1, &rev_alphabet, 1);
		rev_alphabet--;
	}
}
