/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:53:41 by prochell          #+#    #+#             */
/*   Updated: 2021/08/03 15:36:06 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	deal_key(int key, t_fdf *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 126 || key == 13)
		data->shift_y -= 10;
	else if (key == 125 || key == 1)
		data->shift_y += 10;
	else if (key == 124 || key == 2)
		data->shift_x += 10;
	else if (key == 123 || key == 0)
		data->shift_x -= 10;
	else if (key == 53)
		exit(0);
	else
		return (0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	// int		i;
	// int		j;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_err(1);
	read_file(argv[1], data);

	// Check
	// printf("Height - %d\n", data->height);
	// printf("Width - %d\n", data->width);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	// mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, #color);
	// bresenham(10, 10 , 600, 300, data);
	data->zoom = 40;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);

	// i = 0;
	// while (i <= data->height)
	// {
	// 	j = 0;
	// 	while (j < data->width)
	// 	{
	// 		printf("%3d", data->matrix[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// 	printf("\n");
	// }

	return (0);
}