/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/22 11:34:49 by alvega-g         ###   ########.fr       */
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
void apply_image(data_t *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;
	void *temp;

	image_t = mlx_load_png(texture_path);
	temp = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, temp, W_WIDTH * x, W_HEIGHT * y);
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
				apply_image(game, "./textures/wall.png", j, i);
			if (game->map[i][j] == '0')
				apply_image(game, "./textures/background.png", j, i);
			if (game->map[i][j] == 'P')
				apply_image(game, "./textures/player.png", j, i);
			if (game->map[i][j] == 'E')
				apply_image(game, "./textures/exit.png", j, i);
			if (game->map[i][j] == 'C')
				apply_image(game, "./textures/collectable.png", j, i);
			if (game->map[i][j] == 'V')
				apply_image(game, "./textures/enemy.png", j, i);
			j++;
		}
		i++;
	}
}
/* Creation of window */
int window_control(data_t *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height, "so_long", true);
	if (!game->mlx)
		return (error_message('W'));
	window_tiling(game);	
	mlx_loop_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	return (0);
}
