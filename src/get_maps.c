#include "../include/cub3d.h"

int	ft_get_maps(t_list *s, char **argv)
{
	if (ft_read_map(argv, s) == 1)
		return (1);
	s->map3d = ft_split(s->map2d, '\n');
	if (s->map3d == NULL)
		return (printf("Error in ft_split: s->map3d == NULL\n"), 1);
	if (ft_clean_map3d_split(s) == 1)
		return (printf("Error clean_map3d_split"), 1);
	ft_get_playable_map(s);
	ft_get_playable_map_strlen_arraylen(s);
	ft_create_new_playable_map(s);
	return (0);
}

int	ft_checks(t_list *s)
{
	if (ft_check_map_args(s) == 1)
		return (printf("Error in ft_check_map_args\n"), 1);
	if (ft_check_chars_in_playable_map(s) == 1)
		return (printf("error en ft_check_chars_in_playable_map\n"), 1);
	if (ft_check_jumplines_in_playable_map(s) == 1)
		return (printf("error en ft_check_chars_in_playable_map\n"), 1);
	if (ft_check_map_double_jump_line(s) == 1)
		return (printf("error en ft_check_jumplines_in_playable_map\n"), 1);
	if (ft_check_new_playable_map_its_playable(s, '0') == 1)
	{
		printf("Error in ft_check_new_playable_map_its_playable 0\n");
		return (1);
	}
	if (ft_check_player_in_new_map(s) == 1)
		return (printf("Error in ft_check_player_in_new_map\n"), 1);
	if (check_textures(s) == 1)
		return (printf("Error in check_textures\n"), 1);
	if (check_floor_cellig_values(s) == 1)
		return (printf("Error in check_floor_cellig_values\n"), 1);
	return (0);
}

int	ft_floor_cell(t_list *s)
{
	if (ft_get_pj_init_position(s) == 1)
		return (printf("Error in ft_get_pj_init_position\n"), 1);
	ft_parshing_map_args(s);
	if (ft_clean_floor(s) == 1)
		return (printf("error en ft_clean_floor\n"), 1);
	if (ft_clean_celling(s) == 1)
		return (printf("error en ft_clean_celling\n"), 1);
	if (ft_floor_atoi_array(s) == 1)
		return (printf("error reserving memory for s->floor_int_arr\n"), 1);
	if (ft_cell_atoi_array(s) == 1)
		return (printf("error reserving memory for s->cell_int_arr\n"), 1);
	s->floor_rgb = ft_transf_rgb(s->floor_int_arr[0], \
	s->floor_int_arr[1], s->floor_int_arr[2]);
	s->cell_rgb = ft_transf_rgb(s->celling_int_arr[0], \
	s->celling_int_arr[1], s->celling_int_arr[2]);
	return (0);
}

void	toito(t_list *s)
{
	int	i;

	(void)s;
	i = 0;
	printf("---TOITO-----\n");
	i = 0;
	printf("******no_arr*******\n");
	while (s->no_arr && s->no_arr[i])
	{
		printf("s->no_arr[%i] = %s\n", i, s->no_arr[i]);
		i++;
	}
	i = 0;
	printf("******so_arr*******\n");
	while (s->so_arr && s->so_arr[i])
	{
		printf("s->so_arr[%i] = %s\n", i, s->so_arr[i]);
		i++;
	}
	i = 0;
	printf("******we_arr*******\n");
	while (s->we_arr && s->we_arr[i])
	{
		printf("s->WE[%i] = %s\n", i, s->we_arr[i]);
		i++;
	}
	i = 0;
	printf("******ea_arr*******\n");
	while (s->ea_arr && s->ea_arr[i])
	{
		printf("s->EA[%i] = %s\n", i, s->ea_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->floor******\n");
	while (i <= s->floor_size)
	{
		printf("s->floor[%i] = %s\n", i, s->floor[i]);
		i++;
	}
	i = 0;
	printf("******s->floor_int_arr******\n");
	while (i < s->floor_size)
	{
		printf("s->floor_int_arr[%i] = %d\n", i, s->floor_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->celling******\n");
	while (i <= s->cell_size)
	{
		printf("s->celling[%i] = %s\n", i, s->celling[i]);
		i++;
	}
	i = 0;
	printf("******s->cell_int_arr******\n");
	while (i < s->cell_size)
	{
		printf("s->celling_int_arr[%i] = %d\n", i, s->celling_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->map3d******\n");
	while (s->map3d[i])
	{
		printf("s->map3d[%i] = %s\n", i, s->map3d[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******map_settings******\n");
	while (s->map_settings[i])
	{
		printf("map_settings[%i] = %s\n", i, s->map_settings[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******s->playable_map******\n");
	while (s->playable_map[i])
	{
		printf("%s\n", s->playable_map[i]);
		i++;
	}
	printf("******s->playable_str_len******\n");
	printf("str_len =%i\n", s->playable_str_len);
	printf("----------------\n");
	printf("******s->playable_array_len******\n");
	printf("array_len =%i\n", s->playable_array_len);
	printf("----------------\n");
	i = 0;
	printf("******s->new_playable_map******\n");
	while (s->new_playable_map[i])
	{
		printf("%s\n", s->new_playable_map[i]);
		i++;
	}
	printf("s->floor_rgb =%i\n", s->floor_rgb);
	printf("s->celling_rgb =%i\n", s->cell_rgb);
	printf("----------------\n");
	printf("s->n=%i\n", s->n);
	printf("s->s=%i\n", s->s);
	printf("s->e=%i\n", s->e);
	printf("s->w=%i\n", s->w);
	printf("s->pj_init_nsew=%c\n", s->pj_init_nsew);
	printf("---TOITO-----\n");
}
