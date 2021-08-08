/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:21:31 by prochell          #+#    #+#             */
/*   Updated: 2021/08/08 14:55:11 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_butt && x >= 0 && x <= data->img_width && \
		y >= 0 && y <= data->img_height)
	{
		printf("x - %d, y - %d, %f\n", x, y, data->x1);
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	(void)key;
	data->left_butt = 0;
	return (0);
}

int	deal_key(int key, t_fdf *data)
{
	// ft_putnbr(key);
	// ft_putchar('\n');
	if (key == 126 || key == 13)
		data->shift_y -= 10;
	else if (key == 125 || key == 1)
		data->shift_y += 10;
	else if (key == 124 || key == 2)
		data->shift_x += 10;
	else if (key == 123 || key == 0)
		data->shift_x -= 10;
	else if (key == 14)
		data->cof_z += 0.1;
	else if (key == 12)
		data->cof_z -= 0.1;
	else if (key == 69)
		data->zoom += 5;
	else if (key == 78)
	{
		if (data->zoom <= 1)
			return (0);
		else
			data->zoom -= 5;
	}
	else if (key == 53)
		exit(0);
	else
		return (0);
	render(data);
	return (0);
}

int	deal_mouse(int key, int x, int y, t_fdf *data)
{
	// ft_putnbr(key);
	// ft_putchar('\n');
	(void)x;
	(void)y;
	if (key == 4)
		data->zoom += 5;
	if (key == 5)
	{
		if (data->zoom <= 1)
			return (0);
		else
			data->zoom -= 5;
	}
	if (key == 1)
		data->left_butt = 1;
	render(data);
	return (0);
}
