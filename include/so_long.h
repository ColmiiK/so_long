/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/29 12:19:18 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_WIDTH 64
# define W_HEIGHT 64

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/include/libft.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_data
{
	void	*mlx;
	int		fd;
	int		map_width;
	int		map_height;
	int		c_count;
	int		p_count;
	int		e_count;
	int		moves;
	int		player_x_pos;
	int		player_y_pos;
	int		exit_x_pos;
	int		exit_y_pos;
	int		x;
	int		y;

	char	**map;
	void	*wall_img;
	void	*background_img;
	void	*player_img;
	void	*exit_img;
	void	*collectable_img;
	void	*enemy_img;
	void	*wall_tex;
	void	*background_tex;
	void	*player_tex;
	void	*exit_tex;
	void	*collectable_tex;
	void	*enemy_tex;
	void	*window;
}			t_data;

int			populate_map(t_data *game, char *av);
int			is_map_correct(t_data *game);
int			error_message(t_data *game, char code);
size_t		get_width(char *str);
int			window_control(t_data *game);
void		window_tiling(t_data *game);

void		apply_image(t_data *game, void *img, int x, int y);
void		move_player(t_data *game, int mod_y, int mod_x);
void		obtain_player_exit_pos(t_data *game);
int			is_map_doable(t_data *game);
void		ft_annihilation(t_data *game);

#endif