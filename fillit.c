/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:46:31 by sdjemmou          #+#    #+#             */
/*   Updated: 2018/12/09 20:22:48 by sdjemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_tetcmp(int i, int m, char **tab)
{
	int 		fd;
	int			f;
	char		*line;
	int			k;

	f = i + 10;
	while (f <= m)
	{
		fd = open(ft_itoa(f), O_RDONLY);
		k = 0;
		i = 0;
		while (get_next_line(fd, &line) != 0 && k < 4)
		{
			if (ft_strcmp(line, tab[k]) == 0)
				i++;
			k++;
		}
		close(fd);
		if (i == 4)
			return (f);
		f = f + 10;
	}
	return (0);
}

int			ft_count(char *line)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			k++;
		i++;
	}
	return (k);
}

int			ft_seektet(char **tab)
{
	if (tab[0][0] == '.')
		return (ft_tetcmp(0, 60, tab));
	if (tab[0][0] == '#' && ft_count(tab[0]) == 1)
		return (ft_tetcmp(1, 51, tab));
	if (tab[0][0] == '#' && ft_count(tab[0]) == 2)
		return (ft_tetcmp(2, 42, tab));
	if (tab[0][0] == '#' && ft_count(tab[0]) == 3)
		return (ft_tetcmp(3, 33, tab));
	if (tab[0][0] == '#' && ft_count(tab[0]) == 4)
		return (ft_tetcmp(4, 14, tab));
	return (0);
}

int			*ft_deftet(char *file)
{
	char	*tab[4];
	int		fd;
	int		i;
	int		nbrtet;
	int		*tet;

	i = 0;
	nbrtet = ft_checklines(file);
	tet = (int *)malloc(sizeof(int) * nbrtet);
	fd = open(file, O_RDONLY);
	while (i <= nbrtet && nbrtet != 0)
	{
		ft_tmptab(fd, tab);
		tet[i] = ft_seektet(tab);
		i++;
	}
	return (tet);
}

int			main(int ac, char **av)
{
	int *t;
	int n;
	int i;
	t_tetris *grid;
	i = 0;
	n = ft_checklines(av[1]);
	t = ft_deftet(av[1]);
	if (ac == 2)
	{
		while (i < n)
		{
			//ft_putnbr(t[i]);
			//ft_putchar('\n');
			i++;
		}
	}
	i = 0;
   	grid = malloc(sizeof(t_tetris) * n);
	while (i < n)
	{
		int k ;
		char *buff;
		buff = malloc(sizeof(char));
		char *line;
		int fd = open(ft_itoa(t[i]),O_RDONLY);
		int j = 0;
		while (j < 4)
		{
			get_next_line(fd,&line);
			k = 0;
			while (k < 4)
			{
				grid[i].t[j][k] = line[k];
				k++;
			}	
			j++;
		}
		free(buff);
		i++;
	}
	int j;
	i = j = 0;
	while (i < 4)
	{
		j =0 ;
		while (j < 4)
		{
			ft_putchar(grid[0].t[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (0);
}

