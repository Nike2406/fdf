/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/08/12 00:15:43 by prochell         ###   ########.fr       */
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
	data->cof_z = 0.1;
	data->img_height = 1000;
	data->img_width = 1000;
	data->color = 0xFFFFFF;
	data->left_butt = 0;
	data->render_flag = 0;
	data->rotate_x = 0;
	data->rotate_y = 0;
	data->rotate_z = 0;
	data->alpha = 0.8;
}
