/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:02 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 17:39:42 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	**ft_pam(t_data *d, char **map)
{
	int		len;
	int		slen;
	int		i;
	int		j;
	int		k;

	len = 0;
	while (map[0][len])
		len++;
	slen = 0;
	while (map[slen])
		slen++;
	d->pam = malloc (sizeof(char *) * (len + 1));
	d->pam[len] = NULL;
	i = 0;
	while (i < len)
	{
		k = 0;
		j = slen - 1;
		d->pam[i] = malloc (sizeof(char) * (slen + 1));
		while (j >= 0)
			d->pam[i][k++] = map[j--][i];
		d->pam[i][k] = '\0';
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_set_texture_color(t_data *d, int j, int p)
{
	double	x;
	int		y;

	if (d->texture == 'x')
	{
		x = 300 * (d->ry - floor(d->ry));
		y = (300 * p) / j;
		return (d->active.addr[(300 * y) + (int)x]);
	}
	else if (d->texture == 'y')
	{
		x = 300 * (d->rx - floor(d->rx));
		y = (300 * p) / j;
		return (d->active.addr[(300 * y) + (int)x]);
	}
	return (0);
}

void	ft_create_line(t_data *d, int x)
{
	int	j;
	int	y;
	int	k;
	int	p;

	j = (int)(480 / d->dist);
	d->correct = j - 480;
	if (d->correct < 0)
		d->correct = 0;
	y = 0;
	while (y < (480 - j) / 2)
		my_mlx_pixel_put(d, x, y++, 0x000000FF);
	k = y + j;
	p = 0;
	while (y < 480 && y < k)
	{
		my_mlx_pixel_put(d, x, y++, \
		ft_set_texture_color(d, j, p++ + (d->correct / 2)));
	}
	while (y < 480)
		my_mlx_pixel_put(d, x, y++, 0x001CE507);
}

int	ft_move(t_data *d)
{
	int	i;

	i = 749;
	d->angle = d->angle_ini - 33;
	while (i >= 0)
	{
		if (d->angle < 0)
			d->angle += 360;
		if (d->angle <= 90 && i >= 0)
			i = ft_move_q1(d, i);
		else if (d->angle <= 180 && i >= 0)
			i = ft_move_q2(d, i);
		else if (d->angle <= 270 && i >= 0)
			i = ft_move_q3(d, i);
		else if (d->angle <= 360 && i >= 0)
			i = ft_move_q4(d, i);
		if (d->angle_ini < 0)
			d->angle_ini += 360;
		else if (d->angle_ini > 360)
			d->angle_ini -= 360;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}
