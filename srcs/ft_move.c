/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:33:21 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_move_in(t_point *map, char c)
{
	if (map->map[map->py][map->px] != 'X')
		map->map[map->py][map->px] = '0';
	else
		map->map[map->py][map->px] = 'E';
	if (c == 'u')
		map->py = map->py - 1;
	if (c == 'd')
		map->py = map->py + 1;
	if (c == 'l')
		map->px = map->px - 1;
	if (c == 'r')
		map->px = map->px + 1;
	if (map->map[map->py][map->px] == 'C')
		map->c_count = map->c_count - 1;
	if (map->map[map->py][map->px] == 'E')
		map->map[map->py][map->px] = 'X';
	else
		map->map[map->py][map->px] = 'P';
	map->m_count = map->m_count + 1;
	printf("Player moved %d time\n", map->m_count);
	ft_end_game(map);
}

void	ft_end_game(t_point *map)
{
	if (map->map[map->py][map->px] == 'X' && map->c_count == 0)
	{
		printf("You win !\n");
		ft_exit_free_all(map, 0);
	}
}

void	ft_move_wasd(t_point *map, int key)
{
	if (key == KEY_MOVE_UP && map->map[map->py - 1][map->px] != '1')
		ft_move_in(map, 'u');
	if (key == KEY_MOVE_DOWN && map->map[map->py + 1][map->px] != '1')
		ft_move_in(map, 'd');
	if (key == KEY_MOVE_LEFT && map->map[map->py][map->px - 1] != '1')
		ft_move_in(map, 'l');
	if (key == KEY_MOVE_RIGHT && map->map[map->py][map->px + 1] != '1')
		ft_move_in(map, 'r');
}

void	ft_init_move(t_point *map)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	map->c_count = 0;
	map->m_count = 0;
	while (i < map->l)
	{
		while (map->map[i][u] != '\0')
		{
			if (map->map[i][u] == 'C')
				map->c_count = map->c_count + 1;
			if (map->map[i][u] == 'P')
			{
				map->px = u;
				map->py = i;
			}
			u++;
		}
		u = 0;
		i++;
	}
}
