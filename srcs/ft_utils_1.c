/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:54:25 by guderram          #+#    #+#             */
/*   Updated: 2021/12/15 16:54:40 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_disp_map(char **str)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	printf("affichage map :\n");
	while (str[i])
	{
		while (str[i][u])
		{
			printf("%c", str[i][u]);
			u++;
		}
		printf("'\n");
		u = 0;
		i++;
	}
	printf("fin map\n");
}

int	ft_atoi(const char *nptr)
{
	int	re;
	int	i;
	int	sig;

	i = 0;
	sig = 1;
	re = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v')
		|| (nptr[i] == '\f') || (nptr[i] == '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sig = -sig;
		i++;
	}
	while ((48 <= nptr[i]) && (nptr[i] <= 57))
	{
		re = (re * 10) + (nptr[i] - 48);
		i++;
	}
	return (re * sig);
}

int	ft_isdigit(int c)
{
	if ((48 <= c) && (c <= 57))
		return (1);
	else
		return (0);
}
