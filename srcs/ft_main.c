/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:58:10 by guderram          #+#    #+#             */
/*   Updated: 2021/12/17 12:22:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	t_point	map;

	if (argc != 2)
		return (ft_exor_nfn(1));
	if (ft_check_file_name(argv[1], 1) != 0)
		return (-1);
	ft_init_map(&map);
	if (ft_parsing_map(&map, argv[1]) == -1)
		return (-1);
	ft_verif_something(&map);
	if (map.error == 0)
		ft_windows(&map);
	return (ft_exit_free_map(&map, 0));
}
