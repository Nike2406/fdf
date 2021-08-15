/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:53:41 by prochell          #+#    #+#             */
/*   Updated: 2021/08/15 16:01:43 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color) // test
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
	if (data->clue)
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
	data->proection_flag = 1;
	data->clue = 1;
	data_preset(data);
	render(data);
	return (0);
}