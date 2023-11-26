/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:23 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/26 16:42:28 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	event_checker(t_data *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'C')
		game->number_of_collectables--;
	if (game->map[y][x] == 'V')
		ft_printf("Game over!\n");
	if (game->map[y][x] == 'E' && game->number_of_collectables == 0)
		ft_printf("Finished game!\n");
	if (game->map[y][x] == 'E' && game->number_of_collectables != 0)
		return (1);
	return (0);
}

void	move_player_up(t_data *game)
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
				if (!event_checker(game, y - 1, x))
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
					window_tiling(game);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}

void	move_player_left(t_data *game)
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
				if (!event_checker(game, y, x - 1))
				{
					game->map[y][x] = '0';
					game->map[y][x - 1] = 'P';
					window_tiling(game);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}

void	move_player_down(t_data *game)
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
				if (!event_checker(game, y + 1, x))
				{
					game->map[y][x] = '0';
					game->map[y + 1][x] = 'P';
					window_tiling(game);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}

void	move_player_right(t_data *game)
{
	int y;
	int x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				if (!event_checker(game, y, x + 1))
				{
					game->map[y][x] = '0';
					game->map[y][x + 1] = 'P';
					window_tiling(game);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}
