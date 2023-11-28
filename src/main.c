/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/28 15:56:36 by alvega-g         ###   ########.fr       */
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
	Only read .ber files
	Map error message
	Window creation
	Escape closes the window
	Window error messasage
	Background/wall/player... tiling
	Player image
	Player input (WASD)
	Hook for moves
	Player movement
	Player collision
	Exit
	Coin counter
	Coin check for exit
	
	
	TODO:
	
	
	Window adjustment


	Enemy image
	Coin image
	Moves on screen
	Player sprite movement
	Enemy movement
	Enemy player tracking?
	Gameover on enemy touch
	Correct termination of program
	Norminette OK
	Static check
	Leak testing
*/
void leaks(void)
{
	system("leaks -q so_long");
}

void ft_debug(t_data *game)
{
	for (int i = 0; i < game->map_height; i++)
		ft_printf("%s", game->map[i]);
	ft_printf("\nHeight of map -> %i\n", game->map_height);
	ft_printf("Width of map -> %i\n", game->map_width);
	ft_printf("Number of collectables -> %i\n", game->c_count);
	ft_printf("Player starting position -> %i.%i\n", game->player_x_pos, game->player_y_pos);
	ft_printf("Exit starting position -> %i.%i\n", game->exit_x_pos, game->exit_y_pos);
}

int	main(int ac, char **av)
{
	t_data	game;

	atexit(leaks);
	ft_memset(&game, 0, sizeof(t_data));
	game.moves = 0;
	if (ac == 2)
	{
		if (populate_map(&game, av[1]))
			return (error_message('M'));
		if (is_map_correct(&game))
			return (error_message('M'));
		if (is_map_doable(&game))
			return (error_message('D'));
		ft_debug(&game);
		if (window_control(&game))
			return (error_message('W'));
	}
	ft_annihilation(&game);
}
