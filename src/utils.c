/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/08/11 14:06:13 by prochell         ###   ########.fr       */
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
	data->zoom = 40;
	data->cof_z = 0.5;
	data->img_height = 1000;
	data->img_width = 1000;
	data->color = 0xFFFFFF;
	data->left_butt = 0;
	data->render_flag = 0;
	data->x = 0;
	data->x1 = 0;
	data->y = 0;
	data->y1 = 0;
	data->z = 0;
	data->z1 = 0;
}
