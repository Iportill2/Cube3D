/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goiko.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:34:32 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 13:58:28 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_set_game(t_list *s, char **ar)
{
	int		i;

	s->ar_sets = malloc (sizeof (char **) * 7);
	i = 0;
	while(i < 6)
	{
		s->ar_sets[i] = ft_dual_split (ar[i], ' ', ',');
		i++;
	}
	s->ar_sets[i] = NULL;
}
int	ft_check_settings(t_list *s)//creo que ya lo tenemos en otra parte
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (i < 6)
	{
		if ((ft_strcmp(s->ar_sets[i][0], "NO") == 0) || \
			(ft_strcmp(s->ar_sets[i][0], "SO") == 0)|| \
			(ft_strcmp(s->ar_sets[i][0], "WE") == 0)|| \
			(ft_strcmp(s->ar_sets[i][0], "EA") == 0)|| \
			(ft_strcmp(s->ar_sets[i][0], "C") == 0)|| \
			(ft_strcmp(s->ar_sets[i][0], "F") == 0))
				n++;
		i++;
	}
	if (n < 6)
		return(printf("------Argumentos mal--------- "), 1);
	return (0);
}
int	ft_check_line7(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return(printf("Error\nTrash in map settings\n"), 1);
		i++;
	}
	return(0);
}

int	ft_error_goiko(t_list *s)
{
	int		i;
	char	**ar;

	i = 0;
/* 	printf("\nPLAYABLE MAP\n\n");
	while (s->playable_map[i])
		printf("%s\n", s->playable_map[i++]);

	i = 0;
	printf("\nNEW PLAYABLE MAP\n\n");
	while (s->new_playable_map[i])
		printf("%s\n", s->new_playable_map[i++]);
	
	i = 0;
	printf("\nMAP SETTINGS\n\n");
	while (s->map_settings[i])
		printf("%s\n", s->map_settings[i++]);
	
	i = 0;
	printf("\nMAP2D\n\n");
	while (s->map2d[i])
		printf("%c", s->map2d[i++]);

	i = 0;
	printf("\nMAP3D\n\n");
	while (s->map3d[i])
		printf("%s\n", s->map3d[i++]);
	 */
	
	ar = ft_split(s->map2d, '\n');
	if (ft_arraylen(ar) < 9)
		printf("\nArray muy corto\n\n");
	
	ft_set_game(s, ar);
	/* if(ft_check_settings(s) == 1)
		return (1); */
	if(ft_check_line7(ar[6]) == 1)
		return (1);
	return (0);
}