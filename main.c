/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/13 16:25:21 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		map->zoom = map->zoom + 300;
		map->shift.x = map->shift.x + map->winsize.x / 2;
		map->shift.y = map->shift.y + map->winsize.y / 2;
	}
	if (keycode == 78 && map->zoom > 300)
	{
		map->zoom = map->zoom - 300;
		map->shift.x = map->shift.x - map->winsize.x / 2;
		map->shift.y = map->shift.y - map->winsize.y / 2;
	}
	if (keycode == 123)
		map->shift.x = map->shift.x - 30;
	if (keycode == 124)
		map->shift.x = map->shift.x + 30;
	if (keycode == 125)
		map->shift.y = map->shift.y + 30;
	if (keycode == 126)
		map->shift.y = map->shift.y - 30;
	if (keycode == 259 && map->imax < 400)
		map->imax = map->imax + 10;
	if (keycode == 261 && map->imax > 10)
		map->imax = map->imax - 10;
	if (keycode == 256)
		map->color_id++;
	ft_win_draw(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		ft_error("usage : ./fractol [mandelbrot, julia, burningship]\n");
	ft_map_init(&map, av[1]);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.winsize.x, map.winsize.y, "Fract_ol");
	ft_win_draw(&map);
	ft_printcontrols();
	mlx_key_hook(map.win, ft_keyhooked, &map);
	mlx_loop(map.mlx);
	return (0);
}
