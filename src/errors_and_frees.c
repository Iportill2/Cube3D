#include "../include/cub3d.h"

void	ft_free_array(char ***s)
{
	int	i;

	i = 0;
	if (*s)
	{
		while ((*s)[i])
			free((*s)[i++]);
		free (*s);
	}
	*s = NULL;
}

void	ft_free_struc(t_data *d)
{
	ft_free_array(&d->new_playable_map);
	ft_free_array(&d->map_settings);
	free(d->map2d);
	free(d->playable_map);
	//ft_free_array(&d->map_date);
	free(d->floor_int_arr);
	free(d->celling_int_arr);
	ft_free_array(&d->so_arr);
	ft_free_array(&d->no_arr);
	ft_free_array(&d->map3d);
	ft_free_array(&d->we_arr);
	ft_free_array(&d->ea_arr);
	ft_free_array(&d->floor);
	ft_free_array(&d->celling);
	free(d);
}
