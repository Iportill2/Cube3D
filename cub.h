/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:06:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/13 17:45:38 by jgoikoet         ###   ########.fr       */
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

/* typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img; */
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
	void	*norte;

	int 	correct;
}				t_data;


char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_enredando_1(t_data *d);
int		ft_enredando_4(t_data *d);
void	ft_screen(t_data *d);
void	ft_create_line(t_data *d, int x);
int		ft_enredando_torcido(t_data *d);
int		ft_move(t_data *d);
int 	ft_move_q1(t_data *d, int i);
int 	ft_move_q2(t_data *d, int i);
int 	ft_move_q3(t_data *d, int i);
int 	ft_move_q4(t_data *d, int i);

void	ft_walk_forward(t_data *d);
void	ft_walk_backward(t_data *d);
void	ft_walk_left(t_data *d);
void	ft_walk_right(t_data *d);

#endif