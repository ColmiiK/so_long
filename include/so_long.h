/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/20 20:45:22 by alvega-g         ###   ########.fr       */
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
	void *collectable;
	void *mlx_pointer;
	void *window_pointer;
	
}	data_t;

void populate_map(data_t *game, char *av);
int is_map_correct(data_t *game);
int error_message(char code);
size_t get_width(char *str);


#endif