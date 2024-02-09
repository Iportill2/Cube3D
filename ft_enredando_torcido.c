/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enredando_torcido.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:24:34 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/06 20:15:59 by jgoikoet         ###   ########.fr       */
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
	d->rx += d->dis_x;
	d->ry += (d->hypo_x * sin(d->angle_rad));
	if (ceil(d->ry) == d->ry)
		d->dis_y = 1;
	else
		d->dis_y = ceil(d->ry) - d->ry;
	d->dis_x = 1;
	d->color = 0x0000AA00;
}

static void	ft_ray_y(t_data *d)
{
	//printf("------------Hola Y------------\n");
	d->ry += d->dis_y;
	d->rx += (d->hypo_y * cos(d->angle_rad));
	if (ceil(d->rx) == d->rx)
		d->dis_x = 1;
	else
		d->dis_x = ceil(d->rx) - d->rx;
	d->dis_y = 1;
	d->color = 0x0000CC00;
}

static void	ft_check_contact(t_data *d)
{
	if (d->pam[(int)floor(d->rx)][(int)floor(d->ry)] == '1')
		d->contact = 1;
	//printf("contact = %d\n", d->contact);
	
	//printf("contenido = %s\n", d->pam[(int)floor(d->px)][(int)floor(d->py)]);
}

int	ft_enredando_torcido(t_data *d)
{
	//d->contact = 0;
	//d->angle_dist_rad = (90 - d->angle_ini + d->angle) * M_PI / 180;
	//d->angle_rad = d->angle * M_PI / 180;
	//d->dis_x = ceil(d->px) - d->px;
	//d->dis_y = ceil(d->py) - d->py;
	//printf("Player pos INI: x[%f]y[%f]\n", d->px, d->py);
	//printf("Dis x = %f\nDis y = %f\n", d->dis_x, d->dis_y);
	//d->dist_ini = d->py;
	
	d->angle = d->angle_ini - 33;
	int	i = 749;
	while(d->angle <= 90 && i >= 0)
	{
		d->rx = d->px;
		d->ry = d->py;
		d->contact = 0;
		d->angle_rad = d->angle * M_PI / 180.0;
		d->dis_x = ceil(d->rx) - d->rx;
		d->dis_y = ceil(d->ry) - d->ry;
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
		d->angle_dist_rad = (90 - d->angle_ini + d->angle) * M_PI / 180;
		//d->dist = d->ry - d->py;
		d->dist = ((d->rx - d->px) / cos(d->angle_rad)) * sin (d->angle_dist_rad);
		printf("angle rad = %f - d->dist: %f\n",d->angle_rad, d->dist);
		ft_create_line(d, i);
		//printf("PIXEL %i, DISTANCIA DE DIBUJADO antigua: %f\n",i, d->dist);
		//printf("PIXEL %i, DISTANCIA DE DIBUJADO NUEVA: %f\n",i, d->dist);
		//printf("dix x = %f\ndis y = %f", d->dis_x, d->dis_y);
		d->angle += 0.088;
		i--;
	}
	//printf("Player pos FIN: x[%f]y[%f]\n", d->px, d->py);
	//printf("d->angle = %f", d->angle);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}
