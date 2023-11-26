/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/26 17:08:53 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* This function should apply a texture to a spot in the window */
void apply_image_wall(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->wall = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->wall, W_WIDTH * x, W_HEIGHT * y);
}
void apply_image_collectable(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->collectable = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->collectable, W_WIDTH * x, W_HEIGHT * y);
}
void apply_image_background(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->background = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->background, W_WIDTH * x, W_HEIGHT * y);
}
void apply_image_player(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->player = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->player, W_WIDTH * x, W_HEIGHT * y);
}
void apply_image_exit(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->exit = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->exit, W_WIDTH * x, W_HEIGHT * y);
}
void apply_image_enemy(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t *image_t;

	image_t = mlx_load_png(texture_path);
	game->enemy = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, game->enemy, W_WIDTH * x, W_HEIGHT * y);
}
/* Run through the window putting textures in the correct places */
void window_tiling(t_data *game)
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
				apply_image_wall(game, "./textures/wall.png", j, i);
			if (game->map[i][j] == '0')
				apply_image_background(game, "./textures/background.png", j, i);
			if (game->map[i][j] == 'P')
				apply_image_player(game, "./textures/player.png", j, i);
			if (game->map[i][j] == 'E')
				apply_image_exit(game, "./textures/exit.png", j, i);
			if (game->map[i][j] == 'C')
				apply_image_collectable(game, "./textures/collectable.png", j, i);
			if (game->map[i][j] == 'V')
				apply_image_enemy(game, "./textures/enemy.png", j, i);
			j++;
		}
		i++;
	}
}

void ft_delete_backlog(t_data *game)
{
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->collectable);
	mlx_delete_image(game->mlx, game->enemy);
}
/* Input detection and movement */
void ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	// ft_delete_backlog(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player_up(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player_left(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player_right(game);
}

// void ft_hook(void *param)
// {
// 	t_data *game;

// 	game = param;
// 	ft_printf("%i\n", game->number_of_collectables);
// }

/* Creation of window */
int window_control(t_data *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height, "so_long", true);
	if (!game->mlx)
		return (error_message('W'));
	window_tiling(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	// mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
