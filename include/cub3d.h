#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
//librerias de mates man man 3 math
# include <math.h>


# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35

typedef struct s_list
{
	void	*mlx;
	void	*window;

	char **playable_map;
	int stop;
	char *map2d;
	char **map3d;
	char **map5d;
	char pj_init_nsew;
	int n;
	int s;
	int e;
	int w;

	char **map_date;

	int lines;
	char **array;

	char **floor;
	int  *floor_int_arr;
	int floor_size;

	char **celling;
	int  *celling_int_arr;
	int  cell_size;

	char **NO;
	char **SO;
	char **WE;
	char **EA;

}	t_list;

/*MAIN*/
void 	toito(t_list *s);
int 	main(int argc,char **argv);
int 	read_map(char **argv,t_list *s);
int 	run_program();
/*UTILS*/
size_t 	ft_strlen(const char *s);
size_t 	ft_arraylen(char **arr);
int 	ft_count_array_len(char **arr);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(const char* s1, const char* s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
int 	ft_strcmp(char *s1,char *s2);

/*SPLIT*/
int 	ft_wordlen(char *s,char c);
int 	ft_count_words(char *s,char c);
char 	*word_dupe(char *s,char c);
int 	fill_words(char **array,char *s,char c);
char 	**ft_split(char *s,char c);

int 	split_cell(t_list *s);
int 	split_floor(t_list *s);

int ft_dual_wordlen(char *s,char c,char d);
int ft_dual_count_words(char *s,char c,char d);
char *dual_word_dupe(char *s,char c,char d);
int dual_fill_words(char **array,char *s,char c,char d);
char **ft_dual_split(char *s,char c,char d);

int check_parameters(t_list *s);

/*PARSHING*/
int 	map(t_list *s);

int 	check_chars_utils_bis(t_list *s);

char 	**create_array(t_list *s);

int		invalid_char_in_array(t_list *s);
int 	get_playable_map(t_list *s);

int parshing_map_args(t_list *s);
int check_map_args(t_list *s);
int check_textures_fd_and_termination(t_list *s);
int floor_atoi_array(t_list *s);
int cell_atoi_array(t_list *s);

int get_pj_init_position(t_list *s);
/*ERROR*/
void    ft_free_array(char ***s);
/*GAME*/
//void	ft_error(t_list *s, char *text, int error);
void	ft_destroy(t_list *s);
int		close_window(t_list *s);
int		key_press(int keycode, t_list *s);
void	ft_hook(t_list *s);
void	ft_star_game(t_list *s);
#endif