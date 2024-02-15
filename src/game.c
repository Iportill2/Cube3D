#include "../include/cub3d.h"

 void	ft_destroy(t_data *d)
{
	mlx_clear_window(d->mlx, d->mlx_win);
	mlx_destroy_window(d->mlx, d->mlx_win);
}

int	ft_close_window(t_data *d)
{
	(void)d;
	printf("You close the window\n");
	return (0);
}

void	ft_hook(t_data *d)
{
	mlx_hook(d->mlx_win, 17, 1, ft_close_window, d);
	mlx_hook(d->mlx_win, 2, 1, ft_key_hook, d);
}

