/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:12:58 by prochell          #+#    #+#             */
/*   Updated: 2021/08/13 20:27:30 by prochell         ###   ########.fr       */
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
	// (void)data->cof_z;
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - p->z * data->cof_z;
	p1->x = (p1->x - p1->y) * cos(0.8);
	p1->y = (p1->x + p1->y) * sin(0.8) - p1->z * data->cof_z;

	// rotate_test(p, p1, data);
	// float y_last;
	// float y_last1;
	// // data->alpha = data->rotate_x;
	// y_last = p->y - ((data->height - 1) / 2);
	// p->y = y_last * cos(data->alpha) + p->z * sin(data->alpha);
	// p->z = -y_last * sin(data->alpha) + p->z * cos(data->alpha);
	// y_last1 = p1->y - ((data->height - 1) / 2);
	// p1->y = y_last1 * cos(data->alpha) + p1->z * sin(data->alpha);
	// p1->z = -y_last1 * sin(data->alpha) + p1->z * cos(data->alpha);
}

void	get_color(t_dot *p, t_dot *p1)
{
	if (p->z)
		p->color = 0xFFCF40;
	else if (p1->z)
		p->color = 0xFFCF40;
	else
	{
		p->color = 0x8243D6;
		p1->color = 0x8243D6;
	}
}

void	get_position(t_fdf *data, t_dot *p, t_dot *p1)
{
	p->z = data->matrix[(int)p->y][(int)p->x];
	p1->z = data->matrix[(int)p1->y][(int)p1->x];

	get_color(p, p1); // step

	// Zoom
	p->x *= data->zoom;
	p->y *= data->zoom;
	p1->x *= data->zoom;
	p1->y *= data->zoom;
	p->z *= data->zoom / 2;
	p1->z *= data->zoom / 2;

	if (data->origin)
	{
		data_preset(data);
		render(data);
		data->origin = 0;
		return ;
	}

	// Isometric
	if (data->proection_flag)
	{
		isometric(data, p, p1);
		// data->proection_flag = 0;
	}

	// Rotate
	rotate_x(p, p1, data, data->rotate_x);
	rotate_y(p, p1, data, data->rotate_y);
	rotate_z(p, p1, data->rotate_z);

	// Centering
	p->x += data->img_width / 2;
	p->y += data->img_width / 2;
	p1->x += data->img_width / 2;
	p1->y += data->img_width / 2;

	// Shift
	p->x += data->shift_x;
	p1->x += data->shift_x;
	p->y += data->shift_y;
	p1->y += data->shift_y;

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
