/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/20 20:44:12 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
	CHARACTER SPRITES -> https://twitter.com/unseven/status/1534943454920417283
	DEATH SPRITE -> https://twitter.com/poncle_vampire/status/1545784877349588992

*/

/*	
	TODO:
	Map checking function does not work <- FT_STRLEN DOES NOT CORRECTLY ACCOUNTS FOR NEWLINE
	
	Function that returns error appropiate error message
	
	Window creation
	Window adjustment

	Background tiling
	Wall tiling
	
	Player image
	Player input (WASD, Escape)
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

int main(int ac, char **av)
{
	data_t game;
	
	ft_memset(&game, 0, sizeof(data_t));
	if (ac == 2)
	{
		populate_map(&game, av[1]);
		if (!is_map_correct(&game))
			return (0);
	}
	for (int i = 0; i < game.map_height; i++){
		ft_printf("%s", game.map[i]);
	}
	ft_printf("\nHeight of map -> %i\n", game.map_height);
	ft_printf("Width of map -> %i\n", game.map_width);
	ft_printf("Number of collectables -> %i\n", game.collectables);
}
