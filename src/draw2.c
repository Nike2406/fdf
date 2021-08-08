/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:53:56 by prochell          #+#    #+#             */
/*   Updated: 2021/08/08 13:56:55 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	show_tab(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, 0x0000ffff, "x = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 100, 0x0000ffff, ft_itoa((int)data->x));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 150, 0x0000ffff, "y = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, 0x0000ffff, ft_itoa((int)data->y));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, 0x0000ffff, "z = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 200, 0x0000ffff, ft_itoa((int)data->z));
}
