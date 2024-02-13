#include "../include/cub3d.h"

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
	d->color = WALL_COLOR;////color de las paredes S mitad izq
	d->texture = 'x';
	d->active  = d->w;
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
	d->color = WALL_COLOR;/////color de las paredes W mitad der
	d->texture = 'y';
	d->active  = d->s;
}

static void	ft_check_contact(t_data *d)
{
	if (d->pam[(int)floor(d->rx)][(int)floor(d->ry)] == '1')
		d->contact = 1;
	//printf("contact = %d\n", d->contact);
	
	//printf("contenido = %s\n", d->pam[(int)floor(d->px)][(int)floor(d->py)]);
}

int ft_move_q1(t_data *d, int i)
{
	while (i >= 0 && d-> angle <= 90)
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
		d->dist = ((d->rx - d->px) / cos(d->angle_rad)) * sin (d->angle_dist_rad);
		//printf("angle rad = %f - d->dist: %f\n",d->angle_rad, d->dist);
		ft_create_line(d, i);
		d->angle += 0.088;
		i--;
	}
	//printf("Q1   d->angle_ini = %f\n", d->angle_ini);
	return (i);
}
