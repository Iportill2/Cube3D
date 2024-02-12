#include "../include/cub3d.h"

int	ft_move(t_list *s)
{
	int	i;

	i = 749;
	s->angle = s->angle_ini - 33;
	while (i >= 0)
	{
		//printf("Hola\n");
		if (s->angle < 0)
			s->angle += 360;	
		if (s->angle <= 90 && i >=0)
			i = ft_move_q1(s, i);
		else if (s->angle <= 180 && i >=0)
			i = ft_move_q2(s, i);
		else if (s->angle <= 270 && i >=0)
			i = ft_move_q3(s, i);
		else if (s->angle <= 360 && i >=0)
			i = ft_move_q4(s, i);
		if (s->angle_ini < 0)
			s->angle_ini += 360;
		else if (s->angle_ini > 360)
			s->angle_ini -= 360;
	}
	printf("d->angle_ini: %f\n", s->angle_ini);
	printf("x = %f, y = %f\n", s->px, s->py);
	mlx_put_image_to_window(s->mlx, s->mlx_win, s->img, 0, 0);
	return (0);
}