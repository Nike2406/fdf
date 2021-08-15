/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:07:39 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 16:08:32 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int	get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
