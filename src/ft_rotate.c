/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:04:24 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/15 12:09:04 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rotate(t_data *d)
{
	if (d->rotate == 1)
		d->angle_ini += ROTATE_STEP;
	else if (d->rotate == 2)
		d->angle_ini -= ROTATE_STEP;
}
