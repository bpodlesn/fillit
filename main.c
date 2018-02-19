/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:44:28 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/01/22 17:56:18 by inazarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_struct	ft_check_down(t_struct fs, int size_map, int *flag)
{
	int i;

	i = -1;
	while (i++ < 4)
	{
		if (fs.y[i] == (size_map))
		{
			fs = ft_move_down_left_fs(fs, size_map);
			(*flag)++;
		}
	}
	return (fs);
}

int			ft_retfig(char **argv)
{
	int		figures;
	int		f;
	char	buf[22];
	int		ins;

	figures = 0;
	f = open(*argv, O_RDONLY);
	while ((ins = read(f, &buf, 21)))
	{
		if (ins <= 0)
			ft_error();
		figures++;
	}
	close(f);
	return (figures);
}

t_struct	*ft_fs_reader(t_struct *fs, int *ct, char **argv)
{
	int		f_in;
	char	buf[22];
	int		in;
	char	c;

	c = 'A';
	f_in = open(*argv, O_RDONLY);
	while ((in = read(f_in, &buf, 21)))
	{
		buf[in] = '\0';
		ft_isvalid(buf);
		fs[(*ct)] = ft_to_mas(buf, (c + (*ct)), 0, 0);
		(*ct)++;
	}
	if ((buf[20] == '\n' && buf[19] == '\n') || ((*ct) > 26)
		|| (buf[0] != '.' && buf[0] != '#'))
		ft_error();
	close(f_in);
	return (fs);
}

int			main(int argc, char **argv)
{
	int			nu;
	int			count_tet;
	t_struct	*fs;

	count_tet = 0;
	if (argc != 2)
	{
		write(1, "Usage: ./fillit filename\n", 25);
		return (0);
	}
	fs = (t_struct *)malloc(sizeof(t_struct) * (ft_retfig(&argv[1])));
	if (!fs)
		return (0);
	ft_fs_reader(fs, &count_tet, &argv[1]);
	nu = ft_size_map(count_tet);
	fs = ft_solver_excl(&nu, count_tet, fs);
	ft_print_map3(fs, nu, count_tet);
	return (0);
}
