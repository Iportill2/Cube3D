#include "../include/cub3d.h"

int	ft_cell_atoi_array(t_list *s)
{
	int	i;
	int	e;

	i = 1;
	e = 0;
	while (s->floor[i])
		i++;
	s->cell_size = i -1;
	s->celling_int_arr = ft_calloc(sizeof(int *), (s->cell_size));
	if (s->celling_int_arr == NULL)
		return (1);
	i = 1;
	while (s->floor[i])
	{
		s->celling_int_arr[e] = ft_atoi(s->celling[i]);
		e++;
		i++;
	}
	return (0);
}

int	ft_clean_celling(t_list *s)
{
	int	i;

	i = 0;
	while (s->celling[1][i])
	{
		if (s->celling[1][i] >= '0' && s->celling[1][i] <= '9')
			i++;
		else
			return (1);
	}
	i = 0;
	while (s->celling[2][i])
	{
		if (s->celling[2][i] >= '0' && s->celling[2][i] <= '9')
			i++;
		else
			return (1);
	}
	i = 0;
	while (s->celling[3][i])
	{
		if (s->celling[3][i] >= '0' && s->celling[3][i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_transf_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}
