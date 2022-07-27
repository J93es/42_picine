/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_judge_col.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:22:06 by mijung            #+#    #+#             */
/*   Updated: 2022/05/29 15:25:29 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_JUDGE_COL_H
# define SUB_JUDGE_COL_H

int	judge_col_num(int arr[9][9], int col_pos, int row_pos);
int	judge_col_up(int arr[9][9], int row_pos);
int	judge_col_down(int arr[9][9], int row_pos);
#endif
