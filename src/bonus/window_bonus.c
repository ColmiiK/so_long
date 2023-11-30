/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/30 13:10:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	load_images(t_data *game)
{
	game->wall_tex = mlx_load_png("./textures/wall/wall_0.png");
	game->background_tex = mlx_load_png("./textures/background/background.png");
	game->player_tex = mlx_load_png("./textures/player/baba_0.png");
	game->collectable_tex = mlx_load_png("./textures/collectable/cheese_0.png");
	game->exit_tex = mlx_load_png("./textures/exit/flag_0.png");
	game->enemy_tex = mlx_load_png("./textures/enemy/keke_0.png");
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_tex);
	game->background_img = mlx_texture_to_image(game->mlx,
			game->background_tex);
	game->player_img = mlx_texture_to_image(game->mlx, game->player_tex);
	game->collectable_img = mlx_texture_to_image(game->mlx,
			game->collectable_tex);
	game->exit_img = mlx_texture_to_image(game->mlx, game->exit_tex);
	game->enemy_img = mlx_texture_to_image(game->mlx, game->enemy_tex);
}

void	apply_image(t_data *game, void *img, int x, int y)
{
	mlx_image_to_window(game->mlx, game->background_img,
		W_WIDTH * x, W_HEIGHT * y);
	mlx_image_to_window(game->mlx, img, W_WIDTH * x, W_HEIGHT * y);
}

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
				apply_image(game, game->wall_img, j, i);
			if (game->map[i][j] == '0')
				apply_image(game, game->background_img, j, i);
			if (game->map[i][j] == 'P')
				apply_image(game, game->player_img, j, i);
			if (game->map[i][j] == 'E')
				apply_image(game, game->exit_img, j, i);
			if (game->map[i][j] == 'C')
				apply_image(game, game->collectable_img, j, i);
			if (game->map[i][j] == 'V')
				apply_image(game, game->enemy_img, j, i);
			j++;
		}
		i++;
	}
}

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
		ft_printf("BONUS: You have to pick up %i collectables!\n",
			game->c_count);
}

int	window_control(t_data *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height,
			"so_long", false);
	if (!game->mlx)
		return (error_message(game, 'W'));
	load_images(game);
	window_tiling(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop(game->mlx);
	return (0);
}
