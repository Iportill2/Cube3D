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
	ft_free_array(&s->playable_map);
	ft_free_array(&s->new_playable_map);
	ft_free_array(&s->map_settings);
	ft_free_array(&s->map3d);
	ft_free_array(&s->playable_map);
	ft_free_array(&s->playable_map);
}
