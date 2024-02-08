#include "../include/cub3d.h"

void	ft_destroy(t_list *s)
{
	mlx_clear_window(s->mlx, s->window);
	mlx_destroy_window(s->mlx, s->window);
}

int	ft_close_window(t_list *s)
{
	(void)s;
	printf("You close the window\n");
	return (0);
}

int	ft_key_press(int keycode, t_list *s)
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
}

void	ft_hook(t_list *s)
{
	mlx_hook(s->window, 17, 1, ft_close_window, s);
	mlx_hook(s->window, 2, 1, ft_key_press, s);
}

void	ft_star_game(t_list *s)
{
	s->mlx = mlx_init();
	s->window = mlx_new_window(s->mlx, (int)640,
			(int)480, "Cub3D");
	ft_hook(s);
	mlx_loop(s->mlx);
}
