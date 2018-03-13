/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:55:52 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/13 16:03:11 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_coord_d
{
	double		x;
	double		y;
}				t_coord_d;

typedef struct	s_complex
{
	double		i;
	double		r;
}				t_complex;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*fname;
	t_coord		winsize;
	char		*img_data;
	double		zoom;
	t_coord		shift;
	int			imax;
	int			color_id;
}				t_map;

int				ft_keyhooked(int keycode, t_map *map);

void			ft_win_draw(t_map *map);
void			ft_img_putpixel(t_map *map, t_coord p, int *color);
void			ft_calc_color(t_map *map, t_coord p);

void			ft_map_init(t_map *map, char *file_name);

void			ft_printcontrols(void);
void			ft_error(char *s);
void			ft_pickcolors(t_map *map, int *color, int i);

int				ft_mandelbrot(t_map *map, t_coord p);
int				ft_julia(t_map *map, t_coord p);
int				ft_burningship(t_map *map, t_coord p);

double			ft_abs_d(double nb);

#endif
