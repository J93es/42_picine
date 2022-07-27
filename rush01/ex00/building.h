/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:21:25 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 13:56:49 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDING_H
# define BUILDING_H

int		ft_building(int arr[9][9], int col_pos, int row_pos, int num);
int		ft_judge_center(int arr[9][9], int col_pos, int row_pos);
void	ft_print_arr(int arr[9]);
void	ft_put_str(char *str);
void	ft_set_pos(int *col_pos, int *row_pos);
#endif
