#include "../include/cub3d.h"

int	ft_check_chars_in_playable_map(t_data *d)
{
	if (d->nx == 1 && (d->sx > 0 || d->ex > 0 || d->wx > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)d), 1);
	if (d->sx == 1 && (d->nx > 0 || d->ex > 0 || d->wx > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)d), 1);
	if (d->ex == 1 && (d->sx > 0 || d->nx > 0 || d->wx > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)d), 1);
	if (d->wx == 1 && (d->sx > 0 || d->ex > 0 || d->nx > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)d), 1);
	if (d->nx != 0 && d->nx != 1)
		return (printf("N set more than one time\n"), free((void *)d), 1);
	if (d->sx != 0 && d->sx != 1)
		return (printf("S set more than one time\n"), free((void *)d), 1);
	if (d->ex != 0 && d->ex != 1)
		return (printf("E set more than one time\n"), free((void *)d), 1);
	if (d->wx != 0 && d->wx != 1)
		return (printf("W set more than one time\n"), free((void *)d), 1);
	if (d->invalid_char != 0)
		return (printf("Invalid character in map\n"), free((void *)d), 1);
	if (ft_check_initial_position(d) == 1)
		return (1);
	return (0);
}

int	ft_check_textures(t_data *d)
{
	int	fd;

	fd = open(d->no_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in d->no_arr[1]º\n"), 1);
	fd = open(d->so_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in d->so_arr[1]º\n"), 1);
	fd = open(d->we_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in d->we_arr[1]º\n"), 1);
	fd = open(d->ea_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in d->ea_arr[1]º\n"), 1);
	return (0);
}

int	ft_check_map_args(t_data *d)
{
	if (ft_arraylen(d->no_arr) != 2 || ft_arraylen(d->so_arr) != 2 || \
	ft_arraylen(d->we_arr) != 2 || ft_arraylen(d->ea_arr) != 2 || \
	ft_arraylen(d->floor) != 4 || ft_arraylen(d->celling) != 4)
		return (printf("Error in ft_check_map_args\n"), 1);
	return (0);
}

int	ft_check_map_double_jump_line_bis(t_data *d, int n, int e, int w)
{
	if (d->map2d[d->i] == 'N')
		n++;
	else if (d->map2d[d->i] == 'S')
		d->s_c++;
	else if (d->map2d[d->i] == 'E')
		e++;
	else if (d->map2d[d->i] == 'W')
		w++;
	else if (d->map2d[d->i] == 'F')
		d->f++;
	else if (d->map2d[d->i] == 'C')
		d->c++;
	if ((n == 2 || n == 3) && (d->s_c == 2 || d->s_c == 3) && \
	(e == 3 || e == 4) && (w == 2 || w == 3) && d->f == 1 && \
	d->c == 1 && (d->stop == 0) && d->map2d[d->i] == '\n')
		d->stop = 1;
	else if ((d->stop == 1) && d->map2d[d->i] == '\n')
		d->stop = 1;
	else if (d->stop != 0 && (d->map2d[d->i] == '1'))
		d->stop = 2;
	else if ((d->stop == 2) && d->map2d[d->i] == '\n')
		d->stop = 3;
	else if ((d->stop == 3) && d->map2d[d->i] == '\n')
		return (1);
	return (0);
}

int	ft_check_map_double_jump_line(t_data *d)
{
	int	n;
	int	s1;
	int	w;
	int	e;

	n = 0;
	s1 = 0;
	w = 0;
	e = 0;
	if (d->map2d == NULL)
		return (1);
	while (d->map2d[d->i])
	{
		if (ft_check_map_double_jump_line_bis(d, n, e, w) == 1)
			return (printf("Error in ft_check_map_double_jump_line\n"), 1);
		d->i++;
	}
	return (0);
}
