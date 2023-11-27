/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:12:46 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/27 13:39:14 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	**create_bool_matrix(t_data *game)
{
	bool	**matrix;
	int		i;
	int		j;

	i = -1;
	j = -1;
	matrix = (bool **)malloc(game->map_height * sizeof(bool *));
	if (!matrix)
		return (NULL);
	while (++i < game->map_height)
	{
		matrix[i] = (bool *)malloc(game->map_width * sizeof(bool));
		if (!matrix[i])
		{
			while (++j < i)
				free(matrix[j]);
			free(matrix);
			return (NULL);
		}
		while (++j < game->map_width)
			matrix[i][j] = false;
	}
	return (matrix);
}

static void	free_bool_matrix(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->visited[i]);
		i++;
	}
	free(game->visited);
}

bool	validate_map(t_data *game)
{
	int	x;
	int	y;
	int	orig_x;
	int	orig_y;

	x = game->player_x_pos;
	y = game->player_y_pos;
	if (game->c_count == 0 && game->e_count == 1)
		return (true);
	if (x < 0 || y < 0 || x >= game->map_height || y >= game->map_width
		|| game->map[x][y] == '1')
		return (false);
	if (game->map[x][y] == 'C')
		game->c_count--;
	if (game->map[x][y] == 'E')
		game->e_count++;
	game->map[x][y] = '1';
	orig_x = game->player_x_pos;
	orig_y = game->player_y_pos;
	game->player_x_pos = orig_x - 1;
	if (validate_map(game))
		return (true);
	game->player_x_pos = orig_x + 1;
	if (validate_map(game))
		return (true);
	game->player_y_pos = orig_y - 1;
	if (validate_map(game))
		return (true);
	game->player_y_pos = orig_y + 1;
	if (validate_map(game))
		return (true);
	game->player_x_pos = orig_x;
	game->player_y_pos = orig_y;
	return (false);
}

bool	is_map_doable(t_data *game)
{
	bool	result;

	game->visited = create_bool_matrix(game);
	result = validate_map(game);
	free_bool_matrix(game);
	return (result);
}
