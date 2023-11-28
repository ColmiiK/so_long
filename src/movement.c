/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:23 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/28 17:29:22 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	event_checker(t_data *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'C')
		game->c_count--;
	if (game->map[y][x] == 'V')
		ft_printf("Game over!\n");
	if (game->map[y][x] == 'E' && game->c_count == 0)
		ft_printf("Finished game in %i moves!\n", game->moves);
	if (game->map[y][x] == 'E' && game->c_count != 0)
		return (1);
	return (0);
}
void	update_map(t_data *game, int cur_y, int cur_x, int next_y, int next_x)
{
	game->map[cur_y][cur_x] = '0';
	game->map[next_y][next_x] = 'P';
	apply_image(game, game->player_img, next_x, next_y);
	apply_image(game, game->background_img, cur_x, cur_y);
}			

void	move_player(t_data *game, int mod_y, int mod_x)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				if (!event_checker(game, y + mod_y, x + mod_x))
				{
					update_map(game, y, x, y + mod_y, x + mod_x);
					game->moves++;
					ft_printf("You have moved %i times!\n", game->moves);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}
