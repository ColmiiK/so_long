/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:32:09 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:43 by alvega-g         ###   ########.fr       */
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

typedef struct s_image
{
	void		*t_0;
	mlx_image_t	*i_0;
}				t_image;

typedef struct s_data
{
	mlx_t		*mlx;
	int			fd;
	int			map_width;
	int			map_height;
	int			c_count;
	int			p_count;
	int			e_count;
	int			v_e_count;
	int			h_e_count;
	int			moves;
	int			player_x_pos;
	int			player_y_pos;
	int			exit_x_pos;
	int			exit_y_pos;
	int			x;
	int			y;
	bool		v_enemy_flag;
	bool		h_enemy_flag;

	char		**map;
	mlx_image_t	*counter;
	t_image		wall;
	t_image		background;
	t_image		player;
	t_image		exit;
	t_image		collectable;
	t_image		enemy;
	int			anim_counter;
	void		*window;
}				t_data;

int				populate_map(t_data *game, char *av);
int				is_map_correct(t_data *game);
int				error_message(t_data *game, char code);
size_t			get_width(char *str);
int				window_control(t_data *game);
void			apply_image(t_data *game, t_image *img, int x, int y);
void			move_player(t_data *game, int mod_y, int mod_x);
void			obtain_player_exit_pos(t_data *game);
int				is_map_doable(t_data *game);
void			ft_annihilation(t_data *game);
int				check_for_letters(t_data *game);
void			enemy_movement(t_data *game);
void			animation(t_data *game);
void			load_textures(t_data *game);
void			load_images_0(t_data *game);
void			load_images_1(t_data *game);
void			load_images_2(t_data *game);
void			mini_window_tiling(t_data *game);
void			delete_images(t_data *game);
void			load_textures_and_images(t_data *game);
void			coin_count(t_data *game);

#endif