/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/05 13:09:40 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	apply_image(t_data *game, void *img, int x, int y)
{
	int i = 0;
	int j = 0;
	
	i = mlx_image_to_window(game->mlx, game->background_i,
		W_WIDTH * x, W_HEIGHT * y);
	j = mlx_image_to_window(game->mlx, img, W_WIDTH * x, W_HEIGHT * y);

	printf("%i - %i\n", i, j);
}

void	window_tiling(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				apply_image(game, game->wall_i, j, i);
			if (game->map[i][j] == '0')
				apply_image(game, game->background_i, j, i);
			if (game->map[i][j] == 'P')
				apply_image(game, game->player_i, j, i);
			if (game->map[i][j] == 'E')
				apply_image(game, game->exit_i, j, i);
			if (game->map[i][j] == 'C')
				apply_image(game, game->collectable_i, j, i);
			if (game->map[i][j] == 'V')
				apply_image(game, game->enemy_i, j, i);
			if (game->map[i][j] == 'H')
				apply_image(game, game->enemy_i, j, i);
		}
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
		ft_printf("You have to pick up %i collectables!\n",
			game->c_count);
}

void ft_loop(void *param)
{
	t_data *game;

	game = param;
	
	game->time += game->mlx->delta_time;
	if (game->time >= 1.0/3.0)
	{
		animation(game);
		game->anim_counter++;
		if (game->anim_counter > 2)
			game->anim_counter = 0;
		enemy_movement(game);
		mini_window_tiling(game);
		if (game->counter)
			mlx_delete_image(game->mlx, game->counter);
		game->counter = mlx_put_string(game->mlx, ft_itoa(game->moves), 0, 0);
		game->time = 0;
	}
}

int	window_control(t_data *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height, "so_long", false);
	if (!game->mlx)
		return (error_message(game, 'W'));
	load_textures(game);
	load_images_0(game);
	window_tiling(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop_hook(game->mlx, &ft_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
