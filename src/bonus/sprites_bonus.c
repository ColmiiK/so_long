/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:54:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/04 14:08:35 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	load_sprites(t_data *game)
{
	game->wall_t = mlx_load_png("./textures/wall_0.png");
	game->background_t = mlx_load_png("./textures/background.png");
	game->player_t = mlx_load_png("./textures/baba_0.png");
	game->collectable_t = mlx_load_png("./textures/cheese_0.png");
	game->exit_t = mlx_load_png("./textures/flag_0.png");
	game->enemy_t = mlx_load_png("./textures/keke_0.png");
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t);
	game->background_i = mlx_texture_to_image(game->mlx,
			game->background_t);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t);
	game->collectable_i = mlx_texture_to_image(game->mlx,
			game->collectable_t);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t);
	game->enemy_i = mlx_texture_to_image(game->mlx, game->enemy_t);
}