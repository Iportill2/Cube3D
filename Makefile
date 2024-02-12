
NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 #-fsanitize=address -g3 #-llsan #-fsanitize=leak 
LMLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM			= rm -rf
MLX			= mlx

SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)check_one.c \
			$(SRC_DIR)check_two.c \
			$(SRC_DIR)errors_and_frees.c \
			$(SRC_DIR)parshing.c \
			$(SRC_DIR)cell_and_rgb.c \
			$(SRC_DIR)split.c \
			$(SRC_DIR)floor.c \
			$(SRC_DIR)dual_split.c \
			$(SRC_DIR)utils_one.c \
			$(SRC_DIR)utils_two.c \
			$(SRC_DIR)get_maps.c \
			$(SRC_DIR)game.c \
			$(SRC_DIR)ft_move_q1.c \
			$(SRC_DIR)ft_move_q1.c \
			$(SRC_DIR)ft_move_q1.c \
			$(SRC_DIR)ft_move_q1.c \
			$(SRC_DIR)move.c \
			$(SRC_DIR)screen.c \
			$(SRC_DIR)walk.c 


			
SRC_DIR	=			src/
OBJS	= 	$(SRCS:.c=.o)

.SILENT:

all:		$(NAME)

%.o: $(SRC_DIR)%.c
		$(CC) $(CFLAGS)  -c $< -o $@

$(NAME):	$(OBJS) 
			$(MAKE) -C mlx 2> logs
			make  -C $(MLX)
			$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a -o $@ $^

clean:
			@make -C $(MLX) clean
			@$(RM) $(OBJS) 


fclean:		clean
			@$(RM) $(NAME)  logs

re:			fclean all

.PHONY:		all clean fclean re 

