/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:10:03 by guderram          #+#    #+#             */
/*   Updated: 2021/12/14 20:11:28 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_set_world_spawn(m_point *map, int u)
{
	if (map->spawn != '0')
	{
		map->x = u;
		map->error = 830;
	}
	else
		map->spawn = map->file[u];
}

int	ft_is_not_map(char c, int one)
{
	int	m;

	m = 0;
	if (c == '1' && one == 1)
		m++;
	if (c == '0')
		m++;
	if (c == 'C')
		m++;
	if (c == '\n' && one == 1)
		m++;
	if (c == 'E')
		m++;
	if (c == 'P')
		m++;
	return (m);
}

int	ft_next_zero_char(char c)
{
	int	x;

	x = 0;
	if (c == '0')
		x++;
	if (c == '1')
		x++;
	if (c == 'C')
		x++;
	if (c == 'E')
		x++;
	if (c == 'P')
		x++;
	return (x);
}

void	ft_next_zero_map(m_point *map, int l, int x)
{
	if (l == 0 || l == map->l - 1)
		map->error = 970;
	if (map->error == 0 && ft_next_zero_char(map->map[l - 1][x - 1]) == 0)
		ft_map_disp_error(map, l - 1, x - 1, 960);
	if (map->error == 0 && ft_next_zero_char(map->map[l - 1][x]) == 0)
		ft_map_disp_error(map, l - 1, x, 961);
	if (map->error == 0 && ft_next_zero_char(map->map[l - 1][x + 1]) == 0)
		ft_map_disp_error(map, l - 1, x + 1, 962);
	if (map->error == 0 && ft_next_zero_char(map->map[l][x - 1]) == 0)
		ft_map_disp_error(map, l, x - 1, 963);
	if (map->error == 0 && ft_next_zero_char(map->map[l][x + 1]) == 0)
		ft_map_disp_error(map, l, x + 1, 964);
	if (map->error == 0 && ft_next_zero_char(map->map[l + 1][x - 1]) == 0)
		ft_map_disp_error(map, l + 1, x - 1, 965);
	if (map->error == 0 && ft_next_zero_char(map->map[l + 1][x]) == 0)
		ft_map_disp_error(map, l + 1, x, 966);
	if (map->error == 0 && ft_next_zero_char(map->map[l + 1][x + 1]) == 0)
		ft_map_disp_error(map, l + 1, x + 1, 967);
	if (map->error == 970)
		ft_map_disp_error(map, l, x, 970);
}
