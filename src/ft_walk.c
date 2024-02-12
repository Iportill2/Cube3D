#include "../include/cub3d.h"

void	ft_walk_colision(t_list *s, double x, double y)
{
	/* int	xx;
	int	yy;

	xx = x;
	yy = y;  */
	if (s->pam[(int)x][(int)y] != '1')//OJO con '-'
	{
		s->px = x;
		s->py = y;
	}
}

void	ft_walk_left(t_list *s)
{
	double	x;
	double	y;

	if (s->angle_ini <= 90)
	{
		x = s->px - (s->walk_step * sin (s->angle_ini * M_PI / 180.0));
		y = s->py + (s->walk_step *	cos (s->angle_ini * M_PI / 180.0));
	}
	else if (s->angle_ini <= 180)
	{
		x = s->px - (s->walk_step * cos ((s->angle_ini - 90) * M_PI / 180.0));
		y = s->py - (s->walk_step *	sin ((s->angle_ini - 90) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 270)
	{
		x = s->px + (s->walk_step * sin ((s->angle_ini - 180) * M_PI / 180.0));
		y = s->py - (s->walk_step *	cos ((s->angle_ini - 180) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 360)
	{
		x = s->px + (s->walk_step * cos ((s->angle_ini - 270) * M_PI / 180.0));
		y = s->py + (s->walk_step *	sin ((s->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(s, x, y);
}
void	ft_walk_right(t_list *s)
{
	double	x;
	double	y;

		if (s->angle_ini <= 90)
	{
		x = s->px + (s->walk_step * sin (s->angle_ini * M_PI / 180.0));
		y = s->py - s->walk_step *	cos (s->angle_ini * M_PI / 180.0);
	}
	else if (s->angle_ini <= 180)
	{
		x = s->px +  (s->walk_step * cos ((s->angle_ini - 90) * M_PI / 180.0));
		y = s->py + (s->walk_step *	sin ((s->angle_ini - 90) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 270)
	{
		x = s->px - (s->walk_step * sin ((s->angle_ini - 180) * M_PI / 180.0));
		y = s->py + (s->walk_step *	cos ((s->angle_ini - 180) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 360)
	{
		x = s->px - (s->walk_step * cos ((s->angle_ini - 270) * M_PI / 180.0));
		y = s->py - (s->walk_step *	sin ((s->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(s, x, y);
}
void	ft_walk_forward(t_list *s)
{
	double	x;
	double	y;

	if (s->angle_ini <= 90)
	{
		x = s->px + (s->walk_step * cos (s->angle_ini * M_PI / 180.0));
		y = s->py + (s->walk_step *	sin (s->angle_ini * M_PI / 180.0));
	}
	else if (s->angle_ini <= 180)
	{
		x = s->px - (s->walk_step * sin ((s->angle_ini - 90) * M_PI / 180.0));
		y = s->py + (s->walk_step *	cos ((s->angle_ini - 90) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 270)
	{
		x = s->px - (s->walk_step * cos ((s->angle_ini - 180) * M_PI / 180.0));
		y = s->py - (s->walk_step *	sin ((s->angle_ini - 180) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 360)
	{
		x = s->px + (s->walk_step * sin ((s->angle_ini - 270) * M_PI / 180.0));
		y = s->py - (s->walk_step *	cos ((s->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(s, x, y);
}

void	ft_walk_backward(t_list *s)
{
	
	double	x;
	double	y;

	if (s->angle_ini <= 90)
	{
		x = s->px - (s->walk_step * cos (s->angle_ini * M_PI / 180.0));
		y = s->py - (s->walk_step *	sin (s->angle_ini * M_PI / 180.0));
	}
	else if (s->angle_ini <= 180)
	{
		x = s->px + (s->walk_step * sin ((s->angle_ini - 90) * M_PI / 180.0));
		y = s->py - (s->walk_step *	cos ((s->angle_ini - 90) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 270)
	{
		x = s->px + (s->walk_step * cos ((s->angle_ini - 180) * M_PI / 180.0));
		y = s->py + (s->walk_step *	sin ((s->angle_ini - 180) * M_PI / 180.0));
	}
	else if (s->angle_ini <= 360)
	{
		x = s->px - (s->walk_step * sin ((s->angle_ini - 270) * M_PI / 180.0));
		y = s->py + (s->walk_step *	cos ((s->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(s, x, y);
}
