/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_judge_row.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:22:14 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 13:59:40 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_JUDGE_ROW_H
# define SUB_JUDGE_ROW_H

int	judge_row_num(int arr[9][9], int col_pos, int row_pos);
int	judge_row_left(int arr[9][9], int col_pos);
int	judge_row_right(int arr[9][9], int col_pos);
#endif
