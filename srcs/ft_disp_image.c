/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:22:31 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_img(t_point *map)
{
	int	size;

	size = CUB_SIZE;
	map->wall = mlx_xpm_file_to_image(map->mlx, WALL, &size, &size);
	map->collec = mlx_xpm_file_to_image(map->mlx, COLLEC, &size, &size);
	map->exit = mlx_xpm_file_to_image(map->mlx, EXIT, &size, &size);
	map->player = mlx_xpm_file_to_image(map->mlx, PLAYER, &size, &size);
	map->ground = mlx_xpm_file_to_image(map->mlx, GROUND, &size, &size);
}

void	ft_disp_image(t_point *map, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win1, map->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->win1, map->collec, x, y);
	if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->win1, map->exit, x, y);
	if (c == 'P' || c == 'X')
		mlx_put_image_to_window(map->mlx, map->win1, map->player, x, y);
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win1, map->ground, x, y);
}

void	ft_screen(t_point *map)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (i < map->l)
	{
		while (map->map[i][u] != '\0')
		{
			ft_disp_image(map, u * CUB_SIZE, i * CUB_SIZE, map->map[i][u]);
			u++;
		}
		u = 0;
		i++;
	}
}
