/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:52:46 by prochell          #+#    #+#             */
/*   Updated: 2021/08/10 21:47:30 by prochell         ###   ########.fr       */
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

	struct	s_col	trgb;
	double	x;
	double	y;
	int	z;
	double	x1;
	double	y1;
	int	z1;


	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		deal_key(int key, t_fdf *data);
int		deal_mouse(int key, int x, int y, t_fdf *data);
int		mouse_up(int key, int x, int y, t_fdf *data);
int		mouse_move(int x, int y, t_fdf *data);
void	pre_brase(int f, double x, double y, t_fdf *data);
void	bresenham(t_fdf *data);
void	draw(t_fdf *data);
void	isometric(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	render(t_fdf *data);
int		get_color(t_fdf *data, double start_x, double start_y);
void	get_hook(t_fdf *data);
void	show_tab(t_fdf *data);

void	rotate_x(t_fdf *data);
void	rotate_y(t_fdf *data);
void	rotate_z(t_fdf *data);

// int		create_trgb(t_col *col);
// int		get_t(int trgb);
// int		get_r(int trgb);
// int		get_g(int trgb);
// int		get_b(int trgb);
t_col	get_col(int	trgb);
t_col	val_shift(t_col *a, t_col *b, int step);
void	plus_shift(t_col *a, t_col *shift);

//Ilrech
int	create_trgb(int r, int g, int b);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);


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
