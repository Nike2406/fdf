/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:07:46 by prochell          #+#    #+#             */
/*   Updated: 2021/08/12 03:00:48 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_test(t_dot *p, t_dot *p1, t_fdf *data)
{
	float	y_last;
	float	y_last1;
	// double	alpha;

	y_last = p->y - ((data->height - 1) / 2);
	p->y = y_last * cos(data->alpha) + p->z ;
	p->z = -y_last * sin(data->alpha) + p->z;
	y_last1 = p1->y - ((data->height - 1) / 2);
	p1->y = y_last1 * cos(data->alpha) + p1->z;
	p1->z = -y_last1 * sin(data->alpha) + p1->z;
}

void	rotate_x(t_dot *p, t_dot *p1, t_fdf *data)
{
	float	y_last;
	float	y_last1;
	// double	alpha;

	// alpha = data->rotate_x;
	y_last = p->y - ((data->height - 1) / 2);
	p->y = y_last * cos(data->alpha) + p->z * sin(data->alpha);
	p->z = -y_last * sin(data->alpha) + p->z * cos(data->alpha);
	y_last1 = p1->y - ((data->height - 1) / 2);
	p1->y = y_last1 * cos(data->alpha) + p1->z * sin(data->alpha);
	p1->z = -y_last1 * sin(data->alpha) + p1->z * cos(data->alpha);
}

void	rotate_y(t_dot *p, t_dot *p1, t_fdf *data)
{
	float	x_last;
	float	x_last1;
	// double	alpha;

	// alpha = data->rotate_y;
	x_last = p->x - ((data->width - 1) / 2);
	p->x = x_last * cos(data->alpha) + p->z * sin(data->alpha);
	p->z = -x_last * sin(data->alpha) + p->z * cos(data->alpha);
	x_last1 = p1->x - ((data->width - 1) / 2);
	p1->x = x_last1 * cos(data->alpha) + p1->z * sin(data->alpha);
	p1->z = -x_last1 * sin(data->alpha) + p1->z * cos(data->alpha);
}

void	rotate_z(t_dot *p, t_dot *p1, t_fdf *data)
{
	float	x_last;
	float	y_last;
	float	x_last1;
	float	y_last1;
	// double	data->alpha;

	// data->alpha = data->rotate_z;
	(void)data;
	x_last = p->x;
	y_last = p->y;
	p->x = x_last * cos(data->alpha) + y_last * sin(data->alpha);
	p->y = -x_last * sin(data->alpha) + y_last * cos(data->alpha);
	x_last1 = p1->x;
	y_last1 = p1->y;
	p1->x = x_last1 * cos(data->alpha) + y_last1 * sin(data->alpha);
	p1->y = -x_last1 * sin(data->alpha) + y_last1 * cos(data->alpha);
}