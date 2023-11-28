/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:39:55 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/28 17:03:55 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_message(t_data *game, char code)
{
	if (code == 'M')
		ft_printf("Error\n Map is invalid.\n");
	if (code == 'W')
		ft_printf("Error\n Unable to create window.\n");
	if (code == 'D')
		ft_printf("Error\n Map cannot be finished.\n");
	ft_annihilation(game);
	return (1);
}
