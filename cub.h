/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:06:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 16:18:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}			t_img;

typedef struct s_data
{
	int		color;
	char	**map;
	char	**pam;
	double	px;
	double	py;
	double	rx;
	double	ry;

	double	walk_step;
	double	rotate_step;

	double	dis_x;
	double	dis_y;
	double	angle_ini;
	double	angle_dist_rad;
	double	angle;
	double	angle_rad;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	adyacent;
	double	opposit;
	double	hypo_x;
	double	hypo_y;

	double	dist_ini;
	double	dist;

	double	closer;

	int		contact;

	char	texture;

	t_img	n;
	t_img	s;
	t_img	e;
	t_img	w;
	t_img	active;

	int		correct;
}				t_data;

/*MAIN*/
int		main(int argc, char **argv);
int		ft_maplen(char *s);
char	**ft_pam(char **map);

/*FT_WALK*/
void	ft_walk_backward(t_data *d);
void	ft_walk_forward(t_data *d);
void	ft_walk_right(t_data *d);
void	ft_walk_left(t_data *d);
void	ft_walk_colision(t_data *d, double x, double y);

/*FT_STRLEN*/
size_t	ft_strlen(const char *s);

/*FT_SPLIT*/
char	**ft_split(char const *s, char c);
/*y sus staticts*/

/*FT_SCREEN*/
void	ft_screen(t_data *d);
void	ft_charge_image(t_data *d);
int		ft_key_hook(int keycode, t_data *d);
void	ft_create_line(t_data *d, int x);
int		ft_set_texture_color(t_data *d, int j, int p);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_set_player_coord(t_data *d);
int		ft_free(t_data *d);

/*FT_MOVE*/
int		ft_move(t_data *d);

/*FT_MOVE_Q1*/
int		ft_move_q1(t_data *d, int i);
//static void	ft_check_contact(t_data *d);
//static void	ft_ray_y(t_data *d);
//static void	ft_ray_x(t_data *d)	;

/*FT_MOVE_Q2*/
int		ft_move_q2(t_data *d, int i);
//static void	ft_check_contact_y(t_data *d);
//static void	ft_check_contact_x(t_data *d);
//static void	ft_ray_y(t_data *d);
//static void	ft_ray_x(t_data *d);

/*FT_MOVE_Q3*/
int		ft_move_q3(t_data *d, int i);
//static void	ft_check_contact_y(t_data *d);
//static void	ft_check_contact_x(t_data *d);
//static void	ft_ray_y(t_data *d);
//static void	ft_ray_x(t_data *d);

/*FT_MOVE_Q4*/
int		ft_move_q4(t_data *d, int i);
//static void	ft_check_contact_y(t_data *d);
//static void	ft_check_contact_x(t_data *d);
//static void	ft_ray_y(t_data *d);
//static void	ft_ray_x(t_data *d);

#endif