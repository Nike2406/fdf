// void	bresenham(t_fdf *data, t_dot *p, t_dot *p1)
// {
// 	double	x_step;
// 	double	y_step;
// 	long	max;

// 	get_position(data, p, p1);

// 	x_step = p1->x - p->x;
// 	y_step = p1->y - p->y;
// 	max = MAX(MOD(x_step), MOD(y_step));
// 	x_step /= max;
// 	y_step /= max;

// 	t_col	trgb0;
// 	t_col	trgb1;
// 	t_col	trgb_shift;

// 	if (p->z)
// 		trgb0 = get_col(0xAA0000);
// 	else
// 		trgb0 = get_col(0xFFFFFF);
// 	if (p1->z)
// 		trgb1 = get_col(0xAA0000);
// 	else
// 		trgb1 = get_col(0xFFFFFF);
// 	trgb_shift = val_shift(&trgb0, &trgb1, max);

// 	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
// 	{
// 		if ((p->x >= 0 && p->x <= data->img_width) && \
// 		(p->y >= 0 && p->y < data->img_height))
// 		{
// 			plus_shift(&trgb0, &trgb_shift);
// 			my_mlx_pixel_put(data, p->x, p->y, create_trgb(&trgb0));
// 		}
// 		p->x += x_step;
// 		p->y += y_step;
// 	}
// }


// t_col	get_col(int	trgb)
// {
// 	t_col col;

// 	col.r = (trgb >> 8 * 2) - ((trgb >> (8 * 3)) << 8);
// 	col.g = (trgb >> 8) - ((trgb >> (8 * 2)) << 8);
// 	col.b = (trgb) - ((trgb >> 8) << 8);


// 	return (col);
// }

// t_col	val_shift(t_col *b, t_col *a, int step)
// {
// 	t_col shift;

// 	shift.r = (a->r - b->r) / step;
// 	shift.g = (a->g - b->g) / step;
// 	shift.b = (a->b - b->b) / step;
// 	return (shift);
// }

// void	plus_shift(t_col *a, t_col *shift)
// {
// 	a->r += shift->r;
// 	a->g += shift->g;
// 	a->b += shift->b;
// }

// int	create_trgb(t_col *col)
// {
// 	// return (col->t << 24 | col->r << 16 | col->g << 8 | col->b);
// 	int	res;

// 	// res = col->t;
// 	// res <<= 8;
// 	res = col->r;
// 	res <<= 8;
// 	res += col->g;
// 	res <<= 8;
// 	res += col->b;
// 	return (res);
// }

// header

// void	plus_shift(t_col *a, t_col *shift);
// t_col	val_shift(t_col *b, t_col *a, int step);
// t_col	get_col(int	trgb);
// int		create_trgb(t_col *col);
