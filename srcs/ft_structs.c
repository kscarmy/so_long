/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_map(t_point *map)
{
	map->error = 0;
	map->spawn = '0';
	map->l = 0;
	map->file = NULL;
	map->map = NULL;
}

void	ft_disp_verif(t_point *map)
{
	int	u;

	u = 0;
	while (u < map->l)
	{
		printf("'%s'\n", map->map[u]);
		u++;
	}
}

int	ft_exit_free_map(t_point *map, int ret)
{
	int	i;

	i = 0;
	while (i < map->l)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	if (map->map != NULL)
	{
		free(map->map);
		map->map = NULL;
		map->l = 0;
	}
	if (map->file != NULL)
		ft_strdel(&map->file);
	printf("\n\033[0m<Les mallocs ont ete clears>\n");
	ft_disp_verif(map);
	return (ret);
}
