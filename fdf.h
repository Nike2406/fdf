/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:52:46 by prochell          #+#    #+#             */
/*   Updated: 2021/08/13 14:35:30 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h> // Del
# include <math.h>
# include "./minilibx_macos/mlx.h"

typedef struct s_col
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_col;

typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_dot;


typedef struct s_fdf
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		**matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	cof_z;
	int		img_width;
	int		img_height;
	int		left_butt;
	int		render_flag;

	// float	beta;

	float	rotate_x;
	float	rotate_y;
	float	rotate_z;
	int		mouse_x;
	int		mouse_y;
	int		mouse_prev_x;
	int		mouse_prev_y;

	int		origin;

	struct	s_col	trgb;
	// double	x;
	// double	y;
	// int		z;
	// double	x1;
	// double	y1;
	// int		z1;


	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		deal_key(int key, t_fdf *data);
int		deal_mouse(int key, int x, int y, t_fdf *data);
int		mouse_up(int key, int x, int y, t_fdf *data);
int		mouse_move(int x, int y, t_fdf *data);
void	pre_brase(int f, t_dot *p, t_dot *p1, int x, int y);
void	bresenham(t_fdf *data, t_dot *p, t_dot *p1);
void	get_position(t_fdf *data, t_dot *p, t_dot *p1);
void	draw(t_fdf *data);
void	isometric(t_fdf *data, t_dot *p, t_dot *p1);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	render(t_fdf *data);
void	get_hook(t_fdf *data);
void	show_tab(t_fdf *data, t_dot *p);

void	rotate_x(t_dot *p, t_dot *p1, t_fdf *data, double alpha);
void	rotate_y(t_dot *p, t_dot *p1, t_fdf *data, double alpha);
void	rotate_z(t_dot *p, t_dot *p1, double alpha);

void	get_color(t_dot *p, t_dot *p1);

void	read_file(char *file_name, t_fdf *data);
void	fill_matrix(int *z_line, char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);
int		prefill(int fd, t_fdf *data, int j);

int		ft_err(int	code);
void	data_preset(t_fdf *data);
float	MAX(float a, float b);
float	MOD(float a);

#endif
