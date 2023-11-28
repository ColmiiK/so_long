/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:12:46 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/28 13:37:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*

	Starting from player position, check if all coins and the exit can be reached
	If not, the map is not valid
	
	Starting from player_x and player_y pos, move in all directions as long as there is not a wall
	Each time a coin is reached, substract one from game->c_count
	If flag is reached, activate exit_flag
	If c_count == 0 and exit_flag == 1, then map is valid
	

*/

static void free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (i > 0)
		free(map);
	map = NULL;
}

static bool flood_fill(t_data *game, int x, int y, char **valid)
{
	static int coins = 0;
	static bool exit_flag = false;
	
	if (valid[y][x] == '1')
		return (false);
	else if (valid[y][x] == 'C')
		coins++;
	else if (valid[y][x] == 'E')
		exit_flag = true;
	valid[y][x] = '1';
	flood_fill(game, x + 1, y, valid);
	flood_fill(game, x - 1, y, valid);
	flood_fill(game, x, y + 1, valid);
	flood_fill(game, x, y - 1, valid);
	if (coins == game->c_count && exit_flag == true)
		return (true);
	return (false);
}

static char **map_creation(t_data *game)
{
	int i;
	char **check_map;
	
	i = -1;
	check_map = ft_calloc((game->map_height + 1), sizeof(char *));
	while (++i < game->map_height)
		check_map[i] = ft_strdup(game->map[i]);
	return (check_map);
}

int is_map_playable(t_data *game)
{
	char **valid;

	valid = map_creation(game);
	if (!flood_fill(game, game->player_x_pos, game->player_y_pos, valid))
	{
		free_map(valid);
		return (1);
	}
	free_map(valid);
	return (0);
}
