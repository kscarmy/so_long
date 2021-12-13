/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnew(int *error)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if ((*error = (str == NULL) ? 1 : 0) == 1)
		return (NULL);
	str[0] = '\0';
	return (str);
}

int		ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_strcount(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_strjoin(char **str, const char *buff, int buff_size, int *error)
{
	char	*tmp;
	int		i;
	int		u;

	i = 0;
	u = 0;
	tmp = *str;
	*str = malloc(sizeof(char) * (ft_strlen(tmp) + buff_size + 1));
	if ((*error = (*str == NULL) ? 1 : 0) == 0)
	{
		while (tmp[i] != '\0')
		{
			(*str)[i] = tmp[i];
			i++;
		}
		while (u != buff_size)
		{
			(*str)[i + u] = buff[u];
			u++;
		}
		(*str)[i + u] = '\0';
	}
	ft_strdel(&tmp);
}
