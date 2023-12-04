/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:04:21 by alvega-g          #+#    #+#             */
/*   Updated: 2023/12/04 14:07:37 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

size_t	get_width(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

void	obtain_player_exit_pos(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x_pos = j;
				game->player_y_pos = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x_pos = j;
				game->exit_y_pos = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_annihilation(t_data *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		free(game->map[i]);
	free(game->map);
	if (game->wall_i)
	{
		mlx_delete_image(game->mlx, game->wall_i);
		mlx_delete_image(game->mlx, game->background_i);
		mlx_delete_image(game->mlx, game->player_i);
		mlx_delete_image(game->mlx, game->collectable_i);
		mlx_delete_image(game->mlx, game->exit_i);
		mlx_delete_image(game->mlx, game->enemy_i);
		mlx_delete_texture(game->wall_t);
		mlx_delete_texture(game->background_t);
		mlx_delete_texture(game->player_t);
		mlx_delete_texture(game->collectable_t);
		mlx_delete_texture(game->exit_t);
		mlx_delete_texture(game->enemy_t);
		mlx_terminate(game->mlx);
	}
}

int	check_for_letters(t_data *game)
{
	int		i;
	int		j;
	char	*allowed;

	allowed = "10PCE\n";
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!ft_strchr(allowed, game->map[i][j]))
				return (1);
		}
	}
	return (0);
}
