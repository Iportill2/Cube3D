/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:53:13 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/09 16:23:52 by jgoikoet         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_create_line(t_data *d, int x)
{
	int	j;
	int	y;
	int k;

	j = (int)(480 / d->dist);
	if (j > 480)
		j = 480;
	y = 0;
	 while (y < (480 - j) / 2)
		my_mlx_pixel_put(d, x, y++, 0x000000BB);
	k = y + j;
	while (y < k)
		my_mlx_pixel_put(d, x, y++, d->color);
	while (y < 480)
		my_mlx_pixel_put(d, x, y++, 0x00000000);
}
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

void	ft_screen(t_data *d)
{
	ft_set_player_coord(d);
	d->walk_step = 0.07;
	d->rotate_step = 5;
	d->angle_ini = 180;
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, 750, 480, "cube3D");
	d->img = mlx_new_image(d->mlx, 750, 480);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
	mlx_loop_hook(d->mlx, ft_move, d);
	//mlx_loop_hook(d->mlx, ft_enredando_torcido, d);
	mlx_key_hook(d->mlx_win, ft_key_hook, d);
	//ft_enredando_torcido(d);
	//mlx_hook(d->mlx_win, 17, 0, ft_free, &d);
	mlx_loop(d->mlx);
}
