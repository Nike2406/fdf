/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:21:31 by prochell          #+#    #+#             */
/*   Updated: 2021/08/07 23:37:53 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *data)
{
	if (data->left_butt)
		printf("x - %d, y - %d, %f\n", x, y, data->x1);
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