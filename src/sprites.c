/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:54:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/06 16:26:46 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	load_images(t_data *game)
{
	game->background.i_0 = mlx_texture_to_image(game->mlx,
			game->background.t_0);
	game->wall.i_0 = mlx_texture_to_image(game->mlx, game->wall.t_0);
	game->player.i_0 = mlx_texture_to_image(game->mlx, game->player.t_0);
	game->collectable.i_0 = mlx_texture_to_image(game->mlx,
			game->collectable.t_0);
	game->exit.i_0 = mlx_texture_to_image(game->mlx, game->exit.t_0);
	game->enemy.i_0 = mlx_texture_to_image(game->mlx, game->enemy.t_0);
}

void	load_textures_and_images(t_data *game)
{
	game->background.t_0 = mlx_load_png("./textures/background.png");
	game->wall.t_0 = mlx_load_png("./textures/wall_0.png");
	game->player.t_0 = mlx_load_png("./textures/baba_0.png");
	game->collectable.t_0 = mlx_load_png("./textures/cheese_0.png");
	game->exit.t_0 = mlx_load_png("./textures/flag_0.png");
	game->enemy.t_0 = mlx_load_png("./textures/keke_0.png");
	load_images(game);
}
