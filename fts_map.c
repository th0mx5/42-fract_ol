/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/13 16:10:28 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map_init(t_map *map, char *file_name)
{
	map->fname = ft_strdup(file_name);
	if (ft_strequ(map->fname, "mandelbrot"))
	{
		map->winsize.x = 270 * 3;
		map->winsize.y = 240 * 3;
	}
	else if (ft_strequ(map->fname, "julia"))
	{
		map->winsize.x = 250 * 3;
		map->winsize.y = 250 * 3;
	}
	else if (ft_strequ(map->fname, "burningship"))
	{
		map->winsize.x = 320 * 3;
		map->winsize.y = 250 * 3;
	}
	else
		ft_error("error");
	map->zoom = 300;
	map->imax = 50;
	map->shift.x = 0;
	map->shift.y = 0;
	map->shift.z = 0;
}
