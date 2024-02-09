/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enredando_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:24:34 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/02 18:59:27 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_set_player_coord(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->pam[i])
	{
		j = 0;
		while(d->pam[i][j])
		{
			if (d->pam[i][j] == 'N')
			{
				d->px = i + 0.5;
				d->py = j + 0.5;
				
				return;
			}
			j++;
		}
		i++;
	}
}

static void	ft_ray_x(t_data *d)
{
	//printf("---------Hola X------------\n");
	d->px += d->dis_x;
	d->py += (d->hypo_x * sin(d->angle_rad));
	if (ceil(d->py) == d->py)
		d->dis_y = 1;
	else
		d->dis_y = ceil(d->py) - d->py;
	d->dis_x = 1;
	d->color = 0x0000AA00;
}

static void	ft_ray_y(t_data *d)
{
	//printf("------------Hola Y------------\n");
	d->py += d->dis_y;
	d->px += (d->hypo_y * cos(d->angle_rad));
	if (ceil(d->px) == d->px)
		d->dis_x = 1;
	else
		d->dis_x = ceil(d->px) - d->px;
	d->dis_y = 1;
	d->color = 0x0000CC00;
}

static void	ft_check_contact(t_data *d)
{
	if (d->pam[(int)floor(d->px)][(int)floor(d->py)] == '1')
		d->contact = 1;
	//printf("contact = %d\n", d->contact);
	
	//printf("contenido = %s\n", d->pam[(int)floor(d->px)][(int)floor(d->py)]);
}

int	ft_enredando_1(t_data *d)
{
	ft_set_player_coord(d);
	d->contact = 0;
	d->angle =57;
	d->angle_rad = d->angle * M_PI / 180;
	d->dis_x = ceil(d->px) - d->px;
	d->dis_y = ceil(d->py) - d->py;
	printf("Player pos INI: x[%f]y[%f]\n", d->px, d->py);
	printf("Dis x = %f\nDis y = %f\n", d->dis_x, d->dis_y);
	d->dist_ini = d->py;
	
	int	i = 749;
	while(i >374)
	{
		ft_set_player_coord(d);
		d->contact = 0;
		d->angle_rad = d->angle * M_PI / 180.0;
		d->dis_x = ceil(d->px) - d->px;
		d->dis_y = ceil(d->py) - d->py;
		while (d->contact == 0)
		{
			d->hypo_x = d->dis_x / cos(d->angle_rad);
			d->hypo_y = d->dis_y / sin(d->angle_rad);
			if (d->hypo_x < d->hypo_y)
				ft_ray_x(d);
			else
				ft_ray_y(d);
			ft_check_contact(d);
		}
		d->dist = d->py - d->dist_ini;
		ft_create_line(d, i);
		printf("PIXEL %i, DISTANCIA DE DIBUJADO: %f\n",i, d->dist);
		d->angle += 0.088;
		i--;
	}	
	return (0);
}
