/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:54:17 by guderram          #+#    #+#             */
/*   Updated: 2021/12/14 20:09:03 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_create_mapping_bis(m_point *map, int *one)
{
	int	u;

	u = map->x;
	while (map->file[u] != '\0')
	{
		if (map->file[u] == '\n' && one == 0 && u != map->x)
			break ;
		if (map->file[u] == '1')
			one++;
		if (map->file[u] == '\n' && one > 0)
			map->l = map->l + 1;
		if (map->file[u] == '\n')
			one = 0;
		u++;
	}
	while (map->file[u] == ' ' || map->file[u] == '\t' || map->file[u] == '\n')
		u++;
	return (u);
}

void	ft_create_mapping(m_point *map)
{
	int	u;
	int	one;

	one = 0;
	u = ft_create_mapping_bis(map, &one);
	if (map->file[u] != '\0')
		map->error = 840;
	map->map = (char **)malloc(sizeof(char *) * (map->l + 1));
	if (map->map == NULL)
		map->error = 1100;
	map->map[map->l] = NULL;
	u = 0;
	while (map->error == 0 && u < map->l)
	{
		map->map[u] = (char *)malloc(sizeof(char) * 1);
		map->map[u][0] = '\0';
		u++;
	}
}

void	ft_fill_line_map(m_point *map)
{
	int	i;
	int	u;
	int	j;

	i = 0;
	u = 0;
	j = 0;
	while (u < map->l && map->file[i] && map->file[i] != '\0')
	{
		map->map[u][j] = map->file[i];
		if (u < map->l && map->file[i] == '\n')
		{
			map->map[u][j] = '\0';
			j = 0;
			u++;
		}
		else
			j++;
		i++;
	}
}

void	ft_parse_map_bis(m_point *map)
{
	int	x;

	x = 0;
	while (map->map[0][x] != '\0' && map->map[0][x]
	!= '0' && map->map[0][x] != '2')
		x++;
	if (!(map->map[0][x] == '\0' || map->map[0][x] != '2'))
		map->error = 950;
	x = 0;
	while (map->map[map->l - 1][x] != '\0'
	&& map->map[map->l - 1][x] != '0' && map->map[map->l - 1][x] != '2')
		x++;
	if (!(map->map[map->l - 1][x] == '\0' || map->map[map->l - 1][x] != '2'))
		map->error = 955;
}

void	ft_parse_map(m_point *map)
{
	int	l;
	int	x;

	l = 0;
	x = 0;
	ft_parse_map_bis(map);
	while (map->error == 0 && map->map != NULL && map->map[l] != NULL)
	{
		while (map->error == 0 && map->map[l][x] != '\0')
		{
			if (ft_is_not_map(map->map[l][x], 0) == 1)
				ft_next_zero_map(map, l, x);
			if ((map->map[l][x] == '0' && map->error == 0)
			|| (map->map[l][x] == '2' && map->error == 0))
				ft_next_zero_map(map, l, x);
			x++;
		}
		x = 0;
		l++;
	}
}
