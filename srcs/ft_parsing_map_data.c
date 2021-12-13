/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 13:44:00 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// void ft_parsing_resolution(m_point *map)
// {
//     int z;

//     z = 1;
//     if (map->res == 0)
//     {
//         z = z + ft_incre_spaces(map, 0, z);
//         map->rx = ft_atoi((&map->file[map->x + z])); // donne une valeur à rx
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         map->ry = ft_atoi((&map->file[map->x + z])); // donne une valeur à ry
//         z = z + ft_incre_spaces(map, 0, z);
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = z + ft_incre_spaces(map, 0, z);
//         map->x = map->x + z;
//         if (map->file[map->x] != '\n' || map->rx <= 0 || map->ry <= 0)
//             map->error = 505;
//         map->res = 1;
//     }
//     else
//         map->error = 500;
// }

// void    ft_parsing_floor(m_point *map)
// {
//     int z;

//     z = 1;
//     if (map->floor == 0)
//     {
//         z = z + ft_incre_spaces(map, 0, z);
//         map->fr = ft_atoi((&map->file[map->x + z])); // Floor Red
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = (map->file[map->x + z] == ',') ? z + 1 : z;
//         map->fg = ft_atoi((&map->file[map->x + z])); // Floor Green
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = (map->file[map->x + z] == ',') ? z + 1 : z;
//         map->fb = ft_atoi((&map->file[map->x + z])); // Floor Blue
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = z + ft_incre_spaces(map, 0, z);
//         map->x = map->x + z;
//         if (map->file[map->x] != '\n' || ft_is_color(map->fr) || ft_is_color(map->fg) || ft_is_color(map->fb))
//             map->error = 515;
//         map->floor = 1;
//     }
//     else
//         map->error = 510;
// }

// void    ft_parsing_ceiling(m_point *map)
// {
//     int z;

//     z = 1;
//     if (map->ceiling == 0)
//     {
//         z = z + ft_incre_spaces(map, 0, z);
//         map->cr = ft_atoi((&map->file[map->x + z])); // Ceiling Red
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = (map->file[map->x + z] == ',') ? z + 1 : z;
//         map->cg = ft_atoi((&map->file[map->x + z])); // Ceiling Green
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = (map->file[map->x + z] == ',') ? z + 1 : z;
//         map->cb = ft_atoi((&map->file[map->x + z])); // Ceiling Blue
//         while (ft_isdigit(map->file[map->x + z]) == 1) // bouge le head jusqu'au prochain int
//             z++;
//         z = z + ft_incre_spaces(map, 0, z);
//         map->x = map->x + z;
//         if (map->file[map->x] != '\n' || ft_is_color(map->cr) || ft_is_color(map->cg) || ft_is_color(map->cb))
//             map->error = 525;
//         map->ceiling = 1;
//         // printf("zeubix : %d\n", map->x);
//     }
//     else
//         map->error = 520;
// }

char    *ft_parsing_get_path(m_point *map, int z)
{
    char *str;
    int u;
    int k;

    u = 0;
    k = 0;
    while (ft_is_space(map->file[map->x + z + u], 1, 1, map) == 0)
        u++;
    str = malloc(sizeof(char) * (u + 1));
	if ((map->error = (str == NULL) ? 1010 : map->error) != 0)
		return (NULL);
    while (map->error == 0 && k < u)
    {
        str[k] = map->file[map->x + z + k];
        k++;
    }
    str[k] = '\0';
    // printf("alors ?\n");
    map->error = (ft_check_open(str) == 1) ? 900 : map->error;
    map->x = (map->error == 0) ? map->x + z + u : map->x;
    return (str);
}

// void    ft_parsing_path_to(m_point *map)
// {
//     int z;
//     int y;

//     y = map->x;
//     z = (map->file[map->x] == 'S' && map->file[map->x + 1] == ' ') ? 1 : 2;
//     z = z + ft_incre_spaces(map, 0, z);
//     map->error = (map->no != NULL && map->file[map->x] == 'N' && map->file[map->x + 1] == 'O') ? 600 : map->error; //check si déjà alloué
//     map->error = (map->so != NULL && map->file[map->x] == 'S' && map->file[map->x + 1] == 'O') ? 610 : map->error;
//     map->error = (map->we != NULL && map->file[map->x] == 'W' && map->file[map->x + 1] == 'E') ? 620 : map->error;
//     map->error = (map->ea != NULL && map->file[map->x] == 'E' && map->file[map->x + 1] == 'A') ? 630 : map->error;
//     map->error = (map->s != NULL && map->file[map->x] == 'S' && map->file[map->x + 1] == ' ') ? 640 : map->error;
//     if (map->error == 0 && map->file[y] == 'N' && map->file[y + 1] == 'O')
//         map->no = ft_parsing_get_path(map, z);
//     if (map->error == 0 && map->file[y] == 'S' && map->file[y + 1] == 'O')
//         map->so = ft_parsing_get_path(map, z);
//     if (map->error == 0 && map->file[y] == 'W' && map->file[y + 1] == 'E')
//         map->we = ft_parsing_get_path(map, z);
//     if (map->error == 0 && map->file[y] == 'E' && map->file[y + 1] == 'A')
//         map->ea = ft_parsing_get_path(map, z);
//     if (map->error == 0 && map->file[y] == 'S' && map->file[y + 1] == ' ')
//         map->s = ft_parsing_get_path(map, z);
    
// }
