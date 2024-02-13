#include "../include/cub3d.h"

int	ft_get_playable_map_bis(t_data *d, int i, int u)
{
	while (d->map3d[u])
	{
		u++;
	}
	d->playable_map = ft_calloc(sizeof(char *), u + 1);
	if (d->playable_map == NULL)
		return (1);
	u = 0;
	while (d->map3d[i])
	{
		d->playable_map[u] = d->map3d[i];
		u++;
		i++;
	}
	return (0);
}

int	ft_get_playable_map(t_data *d)
{
	int	i;
	int	e;
	int	u;

	i = 0;
	e = 0;
	u = 0;
	while (d->map3d[i])
	{
		e = 0;
		while (d->map3d[i][e] == ' ' || d->map3d[i][e] == '\t')
		{
			e++;
		}
		if (d->map3d[i][e] == '0' || d->map3d[i][e] == '1')
			break ;
		i++;
	}
	u = i;
	if (ft_get_playable_map_bis(d, i, u) == 1)
		return (printf("Error in ft_get_playable_map_bis\n"), 1);
	return (0);
}

int	ft_get_maps(t_data *d, char **argv)
{
	if (ft_read_map(argv, d) == 1)
		return (1);
	d->map3d = ft_split(d->map2d, '\n');
	if (d->map3d == NULL)
		return (printf("Error in ft_split: d->map3d == NULL\n"), 1);
	if (ft_clean_map3d_split(d) == 1)
		return (printf("Error clean_map3d_split"), 1);
	ft_get_playable_map(d);
	ft_get_playable_map_strlen_arraylen(d);
	ft_create_new_playable_map(d);
	if(ft_pam(d->new_playable_map) == NULL)
		return (printf("Error creating d->pam\n"), 1);
	else
		d->pam = ft_pam(d->new_playable_map);
	return (0);
}

int	ft_get_pj_init_position_bis(t_data *d, int i, int e)
{
	if (d->playable_map[i][e] == 'N')
	{
		d->pj_init_nsew = d->playable_map[i][e];
		d->nx++;
	}
	else if (d->playable_map[i][e] == 'S')
	{
		d->pj_init_nsew = d->playable_map[i][e];
		d->sx++;
	}
	else if (d->playable_map[i][e] == 'E')
	{
		d->pj_init_nsew = d->playable_map[i][e];
		d->ex++;
	}
	else if (d->playable_map[i][e] == 'W')
	{
		d->pj_init_nsew = d->playable_map[i][e];
		d->wx++;
	}
	return (0);
}

int	ft_get_pj_init_position(t_data *d)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	if (d->playable_map == NULL)
		return (1);
	while (d->playable_map[i])
	{
		e = 0;
		while (d->playable_map[i][e])
		{
			if (ft_get_pj_init_position_bis(d, i, e) == 1)
				return (printf("Error in ft_get_pj_init_position_bis\n"), 1);
			else if (d->playable_map[i][e] != 'N' && \
			d->playable_map[i][e] != 'S'\
			&& d->playable_map[i][e] != 'E' && d->playable_map[i][e] != 'W' \
			&& d->playable_map[i][e] != '0' && d->playable_map[i][e] != '1'\
			&& d->playable_map[i][e] != ' ' && d->playable_map[i][e] != '\n')
				d->invalid_char++;
			e++;
		}
		i++;
	}
	return (0);
}
