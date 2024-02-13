#include "../include/cub3d.h"

int	ft_move(t_data *d)
{
	int	i;

	i = 749;
	d->angle = d->angle_ini - 33;
	while (i >= 0)
	{
		if (d->angle < 0)
			d->angle += 360;	
		if (d->angle <= 90 && i >=0)
			i = ft_move_q1(d, i);
		else if (d->angle <= 180 && i >=0)
			i = ft_move_q2(d, i);
		else if (d->angle <= 270 && i >=0)
			i = ft_move_q3(d, i);
		else if (d->angle <= 360 && i >=0)
			i = ft_move_q4(d, i);
		if (d->angle_ini < 0)
			d->angle_ini += 360;
		else if (d->angle_ini > 360)
			d->angle_ini -= 360;
	}
/* 	printf("d->angle_ini: %f\n", d->angle_ini);
	printf("x = %f, y = %f\n", d->px, d->py); */
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}