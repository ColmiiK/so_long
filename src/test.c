/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:59 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/14 13:16:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	const mlx_t *mlx = param;
	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	// Starts mlx
	mlx_t* mlx = mlx_init(W_WIDTH, W_HEIGHT, "Test", true);
	if (!mlx)
		ft_error();
	
	// Loads the texture
	mlx_texture_t* texture = mlx_load_png("./textures/space.png");
	if (!texture)
		ft_error();
	
	// Converts the texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error();
	
	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
