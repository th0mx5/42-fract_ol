/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/10 19:00:55 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_keyhooked(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		map->zoom = map->zoom + 0.1;
	if (keycode == 78 && map->zoom > 0.2)
		map->zoom = map->zoom - 0.1;
	if (keycode == 123)
		map->shift.x = map->shift.x + 10;
	if (keycode == 124)
		map->shift.x = map->shift.x - 10;
	if (keycode == 125)
		map->shift.y = map->shift.y - 10;
	if (keycode == 126)
		map->shift.y = map->shift.y + 10;
	ft_win_draw(map);
	return (0);
}

int main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		ft_error("usage : ./fractol [mandelbrot, julia, burningship]\n");
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 500, 500, "Fract_ol");
	(void)**av;
	ft_win_draw(&map);
	ft_printcontrols();
	mlx_key_hook(map.win, ft_keyhooked, &map);
	mlx_loop(map.mlx);
	return (0);
}
