/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:26:12 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/12/26 15:26:15 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_two_fs_check(t_struct fs1, t_struct fs2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (fs1.x[x] == fs2.x[y] && fs1.y[x] == fs2.y[y])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void		ft_print_char_fs(t_struct fs, int x, int y, int *a)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (fs.x[i] == x && fs.y[i] == y)
		{
			write(1, &fs.c, 1);
			(*a)++;
		}
		i++;
	}
}

void		ft_print_map3(t_struct *fs, int nu, int count_tet)
{
	int x;
	int y;
	int o;
	int a;

	x = -1;
	while (x++ < nu - 1)
	{
		y = -1;
		while (y++ < nu - 1)
		{
			o = 0;
			a = 0;
			while (o < count_tet)
			{
				ft_print_char_fs(fs[o], x, y, &a);
				o++;
			}
			if (a == 0)
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}

t_struct	ft_allswap_fs(int *sm, t_struct *fs, int s, int f)
{
	int temp_map_size;

	temp_map_size = *sm;
	while (f < s)
	{
		if (ft_two_fs_check(fs[f], fs[s]))
		{
			fs[s] = ft_move_right_fs(fs[s], temp_map_size);
			ft_backswap_fs(sm, fs, s, f);
		}
		else
			f++;
	}
	return (fs[s]);
}

t_struct	ft_backswap_fs(int *sm, t_struct *fs, int s, int f)
{
	while (f != -1)
	{
		if (ft_two_fs_check(fs[f], fs[s]))
		{
			fs[s] = ft_move_right_fs(fs[s], *sm);
			ft_allswap_fs(sm, fs, s, f);
		}
		else
			f--;
	}
	return (fs[s]);
}
