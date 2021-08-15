/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:05:38 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 20:03:28 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../fdf.h"

// // ILRECH
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
// // End Ilrech

// int	get_t(int trgb)
// {
// 	return (trgb & (0xFF << 24));
// }

// int	get_r(int trgb)
// {
// 	return (trgb & (0xFF << 16));
// }

// int	get_g(int trgb)
// {
// 	return (trgb & (0xFF << 8));
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }

// tmp get_color

// int	get_color(t_fdf *data, double start_x, double start_y)
// {
// 	// Color
// 	// if (z || z1)
// 	// 	data->color = 0xFFCF40;
// 	// else
// 	// 	data->color = 0x8243D6;
// 	// int	tmp_color;
// 	int	col1 = 0xFFCF40;
// 	int	col2 = 0x8243D6;
// 	int arr1[3];
// 	int arr2[3];
// 	int arr_tmp[3];
// 	arr1[0] = start_x;
// 	arr1[1] = start_y;
// 	arr1[2] = col1;
// 	arr2[0] = p->x1;
// 	arr2[1] = p->y1;
// 	arr2[2] = col2;
// 	arr_tmp[0] = p->x;
// 	arr_tmp[1] = p->y;
// 	arr_tmp[2] = 0x00;
// 	// float	coeff;
// 	// t_col	trgb0;
// 	// t_col	trgb1;
// 	// t_col	trgb_shift;
// 	double	coeff;

// 	// if (p->z)
// 	// 	trgb0 = get_col(0xAA0000);
// 	// else
// 	// 	trgb0 = get_col(0xFFFFFF);
// 	// if (p1->z)
// 	// 	trgb1 = get_col(0xAA0000);
// 	// else
// 	// 	trgb1 = get_col(0xFFFFFF);

// 	// coeff = sqrt((p->x1 - p->y1) * (p->x1 - p->y1)
// 	// 		+ (p->x - p->y) * (p->x - p->y))
// 	// 	/ sqrt((p->y - p->z) * (p->y - p->z)
// 	// 		+ (p->x - p1->z) * (p->x - p1->z));

// 	coeff = sqrt((arr2[0] - arr_tmp[0]) * (arr2[0] - arr_tmp[0])
// 			+ (arr2[1] - arr_tmp[1]) * (arr2[1] - arr_tmp[1]))
// 		/ sqrt((arr2[0] - arr1[0]) * (arr2[0] - arr1[0])
// 			+ (arr2[1] - arr1[1]) * (arr2[1] - arr1[1]));

// // coeff = sqrt((p->x - p->z) * (p->x - p->z)
// // 			+ (p->y - p1->z) * (p->y - p1->z))
// // 		/ sqrt((p->x -p->x1) * (p->x -p->x1)
// // 			+ (p->y - p->y1) * (p->y - p->y1));
// 	// coeff = 0.5;
// 	data->color = create_trgb(get_r(col2) + \
// 			(get_r(col1) - get_r(col2)) * coeff, \
// 			get_g(col1) + (get_g(col2) - get_g(col1)) * coeff, \
// 			get_b(col1) + (get_b(col2) - get_b(col1)) * coeff);
// 	return (data->color);

// 	// data->color = 0x8243D6;
// 	// if (z)
// 	// 	data->color += z;
// 	// else if (z1)
// 	// 	data->color += z1;

// 	// coeff = sqrt((x1 - y1) * (x1 - y1)
// 	// 		+ (x - y) * (x - y))
// 	// 	/ sqrt((y - z1) * (y - z1)
// 	// 		+ (x - z) * (x - z));

// 	// data->color = create_trgb(0, get_r(col1) \
// 	// 		+ (get_r(col2) - get_r(col1)) * coeff, \
// 	// 		get_g(col1) + (get_g(col2) - get_g(col1)) * coeff, \
// 	// 		get_b(col1) + (get_b(col2) - get_b(col1)) * coeff);

// 	// if (p->z || p1->z)
// 	// {
// 	// 	data->color = 0xFFCF40;
// 	// }
// 	// else
// 	// 	data->color = 0x8243D6;

// }

//Header

//Ilrech
// int	create_trgb(int r, int g, int b);
// int	get_r(int trgb);
// int	get_g(int trgb);
// int	get_b(int trgb);



// void	proect_color(t_dot *tmp, t_dot *p, t_dot *p1)
// {
// 	double	coeff;

// 	//tmp = p0
// 	//p = p_main
// 	//p1 = p1
// 	coeff = ((p1->x - tmp->x) * (p1->y - tmp->y)) \
// 	/ ((p1->x - p->x) * (p1->y - p->y));

// 	printf("coeff - %f", coeff);
// 	tmp->color = create_trgb(get_r(p1->color)
// 			+ (get_r(p->color) - get_r(p1->color)) * coeff,
// 			get_g(p1->color) + (get_g(p->color) - get_g(p1->color)) * coeff,
// 			get_b(p1->color) + (get_b(p->color) - get_b(p1->color)) * coeff);
// }

