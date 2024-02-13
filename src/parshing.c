#include "../include/cub3d.h"

void	ft_parshing_map_args(t_data *d)
{
	int	i;

	i = 0;
	while (d->map_settings[i] && i < 6)
	{
		d->map_date = ft_dual_split(d->map_settings[i], ' ', ',');
		if (ft_strcmp(d->map_date[0], "NO") == 0)
			d->no_arr = d->map_date;
		else if (ft_strcmp(d->map_date[0], "SO") == 0)
			d->so_arr = d->map_date;
		else if (ft_strcmp(d->map_date[0], "WE") == 0)
			d->we_arr = d->map_date;
		else if (ft_strcmp(d->map_date[0], "EA") == 0)
			d->ea_arr = d->map_date;
		else if (ft_strcmp(d->map_date[0], "F") == 0)
			d->floor = d->map_date;
		else if (ft_strcmp(d->map_date[0], "C") == 0)
			d->celling = d->map_date;
		else
			ft_free_array(&d->map_date);
		i++;
	}
	return ;
}

int	ft_clean_map3d_split_bis(t_data *d, int i, int count)
{
	while (d->map3d[i])
	{
		count = count + ft_array_check(d->map3d[i]);
		i++;
	}
	if (count != 6)
		return (printf("Too many arguments in map_settings\n"), 1);
	d->map_settings = ft_calloc(sizeof(char *), count + 1);
	if (d->map_settings == NULL)
		return (1);
	return (0);
}

int	ft_clean_map3d_split(t_data *d)
{
	int	i;
	int	e;
	int	count;

	i = 0;
	e = 0;
	count = 0;
	if (ft_clean_map3d_split_bis(d, i, count) == 1)
		return (printf("Error in ft_clean_map3d_split_bis\n"), 1);
	if (d->map_settings == NULL)
		return (1);
	i = 0;
	while (d->map3d[i])
	{
		if (ft_array_check(d->map3d[i]) == 1)
		{
			d->map_settings[e] = ft_strdup(d->map3d[i]);
			e++;
			i++;
		}
		else
			i++;
	}
	return (0);
}

int	ft_create_new_playable_map(t_data *d)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	d->new_playable_map = ft_calloc(sizeof(char *), \
	(d->playable_array_len + 1));
	if (d->new_playable_map == NULL)
		return (1);
	while (d->playable_map[i])
	{
		d->new_playable_map[i] = ft_calloc(sizeof(char), \
		(d->playable_str_len + 1));
		if (d->new_playable_map[i] == NULL)
			return (1);
		i++;
	}
	if (ft_calloc_for_new_playable_map(d, e) == 1)
		return (1);
	return (0);
}

int	ft_calloc_for_new_playable_map(t_data *d, int e)
{
	int	i;

	i = 0;
	while (d->playable_map[i])
	{
		e = 0;
		while (d->playable_map[i][e])
		{
			if (d->playable_map[i][e] == ' ')
				d->new_playable_map[i][e] = '-';
			else
				d->new_playable_map[i][e] = d->playable_map[i][e];
			e++;
		}
		while (e < d->playable_str_len)
		{
			d->new_playable_map[i][e] = '-';
			e++;
		}
		i++;
	}
	return (0);
}
