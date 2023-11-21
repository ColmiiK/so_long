/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/21 17:16:20 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Hooks to control inputs */
void ft_hook(void *param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
/* This function should apply a texture to a spot in the window */
void apply_image(data_t *game, char *texture)
{
	
}
/* Run through the window putting textures in the correct places */
void window_tiling(data_t *game)
{
	int i;
	int j;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				apply_image(game, "./textures/wall.png");
			if (game->map[i][j] == '0')
				apply_image(game, "./textures/background.png");
			if (game->map[i][j] == 'P')
				apply_image(game, "./textures/player.png");
			if (game->map[i][j] == 'E')
				apply_image(game, "./textures/exit.png");
			if (game->map[i][j] == 'C')
				apply_image(game, "./textures/collectable.png");
			if (game->map[i][j] == 'V')
				apply_image(game, "./textures/enemy.png");
			j++;
		}
		i++;
	}
}
/* Creation of window */
int window_control(data_t *game)
{
	mlx_texture_t *background_t;

	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height, "so_long", true);
	if (!game->mlx)
		return (error_message('W'));
	background_t = mlx_load_png("./textures/space.png");
	game->background = mlx_texture_to_image(game->mlx, background_t);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	
	mlx_loop_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	return (0);
}
