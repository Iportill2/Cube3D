/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_goiko.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:41:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/16 12:56:07 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_array_len(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		i++;
	return (i);
}

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
int	ft_check_settings(t_list *s)
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (i < 6)
	{
		if (!ft_strcmp(s->ar_sets[i][0], "NO") || \
			!ft_strcmp(s->ar_sets[i][0], "SO") || \
			!ft_strcmp(s->ar_sets[i][0], "WE") || \
			!ft_strcmp(s->ar_sets[i][0], "EA") || \
			!ft_strcmp(s->ar_sets[i][0], "C") || \
			!ft_strcmp(s->ar_sets[i][0], "F"))
				n++;
		i++;
	}
	if (n < 6)
		printf("------Argumentos mal--------- ");
	printf("n = %i\n\n", n);
	return (0);
}
int	ft_check_line7(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ')
			printf("----- Septima linea mal ------\n");
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
	if (ft_array_len(ar) < 9)
		printf("\nArray muy corto\n\n");
	
	ft_set_game(s, ar);
	ft_check_settings(s);
	ft_check_line7(ar[6]);
	return (0);
}
