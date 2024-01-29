NAME = cub3D
CC = gcc
SRC =	main.c \
		error.c \
		parshing.c \
		split.c \
		utils.c

INCLUDES = -I./libft
LIBS =  -L./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
#LIBS = -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
all: $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS)  -o $(NAME) $(LIB_FLAGS)
clean:
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf ./a.out
fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf cub3d.dSYM
re: fclean all
.PHONY: all clean fclean re