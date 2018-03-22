/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/22 14:22:10 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	ft_zoom(keycode, map, 0, 0);
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

int	ft_mousehooked(int button, int x, int y, t_map *map)
{
	if (button == 6 || button == 7)
		ft_zoom(69, map, x, y);
	if (button == 4)
		ft_zoom(78, map, x, y);
	ft_win_draw(map);
	return (0);
}

int	ft_hook(int x, int y, t_map *map)
{
	if (ft_abs(map->mouse.x) - ft_abs(x) > 10 || \
			ft_abs(map->mouse.y) - ft_abs(y))
	{
		map->mouse.x = x;
		map->mouse.y = y;
		map->c.r = ((double)x + map->shift.x) / map->zoom - 1.2;
		map->c.i = ((double)y + map->shift.y) / map->zoom - 1.2;
	}
	ft_win_draw(map);
	return (0);
}

int	ft_zoom(int keycode, t_map *map, int x, int y)
{
	if (keycode == 69)
	{
		map->zoom = map->zoom + 300;
		map->shift.x = map->shift.x + map->winsize.x / 2 + x;
		map->shift.y = map->shift.y + map->winsize.y / 2 + y;
	}
	if (keycode == 78 && map->zoom > 300)
	{
		map->zoom = map->zoom - 300;
		map->shift.x = map->shift.x - map->winsize.x / 2 - x;
		map->shift.y = map->shift.y - map->winsize.y / 2 - y;
	}
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
	mlx_mouse_hook(map.win, ft_mousehooked, &map);
	mlx_hook(map.win, 6, (1L << 6), ft_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
