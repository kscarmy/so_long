/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_incre_spaces(m_point *map, int backn, int h) // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
{
	int u;

	u = 0;
	while (ft_is_space(map->file[map->x + u + h], backn, 0, map) > 0)
		u++;
	return (u);
}

int		ft_is_space(char c, int backn, int end, m_point *map)
{
	int x;

	x = 0;
	// if (map->error == 0) // WTF ICI EFT
	// {
	// 	// ft_check_file_half(map); // WTF ???
	// 	if (map->error == 0 && backn == 1)
	// 		backn = 0;
	// 	map->error = 0;
	// }
	map->error = map->error; // A SUPPRIMER
	if (c == ' ')
		x++;
	if (c == '\n' && backn == 1)
		x++;
	if (c == '\t')
		x++;
	if (c == '\0' && end == 1)
		x++;
	return (x);
}

int		ft_is_color(int color) // Si color faux return 1, sinon 0
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}