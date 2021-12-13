NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GNL_C = gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

SRC_C = srcs/ft_error_1.c\
		srcs/ft_check_file_name.c\
		srcs/ft_structs.c\
		srcs/ft_parsing_map_data.c\
		srcs/ft_parsing_map.c\
		srcs/ft_parsing_utils.c\
		srcs/ft_parsing_map_map.c\
		srcs/ft_parsing_map_utils.c\
		srcs/ft_utils_1.c\

MAIN_C = srcs/main.c\

OBJS =		get_next_line.o\
			get_next_line_utils.o\
			ft_error_1.o\
			ft_check_file_name.o\
			ft_structs.o\
			ft_parsing_map.o\
			ft_parsing_utils.o\
			ft_parsing_map_data.o\
			ft_parsing_map_map.o\
			ft_parsing_map_utils.o\
			ft_utils_1.o\


all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(MAIN_C) $(SRC_C) $(GNL_C) -o $(NAME)
#-g3 -fsanitize=leak
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
	@rm -rf $(OBJS)
