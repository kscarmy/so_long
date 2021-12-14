#include "../includes/libft.h"

int main(int argc, char **argv)
{
    m_point map; // déclaration de la structure "map".

	if (argc != 2)
		return(ft_exor_nfn(1));

	if (ft_check_file_name(argv[1], 1) != 0)
		return (-1);
	ft_init_map(&map);
		// return(ft_exor_nfn(4)); // Dans le cas où je dois malloc des données dans ft_init_map
	// ft_disp_verif(&map);
	// return(0);
	if (ft_parsing_map(&map, argv[1]) == -1) // parsing du fichier
		return (-1);
	// ft_disp_verif(&map);
	// ft_disp_map(map.map);
	ft_windows(&map);
	return (ft_exit_free_map(&map, 0));
}