/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:04:32 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/21 13:22:55 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_hook(void *param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int window_control(data_t *game)
{
	game->mlx = mlx_init(W_WIDTH, W_HEIGHT, "so_long", true);
	if (!game->mlx)
		return (error_message('W'));
	mlx_loop_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	return (0);
}
