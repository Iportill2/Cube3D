NAME = cube3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 #-g3 -fsanitize=address
SRC_FILES = main.c \
			ft_strlen.c \
			ft_split.c \
			ft_screen.c \
			ft_move.c \
			ft_move_q1.c \
			ft_move_q2.c \
			ft_move_q3.c \
			ft_move_q4.c \
			ft_walk.c

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAG) -Ilibmlx $^ 

%.o: %.c
	$(CC) -c $(CFLAG) -Ilibmlx $^ 

lib:
	make -C libmlx

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) libmlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libmlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib