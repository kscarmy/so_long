/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 20:14:59 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// int		ft_is_rectangular(m_point *map)
// {
// 	int i;
// 	int u;
// 	int ref;

// 	i = 0;
// 	u = 0;
// 	ref = 0;
// 	while 
// 	while (u < map->l)
// 	{
		
// 		u++;
// 	}
// }

void	ft_strfreejoin_newline(m_point *map, char *buff)
{
	char	*tmp;
	int		i;
    int u;

	i = 0;
    u = 0;
	tmp = map->file;
	map->file = malloc (sizeof(char) * (ft_strlen(tmp) + ft_strlen(buff) + 2));
	if ((map->error = (map->file == NULL) ? 1010 : map->error) == 0)
	{
		while (tmp != NULL && tmp[i] != '\0')
		{
			map->file[i] = tmp[i];
			i++;
		}
        while (buff[u] != '\0')
        {
            map->file[i + u] = buff[u];
            u++;
        }
		map->file[i + u] = '\n';
        map->file[i + u + 1] = '\0';
	}
	ft_strdel(&tmp);
}

void    ft_parsing_open_fd(m_point *map, char *argv)
{
    int ret;
    int fd;
    char *buff;

    ret = 0;
    buff = NULL;
    fd = open(argv, O_RDONLY);
    while ((ret = get_next_line(fd, &buff)) > 0)
    {
        ft_strfreejoin_newline(map, buff);
        ft_strdel(&buff);
    }
    ft_strfreejoin_newline(map, buff);
    ft_strdel(&buff);
    close(fd);
    if (fd == -1)
        map->error = 15;
    if (ret != 0)
        map->error = 20;
}

int ft_parsing_map(m_point *map, char *argv)
{
    int m;

    m = 0;
    ft_parsing_open_fd(map, argv);
    if (map->error == 0)
        ft_check_map(map);
    if (map->error > 0)
        ft_error_detected(map);
    return ((map->error == 0) ? 1 : ft_exit_free_map(map, -1));
	return(1);
}
