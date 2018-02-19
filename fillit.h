/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:53:59 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/12/26 15:59:31 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct	s_struct
{
	int		x[4];
	int		y[4];
	char	c;
}				t_struct;

void			ft_print_fs(t_struct fs, int num);
int				ft_retfig(char **argv);
int				ft_if_fs_on_map(t_struct *fs, int size_map, int ct);
int				ft_size_map(int num);
int				ft_two_fs_check(t_struct fs1, t_struct fs2);
t_struct		*ft_swaper_fs(int *size_map, int ct, t_struct *fs);
t_struct		*ft_nujnaya(int *size_map, t_struct *fs, int *n);
t_struct		*ft_perestanovka_fs(int *size_map, int ct, t_struct *fs);
t_struct		*ft_solver_excl(int *size_map, int ct, t_struct *fs);
t_struct		ft_to_mas(char *s, char c, int i, int k);
t_struct		ft_move_down_left_fs(t_struct fs, int size_map);
t_struct		ft_move_right_fs(t_struct fs, int size_map);
t_struct		ft_left_top_fs(t_struct fs, int size_map);
t_struct		ft_allswap_fs(int *sm, t_struct *fs, int s, int f);
t_struct		ft_backswap_fs(int *sm, t_struct *fs, int s, int f);
t_struct		*ft_fs_reader(t_struct *fs, int *ct, char **argv);
void			ft_print_fs(t_struct fs, int num);
void			ft_print_char_fs(t_struct fs, int x, int y, int *a);
void			ft_print_map3(t_struct *fs, int nu, int count_tet);
void			ft_error(void);
void			ft_touches(char *s);
void			ft_isfour(char *s);
void			ft_isvalid(char *s);
t_struct		ft_check_down(t_struct fs, int size_map, int *flag);

#endif
