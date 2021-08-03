/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:56:50 by prochell          #+#    #+#             */
/*   Updated: 2021/08/03 19:33:37 by prochell         ###   ########.fr       */
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
