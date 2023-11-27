/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/27 11:47:28 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* This function should apply a texture to a spot in the window */
void	apply_image(t_data *game, char *texture_path, int x, int y)
{
	mlx_texture_t	*image_t;
	void			*temp;

	image_t = mlx_load_png(texture_path);
	temp = mlx_texture_to_image(game->mlx, image_t);
	mlx_image_to_window(game->mlx, temp, W_WIDTH * x, W_HEIGHT * y);
}

/* Run through the window putting textures in the correct places */
void	window_tiling(t_data *game)
{
	int	i;
	int	j;

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
/* Input detection and movement */
void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, -1, 0);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 0, -1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, +1, 0);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 0, +1);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_printf("You have to pick up %i collectables!\n",
			game->number_of_collectables);
}

// void ft_hook(void *param)
// {
// 	t_data *game;

// 	game = param;
// 	ft_printf("%i\n", game->number_of_collectables);
// }

/* Creation of window */
int	window_control(t_data *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height,
		"so_long", true);
	if (!game->mlx)
		return (error_message('W'));
	window_tiling(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	// mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
