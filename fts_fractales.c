/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_fractales.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:29:36 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/15 15:38:58 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot(t_map *map, t_coord p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp;

	c.r = ((double)p.x + map->shift.x) / map->zoom - 2.1;
	c.i = ((double)p.y + map->shift.y) / map->zoom - 1.2;
	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && i < map->imax)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

int		ft_julia(t_map *map, t_coord p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp;

	c.r = map->c.r;
	c.i = map->c.i;
	z.r = ((double)p.x + map->shift.x) / map->zoom - 1.2;
	z.i = ((double)p.y + map->shift.y) / map->zoom - 1.2;
	i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && i < map->imax)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}

int		ft_burningship(t_map *map, t_coord p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp;

	c.r = ((double)p.x + map->shift.x) / map->zoom - 2.1;
	c.i = ((double)p.y + map->shift.y) / map->zoom - 1.8;
	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.r * z.r + z.i * z.i) < 4 && i < map->imax)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * ft_abs_d(z.i * tmp) + c.i;
		i++;
	}
	return (i);
}
