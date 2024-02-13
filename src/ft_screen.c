#include "../include/cub3d.h"

static void	ft_set_player_coord(t_list *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->pam[i])
	{
		j = 0;
		while(s->pam[i][j])
		{
			if (s->pam[i][j] == 'N')
			{
				s->px = i + 0.5;
				s->py = j + 0.5;
				return;
			}
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_list *s, int x, int y, int color)
{
	char	*dst;

	dst = s->addr + (y * s->line_length + x * (s->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* void	ft_create_line(t_data *d, int x)
{
	int	j;
	int	y;
	int k;

	j = (int)(480 / d->dist);
	if (j > 480)
		j = 480;
	y = 0;
	 while (y < (480 - j) / 2)
		my_mlx_pixel_put(d, x, y++, 0x00000099);
	k = y + j;
	while (y < k)
		my_mlx_pixel_put(d, x, y++, d->color);
	while (y < 480)
		my_mlx_pixel_put(d, x, y++, 0x00000000);
} */

void	ft_create_line(t_list *s, int x)
{
	int	j;
	int	y;
	int k;

	j = (int)(480 / s->dist);
	if (j > 480)
		j = 480;
	y = 0;
	 while (y < (480 - j) / 2)
		my_mlx_pixel_put(s, x, y++, 0x00000099);
	k = y + j;
	while (y < k)
		my_mlx_pixel_put(s, x, y++, s->color);
	while (y < 480)
		my_mlx_pixel_put(s, x, y++, 0x00000000);
}

int	ft_key_hook(int keycode, t_list *s)
{
	if (keycode == Q || keycode == ESC)
	{
		ft_destroy(s);
		printf("You close the window\n");
		exit(0);
	}
	if (keycode == LEFTKEY)
		s->angle_ini += s->rotate_step;
	if (keycode == RIGHTKEY)
		s->angle_ini -= s->rotate_step;
	if (keycode == DOWNKEY || keycode == S)
		ft_walk_backward(s);
	if (keycode == UPKEY || keycode == W)
		ft_walk_forward(s);
	if (keycode == A)
		ft_walk_left(s);
	if (keycode == D)
		ft_walk_right(s);
	return (0);
}

void	ft_charge_image(t_list *s)
{
	int	x;
	int	y;

	x = 300;
	y = 300;
	s->nx.img  = mlx_xpm_file_to_image(s->mlx, "textures/Iker.xpm", &x, &y);
	if(!s->nx.img)
	{
		printf("ERROR cargando texturas!!\n");
		exit(1);
	}
	s->nx.addr = (int *) mlx_get_data_addr(s->nx.img, &s->nx.bits_per_pixel,
			&s->nx.line_length, &s->nx.endian);
	s->nx.line_length = s->nx.line_length / 4;
	//printf("line lenght:%i\n", d->n.line_length);
	int i = 0;
	while (i < 1000)
		printf("%i\n", s->nx.addr[i++]);
}


void	ft_screen(t_list *s)
{
	ft_set_player_coord(s);
 	s->walk_step = 0.07;
	s->rotate_step = 5;
	s->angle_ini = 180;
	s->mlx = mlx_init();
	ft_charge_image(s);
	s->mlx_win = mlx_new_window(s->mlx, 750, 480, "cube3D");
	s->img = mlx_new_image(s->mlx, 750, 480);
	s->addr = mlx_get_data_addr(s->img, &s->bits_per_pixel, &s->line_length, &s->endian);
	mlx_loop_hook(s->mlx, ft_move, s);
	//mlx_key_hook(s->mlx_win, ft_key_hook, s);//
	mlx_hook(s->mlx_win, 2, (1L << 0), ft_key_hook, s);//
	mlx_loop(s->mlx);
}

/* int	ft_press_key(int key, void *param)
{
	t_data	*dt;

	dt = (t_data *)param;
	if (key == RIGHTKEY)
		dt->move.rright = 1;
	else if (key == LEFTKEY)
		dt->move.rleft = 1;
	else if ((key == DOWNKEY || key == 1))
		dt->move.mback = 1;
	else if ((key == UPKEY || key == 13))
		dt->move.mfor = 1;
	else if (key == 2)
		dt->move.mright = 1;
	else if (key == 0)
		dt->move.mleft = 1;
	else if (key == 53)
		ft_close(param);
	return (0);
}

int	ft_release_key(int key, void *param)
{
	t_data	*dt;

	dt = (t_data *)param;
	if (key == RIGHTKEY)
		dt->move.rright = 0;
	else if (key == LEFTKEY)
		dt->move.rleft = 0;
	else if ((key == DOWNKEY || key == 1))
		dt->move.mback = 0;
	else if ((key == UPKEY || key == 13))
		dt->move.mfor = 0;
	else if (key == 2)
		dt->move.mright = 0;
	else if (key == 0)
		dt->move.mleft = 0;
	return (0);
} */

/*
int	ft_key_hook(int keycode, t_data *d)
{
	if (keycode == 124)
		d->angle_ini -= d->rotate_step;
	if (keycode == 123)
		d->angle_ini += d->rotate_step;
	if (keycode == 126 || keycode == 13)
		ft_walk_forward(d);
	if (keycode == 125 || keycode == 1)
		ft_walk_backward(d);
	if (keycode == 0)
		ft_walk_left(d);
	if (keycode == 2)
		ft_walk_right(d);
	return (0);
}
*/