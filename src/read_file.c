/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:06:13 by prochell          #+#    #+#             */
/*   Updated: 2021/08/10 23:02:46 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_err(1);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	if (*line != '\0')
		height++;
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_err(1);
	while (get_next_line(fd, &line))
		width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	// char	**colrs;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		// colrs = ft_split(line, ',');
		// while (colrs[j])

		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	prefill(int fd, t_fdf *data, int j)
{
	char	*line;
	int		i;

	i = 0;
	line = "";
	while (j >= 0)
	{
		get_next_line(fd, &line);
		fill_matrix(data->matrix[i], line);
		free(line);
		j--;
		i++;
	}
	return (i);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	int		j;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix)
		ft_err(1);
	i = 0;
	while (i <= data->height)
	{
		data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	j = i;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_err(1);
	i = prefill(fd, data, j);
	close(fd);
	data->matrix[i - 1] = NULL;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
