/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/22 11:40:36 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 64
# define W_HEIGHT 64

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <math.h>

typedef struct data_s
{
	int		fd;
	int		map_width;
	int		map_height;
	int		number_of_collectables;

	char	**map;
	void 	*mlx;
	void	*window;
	void	*background;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*enemy;
	void	*exit;

}			data_t;

int		populate_map(data_t *game, char *av);
int			is_map_correct(data_t *game);
int			error_message(char code);
size_t		get_width(char *str);
int			window_control(data_t *game);

#endif