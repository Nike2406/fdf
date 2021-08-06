/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:12:58 by prochell          #+#    #+#             */
/*   Updated: 2021/08/06 21:27:46 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	MOD(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	MAX(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z * data->cof_z;
}

void	get_color(t_fdf *data, float x, float y, float x1, float y1, int z, int z1)
{
	// Color
	// if (z || z1)
	// 	data->color = 0xFFCF40;
	// else
	// 	data->color = 0x8243D6;
	// int	tmp_color;
	// int	col1 = 0xFFCF40;
	// int	col2 = 0x8243D6;
	// float	coeff;


	(void)x;
	(void)y;
	(void)x1;
	(void)y1;
	(void)z;
	(void)z1;

	// data->color = 0x8243D6;
	// if (z)
	// 	data->color += z;
	// else if (z1)
	// 	data->color += z1;

	// coeff = sqrt((x1 - y1) * (x1 - y1)
	// 		+ (x - y) * (x - y))
	// 	/ sqrt((y - z1) * (y - z1)
	// 		+ (x - z) * (x - z));

	// data->color = create_trgb(0, get_r(col1) \
	// 		+ (get_r(col2) - get_r(col1)) * coeff, \
	// 		get_g(col1) + (get_g(col2) - get_g(col1)) * coeff, \
	// 		get_b(col1) + (get_b(col2) - get_b(col1)) * coeff);

	if (z || z1)
		data->color = 0xFFCF40;
	else
		data->color = create_trgb(0, 0, 255, 0);

}

// [1:1] [3:12]
void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];

	// Zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	// Isometric
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);

	// Centering
	x += 400;
	y += 300;
	x1 += 400;
	y1 += 300;

	// Shift
	x += data->shift_x;
	x1 += data->shift_x;
	y += data->shift_y;
	y1 += data->shift_y;

	x_step = x1 - x; // -2
	y_step = y1 - y; // -11
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(x - x1) || (int)(y - y1))
	{
		if ((x >= 0 && x <= data->img_width) && \
		(y >= 0 && y <= data->img_height))
		{
			get_color(data, x, y, x1, y1, z, z1);
			my_mlx_pixel_put(data, x, y, data->color);
		}
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
