/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:53:56 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 15:54:03 by prochell         ###   ########.fr       */
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
