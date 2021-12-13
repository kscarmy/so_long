/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:18 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:20 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
void	ft_strdel(char **as);
int		ft_strlen(char *str);
char	*ft_strnew(int *error);
int		ft_strchr(char *str);
int		ft_strcount(char *str);
void	ft_strjoin(char **str, const char *buff, int buff_size, int *error);
char	*ft_strsub(char const *s, unsigned int start, size_t len, int **error);
void	ft_read(char **str, char **line, int ret, int *error);
int		ft_exerror(char **str, int error);

#endif
