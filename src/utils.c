/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/07/31 23:54:46 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Error\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

// void	get_gnl_eof(int	fd, char *line)
// {
// 	int	eof;

// 	eof = get_next_line(fd, &line);
// 	while (1)
// 	{
// 		if (eof >= 0)
// 		{
// 			get_next_line
// 		}
// 	}

// }
