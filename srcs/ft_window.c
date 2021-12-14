#include "../includes/libft.h"

int		ft_entry_keyboard(int key, void *p)
{
	m_point *map;

	map = p;
	// printf("key : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n", key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	// printf("test : %s\n", win->map->no);
	if (key == KEY_ECHAP)
	{
		ft_exit_free_all(map, 0);
		exit(0);
	}
	if (key == KEY_MOVE_UP || key == KEY_MOVE_LEFT || key == KEY_MOVE_RIGHT || key == KEY_MOVE_DOWN)
	{
		ft_move_wasd(map, key);
		mlx_clear_window(map->mlx, map->win1);
		ft_screen(map); // affiche les déplacements
	}
	return(0);
}

int		ft_cross_is_red(m_point *map)
{
	ft_exit_free_all(map, 0);
	return (0);
}

void	ft_exit_free_all(m_point *map, int ret)
{
	printf("All is begin freeing\n");
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->collec);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->player);
	mlx_destroy_image(map->mlx, map->ground);
	// mlx_destroy_image(win->mlx, win->im1); // Pour une image
	mlx_clear_window(map->mlx, map->win1);
	mlx_destroy_window(map->mlx, map->win1);

	exit(ft_exit_free_map(map, ret));
}



void	ft_windows(m_point *map)
{
	map->mlx = mlx_init();
	map->win1 = mlx_new_window(map->mlx, (ft_strlen(map->map[0]) * CUB_SIZE), (map->l * CUB_SIZE),"so_long");
	ft_init_img(map);
	ft_screen(map);
	mlx_key_hook(map->win1,ft_entry_keyboard,map);
	mlx_hook(map->win1, 17, (0L), ft_cross_is_red, map);
	mlx_loop(map->mlx);
	ft_exit_free_all(map, 0);
}
