/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 13:53:56 by prochell          #+#    #+#             */
/*   Updated: 2021/08/11 21:33:10 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	show_tab(t_fdf *data, t_dot *p)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, 0x0000ffff, "x = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 100, 0x0000ffff, ft_itoa((int)p->x));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 130, 0x0000ffff, "y = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 130, 0x0000ffff, ft_itoa((int)p->y));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 220, 0x0000ffff, "z = ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 220, 0x0000ffff, ft_itoa((int)p->z));
}
