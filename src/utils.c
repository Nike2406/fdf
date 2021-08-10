/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/08/10 23:12:50 by prochell         ###   ########.fr       */
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

int	create_trgb(t_col *col)
{
	// return (col->t << 24 | col->r << 16 | col->g << 8 | col->b);
	int	res;

	res = col->t;
	res <<= 8;
	res += col->r;
	res <<= 8;
	res += col->g;
	res <<= 8;
	res += col->b;
	return (res);
}

t_col	get_col(int	trgb)
{
	t_col col;

	/*
	T
	11111111 101010101 00100100 00001000
	>> 16
	00000000 00000000 00000000 11111111

	R
	11111111 101010101 00100100 00001000
	<< 8
	101010101 00100100 00001000 00000000
	>> 16
	00000000 00000000 00000000 101010101

	G
	11111111 101010101 00100100 00001000
	<< 16
	00100100 00001000 00000000 00000000
	>> 24
	00000000 00000000 00000000 00100100

	B
	11111111 101010101 00100100 00001000
	<< 24
	00001000 00000000 00000000 00000000
	>> 24
	00000000 00000000 00000000 00001000

	*/
	// col.t = (trgb & (0xFF << 24));
	// col.r = (trgb & (0xFF << 16));
	// col.g = (trgb & (0xFF << 8));
	// col.b = (trgb & 0xFF );

	// col.t = trgb >> 24;
	// col.r = (trgb << 8) >> 16;
	// col.g = (trgb << 16) >> 24;
	// col.b = (trgb << 24) >> 24;

	col.t = 0x00;
	col.r = (trgb >> 8 * 2) - ((trgb >> (8 * 3)) << 8);
	col.g = (trgb >> 8) - ((trgb >> (8 * 2)) << 8);
	col.b = (trgb) - ((trgb >> 8) << 8);

	// col.t = 0x00;
	// col.r = (trgb >> 8 * 2) - ((trgb >> (8 * 3)) << 8);
	// col.g = (trgb >> 8) - ((trgb >> (8 * 2)) << 8);
	// col.b = (trgb) - ((trgb >> 8) << 8);

	return (col);
}

t_col	val_shift(t_col *b, t_col *a, int step)
{
	t_col shift;

	// shift.t = (a->t - b->t) / step;
	shift.t = 0;
	shift.r = (a->r - b->r) / step;
	shift.g = (a->g - b->g) / step;
	shift.b = (a->b - b->b) / step;
	return (shift);
}

void	plus_shift(t_col *a, t_col *shift)
{
	a->t += shift->t;
	a->r += shift->r;
	a->g += shift->g;
	a->b += shift->b;
	// a->t = (a->t + shift->t % 0xFF);
	// a->r = (a->r + shift->r % 0xFF);
	// a->g = (a->g + shift->g % 0xFF);
	// a->b = (a->b + shift->b % 0xFF);
}

//ILRECH
// int	create_trgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

// int	get_r(int trgb)
// {
// 	return ((trgb & (0xFF << 16)) >> 16);
// }

// int	get_g(int trgb)
// {
// 	return ((trgb & (0xFF << 8)) >> 8);
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }
// End Ilrech

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


void	data_preset(t_fdf *data)
{
	data->zoom = 40;
	data->cof_z = 0.5;
	data->img_height = 1000;
	data->img_width = 1000;
	data->color = 0xFFCF40;
	data->left_butt = 0;
	data->render_flag = 0;
	data->x = 0;
	data->x1 = 0;
	data->y = 0;
	data->y1 = 0;
	data->z = 0;
	data->z1 = 0;
}
