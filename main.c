/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/12 18:26:05 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		map->zoom = map->zoom + 30;
	if (keycode == 78 && map->zoom > 100)
		map->zoom = map->zoom - 30;
	if (keycode == 123)
		map->shift.x = map->shift.x + 20;
	if (keycode == 124)
		map->shift.x = map->shift.x - 20;
	if (keycode == 125)
		map->shift.y = map->shift.y - 20;
	if (keycode == 126)
		map->shift.y = map->shift.y + 20;
	if (keycode == 259 && map->imax < 400)
		map->imax = map->imax + 10;
	if (keycode == 261 && map->imax > 10)
		map->imax = map->imax - 10;
	if (keycode == 256)
		ft_switchcolors(map);
	ft_win_draw(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	time_t	t;

	if (ac != 2)
		ft_error("usage : ./fractol [mandelbrot, julia, burningship]\n");
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 500, 500, "Fract_ol");
	ft_map_init(&map, av[1]);
	ft_win_draw(&map);
	srand((unsigned) time(&t));
	ft_printcontrols();
	mlx_key_hook(map.win, ft_keyhooked, &map);
	mlx_loop(map.mlx);
	return (0);
}
