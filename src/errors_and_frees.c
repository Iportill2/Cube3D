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

void	ft_free_struc(t_list *s)
{
	ft_free_array(&s->new_playable_map);
	ft_free_array(&s->map_settings);
	free(s->map2d);
	free(s->playable_map);
	//ft_free_array(&s->map_date);
	free(s->floor_int_arr);
	free(s->celling_int_arr);
	ft_free_array(&s->so_arr);
	ft_free_array(&s->no_arr);
	ft_free_array(&s->map3d);
	ft_free_array(&s->we_arr);
	ft_free_array(&s->ea_arr);
	ft_free_array(&s->floor);
	ft_free_array(&s->celling);
	free(s);
}
