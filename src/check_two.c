#include "../include/cub3d.h"

int	ft_check_initial_position(t_data *d)
{
	if (d->pj_init_nsew != 'N' && d->pj_init_nsew != 'S' && \
	d->pj_init_nsew != 'W' && d->pj_init_nsew != 'E')
		return (printf("The map haven't initial position\n"), 1);
	return (0);
}

int	ft_check_new_playable_map_bis(t_data *d, char c, int i, int e)
{
	if ((i == 0 || i == (d->playable_array_len - 1)) && \
	(d->new_playable_map[i][e] == c))
		return (1);
	if ((e == 0 || e == (d->playable_str_len - 1)) && \
	(d->new_playable_map[i][e] == c))
		return (1);
	if (d->new_playable_map[i][e] == c)
	{
		if ((i != 0) && (d->new_playable_map[i - 1][e] == '-'))
			return (1);
		else if ((i != d->playable_str_len) && \
		(d->new_playable_map[i + 1][e] == '-'))
			return (1);
		else if ((e != 0) && (d->new_playable_map[i][e - 1] == '-'))
			return (1);
		else if ((i != d->playable_array_len) && \
		(d->new_playable_map[i][e + 1] == '-'))
			return (1);
	}
	return (0);
}

int	ft_check_new_playable_map_its_playable(t_data *d, char c)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (d->new_playable_map && d->new_playable_map[i])
	{
		e = 0;
		while (d->new_playable_map[i][e])
		{
			if (ft_check_new_playable_map_bis(d, c, i, e) == 1)
			{
				printf("Error in ft_check_new_playable_map_bis\n");
				return (1);
			}
			e++;
		}
		i++;
	}
	return (0);
}

int	ft_check_player_in_new_map(t_data *d)
{
	if (ft_check_new_playable_map_its_playable(d, d->pj_init_nsew) == 1)
		return (printf("Error in ft_check_new_playable_map_its_playable %c\n", \
		d->pj_init_nsew), 1);
	return (0);
}

int	ft_checks(t_data *d)
{
	if (ft_check_map_args(d) == 1)
		return (printf("Error in ft_check_map_args\n"), 1);
	if (ft_check_chars_in_playable_map(d) == 1)
		return (printf("error en ft_check_chars_in_playable_map\n"), 1);
	if (ft_check_map_double_jump_line(d) == 1)
		return (printf("error in ft_check_map_double_jump_line\n"), 1);
	if (ft_check_new_playable_map_its_playable(d, '0') == 1)
	{
		printf("Error in ft_check_new_playable_map_its_playable 0\n");
		return (1);
	}
	if (ft_check_player_in_new_map(d) == 1)
		return (printf("Error in ft_check_player_in_new_map\n"), 1);
	if (ft_check_textures(d) == 1)
		return (printf("Error in check_textures\n"), 1);
	if (ft_check_floor_cellig_values(d) == 1)
		return (printf("Error in check_floor_cellig_values\n"), 1);
	return (0);
}
