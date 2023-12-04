/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:42:49 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/04 16:43:30 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int 	v_e_count;
	int		h_e_count;
	int		moves;
	void 	*counter;
	int		player_x_pos;
	int		player_y_pos;
	int		exit_x_pos;
	int		exit_y_pos;
	int		x;
	int		y;
	bool	v_enemy_flag;
	bool	h_enemy_flag;
	int frame_counter;
	int frame_duration;

	char	**map;
	void	*wall_i;
	void	*background_i;
	void	*player_i;
	void	*exit_i;
	void	*collectable_i;
	void	*enemy_i;
	void	*wall_t;
	void	*background_t;
	void	*player_t;
	void	*exit_t;
	void	*collectable_t;
	void	*enemy_t;
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
int			check_for_letters(t_data *game);
void		load_sprites(t_data *game);
void move_vertical_enemy(t_data *game);
void move_horizontal_enemy(t_data *game);
void r_move_vertical_enemy(t_data *game);
void r_move_horizontal_enemy(t_data *game);
void enemy_movement(t_data *game);

#endif