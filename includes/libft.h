/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2021/12/18 13:24:23 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdio.h>

# define BUFFER_SIZE 42
# define KEY_MOVE_UP 13
# define KEY_MOVE_DOWN 1
# define KEY_MOVE_LEFT 0
# define KEY_MOVE_RIGHT 2
# define KEY_ECHAP 53
# define VERTICAL_SIZE 1000
# define HORIZONTAL_SIZE 500
# define CUB_SIZE 32
# define WALL "./ress/img_32/wall32.xpm"
# define COLLEC "./ress/img_32/collec32.xpm"
# define EXIT "./ress/img_32/exit32.xpm"
# define PLAYER "./ress/img_32/player32.xpm"
# define GROUND "./ress/img_32/ground32.xpm"

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
char	*ft_strsub_bis(int **error);
int		get_next_line_bis(int error, int ret, char *str);

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_disp_map(char **str);

typedef struct j_point
{
	int		error;
	int		rx;
	int		ry;
	int		x;
	char	*file;
	char	spawn;
	char	**map;
	int		l;
	void	*mlx;
	void	*win1;
	void	*wall;
	void	*collec;
	void	*exit;
	void	*player;
	void	*ground;
	int		px;
	int		py;
	int		c_count;
	int		m_count;
}			t_point;

int		ft_exor_nfn(int error);
int		ft_check_file_name(char *argv, int extension);
int		ft_check_open(char *argv);
void	ft_init_map(t_point *map);
void	ft_disp_verif(t_point *map);
int		ft_exit_free_map(t_point *map, int ret);
int		ft_parsing_map(t_point *map, char *argv);
void	ft_parsing_open_fd(t_point *map, char *argv);
void	ft_strfreejoin_newline(t_point *map, char *buff);
void	ft_parsing_path_to(t_point *map);
char	*ft_parsing_get_path(t_point *map, int z);
int		ft_incre_spaces(t_point *map, int backn, int h);
int		ft_is_space(char c, int backn, int end);
int		ft_is_color(int color);
void	ft_check_file_half(t_point *map);
void	ft_check_map(t_point *map);
void	ft_found_map(t_point *map);
int		ft_is_not_map(char c, int one);
void	ft_set_world_spawn(t_point *map, int u);
void	ft_create_mapping(t_point *map);
void	ft_fill_map(t_point *map);
void	ft_fill_line_map(t_point *map);
void	ft_parse_map(t_point *map);
void	ft_next_zero_map(t_point *map, int l, int x);
void	ft_map_disp_error(t_point *map, int l, int x, int erreur);
int		ft_next_zero_char(char c);
void	ft_error_detected(t_point *map);

int		ft_entry_keyboard(int key, void *p);
void	ft_exit_free_all(t_point *map, int ret);
void	ft_windows(t_point *map);
int		ft_cross_is_red(t_point *map);

void	ft_disp_image(t_point *map, int x, int y, char c);
void	ft_init_img(t_point *map);
void	ft_screen(t_point *map);

void	ft_move_in(t_point *map, char c);
void	ft_move_wasd(t_point *map, int key);
void	ft_init_move(t_point *map);
void	ft_end_game(t_point *map);

void	ft_verif_something(t_point *map);
void	ft_verif_count(t_point *map);

int		ft_check_file_name_bis(int extension, int exist, int u);

int		ft_create_mapping_bis(t_point *map, int *one);
void	ft_parse_map_bis(t_point *map);

void	ft_strfreejoin_newline_bis(t_point *map, char *buff, char *tmp);

#endif
