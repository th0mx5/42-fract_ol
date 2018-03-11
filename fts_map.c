/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/11 19:17:40 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map_init(t_map *map, char *file_name)
{
	map->fname = ft_strdup(file_name);
	map->imax = 50;
	map->zoom = 1.00;
	map->imax = 0;
	map->shift.x = 0;
	map->shift.y = 0;
	map->shift.z = 0;
}
