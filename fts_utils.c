/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/13 16:17:32 by thbernar         ###   ########.fr       */
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

void	ft_pickcolors(t_map *map, int *color, int i)
{
	if (i == map->imax)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}
	else if (map->color_id % 2 == 0)
	{
		color[0] = 255 * ((double)1 - (double)i / map->imax);
		color[1] = 255 * ((double)1 - (double)i / map->imax);
		color[2] = 255 * ((double)1 - (double)i / map->imax);
	}
	else if (map->color_id % 2 == 1)
	{
		color[0] = 100 * i;
		color[1] = 10 * i;
		color[2] = 50 * i;
	}
}

double	ft_abs_d(double nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
