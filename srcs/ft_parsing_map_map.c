/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 19:53:11 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_create_mapping(m_point *map)
{
    int u;
    // int l; // Je dois l'integrer à la structure :)
    int one;

    u = map->x;
    // l = 1; // nbre de lignes, commence à 1 car la tete de lecture est déjà dessus normalement.
    one = 0;
    // one = one + 1; // A SUPPRIMER C PR TESTER
    // printf("4x : %d, u : %d\n", map->x, u);
    while (map->file[u] != '\0')
    {
        if (map->file[u] == '\n' && one == 0 && u != map->x)
        {
            // printf("u : %d,\n'%c'\n", &map->file[u]);
            break ;
        }
        if (map->file[u] == '1')
            one++;
        if (map->file[u] == '\n' && one > 0)
            map->l = map->l + 1;
        one = (map->file[u] == '\n') ? 0 : one;
        u++;
    }
    // printf("test file : \n%s\n", &map->file[map->x + u]);
    // printf("5x : %d, u : %d\n", map->x, u);
    while (map->file[u] == ' ' || map->file[u] == '\t' || map->file[u] == '\n')
        u++;
    // printf("6x : %d, u : %d\n", map->x, u);
    // printf("error : %d\n", map->error);
    // printf("file u : '%c'\n", map->file[u]);
    // printf("1l : %d\n", map->l);
    map->error = (map->file[u] == '\0') ? map->error : 840;
    map->map = (char**)malloc(sizeof(char*) * (map->l + 1));
    map->error = (map->map == NULL) ? 1100 : map->error;
	map->map[map->l] = NULL;
	u = 0;
	while (u < map->l)
	{
		// ft_bzero(map->map[u], 1); // TEST 123
		map->map[u] = (char*)malloc(sizeof(char) * 1); // comme ça je leaks ...
		map->map[u][0] = '\0';
		// map->map[u] = NULL;
		u++;
	}



	// printf("error = '%d'\n", map->error);
    // printf("7x : %d, u : %d\n", map->x, u);
}

void    ft_fill_map(m_point *map)
{
	int u;
	int i;

	u = 0;
	i = 0;
	while (map->file[u] != '\n' && map->file[u] != '\0')
        u++;
	while (i < map->l)
	{
		map->map[i] = (char*)malloc(sizeof(char) * (u + 1));
			if (map->map[i] == NULL)
		map->error = 1200 + i;
		i++;
	}
	ft_fill_line_map(map);

}

void    ft_fill_line_map(m_point *map)
{
	int i; // curseur de lecture dans map file
	int u; // done la ligne de map map
	int	j; // incre la ligne de map map

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



void    ft_parse_map(m_point *map)
{
    int l;
    int x;

    l = 0;
    x = 0;
    while (map->map[0][x] != '\0' && map->map[0][x] != '0' && map->map[0][x] != '2')
        x++;
    map->error = (map->map[0][x] == '\0' || map->map[0][x] != '2') ? map->error : 950;
    x = 0;
    while (map->map[map->l - 1][x] != '\0' && map->map[map->l - 1][x] != '0' && map->map[map->l - 1][x] != '2')
        x++;
    map->error = (map->map[map->l - 1][x] == '\0' || map->map[map->l - 1][x] != '2') ? map->error : 955;
    x = 0;
    // printf("map : %p\n", map);
    // printf("mm : %p\n", map->map);
    // printf
    while (map->error == 0 && map->map != NULL && map->map[l] != NULL)
    {
        // printf("l : %p\n", map->map[l]);
        while (map->error == 0 && map->map[l][x] != '\0')
        {
            // printf("x : %p %c\n", map->map[l][x], map->map[l][x]);
            if (ft_is_not_map(map->map[l][x], 0) == 1)
                ft_next_zero_map(map, l, x);
            if ((map->map[l][x] == '0' && map->error == 0) || (map->map[l][x] == '2' && map->error == 0))
            {
                ft_next_zero_map(map, l, x);
                // printf("HEIN4\n");
            }
            x++;
            // printf("HEIN3\n");
        }
        x = 0;
        l++;
        // printf("HEIN2\n");
    }
    // printf("HEIN1\n");
}

void    ft_check_map(m_point *map) // call toutes les merdes pour la map
{
    if (map->error == 0)
        ft_create_mapping(map);
    if (map->error == 0)
        ft_fill_map(map);
    if (map->error == 0)
        ft_parse_map(map);
}