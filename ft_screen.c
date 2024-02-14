/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:53:13 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 17:08:16 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_free(t_data *d)
{
	printf("-----------------GAME OVER-----------------\n\n");
	mlx_destroy_window(d->mlx, d->mlx_win);
	exit(0);
	return (0);
}

void	ft_set_player_coord(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->pam[i])
	{
		j = 0;
		while (d->pam[i][j])
		{
			if (d->pam[i][j] == 'N')
			{
				d->px = i + 0.5;
				d->py = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_key_hook(int keycode, t_data *d)
{
	if (keycode == 53)
		ft_free(d);
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

void	ft_charge_image(t_data *d)
{
	int	x;

	x = 300;
	d->n.img = mlx_xpm_file_to_image(d->mlx, "textures/iker.xpm", &x, &x);
	d->n.addr = (int *) mlx_get_data_addr(d->n.img, &d->n.bits_per_pixel,
			&d->n.line_length, &d->n.endian);
	d->s.img = mlx_xpm_file_to_image(d->mlx, "textures/goiko.xpm", &x, &x);
	d->s.addr = (int *) mlx_get_data_addr(d->s.img, &d->s.bits_per_pixel,
			&d->s.line_length, &d->s.endian);
	d->e.img = mlx_xpm_file_to_image(d->mlx, "textures/canita.xpm", &x, &x);
	d->e.addr = (int *) mlx_get_data_addr(d->e.img, &d->e.bits_per_pixel,
			&d->e.line_length, &d->e.endian);
	d->w.img = mlx_xpm_file_to_image(d->mlx, "textures/fary.xpm", &x, &x);
	d->w.addr = (int *) mlx_get_data_addr(d->w.img, &d->w.bits_per_pixel,
			&d->w.line_length, &d->w.endian);
}

void	ft_screen(t_data *d)
{
	ft_set_player_coord(d);
	d->walk_step = 0.07;
	d->rotate_step = 5;
	d->angle_ini = 90;
	d->mlx = mlx_init();
	ft_charge_image(d);
	d->mlx_win = mlx_new_window(d->mlx, 750, 480, "cube3D");
	d->img = mlx_new_image(d->mlx, 750, 480);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel,
			&d->line_length, &d->endian);
	mlx_loop_hook(d->mlx, ft_move, d);
	mlx_key_hook(d->mlx_win, ft_key_hook, d);
	mlx_hook(d->mlx_win, 17, 0, ft_free, &d);
	mlx_loop(d->mlx);
}
