#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
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

	int		playable_str_len;
	int		playable_array_len;

	char	**playable_map;
	char	**new_playable_map;
	char	**map_settings;
	char	*map2d;
	char	**map3d;
	char	pj_init_nsew;
	int		invalid_char;
	int		n;
	int		s;
	int		e;
	int		w;

	char	**map_date;

	char	**floor;
	int		*floor_int_arr;
	int		floor_size;
	int		floor_rgb;

	char	**celling;
	int		*celling_int_arr;
	int		cell_size;
	int		cell_rgb;

	char	**no_arr;
	char	**so_arr;
	char	**we_arr;
	char	**ea_arr;

	int		stop;
	int		c;
	int		f;
	int		i;
	int		n_c;
	int		s_c;

}	t_list;

/*MAIN X*/
void	toito(t_list *s);////
int		main(int argc, char **argv);
int		ft_read_map(char **argv, t_list *s);
int		ft_get_playable_map_strlen_arraylen(t_list *s);
/*UTILS_ONE (5) X*/
size_t	ft_strlen(const char *s);
size_t	ft_arraylen(char **arr);
int		ft_count_array_len(char **arr);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
/*UTILS_TWO (5) X*/
char	*ft_calloc_for_ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strcmp(char *s1, char *s2);

/*SPLIT (5) X*/
int		ft_wordlen(char *s, char c);
int		ft_count_words(char *s, char c);
char	*ft_word_dupe(char *s, char c);
int		ft_fill_words(char **array, char *s, char c);
char	**ft_split(char *s, char c);

/*DUAL_SPLIT (5)X*/
int		ft_dual_wordlen(char *s, char c, char d);
int		ft_dual_count_words(char *s, char c, char d);
char	*ft_dual_word_dupe(char *s, char c, char d);
int		ft_dual_fill_words(char **array, char *s, char c, char d);
char	**ft_dual_split(char *s, char c, char d);
/*CHECK_ONE (5) X*/
int		ft_check_chars_in_playable_map(t_list *s);
int		ft_check_textures(t_list *s);
int		ft_check_map_args(t_list *s);
int		ft_check_map_double_jump_line_bis(t_list *s, int n, int e, int w);
int		ft_check_map_double_jump_line(t_list *s);
/*CHECK_TWO (5) X*/
int		ft_check_initial_position(t_list *s);
int		ft_check_new_playable_map_bis(t_list *s, char c, int i, int e);
int		ft_check_new_playable_map_its_playable(t_list *s, char c);
int		ft_check_player_in_new_map(t_list *s);
int		ft_checks(t_list *s);
/*GAME (5) X*/
void	ft_destroy(t_list *s);
int		ft_close_window(t_list *s);
int		ft_key_press(int keycode, t_list *s);
void	ft_hook(t_list *s);
void	ft_star_game(t_list *s);
/*GET_MAPS () X */
int		ft_get_playable_map_bis(t_list *s, int i, int u);
int		ft_get_playable_map(t_list *s);
int		ft_get_maps(t_list *s, char **argv);
int		ft_get_pj_init_position_bis(t_list *s, int i, int e);
int		ft_get_pj_init_position(t_list *s);

/*CELL_AND_RGB (5) X*/
int		ft_array_check(char *s);
int		ft_cell_atoi_array(t_list *s);
int		check_celling_numbers(t_list *s, int n);
int		ft_clean_celling(t_list *s);
int		ft_transf_rgb(int r, int g, int b);
/*FLOOR (5) X*/
int		ft_check_floor_cellig_values(t_list *s);
int		ft_floor_atoi_array(t_list *s);
int		ft_clean_floor(t_list *s);
int		ft_floor_cell(t_list *s);
int		ft_check_floor_arr_int_numbers(t_list *s, int n);
/*PARSHING (5) X*/
void	ft_parshing_map_args(t_list *s);
int		ft_clean_map3d_split_bis(t_list *s, int i, int count);
int		ft_clean_map3d_split(t_list *s);
int		ft_create_new_playable_map(t_list *s);
int		ft_calloc_for_new_playable_map(t_list *s, int e);

/*ERRORS_AND_FREES X*/
void	ft_free_array(char ***s);
void	ft_free_struc(t_list *s);
#endif