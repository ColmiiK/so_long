/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:54:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/05 12:57:40 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	load_textures(t_data *game)
{
	game->background_t = mlx_load_png("./textures/background.png");
	game->wall_t_0 = mlx_load_png("./textures/wall_0.png");
	game->player_t_0 = mlx_load_png("./textures/baba_0.png");
	game->collectable_t_0 = mlx_load_png("./textures/cheese_0.png");
	game->exit_t_0 = mlx_load_png("./textures/flag_0.png");
	game->enemy_t_0 = mlx_load_png("./textures/keke_0.png");

	game->wall_t_1 = mlx_load_png("./textures/wall_1.png");
	game->player_t_1 = mlx_load_png("./textures/baba_1.png");
	game->collectable_t_1 = mlx_load_png("./textures/cheese_1.png");
	game->exit_t_1 = mlx_load_png("./textures/flag_1.png");
	game->enemy_t_1 = mlx_load_png("./textures/keke_1.png");

	game->wall_t_2 = mlx_load_png("./textures/wall_2.png");
	game->player_t_2 = mlx_load_png("./textures/baba_2.png");
	game->collectable_t_2 = mlx_load_png("./textures/cheese_2.png");
	game->exit_t_2 = mlx_load_png("./textures/flag_2.png");
	game->enemy_t_2 = mlx_load_png("./textures/keke_2.png");

}

void delete_images(t_data *game)
{
	mlx_delete_image(game->mlx, game->wall_i);
	mlx_delete_image(game->mlx, game->player_i);
	mlx_delete_image(game->mlx, game->collectable_i);
	mlx_delete_image(game->mlx, game->exit_i);
	mlx_delete_image(game->mlx, game->enemy_i);
}

void load_images_0(t_data *game)
{
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t_0);
	game->background_i = mlx_texture_to_image(game->mlx, game->background_t);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t_0);
	game->collectable_i = mlx_texture_to_image(game->mlx, game->collectable_t_0);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t_0);
	game->enemy_i = mlx_texture_to_image(game->mlx, game->enemy_t_0);
}

void load_images_1(t_data *game)
{
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t_1);
	game->background_i = mlx_texture_to_image(game->mlx, game->background_t);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t_1);
	game->collectable_i = mlx_texture_to_image(game->mlx, game->collectable_t_1);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t_1);
	game->enemy_i = mlx_texture_to_image(game->mlx, game->enemy_t_1);
}

void load_images_2(t_data *game)
{
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t_2);
	game->background_i = mlx_texture_to_image(game->mlx, game->background_t);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t_2);
	game->collectable_i = mlx_texture_to_image(game->mlx, game->collectable_t_2);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t_2);
	game->enemy_i = mlx_texture_to_image(game->mlx, game->enemy_t_2);
}