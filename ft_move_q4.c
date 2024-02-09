/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_q4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:53:32 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/08 19:30:46 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#include "cub.h"

static void	ft_ray_x(t_data *d)
{
	//printf("---------Hola X------------\n");
	d->rx += d->dis_x;
	d->ry -= (d->hypo_x * sin(d->angle_rad));
	if (floor(d->ry) == d->ry)
		d->dis_y = 1;
	else
		d->dis_y = d->ry - floor(d->ry);
	d->dis_x = 1;
	d->color = 0x0000AA00;
}

static void	ft_ray_y(t_data *d)
{
	//printf("------------Hola Y------------\n");
	d->ry -= d->dis_y;
	d->rx += (d->hypo_y * cos(d->angle_rad));
	if (ceil(d->rx) == d->rx)
		d->dis_x = 1;
	else
		d->dis_x = ceil(d->rx) - d->rx;
	d->dis_y = 1;
	d->color = 0x00004400;
}

static void	ft_check_contact_x(t_data *d)
{
	if (d->pam[(int)floor(d->rx)][(int)floor(d->ry)] == '1')
		d->contact = 1;
}

static void	ft_check_contact_y(t_data *d)
{
	if (d->pam[(int)floor(d->rx)][(int)floor(d->ry - 1)] == '1')
		d->contact = 1;
}

int ft_move_q4(t_data *d, int i)
{
	//printf("Q2   d->angle_ini = %f\n", d->angle_ini);
	d->angle = 360 - d->angle;
	while (i >= 0 && (d->angle) >= 0)
	{
		d->rx = d->px;
		d->ry = d->py;
		d->contact = 0;
		d->angle_rad = d->angle * M_PI / 180.0;
		d->dis_x = ceil(d->rx) - d->rx;
		d->dis_y = d->ry - floor(d->ry);
		while (d->contact == 0)
		{
			d->hypo_x = d->dis_x / cos(d->angle_rad);
			d->hypo_y = d->dis_y / sin(d->angle_rad);
			if (d->hypo_x < d->hypo_y)
			{
				ft_ray_x(d);
				ft_check_contact_x(d);
			}
			else
			{
				ft_ray_y(d);
				ft_check_contact_y(d);
			}
		}
		d->angle_dist_rad = ((d->angle) - (270 - d->angle_ini)) * M_PI / 180;
		d->dist = ((d->rx - d->px) / cos(d->angle_rad)) * sin (d->angle_dist_rad);
		//printf("angle rad = %f - d->dist: %f\n",d->angle_rad, d->dist);
		//printf("Q2---------------d-px - d-rx: %f\n",d->px - d->rx );
		ft_create_line(d, i);
		d->angle -= 0.088;
		i--;
	}
	//printf("D->ANGLE en puto Q2: %f\n", d->angle);
	if (d->angle < 0)
		d->angle = (-d->angle);
	return (i);
}
