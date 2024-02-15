/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 19:03:21 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
void	toito(t_list *s,t_data *d)
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
	(void)d;
	printf("******s->new_playable_map******\n");
	while (s->new_playable_map[i])
	{
		printf("%s\n", s->new_playable_map[i]);
		i++;
	}
	i = 0;
	printf("******d->pam******\n");
	while (d->pam[i])
		printf("%s\n", d->pam[i++]);
	printf("s->floor_rgb =%i\n", s->floor_rgb);
	printf("s->cell_rgb =%i\n", s->cell_rgb);
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
void ft_nsew_to_angle_ini(t_list *s,t_data *d)
{
	if(s->pj_init_nsew == 'N')
		d->angle_ini = 90;
	if(s->pj_init_nsew == 'S')
		d->angle_ini = 270;
	if(s->pj_init_nsew == 'E')
		d->angle_ini = 0;	
	if(s->pj_init_nsew == 'W')
		d->angle_ini = 180;
	printf("d->angle_ini = %f\n",d->angle_ini);
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
void ft_s_to_d(t_list *s,t_data *d)
{
	d->cell_rgb = s->cell_rgb;
	d->floor_rgb = s->floor_rgb;
	d->texture_n = s->no_arr[1];
	d->texture_s = s->so_arr[1];
	d->texture_w = s->we_arr[1];
	d->texture_e = s->ea_arr[1];
	
}
int	main(int argc, char **argv)
{
	int len;
	t_data	*d;
	t_list	*s;
	
	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if ((argv[1][len - 1] != 'b') && (argv[1][len - 2] != 'u') \
		&& (argv[1][len - 3] != 'c') && (argv[1][len - 4] != '.'))
			return (printf("Wrong file extension\n"), 1);
		s = ft_calloc(sizeof(t_list), 1);
		d = ft_calloc (sizeof(t_data),1);

		if (ft_get_maps(d,s,argv) == 1)
			return (printf("Error in get_maps\n"), 1);
		if (ft_floor_cell(s) == 1)
			return (printf("Error in ft_floor_cell\n"), 1);
		if (ft_checks(s) == 1)
			return (printf("Error in ft_check\n"), 1);
		//toito(s,d);
		ft_s_to_d(s,d);
		ft_nsew_to_angle_ini(s,d);
		ft_screen(d);
		ft_free_struc(s);
	}
	else
		printf("Invalid num of arguments\n");
	return (0);	
}