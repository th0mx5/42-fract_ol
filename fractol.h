/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:55:52 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/10 18:59:44 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct	s_coord
{
	int x;
	int y;
	int z;
}				t_coord;

typedef struct	s_map
{
	void	*mlx;
	void	*win;
	void	*img;
	t_coord	fsize;
	char	*fname;
	t_coord	wsize;
	int		*img_data;
	double	zoom;
	t_coord	shift;
}				t_map;

int		ft_keyhooked(int keycode, t_map *map);

void	ft_win_draw(t_map *map);

void	ft_printcontrols(void);
void	ft_error(char *s);

#endif
