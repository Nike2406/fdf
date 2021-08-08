/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:53:41 by prochell          #+#    #+#             */
/*   Updated: 2021/08/08 14:13:43 by prochell         ###   ########.fr       */
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
	else if (key == 69)
		data->zoom += 5;
	else if (key == 78)
	{
		if (data->zoom <= 1)
			return (0);
		else
			data->zoom -= 5;
	}
	else if (key == 53)
		exit(0);
	else
		return (0);
	render(data);
	return (0);
}

int	deal_mouse(int key, int x, int y, t_fdf *data)
{
	// ft_putnbr(key);
	// ft_putchar('\n');
	(void)x;
	(void)y;
	if (key == 4)
		data->zoom += 5;
	if (key == 5)
	{
		if (data->zoom <= 1)
			return (0);
		else
			data->zoom -= 5;
	}
	if (key == 1)
		data->left_butt = 1;

	render(data);
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color) // test
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// printf("dst - %p\n", dst);
	// printf("color - %d\n", color);
	*(unsigned int *)dst = color;
}

// void	following_render(t_fdf *data)
// {
// 	void	*tmp;
// 	tmp = data->img;
// 	data->img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_height);
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,\
// 		&data->line_length, &data->endian);
// 	mlx_clear_window(data->mlx_ptr, data->win_ptr);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
// 	show_tab(data);
// 	get_hook(data);
// 	mlx_destroy_image(data->mlx_ptr, tmp);
// }

// void	first_render(t_fdf *data)
// {
// 	data->mlx_ptr = mlx_init();
// 	data->win_ptr = mlx_new_window(data->mlx_ptr, data->img_width, data->img_height, "FDF");
// 	data->img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_height);
// 	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,\
// 		&data->line_length, &data->endian);
// 	draw(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
// 	show_tab(data);
// 	get_hook(data);
// 	mlx_loop(data->mlx_ptr);
// }

void	render(t_fdf *data)
{
	void	*tmp;
	if (!data->render_flag)
	{
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->img_width, data->img_height, "FDF");
	}
	if (data->render_flag)
		tmp = data->img;
	data->img = mlx_new_image(data->mlx_ptr, data->img_width, data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,\
		&data->line_length, &data->endian);
	if (data->render_flag)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	show_tab(data);
	get_hook(data);
	if (data->render_flag)
		mlx_destroy_image(data->mlx_ptr, tmp);
	if (!data->render_flag)
	{
		data->render_flag = 1;
		mlx_loop(data->mlx_ptr);
	}
}

void	get_hook(t_fdf *data)
{
	mlx_hook(data->win_ptr, 2, 1L<<0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_err, data); // exit with red button
	mlx_hook(data->win_ptr, 4, 0, deal_mouse, data);
	mlx_hook(data->win_ptr, 5, 0, mouse_up, data);
	mlx_hook(data->win_ptr, 6, 0, mouse_move, data);
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
	data_preset(data);
	render(data);
	return (0);
}