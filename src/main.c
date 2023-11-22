/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/22 11:34:30 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
	CHARACTER SPRITES -> https://twitter.com/unseven/status/1534943454920417283
	DEATH SPRITE -> https://twitter.com/poncle_vampire/status/1545784877349588992

*/

/*
	DONE:
	
	Map reading
	Map allocation
	Map error checking
	Map error message
	Window creation
	Escape closes the window
	Window error messasage
	Background/wall/player... tiling
	Player image
	
	
	TODO:
	
	ONLY READ .BER FILES!!!
	
	Window adjustment


	Player input (WASD)
	Player movement
	Hook for moves
	Moves on screen
	Player collision
	Player sprite movement

	Exit
	Coin image
	Coin counter
	Coin check for exit

	Enemy image
	Enemy movement
	Enemy player tracking?
	Gameover on enemy touch

	Correct termination of program

	Norminette OK
	STATIC CHECK
	Leak testing
*/

void ft_debug(data_t *game)
{
	for (int i = 0; i < game->map_height; i++)
		ft_printf("%s", game->map[i]);
	ft_printf("\nHeight of map -> %i\n", game->map_height);
	ft_printf("Width of map -> %i\n", game->map_width);
	ft_printf("Number of collectables -> %i\n", game->number_of_collectables);
}

int	main(int ac, char **av)
{
	data_t	game;
	
	ft_memset(&game, 0, sizeof(data_t));
	if (ac == 2)
	{
		populate_map(&game, av[1]);
		if (is_map_correct(&game))
			return (1);
		ft_debug(&game);
		if (window_control(&game))
			return (1);
	}
	mlx_terminate(game.mlx);
}
