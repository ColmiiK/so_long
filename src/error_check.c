/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:39:55 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/27 11:37:01 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_message(char code)
{
	if (code == 'M')
		ft_printf("Error: map is invalid.\n");
	if (code == 'W')
		ft_printf("Error: unable to create window.\n");
	return (1);
}
