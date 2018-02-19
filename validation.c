/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:08:42 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/12/27 13:00:17 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		ft_touches(char *s)
{
	int		touches;
	int		i;

	i = 0;
	touches = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#' && s[i + 1] == '#')
			touches++;
		if (s[i] == '#' && s[i + 5] == '#')
			touches++;
		i++;
	}
	if (touches < 3)
		ft_error();
}

void		ft_isfour(char *s)
{
	int i;

	i = 4;
	while (i < 20)
	{
		if (s[i] != '\n')
			ft_error();
		i += 5;
	}
	if (s[20] != '\n' && s[20] != '\0')
		ft_error();
}

void		ft_isvalid(char *s)
{
	int		a;
	int		hashes;

	hashes = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] != '.' && s[a] != '#' && s[a] != '\n')
			ft_error();
		if (s[a] == '#')
			hashes++;
		a++;
	}
	if (hashes != 4)
		ft_error();
	ft_isfour(s);
	ft_touches(s);
}
