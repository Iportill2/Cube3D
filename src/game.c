#include "../include/cub3d.h"

 void	ft_destroy(t_data *d)
{
	mlx_clear_window(d->mlx, d->window);
	mlx_destroy_window(d->mlx, d->window);
}

int	ft_close_window(t_data *d)
{
	(void)d;
	printf("You close the window\n");
	return (0);
}

/* int	ft_key_press(int keycode, t_data *d)
{
	(void)s;
	if (keycode == Q || keycode == ESC)
	{
		ft_destroy(s);
		printf("You close the window\n");
		exit(0);
	}
	else if (keycode == W)
		printf("");
	else if (keycode == D)
		printf("");
	else if (keycode == A)
		printf("");
	else if (keycode == S)
		printf("");
	return (0);
} */

void	ft_hook(t_data *d)
{
	mlx_hook(d->window, 17, 1, ft_close_window, d);
	mlx_hook(d->window, 2, 1, ft_key_hook, d);
}

void	ft_star_game(t_data *d)
{
	ft_screen(d);
} 