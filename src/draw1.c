/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:12:58 by prochell          #+#    #+#             */
/*   Updated: 2021/08/12 00:18:26 by prochell         ###   ########.fr       */
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

void	isometric(t_fdf *data, t_dot *p, t_dot *p1)
{
	p->x = (p->x - p->y) * cos(data->alpha);
	p->y = (p->x + p->y) * sin(data->alpha) - p->z * data->cof_z;
	p1->x = (p1->x - p1->y) * cos(data->alpha);
	p1->y = (p1->x + p1->y) * sin(data->alpha) - p1->z * data->cof_z;
}

void	get_color(t_dot *p, t_dot *p1)
{
	if (p->z || p1->z)
	{
		p->color = 0xFFCF40;
	}
	else
		p->color = 0x8243D6;
}

void	get_position(t_fdf *data, t_dot *p, t_dot *p1)
{
	p->z = data->matrix[(int)p->y][(int)p->x];
	p1->z = data->matrix[(int)p1->y][(int)p1->x];

	// Zoom
	p->x *= data->zoom;
	p->y *= data->zoom;
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p->z *= data->zoom / 2;
	p1->z *= data->zoom / 2;

	// Rotate
	// rotate_x(p, p1, data);
	// rotate_y(p, p1, data);
	// rotate_z(p, p1, data);

	// Isometric
	isometric(data, p, p1);
	// Centering
	p->x += 400;
	p->y += 300;
	p1->x += 400;
	p1->y += 300;

	// Shift
	p->x += data->shift_x;
	p1->x += data->shift_x;
	p->y += data->shift_y;
	p1->y += data->shift_y;

	// rotate_x(p, p1, data);
	// rotate_y(p, p1, data);
	// rotate_z(p, p1, data);
}

void	bresenham(t_fdf *data, t_dot *p, t_dot *p1)
{
	double	x_step;
	double	y_step;
	long	max;

	// show_tab(data, p);
	get_position(data, p, p1);

	x_step = p1->x - p->x; // -2
	y_step = p1->y - p->y; // -11
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
	{
		if ((p->x >= 0 && p->x <= data->img_width) && \
		(p->y >= 0 && p->y < data->img_height))
		{
			get_color(p, p1);
			my_mlx_pixel_put(data, p->x, p->y, p->color);
		}
		p->x += x_step;
		p->y += y_step;
	}
}

void	pre_brase(int f, t_dot *p, t_dot *p1, int x, int y)
{
	p->x = x;
	p->y = y;
	if (!f)
	{
		p1->x = p->x + 1;
		p1->y = p->y;
	}
	else
	{
		p1->x = p->x;
		p1->y = p->y + 1;
	}
}

void	draw(t_fdf *data)
{
	t_dot	p;
	t_dot	p1;
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
				pre_brase(0, &p, &p1, x, y);
				bresenham(data, &p, &p1);
			}
			if (y < data->height - 1)
			{
				pre_brase(1, &p, &p1, x, y);
				bresenham(data, &p, &p1);
			}
			x++;
		}
		y++;
	}
}
