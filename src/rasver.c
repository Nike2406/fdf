/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:04:37 by prochell          #+#    #+#             */
/*   Updated: 2021/08/11 14:12:32 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../fdf.h"


// int	create_trgb(t_col *col)
// {
// 	// return (col->t << 24 | col->r << 16 | col->g << 8 | col->b);
// 	int	res;

// 	res = col->t;
// 	res <<= 8;
// 	res = col->r;
// 	res <<= 8;
// 	res += col->g;
// 	res <<= 8;
// 	res += col->b;
// 	return (res);
// }


// t_col	get_col(int	trgb)
// {
// 	t_col col;

// 	/*
// 	T
// 	11111111 101010101 00100100 00001000
// 	>> 16
// 	00000000 00000000 00000000 11111111

// 	R
// 	11111111 101010101 00100100 00001000
// 	<< 8
// 	101010101 00100100 00001000 00000000
// 	>> 16
// 	00000000 00000000 00000000 101010101

// 	G
// 	11111111 101010101 00100100 00001000
// 	<< 16
// 	00100100 00001000 00000000 00000000
// 	>> 24
// 	00000000 00000000 00000000 00100100

// 	B
// 	11111111 101010101 00100100 00001000
// 	<< 24
// 	00001000 00000000 00000000 00000000
// 	>> 24
// 	00000000 00000000 00000000 00001000

// 	*/
// 	// col.t = (trgb & (0xFF << 24));
// 	// col.r = (trgb & (0xFF << 16));
// 	// col.g = (trgb & (0xFF << 8));
// 	// col.b = (trgb & 0xFF );

// 	// col.t = trgb >> 24;
// 	// col.r = (trgb << 8) >> 16;
// 	// col.g = (trgb << 16) >> 24;
// 	// col.b = (trgb << 24) >> 24;

// 	// col.r = (trgb << 8) >> 16;
// 	// col.g = (trgb << 16) >> 24;
// 	// col.b = (trgb << 24) >> 24;

// 	col.t = 0x00;
// 	col.r = (trgb >> 8 * 2) - ((trgb >> (8 * 3)) << 8);
// 	col.g = (trgb >> 8) - ((trgb >> (8 * 2)) << 8);
// 	col.b = (trgb) - ((trgb >> 8) << 8);

// 	// col.t = 0x00;
// 	// col.r = (trgb >> 8 * 2) - ((trgb >> (8 * 3)) << 8);
// 	// col.g = (trgb >> 8) - ((trgb >> (8 * 2)) << 8);
// 	// col.b = (trgb) - ((trgb >> 8) << 8);

// 	return (col);
// }

// t_col	val_shift(t_col *b, t_col *a, int step)
// {
// 	t_col shift;

// 	// shift.t = (a->t - b->t) / step;
// 	shift.t = 0;
// 	shift.r = (a->r - b->r) / step;
// 	shift.g = (a->g - b->g) / step;
// 	shift.b = (a->b - b->b) / step;
// 	return (shift);
// }

// void	plus_shift(t_col *a, t_col *shift)
// {
// 	a->t += shift->t;
// 	a->r += shift->r;
// 	a->g += shift->g;
// 	a->b += shift->b;
// 	// a->t = (a->t + shift->t % 0xFF);
// 	// a->r = (a->r + shift->r % 0xFF);
// 	// a->g = (a->g + shift->g % 0xFF);
// 	// a->b = (a->b + shift->b % 0xFF);
// }

// // main_funk

// 	t_col	trgb0;
// 	t_col	trgb1;
// 	t_col	trgb_shift;

// 	if (data->z)
// 		trgb0 = get_col(0xAA0000);
// 	else
// 		trgb0 = get_col(0xFFFFFF);
// 	if (data->z1)
// 		trgb1 = get_col(0xAA0000);
// 	else
// 		trgb1 = get_col(0xFFFFFF);

// 	trgb_shift = val_shift(&trgb0, &trgb1, max);
// 	// double start_x = data->x;
// 	// double start_y = data->x;

// 	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
// 	{
// 		if ((data->x >= 0 && data->x <= data->img_width) && \
// 		(data->y >= 0 && data->y < data->img_height))
// 		{

// 			plus_shift(&trgb0, &trgb_shift);
// 			my_mlx_pixel_put(data, data->x, data->y, create_trgb(&trgb0)); // get_color(data, start_x, start_y)
// 		}
// 		data->x += x_step;
// 		data->y += y_step;
// 	}

// Header

// int		create_trgb(t_col *col);
// int		get_t(int trgb);
// int		get_r(int trgb);
// int		get_g(int trgb);
// int		get_b(int trgb);
// t_col	get_col(int	trgb);
// t_col	val_shift(t_col *a, t_col *b, int step);
// void	plus_shift(t_col *a, t_col *shift);
// int		get_color(t_fdf *data, double start_x, double start_y);

