/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:21:31 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 20:57:34 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_butt && x >= 0 && x <= data->img_width && \
		y >= 0 && y <= data->img_height)
	{
		if (x > data->mouse_x)
			data->rotate_x -= 0.02;
		if (x < data->mouse_x)
			data->rotate_x += 0.02;
		if (y > data->mouse_y)
			data->rotate_y += 0.02;
		if (y < data->mouse_y)
			data->rotate_y -= 0.02;
		data->mouse_x = x;
		data->mouse_y = y;
	}
	render(data);
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
	{
		if (data->proection_flag)
			data->cof_z += 0.02;
	}
	else if (key == 12)
	{
		if (data->proection_flag)
			data->cof_z -= 0.02;
	}
	else if (key == 91) // rotate start
	{
		data->rotate_x += 0.1;
		//up
	}
	else if (key == 88)
	{
		data->rotate_y += 0.1;
		//right
	}
	else if (key == 84)
	{
		data->rotate_x -= 0.1;
		//down
	}
	else if (key == 86) // rotate ends
	{
		data->rotate_y -= 0.1;
		//left
	}
	else if (key == 89)
	{
		data->rotate_z += 0.1;
		//rotate-
	}
	else if (key == 92)
	{
		data->rotate_z -= 0.1;
		//rotate+
	}
	else if (key == 87) // rotate ends
	{
		data->origin = 1;
		//origin state
	}
	else if (key == 49)
	{
		if (data->proection_flag)
			data->proection_flag = 0;
		else
			data->proection_flag = 1;
		// change proection
	}
	else if (key == 4 || key == 44)
	{
		if (data->clue)
			data->clue = 0;
		else
			data->clue = 1;
		// clue
	}
	else if (key == 69 || key == 24)
		data->zoom += 2;
	else if (key == 78 || key == 27)
	{
		if (data->zoom <= 0)
			return (0);
		else
			data->zoom -= 2;
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
		data->zoom += 2;
	if (key == 5)
	{
		if (data->zoom <= 0)
			return (0);
		else
			data->zoom -= 2;
	}
	if (key == 1)
		data->left_butt = 1;
	render(data);
	return (0);
}
