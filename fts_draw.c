/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/12 18:54:18 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_draw(t_map *map)
{
	t_coord	p;
	int		n[3];

	p.x = 0;
	p.y = 0;
	map->img = mlx_new_image(map->win, 500, 500);
	map->img_data = mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
	while (p.y < 500)
	{
		p.x = 0;
		while (p.x < 500)
		{
			ft_calc_color(map, p);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
	mlx_do_sync(map->mlx);
}

void	ft_img_putpixel(t_map *map, t_coord p, int *color)
{
	int i;
	i = (p.x + (p.y * 500)) * 4;
	if (p.x > -1 && p.y > -1 && p.x < 500 && p.y < 500)
	{
		map->img_data[i] = (char)color[0];
		map->img_data[i + 1] = (char)color[1];
		map->img_data[i + 2] = (char)color[2];
	}
}

void	ft_calc_color(t_map *map, t_coord p)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp;
	int			color[3];

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
	color[0] = map->colors[0] * ((double)i / map->imax);
	color[1] = map->colors[1] * ((double)i / map->imax);
	color[2] = map->colors[2] * ((double)i / map->imax);
	//p.x = p.x - (2.7 * map->zoom);
	//p.y = p.y + (2.4 * map->zoom);
	ft_img_putpixel(map, p, color);
}
