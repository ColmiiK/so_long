/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:04:21 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/20 14:04:40 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t get_width(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}