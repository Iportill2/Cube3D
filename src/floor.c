#include "../include/cub3d.h"

int	ft_check_floor_cellig_values(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->cell_size)
	{
		if (d->celling_int_arr[i] > -1 && d->celling_int_arr[i] < 256)
			i++;
		else
			return (1);
	}
	i = 0;
	while (i < d->floor_size)
	{
		if (d->floor_int_arr[i] > -1 && d->floor_int_arr[i] < 256)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_floor_atoi_array(t_data *d)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (d->floor[i])
		i++;
	d->floor_size = i -1;
	d->floor_int_arr = ft_calloc(sizeof(int *), (d->floor_size));
	if (d->floor_int_arr == NULL)
		return (1);
	i = 1;
	while (d->floor[i])
	{
		d->floor_int_arr[e] = ft_atoi(d->floor[i]);
		e++;
		i++;
	}
	return (0);
}

int	ft_check_floor_arr_int_numbers(t_data *d, int n)
{
	int	i;

	i = 0;
	while (d->floor[n][i])
	{
		if (d->floor[n][i] >= '0' && d->floor[n][i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_clean_floor(t_data *d)
{
	if (ft_check_floor_arr_int_numbers(d, 1) == 1)
		return (printf("Error in ft_check_floor_arr_int_numbers 1\n"), 1);
	if (ft_check_floor_arr_int_numbers(d, 2) == 1)
		return (printf("Error in ft_check_floor_arr_int_numbers 2\n"), 1);
	if (ft_check_floor_arr_int_numbers(d, 3) == 1)
		return (printf("Error in ft_check_floor_arr_int_numbers 2\n"), 1);
	return (0);
}

int	ft_floor_cell(t_data *d)
{
	if (ft_get_pj_init_position(d) == 1)
		return (printf("Error in ft_get_pj_init_position\n"), 1);
	ft_parshing_map_args(d);
	if (ft_clean_floor(d) == 1)
		return (printf("Error en ft_clean_floor\n"), 1);
	if (ft_clean_celling(d) == 1)
		return (printf("Error en ft_clean_celling\n"), 1);
	if (ft_floor_atoi_array(d) == 1)
		return (printf("Error reserving memory for d->floor_int_arr\n"), 1);
	if (ft_cell_atoi_array(d) == 1)
		return (printf("Error reserving memory for d->cell_int_arr\n"), 1);
	d->floor_rgb = ft_transf_rgb(d->floor_int_arr[0], \
	d->floor_int_arr[1], d->floor_int_arr[2]);
	d->cell_rgb = ft_transf_rgb(d->celling_int_arr[0], \
	d->celling_int_arr[1], d->celling_int_arr[2]);
	return (0);
}
