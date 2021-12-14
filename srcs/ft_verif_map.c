#include "../includes/libft.h"

void		ft_verif_something(m_point *map)
{
	int i;
	int u;

	i = 0;
	u = 0;
	map->rx = 0; // pour P
	map->ry = 0; // pour E
	map->x = 0; // pour C
	while (i < map->l)
	{
		while (map->map[i][u] != '\0')
		{
			if (map->map[i][u] == 'P')
				map->rx = map->rx + 1;
			if (map->map[i][u] == 'E')
				map->ry = map->ry + 1;
			if (map->map[i][u] == 'C')
				map->x = map->x + 1;
			u++;
		}
		u = 0;
		i++;
	}
	ft_verif_count(map);
}

void		ft_verif_count(m_point *map)
{
	if (map->rx != 1)
	{
		printf("Error : number of player starting position on map\n");
		map->error = map->error + 1;
	}
	if (map->ry == 0)
	{
		printf("Error : no exit on map\n");
		map->error = map->error + 1;
	}
	if (map->x == 0)
	{
		printf("Error : no collectible on map\n");
		map->error = map->error + 1;
	}
}