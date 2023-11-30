/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/30 13:07:18 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (ac == 1)
		return (ft_printf("Error\nNo map was provided.\n"));
	if (ac > 2)
		return (ft_printf("Error\nMore than one argument provided.\n"));
	ft_memset(&game, 0, sizeof(t_data));
	game.moves = 0;
	if (ac == 2)
	{
		if (populate_map(&game, av[1]))
			return (error_message(&game, 'M'));
		if (is_map_correct(&game))
			return (error_message(&game, 'M'));
		if (is_map_doable(&game))
			return (error_message(&game, 'D'));
		if (window_control(&game))
			return (error_message(&game, 'W'));
		ft_annihilation(&game);
	}
}