/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:54:49 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_verif_something(t_point *map)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	map->rx = 0;
	map->ry = 0;
	map->x = 0;
	while (i < map->l)
	{
		while (map->map[i][u] != '\0')
		{
			if (map->map[i][u] == 'P')
				map->rx = map->rx + 1;
			if (map->map[i][u] == 'E')
				map->ry = map->ry + 1;
			if (map->map[i][u] == 'C')
				map->x = map->x + 1;
			u++;
		}
		u = 0;
		i++;
	}
	ft_verif_count(map);
}

void	ft_verif_count(t_point *map)
{
	if (map->rx != 1)
	{
		printf("Error : number of player starting position on map\n");
		map->error = map->error + 1;
	}
	if (map->ry == 0)
	{
		printf("Error : no exit on map\n");
		map->error = map->error + 1;
	}
	if (map->x == 0)
	{
		printf("Error : no collectible on map\n");
		map->error = map->error + 1;
	}
}
