/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 17:41:03 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_maplen(char *s)
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
	ft_pam(d, map);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	printf("\n");
	i = 0;
	/* while (pam[i])
		printf("%s\n", pam[i++]); */
	printf("\n");
	//printf("x[%i]y[%i] = %c\n", x, y, pam[x][y]);
	d->map = map;
	//d->pam = pam;
	ft_screen(d);
	return (0);
}
