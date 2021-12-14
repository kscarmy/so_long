/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2021/12/14 01:20:36 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# include <stdio.h>

# define BUFFER_SIZE 42
# define KEY_MOVE_FRONT 13 // old 122 ?
# define KEY_MOVE_BACK 1 // old 100 ?
# define KEY_MOVE_LEFT 0 // old 113 ?
# define KEY_MOVE_RIGHT 2 // old 115 ?
# define KEY_ROTATE_LEFT 123 // old 65361 ?
# define KEY_ROTATE_RIGHT 124 // old 65363 ?
# define KEY_ECHAP 53 // old 65307 ?
# define VERTICAL_SIZE 1000
# define HORIZONTAL_SIZE 500
# define CUB_SIZE 32
# define WALL "./ress/wall32.xpm"
# define COLLEC "./ress/collec32.xpm"
# define EXIT "./ress/exit32.xpm"
# define PLAYER "./ress/player32.xpm"
# define GROUND "./ress/ground32.xpm"
# define GOELAND "./ress/goeland.xpm"

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
	char	spawn; // Position de spawn du joueur
	char	**map; // La map mdrr
	int		l; // nombre de lignes de la map
	void	*mlx;
	void	*win1;
	void	*wall;
	void	*collec;
	void	*exit;
	void	*player;
	void	*ground;
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

// ft_window.c
int		ft_entry_keyboard(int key, void *p);
void	ft_exit_free_all(m_point *map, int ret);
void	ft_windows(m_point *map);
int    ft_cross_is_red(m_point *map);

// ft_disp_image.c
void	ft_disp_image(m_point *map, int x, int y, char c);
void	ft_init_img(m_point *map);
void	ft_screen(m_point *map);

#endif
