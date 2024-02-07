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

	int playable_str_len;
	int playable_array_len;

	char **playable_map;
	char **new_playable_map;
	char **map_settings;
	int stop;
	char *map2d;
	char **map3d;
	char **map5d;
	char pj_init_nsew;
	int invalid_char;
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
	int floor_rgb;

	char **celling;
	int  *celling_int_arr;
	int  cell_size;
	int  cell_rgb;

	char **NO_arr;
	char **SO_arr;
	char **WE_arr;
	char **EA_arr;

}	t_list;

/*MAIN*/
int 	main(int argc,char **argv);
int 	ft_read_map(char **argv,t_list *s);
int 	run_program();
/*UTILS_ONE (5)*/
size_t 	ft_strlen(const char *s);
size_t 	ft_arraylen(char **arr);
int 	ft_count_array_len(char **arr);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
/*UTILS_TWO (4)*/
char	*ft_strjoin(const char* s1, const char* s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
int 	ft_strcmp(char *s1,char *s2);
int 	ft_transf_rgb(int r, int g, int b);

/*SPLIT (5)*/
int 	ft_wordlen(char *s,char c);
int 	ft_count_words(char *s,char c);
char 	*ft_word_dupe(char *s,char c);
int 	ft_fill_words(char **array,char *s,char c);
char 	**ft_split(char *s,char c);

/*DUAL_SPLIT (5)*/
int 	ft_dual_wordlen(char *s,char c,char d);
int 	ft_dual_count_words(char *s,char c,char d);
char 	*ft_dual_word_dupe(char *s,char c,char d);
int 	ft_dual_fill_words(char **array,char *s,char c,char d);
char 	**ft_dual_split(char *s,char c,char d);

/*PARSHING*/
int 	ft_check_chars_in_playable_map(t_list *s);
int 	ft_get_playable_map(t_list *s);

void 	ft_parshing_map_args(t_list *s);
int 	ft_check_map_args(t_list *s);
int 	ft_floor_atoi_array(t_list *s);
int 	ft_cell_atoi_array(t_list *s);
int 	ft_check_jumplines_in_playable_map(t_list *s);
int 	ft_get_pj_init_position(t_list *s);
int 	ft_check_map_double_jump_line(t_list *s);
int 	ft_clean_floor(t_list *s);
int 	ft_clean_celling(t_list *s);
int 	ft_clean_map3d_split(t_list *s);
int 	ft_array_check(char *s);
int 	ft_check_initial_position(t_list *s);
/*PARSHING_BIS*/
int 	ft_get_playable_map_strlen_arraylen(t_list *s);
int 	ft_calloc_for_new_playable_map(t_list *s);
int 	ft_create_new_playable_map(t_list *s);
int 	ft_check_new_playable_map_its_playable(t_list *s,char c);
int 	ft_check_player_in_new_map(t_list *s);
/*ERROR*/
void    ft_free_array(char ***s);
/*GAME*/
//void	ft_error(t_list *s, char *text, int error);
void	ft_destroy(t_list *s);
int		ft_close_window(t_list *s);
int		ft_key_press(int keycode, t_list *s);
void	ft_hook(t_list *s);
void	ft_star_game(t_list *s);
/*GET_MAPS*/
void 	toito(t_list *s);////////
int 	ft_get_maps(t_list *s,char **argv);
int 	ft_checks(t_list *s);
int 	ft_floor_cell(t_list *s);
#endif