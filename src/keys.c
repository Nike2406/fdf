/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:21:31 by prochell          #+#    #+#             */
/*   Updated: 2021/08/12 01:33:34 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	if (data->left_butt && x >= 0 && x <= data->img_width && \
		y >= 0 && y <= data->img_height)
	{
		// if (x / 20 < data->mouse_x)
		// 	data->rotate_y += 0.05;
		// if (x / 20 < data->mouse_x)
		// 	data->rotate_y -= 0.05;
		// if (y / 20 > data->mouse_y)
		// 	data->rotate_x += 0.05;
		// if (y / 20 < data->mouse_y)
		// 	data->rotate_x -= 0.05;
		printf("x - %d, y - %d, \n", x, y);
	}
	draw(data);
	return (0);

	// data->mouse_prev_x = data->mouse_x;
	// data->mouse_prev_y = data->mouse_y;
	// data->mouse_x = x;
	// data->mouse_y = y;
	// if (data->left_butt && x >= 0 && x <= data->img_width && \
	// 	y >= 0 && y <= data->img_height)
	// {
	// 	data->rotate_x += (x - data->mouse_prev_x);
	// 	data->rotate_y += (y - data->mouse_prev_y);
	// 	draw(data);
	// 	printf("x - %d, y - %d, \n", x, y);
	// }
	// return (0);
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
		data->cof_z += 0.02;
	else if (key == 12)
		data->cof_z -= 0.02;
	else if (key == 91) // rotate start
	{
		data->alpha += 0.1;
		//up
	}
	else if (key == 88)
	{
		data->alpha += 0.1;
		//right
	}
	else if (key == 84)
	{
		data->alpha -= 0.1;
		//down
	}
	else if (key == 86) // rotate ends
	{
		data->alpha -= 0.1;
		//left
	}
	else if (key == 69)
		data->zoom += 4;
	else if (key == 78)
	{
		if (data->zoom <= 0)
			return (0);
		else
			data->zoom -= 4;
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
		data->zoom += 4;
	if (key == 5)
	{
		if (data->zoom <= 0)
			return (0);
		else
			data->zoom -= 4;
	}
	if (key == 1)
		data->left_butt = 1;
	render(data);
	return (0);
}
