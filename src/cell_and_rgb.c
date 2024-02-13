#include "../include/cub3d.h"

int	ft_array_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'C' || s[i] == 'F' || (s[i] == 'N' && s[i + 1] == 'O' ) || \
		(s[i] == 'S' && s[i + 1] == 'O' ) || (s[i] == 'W' \
		&& s[i + 1] == 'E' ) || \
		(s[i] == 'E' && s[i + 1] == 'A' ))
			return (1);
		i++;
	}
	return (0);
}

int	ft_cell_atoi_array(t_data *d)
{
	int	i;
	int	e;

	i = 1;
	e = 0;
	while (d->floor[i])
		i++;
	d->cell_size = i -1;
	d->celling_int_arr = ft_calloc(sizeof(int *), (d->cell_size));
	if (d->celling_int_arr == NULL)
		return (1);
	i = 1;
	while (d->floor[i])
	{
		d->celling_int_arr[e] = ft_atoi(d->celling[i]);
		e++;
		i++;
	}
	return (0);
}

int	check_celling_numbers(t_data *d, int n)
{
	int	i;

	i = 0;
	while (d->celling[n][i])
	{
		if (d->celling[n][i] >= '0' && d->celling[n][i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_clean_celling(t_data *d)
{
	if (check_celling_numbers(d, 1) == 1)
		return (printf("Error in check_celling_numbers 1\n"), 1);
	if (check_celling_numbers(d, 2) == 1)
		return (printf("Error in check_celling_numbers 2\n"), 1);
	if (check_celling_numbers(d, 3) == 1)
		return (printf("Error in check_celling_numbers 3\n"), 1);
	return (0);
}

int	ft_transf_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}
