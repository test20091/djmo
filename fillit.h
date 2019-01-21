/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:29:12 by sdjemmou          #+#    #+#             */
/*   Updated: 2018/12/08 22:17:00 by sdjemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct s_tetris
{
    char t[4][4];
}               t_tetris;

int			ft_checklines(char *file);
void		ft_tmptab(int fd, char **tab);
void		ft_tetup(char **tab);
void		ft_tetleft(char **tab);

#endif

