/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:24 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/15 11:56:53 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_walk_colision(t_data *d, double x, double y)
{
	/* int	xx;
	int	yy;

	xx = x;
	yy = y;  */
	if (d->pam[(int)x][(int)y] != '1')//OJO con '-'
	{
		d->px = x;
		d->py = y;
	}
}

void	ft_walk_left(t_data *d)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	if (d->angle_ini <= 90)
	{
		x = d->px - (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
		y = d->py + (WALK_STEP *	cos (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		x = d->px - (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
		y = d->py - (WALK_STEP *	sin ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		x = d->px + (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
		y = d->py - (WALK_STEP *	cos ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		x = d->px + (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
		y = d->py + (WALK_STEP *	sin ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, x, y);
}
void	ft_walk_right(t_data *d)
{
	double	x;
	double	y;
	 
	x = 0.0;
	y = 0.0;
		if (d->angle_ini <= 90)
	{
		x = d->px + (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
		y = d->py - WALK_STEP *	cos (d->angle_ini * M_PI / 180.0);
	}
	else if (d->angle_ini <= 180)
	{
		x = d->px +  (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
		y = d->py + (WALK_STEP *	sin ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		x = d->px - (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
		y = d->py + (WALK_STEP *	cos ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		x = d->px - (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
		y = d->py - (WALK_STEP *	sin ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, x, y);
}
void	ft_walk_forward(t_data *d)
{
	double	x;
	double	y;
	x = 0.0;
	y = 0.0;
	if (d->angle_ini <= 90)
	{
		x = d->px + (WALK_STEP * cos (d->angle_ini * M_PI / 180.0));
		y = d->py + (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		x = d->px - (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
		y = d->py + (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		x = d->px - (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
		y = d->py - (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		x = d->px + (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
		y = d->py - (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, x, y);
}

void	ft_walk_backward(t_data *d)
{
	
	double	x;
	double	y;
	x = 0.0;
	y = 0.0;
	if (d->angle_ini <= 90)
	{
		x = d->px - (WALK_STEP * cos (d->angle_ini * M_PI / 180.0));
		y = d->py - (WALK_STEP *	sin (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		x = d->px + (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
		y = d->py - (WALK_STEP *	cos ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		x = d->px + (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
		y = d->py + (WALK_STEP *	sin ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		x = d->px - (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
		y = d->py + (WALK_STEP *	cos ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, x, y);
}
