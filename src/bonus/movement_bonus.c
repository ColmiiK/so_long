/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:23 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/04 14:11:57 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	event_checker(t_data *game, int y, int x)
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
		mlx_close_window(game->mlx);
	if (game->map[y][x] == 'E' && game->c_count != 0)
		return (1);
	return (0);
}

void	update_map(t_data *game, int next_y, int next_x)
{
	game->map[game->y][game->x] = '0';
	game->map[next_y][next_x] = 'P';
	apply_image(game, game->player_i, next_x, next_y);
	apply_image(game, game->background_i, game->x, game->y);
}

void	move_player(t_data *game, int mod_y, int mod_x)
{
	move_vertical_enemy(game);
	move_horizontal_enemy(game);
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
					if (game->counter)
						mlx_delete_image(game->mlx, game->counter);
					game->counter = mlx_put_string(game->mlx, ft_itoa(game->moves), 0, 0);
					return ;
				}
			}
			game->x++;
		}
		game->y++;
	}

}

void move_vertical_enemy(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'V')
			{
				if (game->map[game->y + 1][game->x] == '0')
				{
					game->map[game->y][game->x] = '0';
					game->map[game->y + 1][game->x] = 'V';
					apply_image(game, game->enemy_i, game->x, game->y + 1);
					apply_image(game, game->background_i, game->x, game->y);
					return ;
				}
			}
			game->x++;
		}
		game->y++;
	}
}

void move_horizontal_enemy(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'H')
			{
				if (game->map[game->y][game->x + 1] == '0')
				{
					game->map[game->y][game->x] = '0';
					game->map[game->y][game->x + 1] = 'H';
					apply_image(game, game->enemy_i, game->x + 1, game->y);
					apply_image(game, game->background_i, game->x, game->y);
					return ;
				}
			}
			game->x++;
		}
		game->y++;
	}
}