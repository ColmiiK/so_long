/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:59 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/14 16:48:25 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
static mlx_image_t* player;
static mlx_image_t* background;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		player->instances[0].y -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		player->instances[0].y += 10;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		player->instances[0].x -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		player->instances[0].x += 10;
	ft_printf("%f", mlx->delta_time);
}

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(W_WIDTH, W_HEIGHT, "sus", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// Background texture
	mlx_texture_t* background_texture = mlx_load_png("./textures/space.png");
	background = mlx_texture_to_image(mlx, background_texture);
	mlx_image_to_window(mlx, background, 0, 0);

	// Player textures
	mlx_texture_t* player_texture = mlx_load_png("./textures/sus.png");
	player = mlx_texture_to_image(mlx, player_texture);
	mlx_image_to_window(mlx, player, 500, 500);
	
	// Hook to move the character
	mlx_loop_hook(mlx, ft_hook, mlx);

	// Keep the window open and functioning
	mlx_loop(mlx);

	// Terminate execution
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
