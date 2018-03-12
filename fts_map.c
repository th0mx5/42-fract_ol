/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/12 18:17:29 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map_init(t_map *map, char *file_name)
{
	map->fname = ft_strdup(file_name);
	map->zoom = 100;
	map->imax = 50;
	map->shift.x = 0;
	map->shift.y = 0;
	map->shift.z = 0;
	map->colors[0] = rand() % 255;
	map->colors[1] = rand() % 255;
	map->colors[2] = rand() % 255;
}
