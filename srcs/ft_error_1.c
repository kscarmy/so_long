/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 14:58:56 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_exor_nfn(int error)
{
	if (error == 1)
		printf("Erreur : veuillez passer un fichier en argument tel que : ./so_long 'fichier.ber'\n");
	if (error == 2)
		printf("Le fichier ne possede pas la bonne extension *.ber tel que : 'fichier.ber'\n");
	if (error == 3)
		printf("Le fichier spécifié n'existe pas\n");
	if (error == 4)
		printf("ERREUR : L'initialisation de la structure a échouée.\n");
	return (-1);
}

void    ft_map_disp_error(m_point *map, int l, int x, int erreur)
{
    int a;
    int c;

    a = 0;
    c = 0;
    while (map->map[a] != NULL)
    {
        while (map->map[a][c] != '\0')
        {
            if (a == l && c == x)
                printf("\033[1;31mX");
            else
                printf("\033[0m%c", map->map[a][c]);
            c++;
        }
        printf("\n");
        c = 0;
        a++;
    }
    map->error = erreur;
}

void	ft_show_error_file(m_point *map)
{
	int u;
    int j;
    int i;

	u = 0;
    j = 0;
    i = 0;
	printf("\033[0;31m[ERROR IN FILE]\n");
    // ft_error_file_detail(map);
    printf("\n");
	while (u < map->x)
	{
		printf("\033[0;32m%c", map->file[u]);
		u++;
	}
	printf("\033[1;31mI>%c<I", map->file[u]);
	u++;
	while (map->file[u + i] != '\0' && j < 8 && i < 300)
	{
		printf("\033[0;36m%c", map->file[u + i]);
        i++;
		j = (map->file[u + i] == '\n') ? j + 1 : j;

	}
}

void ft_error_detected(m_point *map)
{
    printf("\033[0;31m[ERROR n'%d']\n", map->error);
    if (map->error < 960)
        ft_show_error_file(map);
    if (map->error >= 1000 && map->error < 1500)
        printf("\033[0;31mMalloc error !\n");

}