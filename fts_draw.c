/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/13 16:11:25 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_draw(t_map *map)
{
	t_coord	p;
	int		n[3];

	p.x = 0;
	p.y = 0;
	map->img = mlx_new_image(map->win, map->winsize.x, map->winsize.y);
	map->img_data = mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
	while (p.y < map->winsize.y)
	{
		p.x = 0;
		while (p.x < map->winsize.x)
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

	i = (p.x + (p.y * map->winsize.x)) * 4;
	if (p.x > -1 && p.y > -1 && p.x < map->winsize.x && p.y < map->winsize.y)
	{
		map->img_data[i] = (char)color[0];
		map->img_data[i + 1] = (char)color[1];
		map->img_data[i + 2] = (char)color[2];
	}
}

void	ft_calc_color(t_map *map, t_coord p)
{
	int			i;
	int			color[3];

	i = 0;
	if (ft_strequ(map->fname, "mandelbrot"))
		i = ft_mandelbrot(map, p);
	else if (ft_strequ(map->fname, "julia"))
		i = ft_julia(map, p);
	else
		i = ft_burningship(map, p);
	ft_pickcolors(map, color, i);
	ft_img_putpixel(map, p, color);
}
