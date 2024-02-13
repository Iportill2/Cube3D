#include "../include/cub3d.h"

static void	ft_ray_x(t_list *s)
{
	//printf("---------Hola X------------\n");
	s->rx -= s->dis_x;
	s->ry -= (s->hypo_x * cos(s->angle_rad));
	if (floor(s->ry) == s->ry)
		s->dis_y = 1;
	else
		s->dis_y = s->ry - floor(s->ry);
	s->dis_x = 1;
	s->color = 0x0000AA00;
	//d->color = 0x00AA0000;
	//printf("d->rx: %f\n", d->rx);
}

static void	ft_ray_y(t_list *s)
{
	//printf("------------Hola Y------------\n");
	s->ry -= s->dis_y;
	s->rx -= (s->hypo_y * sin(s->angle_rad));
	if (floor(s->rx) == s->rx)
		s->dis_x = 1;
	else
		s->dis_x = s->rx - floor(s->rx);
	s->dis_y = 1;
	s->color = 0x00004400;
	//printf("d->ry: %f\n", d->ry);
}

static void	ft_check_contact_x(t_list *s)
{
	if (s->pam[(int)floor(s->rx - 1)][(int)floor(s->ry)] == '1')
		s->contact = 1;
}

static void	ft_check_contact_y(t_list *s)
{
	if (s->pam[(int)floor(s->rx)][(int)floor(s->ry - 1)] == '1')
		s->contact = 1;
}

int ft_move_q3(t_list *s, int i)
{
	s->angle = 270 - s->angle;
	while (i >= 0 && s-> angle >= 0)
	{
		s->rx = s->px;
		s->ry = s->py;
		//printf("d->rx: %f\n", d->rx);
		//printf("d->ry: %f\n", d->ry);
		s->contact = 0;
		s->angle_rad = s->angle * M_PI / 180.0;
		s->dis_x = s->rx - floor(s->rx);
		s->dis_y = s->ry - floor(s->ry);
		while (s->contact == 0)
		{
			//printf("Q3   d->angle = %f\n", d->angle);
			s->hypo_y = s->dis_y / cos(s->angle_rad);
			s->hypo_x = s->dis_x / sin(s->angle_rad);
			if (s->hypo_x < s->hypo_y)
			{
				ft_ray_x(s);
				ft_check_contact_x(s);
			}
			else
			{
				ft_ray_y(s);
				ft_check_contact_y(s);
			}
		}
		s->angle_dist_rad = ((s->angle) - (180 - s->angle_ini)) * M_PI / 180;
		//d->angle_dist_rad = ((d->angle + 270) - d->angle_ini) * M_PI / 180;
		s->dist = ((s->py - s->ry) / cos(s->angle_rad)) * sin(s->angle_dist_rad);
		//printf("Q3---------------d-px - d-rx: %f\n",d->px - d->rx );
		//printf("d->px - d->rx: %f\n", d->px - d->rx);
		ft_create_line(s, i);
		s->angle -= 0.088;
		i--;
	}
	if (s->angle < 0)
		s->angle = 270 + (-s->angle);
	return (i);
}