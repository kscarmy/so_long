/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:55:23 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_entry_keyboard(int key, void *p)
{
	t_point	*map;

	map = p;
	if (key == KEY_ECHAP)
	{
		ft_exit_free_all(map, 0);
		exit(0);
	}
	if (key == KEY_MOVE_UP || key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT || key == KEY_MOVE_DOWN)
	{
		ft_move_wasd(map, key);
		mlx_clear_window(map->mlx, map->win1);
		ft_screen(map);
	}
	return (0);
}

int	ft_cross_is_red(t_point *map)
{
	ft_exit_free_all(map, 0);
	return (0);
}

void	ft_exit_free_all(t_point *map, int ret)
{
	printf("All is begin freeing\n");
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->collec);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->player);
	mlx_destroy_image(map->mlx, map->ground);
	mlx_clear_window(map->mlx, map->win1);
	mlx_destroy_window(map->mlx, map->win1);
	exit(ft_exit_free_map(map, ret));
}

void	ft_windows(t_point *map)
{
	map->mlx = mlx_init();
	map->win1 = mlx_new_window(map->mlx, (ft_strlen(map->map[0]) * CUB_SIZE),
			(map->l * CUB_SIZE), "so_long");
	ft_init_img(map);
	ft_init_move(map);
	ft_screen(map);
	mlx_key_hook(map->win1, ft_entry_keyboard, map);
	mlx_hook(map->win1, 17, (0L), ft_cross_is_red, map);
	mlx_loop(map->mlx);
	ft_exit_free_all(map, 0);
}
