/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:53:56 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 20:41:07 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	show_tab(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 50, \
		0xFA5882, "Ho to use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, \
		0x0000ffff, "Move:           use wasd or direction keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 130, \
		 0x0000ffff, "Rotation:       use numpad, where");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 160, \
		 0x0040FF, "OX - 4 & 6");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 190, \
		 0x0040FF, "OY - 2 & 8");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 130, 220, \
		 0x0040FF, "OZ - 7 & 9");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 250, \
		 0x0000ffff, "Actually, you can use mouse for a while =)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 280, \
		 0x0000ffff, "Zoom:           \"+\" & \"-\" on both puds...");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 310, \
		 0x0000ffff, "	... and you can use mouse scroll.");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 340, \
		 0x0000ffff, "Perspective:    space");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 370, \
		 0x0000ffff, "Origin state:   num-5");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 420, \
		 0xFA5882, "To hide this message press \"h\" or a \"?\"");
}

void	isometric(t_fdf *data, t_dot *p, t_dot *p1)
{
	(void)data->cof_z;

	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - p->z;// * data->cof_z;
	p1->x = (p1->x - p1->y) * cos(0.8);
	p1->y = (p1->x + p1->y) * sin(0.8) - p1->z;// * data->cof_z;
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

	// Depth
	// if (p->z > 0 || p1->z > 0)
	// {
	// 	p->z *= data->cof_z;
	// 	p1->z *= data->cof_z;
	// }

	get_color(p, p1); // step

	if (!data->proection_flag)
	{
		p->z = 0;
		p1->z = 0;
	}
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
	change_position(data, p, p1);
}

void	change_position(t_fdf *data, t_dot *p, t_dot *p1)
{
	// Rotate
	rotate_x(p, p1, data, data->rotate_x);
	rotate_y(p, p1, data, data->rotate_y);
	rotate_z(p, p1, data->rotate_z);

	// Isometric
	if (data->proection_flag)
		isometric(data, p, p1);

	// Centering
	p->x += data->img_width / 2;
	p->y += data->img_height / 2;
	p1->x += data->img_width / 2;
	p1->y += data->img_height / 2;

	// Shift
	p->x += data->shift_x;
	p1->x += data->shift_x;
	p->y += data->shift_y;
	p1->y += data->shift_y;
}
