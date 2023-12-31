/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:23 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:50 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static int	event_checker(t_data *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'C')
		game->c_count--;
	if (game->map[y][x] == 'V')
		mlx_close_window(game->mlx);
	if (game->map[y][x] == 'H')
		mlx_close_window(game->mlx);
	if (game->map[y][x] == 'E' && game->c_count == 0)
	{
		ft_printf("Congratulations! You finished the game in %i moves!\n",
			game->moves + 1);
		mlx_close_window(game->mlx);
	}
	if (game->map[y][x] == 'E' && game->c_count != 0)
		return (1);
	return (0);
}

static void	update_map(t_data *game, int next_y, int next_x)
{
	game->map[game->y][game->x] = '0';
	game->map[next_y][next_x] = 'P';
	apply_image(game, &game->player, next_x, next_y);
	apply_image(game, &game->background, game->x, game->y);
}

void	move_player(t_data *game, int mod_y, int mod_x)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'P')
			{
				if (!event_checker(game, game->y + mod_y, game->x + mod_x))
				{
					update_map(game, game->y + mod_y, game->x + mod_x);
					game->moves++;
					return ;
				}
			}
			game->x++;
		}
		game->y++;
	}
}
