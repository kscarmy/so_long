/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/15 17:19:30 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_incre_spaces(m_point *map, int backn, int h)
{
	int	u;

	u = 0;
	while (ft_is_space(map->file[map->x + u + h], backn, 0) > 0)
		u++;
	return (u);
}

int	ft_is_space(char c, int backn, int end)
{
	int	x;

	x = 0;
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

int	ft_is_color(int color)
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}
