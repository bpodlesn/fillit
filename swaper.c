/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:36:48 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/12/26 15:36:50 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_if_fs_on_map(t_struct *fs, int size_map, int ct)
{
	int i;
	int	j;

	i = 0;
	while (i < ct)
	{
		j = 0;
		while (j < 4)
		{
			if (fs[i].x[j] > (size_map - 1) || fs[i].y[j] > (size_map - 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_struct	*ft_swaper_fs(int *size_map, int ct, t_struct *fs)
{
	int a;
	int first;
	int second;

	a = 0;
	first = 0;
	second = 1;
	while (a < ct)
	{
		fs[a] = ft_left_top_fs(fs[a], *size_map);
		a++;
	}
	while (second < ct)
	{
		fs[second] = ft_allswap_fs(size_map, fs, second, first);
		second++;
	}
	return (fs);
}

t_struct	*ft_nujnaya(int *size_map, t_struct *fs, int *n)
{
	fs[*n] = ft_left_top_fs(fs[*n], *size_map);
	(*n)--;
	fs[*n] = ft_move_right_fs(fs[*n], *size_map);
	return (fs);
}

t_struct	*ft_perestanovka_fs(int *size_map, int ct, t_struct *fs)
{
	int n;
	int m;
	int a;

	n = ct - 1;
	a = 0;
	while (n != ct)
	{
		if (ft_if_fs_on_map(fs, *size_map, ct) == 1)
			fs = ft_nujnaya(size_map, fs, &n);
		else
			n++;
		m = -1;
		while (m++ < ct)
			fs[n] = ft_allswap_fs(size_map, fs, n, m);
		if (n <= -1)
			a++;
		if (a == 10)
		{
			fs = ft_swaper_fs(size_map, ct, fs);
			return (fs);
		}
	}
	return (fs);
}

t_struct	*ft_solver_excl(int *size_map, int ct, t_struct *fs)
{
	fs = ft_swaper_fs(size_map, ct, fs);
	fs = ft_perestanovka_fs(size_map, ct, fs);
	while (ft_if_fs_on_map(fs, *size_map, ct) == 1)
	{
		(*size_map) += 1;
		fs = ft_swaper_fs(size_map, ct, fs);
		fs = ft_perestanovka_fs(size_map, ct, fs);
	}
	return (fs);
}
