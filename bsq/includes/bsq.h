/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:16:50 by mijung            #+#    #+#             */
/*   Updated: 2022/06/09 12:40:24 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	long long	col_len;
	long long	row_len;
	long long	first_col_len;
	char		vog;
	char		ob;
	char		full;
	char		**field;
	char		*first_col;
	long long	**copy;
	char		*temp;
	long long	temp_pos;
}	t_map;
typedef struct s_answer
{
	long long	x;
	long long	y;
	long long	score;
}	t_answer;

int			check_min(long long **copy, int i, int j);
t_answer	result_update(t_answer s_result, int i, int j, t_map s_table);
t_answer	bsq_logic(t_map s_table);
t_map		initialize(t_map s_table);
t_map		make_result(t_map s_table, t_answer s_result);
void		write_result(t_map s_table);
void		ft_error(t_map s_table);
void		ft_pipeline(t_map s_table);
int			main(int argc, char *argv[]);
void		free_result(t_map s_table);
void		ft_free_char(char **result, int i, t_map *s_table);
void		ft_free_long_long(long long **result, int i);
long long	**mallocing_long_long(t_map *s_table);
char		**mallocing_char(t_map *s_table);
int			len(char *str);
int			ob_vog_check(t_map *s_table);
int			len_check(t_map *s_table);
int			duplicate_or_nonable_check(t_map *s_table);
int			map_check(t_map *s_table);
int			set_table_len(t_map *s_table);
int			open_file_1(t_map *s_table, char *f_name, int fd);
int			set_field(t_map *s_table, long long i);
int			set_table(t_map *s_table, long long num);
int			make_table(t_map *s_table);
int			open_file_2(t_map *s_table);
#endif
