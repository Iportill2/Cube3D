#include "../include/cub3d.h"

void	toito(t_list *s)
{
	int	i;

	i = 0;
	printf("---TOITO-----\n");
	i = 0;
	printf("******no_arr*******\n");
	while (s->no_arr && s->no_arr[i])
	{
		printf("s->no_arr[%i] = %s\n", i, s->no_arr[i]);
		i++;
	}
	i = 0;
	printf("******so_arr*******\n");
	while (s->so_arr && s->so_arr[i])
	{
		printf("s->so_arr[%i] = %s\n", i, s->so_arr[i]);
		i++;
	}
	i = 0;
	printf("******we_arr*******\n");
	while (s->we_arr && s->we_arr[i])
	{
		printf("s->WE[%i] = %s\n", i, s->we_arr[i]);
		i++;
	}
	i = 0;
	printf("******ea_arr*******\n");
	while (s->ea_arr && s->ea_arr[i])
	{
		printf("s->EA[%i] = %s\n", i, s->ea_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->floor******\n");
	while (i <= s->floor_size)
	{
		printf("s->floor[%i] = %s\n", i, s->floor[i]);
		i++;
	}
	i = 0;
	printf("******s->floor_int_arr******\n");
	while (i < s->floor_size)
	{
		printf("s->floor_int_arr[%i] = %d\n", i, s->floor_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->celling******\n");
	while (i <= s->cell_size)
	{
		printf("s->celling[%i] = %s\n", i, s->celling[i]);
		i++;
	}
	i = 0;
	printf("******s->cell_int_arr******\n");
	while (i < s->cell_size)
	{
		printf("s->celling_int_arr[%i] = %d\n", i, s->celling_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******s->map3d******\n");
	while (s->map3d[i])
	{
		printf("s->map3d[%i] = %s\n", i, s->map3d[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******map_settings******\n");
	while (s->map_settings[i])
	{
		printf("map_settings[%i] = %s\n", i, s->map_settings[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******s->playable_map******\n");
	while (s->playable_map[i])
	{
		printf("%s\n", s->playable_map[i]);
		i++;
	}
	printf("******s->playable_str_len******\n");
	printf("str_len =%i\n", s->playable_str_len);
	printf("----------------\n");
	printf("******s->playable_array_len******\n");
	printf("array_len =%i\n", s->playable_array_len);
	printf("----------------\n");
	i = 0;
	printf("******s->new_playable_map******\n");
	while (s->new_playable_map[i])
	{
		printf("%s\n", s->new_playable_map[i]);
		i++;
	}
	printf("s->floor_rgb =%i\n", s->floor_rgb);
	printf("s->celling_rgb =%i\n", s->cell_rgb);
	printf("----------------\n");
	printf("s->n=%i\n", s->n);
	printf("s->s=%i\n", s->s);
	printf("s->e=%i\n", s->e);
	printf("s->w=%i\n", s->w);
	printf("s->pj_init_nsew=%c\n", s->pj_init_nsew);
	printf("---TOITO-----\n");
}

int	ft_get_playable_map_strlen_arraylen(t_list *s)
{
	int	i;

	i = 0;
	while (s->playable_map && s->playable_map[s->playable_array_len])
	{
		i = ft_strlen(s->playable_map[s->playable_array_len]);
		if (i > s->playable_str_len)
			s->playable_str_len = i;
		s->playable_array_len++;
	}
	return (0);
}

char	**ft_pam(char **map)
{
	int		len;
	int		slen;
	char	**pam;
	int		i;
	int		j;
	int		k;

	len = 0;
	while (map[0][len])
		len++;
	slen = 0;
	while(map[slen])
		slen++;
	pam = malloc (sizeof(char *) * (len + 1));
	pam[len] = NULL;
	i = 0;
	while (i < len)
	{
		k = 0;
		j = slen - 1;
		pam[i] = malloc (sizeof(char) * (slen + 1));
		while (j >= 0)
		{
			pam[i][k++] = map[j--][i];
		}
		pam[i][k] = '\0';
		i++;
	}
	return (pam);
}

int	ft_maplen(char * s)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nNose pudo abrir el archivo"), 0);
	while (read(fd, buffer, 1))
		i++;
	if (i < 1)
		return (close(fd), printf("Error\nMapa vacio.\n"), 0);
	return (close(fd), i);
}

int	ft_read_map(char **argv, t_list *s)
{
	char	*temp;
	int		fd;
	int		read_bytes;

	temp = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("fd=%i\n", fd), printf("mal\n"), free((void *)s), 1);
	while (1)
	{
		temp = ft_calloc(sizeof(char), 2);
		temp[1] = '\0';
		read_bytes = read(fd, temp, 1);
		s->map2d = ft_strjoin(s->map2d, temp);
		free(temp);
		if (read_bytes == 0)
			break ;
	}
	close(fd);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	char	**map;
	char	**pam;
	char	*s;
	int		fd;
	int		i;
	t_data	*d;
	
	(void)argc;
	d = malloc (sizeof(t_data));
	if (!d)
		return (1);
	i = ft_maplen(argv[1]);
	s = malloc (sizeof(char) * (i + 1));
	fd = open(argv[1], O_RDONLY);
	read (fd, s, i);
	s[i] = '\0';
	map = ft_split(s, '\n');
	pam = ft_pam(map);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	printf("\n");
	i = 0;
	while (pam[i])
		printf("%s\n", pam[i++]);
	printf("\n");
	//printf("x[%i]y[%i] = %c\n", x, y, pam[x][y]);
	d->map = map;
	d->pam = pam;
	ft_screen(d);
	return (0);
}
*/

int	main( int argc, char **argv)
{
	t_list	*s;
	int		len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if ((argv[1][len - 1] != 'b') && (argv[1][len - 2] != 'u') \
		&& (argv[1][len - 3] != 'c') && (argv[1][len - 4] != '.'))
			return (printf("Wrong file extension\n"), 1);
		s = ft_calloc(sizeof(t_list), (1));
		if (ft_get_maps(s, argv) == 1)
			return (printf("Error in get_maps\n"), 1);
		if (ft_floor_cell(s) == 1)
			return (printf("Error in ft_floor_cell\n"), 1);
		if (ft_checks(s) == 1)
			return (printf("Error in ft_check\n"), 1);
		toito(s);
		//ft_star_game(s);
		ft_free_struc(s);
	}
	else
		printf("Invalid num of arguments\n");
	return (0);
}
