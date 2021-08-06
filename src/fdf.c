/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:53:41 by prochell          #+#    #+#             */
/*   Updated: 2021/08/06 21:26:43 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		data->cof_z += 0.1;
	else if (key == 12)
		data->cof_z -= 0.1;
	else if (key == 53)
		exit(0);
	else
		return (0);
	following_render(data);
	return (0);
}

int	deal_mouse(int key, t_fdf data)
{
	(void)data;
	ft_putnbr(key);
	ft_putstr("\n");
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color) // test
{
	char	*dst;
	// Передача параметров xyz для отображения
	data->x = x;
	data->y = y;
	// data->x1 = x1;
	// data->y1 = y1;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// printf("dst - %p\n", dst);
	// printf("color - %d\n", color);
	*(unsigned int *)dst = color;
}

void	following_render(t_fdf *data)
{
	void	*tmp;
	tmp = data->img;
	data->img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,\
		&data->line_length, &data->endian);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// /// Show tab
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, 0x0000ffff, "x = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 100, 0x0000ffff, ft_itoa((int)data->x));
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 150, 0x0000ffff, "y = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, 0x0000ffff, ft_itoa((int)data->y));
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, 0x0000ffff, "z = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 200, 0x0000ffff, ft_itoa((int)data->z));
	mlx_destroy_image(data->mlx_ptr, tmp);
}

void	first_render(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->img_width, data->img_height, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,\
		&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	// // Show tab
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, 0x0000ffff, "x = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 100, 0x0000ffff, ft_itoa((int)data->x));
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 150, 0x0000ffff, "y = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 150, 0x0000ffff, ft_itoa((int)data->y));
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 200, 0x0000ffff, "z = ");
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 200, 0x0000ffff, ft_itoa((int)data->z));
	mlx_hook(data->win_ptr, 2, 1L<<0, deal_key, data);
	mlx_mouse_hook(data->win_ptr, deal_mouse, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc > 2)
		return (0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_err(1);
	read_file(argv[1], data);
	data->zoom = 40;
	data->cof_z = 1;
	data->img_height = 1000;
	data->img_width = 1000;
	data->color = 0xFFCF40;
	first_render(data);
	return (0);
}