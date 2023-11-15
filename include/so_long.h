/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/15 16:33:08 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 1200
# define W_HEIGHT 1200



# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <math.h>

typedef struct data_s
{	
	int fd;
	int map_width;
	int map_height;
	int collectables;
	
	char **map;
	void *floor;
	void *wall;
	void *player;
	void *exit;
	void *collectable;
	void *mlx_pointer;
	void *window_pointer;
	
}	data_t;

#endif