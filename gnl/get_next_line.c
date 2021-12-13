/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:10 by guderram          #+#    #+#             */
/*   Updated: 2021/12/05 11:18:29 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_exerror(char **str, int error)
{
	ft_strdel(&*str);
	if (error == 1)
		return (-1);
	return (0);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strsub(char const *s, unsigned int start, size_t len, int **error)
{
	size_t	i;
	char	*str;

	if (start == 0 && len == 0)
	{
		str = malloc(sizeof(char) + 1);
		if ((**error = (str == NULL) ? 1 : 0) == 1)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if ((**error = (str == NULL) ? 1 : 0) == 1)
		return (NULL);
	i = 0;
	str[len] = '\0';
	while (len != 0)
	{
		str[i] = s[i + start];
		i++;
		len--;
	}
	return (str);
}

void	ft_read(char **str, char **line, int ret, int *error)
{
	int		i;
	char	*tmp;

	i = ft_strcount(*str);
	if (i != 0 && ((*str)[i - 1] != '\0') && ret == 0 && *error == 0)
		*line = ft_strsub(*str, 0, (i + 1), &error);
	else if ((*str)[i] != '\0' && *error == 0)
		*line = ft_strsub(*str, 0, i, &error);
	else if ((*str)[i] == '\0' && *error == 0)
		*line = ft_strnew(&*error);
	tmp = *str;
	if (*error == 0)
	{
		*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i, &error);
		ft_strdel(&tmp);
	}
}

int		get_next_line(int fd, char **line)
{
	static	char	*str;
	char			buff[BUFFER_SIZE + 1];
	int				ret;
	int				error;

	ret = 1;
	error = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (str == NULL)
		str = ft_strnew(&error);
	while (error == 0 && ft_strchr(str) == 1 &&
	0 < (ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		ft_strjoin(&str, buff, ret, &error);
	}
	if (error == 1 || ret == -1)
		return (ft_exerror(&str, error));
	ft_read(&str, line, ret, &error);
	if (error == 1)
		return (ft_exerror(&str, error));
	return (((ret == 0 && *str == 0) ? ft_exerror(&str, error) : 1));
}
