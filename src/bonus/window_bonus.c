/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/11 14:00:24 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	apply_image(t_data *game, t_image *img, int x, int y)
{
	mlx_image_to_window(game->mlx, game->background.i_0, W_WIDTH * x, W_HEIGHT
		* y);
	mlx_image_to_window(game->mlx, img->i_0, W_WIDTH * x, W_HEIGHT * y);
	img->i_0->enabled = 1;
	mlx_image_to_window(game->mlx, img->i_1, W_WIDTH * x, W_HEIGHT * y);
	img->i_1->enabled = 0;
	mlx_image_to_window(game->mlx, img->i_2, W_WIDTH * x, W_HEIGHT * y);
	img->i_2->enabled = 0;
}

static void	window_tiling(t_data *game)
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
				apply_image(game, &game->wall, j, i);
			if (game->map[i][j] == '0')
				apply_image(game, &game->background, j, i);
			if (game->map[i][j] == 'P')
				apply_image(game, &game->player, j, i);
			if (game->map[i][j] == 'E')
				apply_image(game, &game->exit, j, i);
			if (game->map[i][j] == 'C')
				apply_image(game, &game->collectable, j, i);
			if (game->map[i][j] == 'V')
				apply_image(game, &game->enemy, j, i);
			if (game->map[i][j] == 'H')
				apply_image(game, &game->enemy, j, i);
		}
	}
}

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
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
		ft_printf("You have to pick up %i collectables!\n", game->c_count);
}

static void	ft_loop(void *param)
{
	t_data		*game;
	char		*temp;
	static int	i;

	game = param;
	if (i % 9 == 0)
	{
		animation(game);
		game->anim_counter++;
		if (game->anim_counter > 2)
			game->anim_counter = 0;
		enemy_movement(game);
	}
	temp = ft_itoa(game->moves);
	if (game->counter)
		mlx_delete_image(game->mlx, game->counter);
	game->counter = mlx_put_string(game->mlx, temp, 0, 0);
	free(temp);
	i++;
}

int	window_control(t_data *game)
{
	game->mlx = mlx_init(W_WIDTH * game->map_width, W_HEIGHT * game->map_height,
			"so_long", false);
	if (!game->mlx)
		return (error_message(game, 'W'));
	load_textures_and_images(game);
	window_tiling(game);
	mlx_key_hook(game->mlx, &ft_keyhook, game);
	mlx_loop_hook(game->mlx, &ft_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
