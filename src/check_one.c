#include "../include/cub3d.h"

int	ft_check_chars_in_playable_map(t_list *s)
{
	if (s->n == 1 && (s->s > 0 || s->e > 0 || s->w > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)s), 1);
	if (s->s == 1 && (s->n > 0 || s->e > 0 || s->w > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)s), 1);
	if (s->e == 1 && (s->s > 0 || s->n > 0 || s->w > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)s), 1);
	if (s->w == 1 && (s->s > 0 || s->e > 0 || s->n > 0))
		return (printf("Initial position set multiple times\n"), \
		free((void *)s), 1);
	if (s->n != 0 && s->n != 1)
		return (printf("N set more than one time\n"), free((void *)s), 1);
	if (s->s != 0 && s->s != 1)
		return (printf("S set more than one time\n"), free((void *)s), 1);
	if (s->e != 0 && s->e != 1)
		return (printf("E set more than one time\n"), free((void *)s), 1);
	if (s->w != 0 && s->w != 1)
		return (printf("W set more than one time\n"), free((void *)s), 1);
	if (s->invalid_char != 0)
		return (printf("Invalid character in map\n"), free((void *)s), 1);
	if (ft_check_initial_position(s) == 1)
		return (1);
	return (0);
}

int	ft_check_textures(t_list *s)
{
	int	fd;

	fd = open(s->no_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in s->no_arr[1]º\n"), 1);
	fd = open(s->so_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in s->so_arr[1]º\n"), 1);
	fd = open(s->we_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in s->we_arr[1]º\n"), 1);
	fd = open(s->ea_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error in s->ea_arr[1]º\n"), 1);
	return (0);
}

int	ft_check_map_args(t_list *s)
{
	if (ft_arraylen(s->no_arr) != 2 || ft_arraylen(s->so_arr) != 2 || \
	ft_arraylen(s->we_arr) != 2 || ft_arraylen(s->ea_arr) != 2 || \
	ft_arraylen(s->floor) != 4 || ft_arraylen(s->celling) != 4)
		return (printf("Error in ft_check_map_args\n"), 1);
	return (0);
}

int	ft_check_jumplines_in_playable_map(t_list *s)
{
	if (s == NULL)
		return (1);
	return (0);
}

int	ft_check_map_double_jump_line(t_list *s)
{
	int	i;
	int	n;
	int	s1;
	int	w;
	int	e;
	int	f;
	int	c;
	int	stop;
	int	count;

	i = 0;
	n = 0;
	s1 = 0;
	w = 0;
	e = 0;
	f = 0;
	c = 0;
	stop = 0;
	count = 0;
	if (s->map2d == NULL)
		return (1);
	while (s->map2d[i])
	{
		if (s->map2d[i] == 'N')
			n++;
		else if (s->map2d[i] == 'S')
			s1++;
		else if (s->map2d[i] == 'E')
			e++;
		else if (s->map2d[i] == 'W')
			w++;
		else if (s->map2d[i] == 'F')
			f++;
		else if (s->map2d[i] == 'C')
			c++;
		if ((n == 2 || n == 3) && (s1 == 2 || s1 == 3) && (e == 3 || e == 4) && \
		(w == 2 || w == 3) && f == 1 && c == 1 && (stop == 0) \
		&& s->map2d[i] == '\n')
			stop = 1;
		else if ((stop == 1) && s->map2d[i] == '\n')
			stop = 1;
		else if (stop != 0 && (s->map2d[i] == '1'))
			stop = 2;
		else if ((stop == 2) && s->map2d[i] == '\n')
			stop = 3;
		else if ((stop == 3) && s->map2d[i] == '\n')
			return (1);
		count++;
		i++;
	}
	return (0);
}
