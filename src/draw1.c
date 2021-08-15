/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:12:58 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 16:03:53 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham(t_fdf *data, t_dot *p, t_dot *p1)
{
	double	x_step;
	double	y_step;
	long	max;

	get_position(data, p, p1);

	x_step = p1->x - p->x;
	y_step = p1->y - p->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
	{
		if ((p->x >= 0 && p->x <= data->img_width) && \
		(p->y >= 0 && p->y < data->img_height))
			my_mlx_pixel_put(data, p->x, p->y, p->color);
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
