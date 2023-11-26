/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:23 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/26 11:13:02 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void move_player_up(t_data *game)
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
				if (game->map[y - 1][x] != '1')
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
				}
			}
			x++;
		}
		y++;
	}
}

void move_player_left(t_data *game)
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
				if (game->map[y][x - 1] != '1')
				{
					game->map[y][x] = '0';
					game->map[y][x - 1] = 'P';
				}
			}
			x++;
		}
		y++;
	}
}
/* FIX: Loops until it hits a wall */
void move_player_down(t_data *game)
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
				if (game->map[y + 1][x] != '1')
				{
					game->map[y][x] = '0';
					game->map[y + 1][x] = 'P';
				}
			}
			x++;
		}
		y++;
	}
}
/* FIX: Loops until it hits a wall */
void move_player_right(t_data *game)
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
				if (game->map[y][x + 1] != '1')
				{
					game->map[y][x] = '0';
					game->map[y][x + 1] = 'P';
				}
			}
			x++;
		}
		y++;
	}
}