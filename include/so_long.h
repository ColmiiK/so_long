/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/27 10:55:42 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 64
# define W_HEIGHT 64

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <math.h>

typedef struct s_data
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

}			t_data;

int		populate_map(t_data *game, char *av);
int			is_map_correct(t_data *game);
int			error_message(char code);
size_t		get_width(char *str);
int			window_control(t_data *game);
void window_tiling(t_data *game);

void apply_image(t_data *game, char *texture_path, int x, int y);
void move_player(t_data *game, int mod_y, int mod_x);
void apply_image_wall(t_data *game, char *texture_path, int x, int y);
void apply_image_collectable(t_data *game, char *texture_path, int x, int y);
void apply_image_background(t_data *game, char *texture_path, int x, int y);
void apply_image_player(t_data *game, char *texture_path, int x, int y);
void apply_image_exit(t_data *game, char *texture_path, int x, int y);
void apply_image_enemy(t_data *game, char *texture_path, int x, int y);

#endif