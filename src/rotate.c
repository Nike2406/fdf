/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:07:46 by prochell          #+#    #+#             */
/*   Updated: 2021/08/14 21:53:27 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

///
void	rotate_x(t_dot *p, t_dot *p1, t_fdf *data, double alpha)
{
	float	y_last;
	float	y_last1;
	(void)data;

	y_last = p->y - ((data->height * data->zoom) / 2);
	p->y = y_last * cos(alpha) + p->z * sin(alpha);
	p->z = -y_last * sin(alpha) + p->z * cos(alpha);
	y_last1 = p1->y - ((data->height * data->zoom ) / 2);
	p1->y = y_last1 * cos(alpha) + p1->z * sin(alpha);
	p1->z = -y_last1 * sin(alpha) + p1->z * cos(alpha);
}

void	rotate_y(t_dot *p, t_dot *p1, t_fdf *data, double alpha)
{
	float	x_last;
	float	x_last1;
	(void)data;

	x_last = p->x - ((data->width * data->zoom) / 2);
	p->x = x_last * cos(alpha) + p->z * sin(alpha);
	p->z = -x_last * sin(alpha) + p->z * cos(alpha);
	x_last1 = p1->x - ((data->width * data->zoom) / 2);
	p1->x = x_last1 * cos(alpha)+ p1->z * sin(alpha);
	p1->z = -x_last1 * sin(alpha) + p1->z * cos(alpha);
}

void	rotate_z(t_dot *p, t_dot *p1, double alpha)
{
	float	x_last;
	float	y_last;
	float	x_last1;
	float	y_last1;

	x_last = p->x;
	y_last = p->y;
	p->x = x_last * cos(alpha) + y_last * sin(alpha);
	p->y = -x_last * sin(alpha) + y_last * cos(alpha);
	x_last1 = p1->x;
	y_last1 = p1->y;
	p1->x = x_last1 * cos(alpha) + y_last1 * sin(alpha);
	p1->y = -x_last1 * sin(alpha) + y_last1 * cos(alpha);
}

// parallell
/*
void	rotate_x(t_dot *p, t_dot *p1, t_fdf *data, double alpha)
{
	float	y_last;
	float	y_last1;

	y_last = p->y - ((data->height * data->zoom) / 2);
	p->y = y_last * cos(alpha);// + p->z * sin(alpha);
	y_last1 = p1->y - ((data->height * data->zoom ) / 2);
	p1->y = y_last1 * cos(alpha);// + p1->z * sin(alpha);
}

void	rotate_y(t_dot *p, t_dot *p1, t_fdf *data, double alpha)
{
	float	x_last;
	float	x_last1;

	x_last = p->x - ((data->width * data->zoom) / 2);
	p->x = x_last * cos(alpha);// + p->z * sin(alpha);
	x_last1 = p1->x - ((data->width * data->zoom) / 2);
	p1->x = x_last1 * cos(alpha);// + p1->z * sin(alpha);
}
void	rotate_z(t_dot *p, t_dot *p1, double alpha)
{
	float	x_last;
	float	y_last;
	float	x_last1;
	float	y_last1;

	x_last = p->x;
	y_last = p->y;
	p->x = x_last * cos(alpha) + y_last * sin(alpha);
	p->y = -x_last * sin(alpha) + y_last * cos(alpha);
	x_last1 = p1->x;
	y_last1 = p1->y;
	p1->x = x_last1 * cos(alpha) + y_last1 * sin(alpha);
	p1->y = -x_last1 * sin(alpha) + y_last1 * cos(alpha);
}
*/

