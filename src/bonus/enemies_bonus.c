/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:17 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/04 16:37:43 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void enemy_movement(t_data *game)
{
	if (game->v_enemy_flag == 0)
		move_vertical_enemy(game);
	if (game->v_enemy_flag == 1)
		r_move_vertical_enemy(game);	
	if (game->h_enemy_flag == 0)
		move_horizontal_enemy(game);
	if (game->h_enemy_flag == 1)
		r_move_horizontal_enemy(game);
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
				if (game->map[game->y + 1][game->x] == '1')
					game->v_enemy_flag = 1;
				if (game->map[game->y + 1][game->x] == 'P')
					mlx_close_window(game->mlx);
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

void r_move_vertical_enemy(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'V')
			{
				if (game->map[game->y - 1][game->x] == '1')
					game->v_enemy_flag = 0;
				if (game->map[game->y - 1][game->x] == 'P')
					mlx_close_window(game->mlx);
				if (game->map[game->y - 1][game->x] == '0')
				{
					game->map[game->y][game->x] = '0';
					game->map[game->y - 1][game->x] = 'V';
					apply_image(game, game->enemy_i, game->x, game->y - 1);
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
				if (game->map[game->y][game->x + 1] == '1')
					game->h_enemy_flag = 1;
				if (game->map[game->y][game->x + 1] == 'P')
					mlx_close_window(game->mlx);
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

void r_move_horizontal_enemy(t_data *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'H')
			{
				if (game->map[game->y][game->x - 1] == '1')
					game->h_enemy_flag = 0;
				if (game->map[game->y][game->x - 1] == 'P')
					mlx_close_window(game->mlx);
				if (game->map[game->y][game->x - 1] == '0')
				{
					game->map[game->y][game->x] = '0';
					game->map[game->y][game->x - 1] = 'H';
					apply_image(game, game->enemy_i, game->x - 1, game->y);
					apply_image(game, game->background_i, game->x, game->y);
					return ;
				}
			}
			game->x++;
		}
		game->y++;
	}
}
