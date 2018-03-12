/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/12 18:20:33 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_printcontrols(void)
{
	ft_putstr("\n--- Controls ---\n");
	ft_putstr("+ : zoom in\n");
	ft_putstr("- : zoom out\n");
	ft_putstr("ARROWS : move\n");
	ft_putstr("LEFT OPTION : move\n");
	ft_putstr("LEFT CMD : move\n");
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(-1);
}

void	ft_switchcolors(t_map *map)
{
	map->color_id++;
	map->colors[0] = 255;
	map->colors[1] = 255;
	map->colors[2] = 255;
	if (map->color_id % 5 == 1)
		map->colors[0] = 0;
	else if (map->color_id % 5 == 2)
		map->colors[1] = 0;
	else if (map->color_id % 5 == 3)
		map->colors[2] = 0;
	else if (map->color_id % 5 == 4)
	{
		map->colors[0] = rand() % 255;
		map->colors[1] = rand() % 255;
		map->colors[2] = rand() % 255;
	}
}
