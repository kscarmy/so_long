/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2021/12/14 18:21:18 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_check_open(char *argv)
{
	int	exit;
	int	fd;

	exit = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit = 1;
	close(fd);
	return (exit);
}

int	ft_check_file_name_bis(int extension, int exist, int u)
{
	if (extension == 1 && exist == 0 && u != 4)
		exist = ft_exor_nfn(2);
	else if (exist == 1)
		exist = ft_exor_nfn(3);
	if (u != 4)
		exist = 1;
	return (exist);
}

int	ft_check_file_name(char *argv, int extension)
{
	char	*exten;
	int		i;
	int		u;
	int		exist;

	i = 0;
	u = 0;
	exist = ft_check_open(argv);
	exten = ".ber\0";
	while (extension == 1 && exist == 0 && argv[i] != '\0')
	{
		u = 0;
		i++;
		while (argv[i] == exten[u] && exten[u] != '\0')
		{
			i++;
			u++;
		}
	}
	return (ft_check_file_name_bis(extension, exist, u));
}
