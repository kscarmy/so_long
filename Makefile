NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext -Lmlx -lmlx -framework OpenGL -framework AppKit

GNL_C = gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		gnl/get_next_line_bis.c\

SRC_C = srcs/ft_error_1.c\
		srcs/ft_check_file_name.c\
		srcs/ft_structs.c\
		srcs/ft_parsing_map_data.c\
		srcs/ft_parsing_map.c\
		srcs/ft_parsing_utils.c\
		srcs/ft_parsing_map_map.c\
		srcs/ft_parsing_map_utils.c\
		srcs/ft_utils_1.c\
		srcs/ft_window.c\
		srcs/ft_disp_image.c\
		srcs/ft_move.c\
		srcs/ft_verif_map.c\

MAIN_C = srcs/main.c\

OBJS =		get_next_line.o\
			get_next_line_utils.o\
			get_next_line_bis.o\
			ft_error_1.o\
			ft_check_file_name.o\
			ft_structs.o\
			ft_parsing_map.o\
			ft_parsing_utils.o\
			ft_parsing_map_data.o\
			ft_parsing_map_map.o\
			ft_parsing_map_utils.o\
			ft_utils_1.o\
			ft_window.o\
			ft_disp_image.o\
			ft_move.o\
			ft_verif_map.o\


all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(MAIN_C) $(SRC_C) $(GNL_C) $(MLXFLAGS) -o $(NAME)
#-g3 -fsanitize=leak
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)
