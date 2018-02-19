/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:10:59 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/12/26 15:11:01 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_size_map(int num)
{
	int n;
	int m;

	n = num * 4;
	m = 2;
	while ((m * m) < n)
		m++;
	return (m);
}

t_struct	ft_to_mas(char *s, char c, int i, int k)
{
	t_struct	new;
	int			x;
	int			y;

	x = 0;
	y = 0;
	new.c = c;
	while (s[k])
	{
		if (s[k] == '\n')
		{
			y = -1;
			x++;
		}
		if (s[k] == '#')
		{
			new.x[i] = x;
			new.y[i] = y;
			i++;
		}
		y++;
		k++;
	}
	return (new);
}

t_struct	ft_move_down_left_fs(t_struct fs, int size_map)
{
	int i;
	int miny;

	miny = size_map - 1;
	i = 0;
	while (i < 4)
	{
		if (fs.y[i] < miny)
			miny = fs.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fs.x[i] += 1;
		fs.y[i] -= miny;
		i++;
	}
	return (fs);
}

t_struct	ft_move_right_fs(t_struct fs, int size_map)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	fs = ft_check_down(fs, size_map, &flag);
	i = -1;
	if (flag == 0)
	{
		while (i++ < 4)
		{
			fs.y[i] += 1;
		}
	}
	fs = ft_check_down(fs, size_map, &flag);
	fs.c -= 1;
	return (fs);
}

t_struct	ft_left_top_fs(t_struct fs, int size_map)
{
	int i;
	int maxx;
	int miny;

	i = 0;
	maxx = fs.x[0];
	miny = size_map - 1;
	while (i < 4)
	{
		if (fs.x[i] < maxx)
			maxx = fs.x[i];
		if (fs.y[i] < miny)
			miny = fs.y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fs.x[i] -= maxx;
		fs.y[i] -= miny;
		i++;
	}
	return (fs);
}
