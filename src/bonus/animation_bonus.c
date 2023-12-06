/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:40 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/06 16:14:58 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	enable_images_0(t_data *game)
{
	game->wall.i_2->enabled = 0;
	game->player.i_2->enabled = 0;
	game->collectable.i_2->enabled = 0;
	game->exit.i_2->enabled = 0;
	game->enemy.i_2->enabled = 0;
	game->wall.i_0->enabled = 1;
	game->player.i_0->enabled = 1;
	game->collectable.i_0->enabled = 1;
	game->exit.i_0->enabled = 1;
	game->enemy.i_0->enabled = 1;
}

static void	enable_images_1(t_data *game)
{
	game->wall.i_0->enabled = 0;
	game->player.i_0->enabled = 0;
	game->collectable.i_0->enabled = 0;
	game->exit.i_0->enabled = 0;
	game->enemy.i_0->enabled = 0;
	game->wall.i_1->enabled = 1;
	game->player.i_1->enabled = 1;
	game->collectable.i_1->enabled = 1;
	game->exit.i_1->enabled = 1;
	game->enemy.i_1->enabled = 1;
}

static void	enable_images_2(t_data *game)
{
	game->wall.i_1->enabled = 0;
	game->player.i_1->enabled = 0;
	game->collectable.i_1->enabled = 0;
	game->exit.i_1->enabled = 0;
	game->enemy.i_1->enabled = 0;
	game->wall.i_2->enabled = 1;
	game->player.i_2->enabled = 1;
	game->collectable.i_2->enabled = 1;
	game->exit.i_2->enabled = 1;
	game->enemy.i_2->enabled = 1;
}

void	animation(t_data *game)
{
	if (game->anim_counter == 0)
		enable_images_0(game);
	if (game->anim_counter == 1)
		enable_images_1(game);
	if (game->anim_counter == 2)
		enable_images_2(game);
}
