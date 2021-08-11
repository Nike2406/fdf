/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:12:58 by prochell          #+#    #+#             */
/*   Updated: 2021/08/11 14:13:29 by prochell         ###   ########.fr       */
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

void	isometric(t_fdf *data)
{
	data->x = (data->x - data->y) * cos(0.8);
	data->y = (data->x + data->y) * sin(0.8) - data->z * data->cof_z;
	data->x1 = (data->x1 - data->y1) * cos(0.8);
	data->y1 = (data->x1 + data->y1) * sin(0.8) - data->z1 * data->cof_z;
}

void	get_color(t_fdf *data)
{
	if (data->z || data->z1)
	{
		data->color = 0xFFCF40;
	}
	else
		data->color = 0x8243D6;
}

void	bresenham(t_fdf *data)
{
	float	x_step;
	float	y_step;
	long	max;

	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];

	// Zoom
	// float coeff = data->zoom / data->cof_z;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->z *= data->zoom / 2;
	data->z1 *= data->zoom / 2;


	// Rotate
	// rotate_x(data);
	// rotate_y(data);
	// rotate_z(data);

	// Isometric
	isometric(data);


	// Centering
	data->x += 400;
	data->y += 300;
	data->x1 += 400;
	data->y1 += 300;

	// Shift
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;

	x_step = data->x1 - data->x; // -2
	y_step = data->y1 - data->y; // -11
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;

	// double start_x = data->x;
	// double start_y = data->x;

	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		if ((data->x >= 0 && data->x <= data->img_width) && \
		(data->y >= 0 && data->y < data->img_height))
		{
			get_color(data);
			my_mlx_pixel_put(data, data->x, data->y, data->color);
		}
		data->x += x_step;
		data->y += y_step;
	}
}

void	pre_brase(int f, double x, double y, t_fdf *data)
{
	data->x = x;
	data->y = y;
	if (!f)
	{
		data->x1 = x + 1;
		data->y1 = y;
	}
	else
	{
		data->x1 = x;
		data->y1 = y + 1;
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
			{
				pre_brase(0, x, y, data);
				bresenham(data);
			}
			if (y < data->height - 1)
			{
				pre_brase(1, x, y, data);
				bresenham(data);
			}
			x++;
		}
		y++;
	}
}
