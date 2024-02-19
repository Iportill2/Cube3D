/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:44:33 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 12:52:41 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_no_so_we_ea_f_c_check(t_list *s)
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
}
