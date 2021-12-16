/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:36:31 by guderram          #+#    #+#             */
/*   Updated: 2021/12/15 17:19:49 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_parsing_get_path(m_point *map, int z)
{
	char	*str;
	int		u;
	int		k;

	u = 0;
	k = 0;
	while (ft_is_space(map->file[map->x + z + u], 1, 1) == 0)
		u++;
	str = malloc(sizeof(char) * (u + 1));
	while (str != NULL && map->error == 0 && k < u)
	{
		str[k] = map->file[map->x + z + k];
		k++;
		str[k] = '\0';
	}
	if (str != NULL && ft_check_open(str) == 1 && map->error == 0)
	{
		map->x = map->x + z + u;
		return (str);
	}
	return (NULL);
}

void	ft_check_map(m_point *map)
{
	if (map->error == 0)
		ft_create_mapping(map);
	if (map->error == 0)
		ft_fill_map(map);
	if (map->error == 0)
		ft_parse_map(map);
}

void	ft_fill_map(m_point *map)
{
	int	u;
	int	i;

	u = 0;
	i = 0;
	while (map->file[u] != '\n' && map->file[u] != '\0')
		u++;
	while (i < map->l)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (u + 1));
		if (map->map[i] == NULL)
			map->error = 1200 + i;
		i++;
	}
	ft_fill_line_map(map);
}
