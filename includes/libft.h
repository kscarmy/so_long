/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2021/12/13 19:34:53 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define BUFFER_SIZE 42

//GNL

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


// ft_utils_1.c
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void	ft_disp_map(char **str);



typedef struct	j_point
{
	int		error; // pas d'erreurs : 0, erreurs : >0
	int 	rx; // résolution : largeur
	int		ry; // résolution : hauteur
	int		x; // tete de lecture utilisé dans : file, 
	char	*file; // contien une copie fichier à lire.
	// int 	res; // de base res = 0, si la résolution est définie alors res = 1
	// int		fr; // Floor : Red
	// int		fg; // Floor : Green
	// int		fb; // Floor : Blue
	// int		floor; // de base floor = 0, si la couleur du sol est définie alors floor = 1
	// int		cr; // Ceiling : Red
	// int		cg; // Ceiling : Green
	// int		cb; // Ceiling : Blue
	// int		ceiling; // de base ceiling = 0, si la couleur du sol est définie alors ceiling = 1
	// char	*no; // ./path_to_the_north_texture
	// char	*so; // ./path_to_the_south_texture
	// char	*we; // ./path_to_the_west_texture
	// char	*ea; // ./path_to_the_east_texture
	// char	*s; // ./path_to_the_sprite_texture
	char	spawn; // Position de spawn du joueur
	char	**map; // La map mdrr
	int		l; // nombre de lignes de la map
}				m_point;

int				ft_exor_nfn(int error); // exit error no free need, int error où error correspond au numéro du message à afficher en sortie.
int				ft_check_file_name(char *argv, int extension); // check l'extension si extension = 1 puis si le fichier spécifié existe en l'ouvrant.
int 			ft_check_open(char *argv); // Ouvre le fichier passé en argument.
void			ft_init_map(m_point *map); // Initialise la structe "map".
void			ft_disp_verif(m_point *map);  // Permet un affichage des valeurs contenues dans la structure.
int				ft_exit_free_map(m_point *map, int ret); // Fonction qui est censé free absolument tout, avec ou sans erreurs.
int				ft_parsing_map(m_point *map, char *argv); // comme son nom l'indique ...
void			ft_parsing_open_fd(m_point *map, char *argv); // stockage du fichier dans map.
void			ft_strfreejoin_newline(m_point *map, char *buff); // rajoute toutes les lignes lues par gnl dans map->file.
void			ft_parsing_path_to(m_point *map); // cherche le nom des données.
char			*ft_parsing_get_path(m_point *map, int z); // remplis la struct du nom trouvé et de ses infos.
int				ft_incre_spaces(m_point *map, int backn, int h);  // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
int				ft_is_space(char c, int backn, int end, m_point *map); // classe tout caractère pouvant être classé comme espace.
int				ft_is_color(int color); // Si color faux return 1, sinon 0
void			ft_check_file_half(m_point *map); // vérification des datas du fichiers
void			ft_check_map(m_point *map); // call toutes les merdes pour la map
void			ft_found_map(m_point *map); // cherche la map.
int				ft_is_not_map(char c, int one); // liste les caractères appartenant à la map.
void			ft_set_world_spawn(m_point *map, int u); // tout est dans le nom.
void			ft_create_mapping(m_point *map); // malloc de la map.
void			ft_fill_map(m_point *map); // remplis la map de son contenus.
void    ft_fill_line_map(m_point *map);
void			ft_parse_map(m_point *map); // parse toute la map à la recherche d'erreurs
void			ft_next_zero_map(m_point *map, int l, int x); // cherche une erreur dans la map et l'indique à map disp error;
void			ft_map_disp_error(m_point *map, int l, int x, int erreur); // indique où se situe l'erreur dans la map.
int				ft_next_zero_char(char c); // Liste des caractères valides dans map.
void			ft_error_detected(m_point *map); // affiche ou est l'erreur.


#endif
