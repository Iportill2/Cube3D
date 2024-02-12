#include "../include/cub3d.h"

static void	ft_ray_x(t_list *s)
{
	//printf("---------Hola X------------\n");
	s->rx += s->dis_x;
	s->ry += (s->hypo_x * sin(s->angle_rad));
	if (ceil(s->ry) == s->ry)
		s->dis_y = 1;
	else
		s->dis_y = ceil(s->ry) - s->ry;
	s->dis_x = 1;
	s->color = 0x0000AA00;
}

static void	ft_ray_y(t_list *s)
{
	//printf("------------Hola Y------------\n");
	s->ry += s->dis_y;
	s->rx += (s->hypo_y * cos(s->angle_rad));
	if (ceil(s->rx) == s->rx)
		s->dis_x = 1;
	else
		s->dis_x = ceil(s->rx) - s->rx;
	s->dis_y = 1;
	s->color = 0x0000DD00;
}

static void	ft_check_contact(t_list *s)
{
	if (s->pam[(int)floor(s->rx)][(int)floor(s->ry)] == '1')
		s->contact = 1;
	//printf("contact = %d\n", d->contact);
	
	//printf("contenido = %s\n", d->pam[(int)floor(d->px)][(int)floor(d->py)]);
}

int ft_move_q1(t_list *s, int i)
{
	while (i >= 0 && s->angle <= 90)
	{
		s->rx = s->px;
		s->ry = s->py;
		s->contact = 0;
		s->angle_rad = s->angle * M_PI / 180.0;
		s->dis_x = ceil(s->rx) - s->rx;
		s->dis_y = ceil(s->ry) - s->ry;
		while (s->contact == 0)
		{
			s->hypo_x = s->dis_x / cos(s->angle_rad);
			s->hypo_y = s->dis_y / sin(s->angle_rad);
			if (s->hypo_x < s->hypo_y)
				ft_ray_x(s);
			else
				ft_ray_y(s);
			ft_check_contact(s);
		}
		s->angle_dist_rad = (90 - s->angle_ini + s->angle) * M_PI / 180;
		s->dist = ((s->rx - s->px) / cos(s->angle_rad)) * sin (s->angle_dist_rad);
		//printf("angle rad = %f - d->dist: %f\n",d->angle_rad, d->dist);
		ft_create_line(s, i);
		s->angle += 0.088;
		i--;
	}
	//printf("Q1   d->angle_ini = %f\n", d->angle_ini);
	return (i);
}
