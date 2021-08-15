/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 15:55:25 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Error\n");
	exit(code);
	return (1);
}

void	data_preset(t_fdf *data)
{
	data->cof_z = 0.1;
	data->img_height = 1000;
	data->img_width = 1500;
	data->zoom = (MAX(data->img_height, data->img_width) \
		 / MAX(data->height, data->width)) * 0.6;
	if (data->zoom < 2)
		data->zoom = 2;
	data->color = 0xFFFFFF;
	data->left_butt = 0;
	data->render_flag = 0;
	data->rotate_x = 0;
	data->rotate_y = 0;
	data->rotate_z = 0;
	data->shift_x = 0;
	data->shift_y = 0;
	data->origin = 0;
	if (data->clue)
		data->clue = 1;
	else
		data->clue = 0;
	if (data->proection_flag)
		data->proection_flag = 1;
	else
		data->proection_flag = 0;
}

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
