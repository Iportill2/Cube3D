#include "../include/cub3d.h"

void	toito(t_data *d)
{
	int	i;

	i = 0;
	printf("---TOITO-----\n");
	i = 0;
	printf("******no_arr*******\n");
	while (d->no_arr && d->no_arr[i])
	{
		printf("d->no_arr[%i] = %s\n", i, d->no_arr[i]);
		i++;
	}
	i = 0;
	printf("******so_arr*******\n");
	while (d->so_arr && d->so_arr[i])
	{
		printf("d->so_arr[%i] = %s\n", i, d->so_arr[i]);
		i++;
	}
	i = 0;
	printf("******we_arr*******\n");
	while (d->we_arr && d->we_arr[i])
	{
		printf("d->WE[%i] = %s\n", i, d->we_arr[i]);
		i++;
	}
	i = 0;
	printf("******ea_arr*******\n");
	while (d->ea_arr && d->ea_arr[i])
	{
		printf("d->EA[%i] = %s\n", i, d->ea_arr[i]);
		i++;
	}
	i = 0;
	printf("******d->floor******\n");
	while (i <= d->floor_size)
	{
		printf("d->floor[%i] = %s\n", i, d->floor[i]);
		i++;
	}
	i = 0;
	printf("******d->floor_int_arr******\n");
	while (i < d->floor_size)
	{
		printf("d->floor_int_arr[%i] = %d\n", i, d->floor_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******d->celling******\n");
	while (i <= d->cell_size)
	{
		printf("d->celling[%i] = %s\n", i, d->celling[i]);
		i++;
	}
	i = 0;
	printf("******d->cell_int_arr******\n");
	while (i < d->cell_size)
	{
		printf("d->celling_int_arr[%i] = %d\n", i, d->celling_int_arr[i]);
		i++;
	}
	i = 0;
	printf("******d->map3d******\n");
	while (d->map3d[i])
	{
		printf("d->map3d[%i] = %s\n", i, d->map3d[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******map_settings******\n");
	while (d->map_settings[i])
	{
		printf("map_settings[%i] = %s\n", i, d->map_settings[i]);
		i++;
	}
	printf("----------------\n");
	i = 0;
	printf("******d->playable_map******\n");
	while (d->playable_map[i])
	{
		printf("%s\n", d->playable_map[i]);
		i++;
	}
	printf("******d->playable_str_len******\n");
	printf("str_len =%i\n", d->playable_str_len);
	printf("----------------\n");
	printf("******d->playable_array_len******\n");
	printf("array_len =%i\n", d->playable_array_len);
	printf("----------------\n");
	i = 0;
	printf("******d->new_playable_map******\n");
	while (d->new_playable_map[i])
	{
		printf("%s\n", d->new_playable_map[i]);
		i++;
	}
	i = 0;
	printf("******d->pam******\n");
	while (d->pam[i])
		printf("%s\n", d->pam[i++]);
	printf("d->floor_rgb =%i\n", d->floor_rgb);
	printf("d->cell_rgb =%i\n", d->cell_rgb);
	printf("----------------\n");
	printf("d->n=%i\n", d->nx);
	printf("d->s=%i\n", d->sx);
	printf("d->e=%i\n", d->ex);
	printf("d->w=%i\n", d->wx);
	printf("d->pj_init_nsew=%c\n", d->pj_init_nsew);
	printf("---TOITO-----\n");
}

int	ft_get_playable_map_strlen_arraylen(t_data *d)
{
	int	i;

	i = 0;
	while (d->playable_map && d->playable_map[d->playable_array_len])
	{
		i = ft_strlen(d->playable_map[d->playable_array_len]);
		if (i > d->playable_str_len)
			d->playable_str_len = i;
		d->playable_array_len++;
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

	if(!map)
		return(NULL);
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

int	ft_read_map(char **argv, t_data *d)
{
	char	*temp;
	int		fd;
	int		read_bytes;

	temp = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("fd=%i\n", fd), printf("mal\n"), free((void *)d), 1);
	while (1)
	{
		temp = ft_calloc(sizeof(char), 2);
		temp[1] = '\0';
		read_bytes = read(fd, temp, 1);
		d->map2d = ft_strjoin(d->map2d, temp);
		free(temp);
		if (read_bytes == 0)
			break ;
	}
	close(fd);
	return (0);
}

int	main( int argc, char **argv)
{
	t_data	*d;
	int		len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if ((argv[1][len - 1] != 'b') && (argv[1][len - 2] != 'u') \
		&& (argv[1][len - 3] != 'c') && (argv[1][len - 4] != '.'))
			return (printf("Wrong file extension\n"), 1);
		d = ft_calloc(sizeof(t_data), (1));
		if (ft_get_maps(d, argv) == 1)
			return (printf("Error in get_maps\n"), 1);
		if (ft_floor_cell(d) == 1)
			return (printf("Error in ft_floor_cell\n"), 1);
		if (ft_checks(d) == 1)
			return (printf("Error in ft_check\n"), 1);

		toito(d);
		ft_star_game(d);
		ft_free_struc(d);
	}
	else
		printf("Invalid num of arguments\n");
	return (0);
}
