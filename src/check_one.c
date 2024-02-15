#include "../include/cub3d.h"

int	ft_check_chars_in_playable_map(t_list *s)
{
	if (s->n == 1 && (s->s > 0 || s->e > 0 || s->w > 0))
		return (printf("Error\nInitial position set multiple times\n"), 1);
	if (s->s == 1 && (s->n > 0 || s->e > 0 || s->w > 0))
		return (printf("Error\nInitial position set multiple times\n"), 1);
	if (s->e == 1 && (s->s > 0 || s->n > 0 || s->w > 0))
		return (printf("Error\nInitial position set multiple times\n"), 1);
	if (s->w == 1 && (s->s > 0 || s->e > 0 || s->n > 0))
		return (printf("Error\nInitial position set multiple times\n"), 1);
	if (s->n != 0 && s->n != 1)
		return (printf("Error\nN set more than one time\n"), 1);
	if (s->s != 0 && s->s != 1)
		return (printf("Error\nS set more than one time\n"), 1);
	if (s->e != 0 && s->e != 1)
		return (printf("Error\nE set more than one time\n"), 1);
	if (s->w != 0 && s->w != 1)
		return (printf("Error\nW set more than one time\n"), 1);
	if (s->invalid_char != 0)
		return (printf("Error\nInvalid character in map\n"), 1);
	if (ft_check_initial_position(s) == 1)
		return (1);
	return (0);
}

int	ft_check_textures(t_list *s)
{
	int	fd;

	fd = open(s->no_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->no_arr[1]), 1);
	fd = open(s->so_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->so_arr[1]), 1);
	fd = open(s->we_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->we_arr[1]), 1);
	fd = open(s->ea_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->ea_arr[1]), 1);
	return (0);
}

int	ft_check_map_args(t_list *s)
{
	if (ft_arraylen(s->no_arr) != 2 || ft_arraylen(s->so_arr) != 2 || \
	ft_arraylen(s->we_arr) != 2 || ft_arraylen(s->ea_arr) != 2 || \
	ft_arraylen(s->floor) != 4 || ft_arraylen(s->celling) != 4)
		return (printf("Error\nIncorrect arguments in texture path\n"), 1);
	return (0);
}

int	ft_check_map_double_jump_line_bis(t_list *s, int n, int e, int w)
{
	if (s->map2d[s->i] == 'N')
		n++;
	else if (s->map2d[s->i] == 'S')
		s->s_c++;
	else if (s->map2d[s->i] == 'E')
		e++;
	else if (s->map2d[s->i] == 'W')
		w++;
	else if (s->map2d[s->i] == 'F')
		s->f++;
	else if (s->map2d[s->i] == 'C')
		s->c++;
	if ((n == 2 || n == 3) && (s->s_c == 2 || s->s_c == 3) && \
	(e == 3 || e == 4) && (w == 2 || w == 3) && s->f == 1 && \
	s->c == 1 && (s->stop == 0) && s->map2d[s->i] == '\n')
		s->stop = 1;
	else if ((s->stop == 1) && s->map2d[s->i] == '\n')
		s->stop = 1;
	else if (s->stop != 0 && (s->map2d[s->i] == '1'))
		s->stop = 2;
	else if ((s->stop == 2) && s->map2d[s->i] == '\n')
		s->stop = 3;
	else if ((s->stop == 3) && s->map2d[s->i] == '\n')
		return (1);
	return (0);
}

int	ft_check_map_double_jump_line(t_list *s)
{
	int	n;
	int	s1;
	int	w;
	int	e;

	n = 0;
	s1 = 0;
	w = 0;
	e = 0;
	if (s->map2d == NULL)
		return (1);
	while (s->map2d[s->i])
	{
		if (ft_check_map_double_jump_line_bis(s, n, e, w) == 1)
			return (printf("Error in ft_check_map_double_jump_line\n"), 1);
		s->i++;
	}
	return (0);
}
