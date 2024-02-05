
NAME		= cub3D

NAME_BONUS	= cub3D_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3 #-llsan #-fsanitize=leak 
LMLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM			= rm -rf
LIB			= Libft
MLX			= mlx

SRCS_BONUS=	$(SRC_DIR_BONUS)main_bonus.c 


SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)error.c \
			$(SRC_DIR)parshing.c \
			$(SRC_DIR)split.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)parshing_bis.c \
			$(SRC_DIR)game.c 
			
SRC_DIR	=			src/
SRC_DIR_BONUS	=	src_bonus/
OBJS	= 	$(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o)

.SILENT:

all:		$(NAME)

bonus: 			$(NAME_BONUS)

%.o: $(SRC_DIR)%.c
		$(CC) $(CFLAGS)  -c $< -o $@

%.o: $(SRC_DIR_BONUS)%.c
		$(CC) $(CFLAGS)  -c $< -o $@


$(NAME):	$(OBJS) 
			make -C $(LIB)
			$(MAKE) -C mlx 2> logs
			make  -C $(MLX)
			$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a $(LIB)/libft.a -o $@ $^



$(NAME_BONUS):	$(OBJS_BONUS)
				make -C $(LIB)
				$(MAKE) -C mlx 2> logs
				make -C $(MLX)
				$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a $(LIB)/libft.a -o $@ $^

clean:
			@make -C $(LIB) clean
			@make -C $(MLX) clean
			@$(RM) $(OBJS) $(OBJS_BONUS)


fclean:		clean
			@make -C $(LIB) fclean
			@$(RM) $(NAME) $(NAME_BONUS) logs

re:			fclean all

.PHONY:		all clean fclean re bonus

