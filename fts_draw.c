/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/11 20:11:45 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_win_draw(t_map *map)
{
	t_coord p;
	int	n[3];

	p.x = 0;
	p.y = 0;
	map->img = mlx_new_image(map->win, 500, 500);
	map->img_data = (int*)mlx_get_data_addr(map->img, &n[0], &n[1], &n[2]);
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

void ft_img_putpixel(t_map *map, t_coord p, int color)
{
	int i;
	int j;

	j = 0;
	i = (p.x + (p.y * 500));
	if (p.x > 0 && p.y > 0 && p.x < 500 && p.y < 500)
		map->img_data[i] = color;
}

void	ft_calc_color(t_map *map, t_coord p)
{
	t_complex	z;
	t_complex	c;
	t_coord_d	a;
	t_coord_d	b;
	int			i;
	int			tmp;

	z.r = 0;
	z.i = 0;
	a.x = -2.1;
	a.y = 0.6;
	b.x = -1.2;
	b.y = 1.2;
	c.r = p.x / 100 + a.x;
	c.i = p.y / 100 + a.y;
	i = 0;
	if (ft_strequ(map->fname, "mandelbrot"))
	{
		while (z.r * z.r + z.i * z.i < 4 && i < 50)
		{
			tmp = z.r;
			z.r = z.r * z.r - z.i * z.i + c.r;
			z.i = 2 * z.i * tmp + c.i;
			i++;
		}
		ft_putnbr(i);
		ft_putstr("\n");

	}
	if (i == 50)
	{
		ft_img_putpixel(map, p, 255255255);
		//ft_putnbr(p.y);
	}
}
