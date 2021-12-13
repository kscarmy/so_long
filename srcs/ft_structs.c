/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 13:58:21 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_map(m_point *map)
{
	map->error = 0;
	// map->rx = 0;
	// map->ry = 0;
	// map->x = 0;
	// map->res = 0;
	// map->floor = 0;
	// map->fr = 0;
	// map->fg = 0;
	// map->fb = 0;
	// map->ceiling = 0;
	// map->cr = 0;
	// map->cg = 0;
	// map->cb = 0;
	map->spawn = '0';
	map->l = 0;
	map->file = NULL;
	// map->no = NULL;
	// map->so = NULL;
	// map->we = NULL;
	// map->ea = NULL;
	// map->s = NULL;
	map->map = NULL; // TEST
}

void	ft_disp_verif(m_point *map)
{
	int u;
	// int i;
	// char *str;

	u = 0;
	// i = 0;
	// printf("R : '%d' : '%d','%d'\n", map->res, map->rx, map->ry);
	// printf("NO : '%s'\n", map->no);
	// printf("SO : '%s'\n", map->so);
	// printf("WE : '%s'\n", map->we);
	// printf("EA : '%s'\n", map->ea);
	// printf("S : '%s'\n", map->s);
	// printf("F : '%d' : '%d','%d','%d'\n", map->floor, map->fr, map->fg, map->fb);
	// printf("C : '%d' : '%d','%d','%d'\n", map->ceiling, map->cr, map->cg, map->cb);
	printf("Spawn : %c\n", map->spawn);
	// printf("BON : '%s'\n", map->map[0]);
	while (u < map->l) // AFFICHAGE DE LA MAP BUGGER
	{
		// str = map->map[u];
		// // printf("'%s'\n", str);
		// i = 0;
		// while (str[i])
		// {
		// 	printf("'%c'", (str[i]));
		// 	i++;
		// }
		// printf("\n");
		printf("'%s'\n", map->map[u]);
		u++;
	}
}

int		ft_exit_free_map(m_point *map, int ret)
{
	int i;

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
	// if (map->no != NULL)
	// 	ft_strdel(&map->no);
	// if (map->so != NULL)
	// 	ft_strdel(&map->so);
	// if (map->we != NULL)
	// 	ft_strdel(&map->we);
	// if (map->ea != NULL)
	// 	ft_strdel(&map->ea);
	// if (map->s != NULL)
	// 	ft_strdel(&map->s);
	if (map->file != NULL)
		ft_strdel(&map->file);
	printf("\n\033[0m<Les mallocs ont ete clears>\n");
	ft_disp_verif(map);
	return (ret);
}
