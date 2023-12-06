/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:54:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/06 16:15:33 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

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
	game->background.i_1 = mlx_texture_to_image(game->mlx,
			game->background.t_0);
	game->wall.i_1 = mlx_texture_to_image(game->mlx, game->wall.t_1);
	game->player.i_1 = mlx_texture_to_image(game->mlx, game->player.t_1);
	game->collectable.i_1 = mlx_texture_to_image(game->mlx,
			game->collectable.t_1);
	game->exit.i_1 = mlx_texture_to_image(game->mlx, game->exit.t_1);
	game->enemy.i_1 = mlx_texture_to_image(game->mlx, game->enemy.t_1);
	game->background.i_2 = mlx_texture_to_image(game->mlx,
			game->background.t_0);
	game->wall.i_2 = mlx_texture_to_image(game->mlx, game->wall.t_2);
	game->player.i_2 = mlx_texture_to_image(game->mlx, game->player.t_2);
	game->collectable.i_2 = mlx_texture_to_image(game->mlx,
			game->collectable.t_2);
	game->exit.i_2 = mlx_texture_to_image(game->mlx, game->exit.t_2);
	game->enemy.i_2 = mlx_texture_to_image(game->mlx, game->enemy.t_2);
}

void	load_textures_and_images(t_data *game)
{
	game->background.t_0 = mlx_load_png("./textures/background.png");
	game->wall.t_0 = mlx_load_png("./textures/wall_0.png");
	game->player.t_0 = mlx_load_png("./textures/baba_0.png");
	game->collectable.t_0 = mlx_load_png("./textures/cheese_0.png");
	game->exit.t_0 = mlx_load_png("./textures/flag_0.png");
	game->enemy.t_0 = mlx_load_png("./textures/keke_0.png");
	game->wall.t_1 = mlx_load_png("./textures/wall_1.png");
	game->player.t_1 = mlx_load_png("./textures/baba_1.png");
	game->collectable.t_1 = mlx_load_png("./textures/cheese_1.png");
	game->exit.t_1 = mlx_load_png("./textures/flag_1.png");
	game->enemy.t_1 = mlx_load_png("./textures/keke_1.png");
	game->wall.t_2 = mlx_load_png("./textures/wall_2.png");
	game->player.t_2 = mlx_load_png("./textures/baba_2.png");
	game->collectable.t_2 = mlx_load_png("./textures/cheese_2.png");
	game->exit.t_2 = mlx_load_png("./textures/flag_2.png");
	game->enemy.t_2 = mlx_load_png("./textures/keke_2.png");
	load_images(game);
}
