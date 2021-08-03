/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:52:46 by prochell          #+#    #+#             */
/*   Updated: 2021/08/03 23:43:24 by prochell         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;


typedef struct s_fdf
{
	int	width;
	int	height;
	int	**matrix;
	int	zoom;
	int	color;
	int	shift_x;
	int	shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		deal_key(int key, t_fdf *data, t_mlx *img);
void	read_file(char *file_name, t_fdf *data);
void	fill_matrix(int *z_line, char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data, t_mlx *img);
void	draw(t_fdf *data, t_mlx *img);
void	isometric(float *x, float *y, int z);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

void	ft_err(int	code);
float	MAX(float a, float b);
float	MOD(float a);

#endif
