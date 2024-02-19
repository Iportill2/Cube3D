/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:44:33 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 17:13:00 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* int	ft_check_no_so_we_ea_f_c_check(t_list *s)
{
	if (s->no_check != 1)
		return (1);
	if (s->so_check != 1)
		return (1);
	if (s->we_check != 1)
		return (1);
	if (s->ea_check != 1)
		return (1);
	if (s->f_check != 1)
		return (1);
	if (s->c_check != 1)
		return (1);
	return (0);
} */

int	ft_check_no_so_we_ea_f_c_check(t_list *s)
{
	if (!s->no_arr || !s->so_arr || !s->we_arr || \
		!s->ea_arr || !s->floor || !s->celling)
		return (1);
	return (0);
}
/* 
void	ft_parshing_map_args_tools(t_list *s)
{
	if (ft_strcmp(s->map_date[0], "WE") == 0 && s->we_check == 0)
	{
		s->we_arr = s->map_date;
		s->we_check++;
	}
	else if (ft_strcmp(s->map_date[0], "EA") == 0 && s->ea_check == 0)
	{
		s->ea_arr = s->map_date;
		s->ea_check++;
	}
	else if (ft_strcmp(s->map_date[0], "F") == 0 && s->f_check == 0)
	{
		s->floor = s->map_date;
		s->f_check++;
	}
	else if (ft_strcmp(s->map_date[0], "C") == 0 && s->c_check == 0)
	{
		s->celling = s->map_date;
		s->c_check++;
	}
} */

/*

*/