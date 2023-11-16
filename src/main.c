/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/16 18:52:19 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*	
	TODO:
	Function that returns error appropiate error message
	
	Window creation
	Window adjustment

	Background tiling
	Wall tiling
	
	Player image
	Player input (WASD, Escape)
	Player movement
	Hook for moves
	Moves on screen
	Player collision
	Player sprite movement
	
	Exit
	Coin image
	Coin counter
	Coin check for exit
	
	Enemy image
	Enemy movement
	Enemy player tracking?
	Gameover on enemy touch
	
	Correct termination of program
	Leak testing
*/

static int add_to_map(data_t *game, char *line)
{	
	char **temp;
	int i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = ft_calloc(game->map_height + 1, sizeof(char *));
	temp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	if (game->map)
		free(game->map);
	temp[i] = line;
	game->map = temp;
	return (1);
}

static int map_width(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void populate_map(data_t *game, char *av)
{
	char *temp_line;
	
	if ((game->fd = open(av, O_RDONLY)) < 0)
		return ;
	while (true)
	{
		temp_line = get_next_line(game->fd);
		if (!add_to_map(game, temp_line))
			break ;
	}
	close(game->fd);
	game->map_width = map_width(game->map[0]);
}

/*
	Does the map have walls (1) all around it
	Does the map only have one exit (E), one starting position (P) and at least one collectable (C)
	Is there a valid map from P to E collecting all C
*/

int is_width_consistent(char **map, size_t len)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

/*TODO: CHECK FOR P, C, and E*/
int is_map_playable(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (!ft_strchr(map[i], 'P')) // No initial position
			return (0);
		if (ft_strchr(map[i], 'P') && player_flag == 1) // More than one starting position
			return (0);
		if (!ft_strchr(map[i], 'C')) // No collectable
			return (0);
		if (!ft_strchr(map[i], 'E' && exit_flag == 1)) // No exit
			return (0);
		i++;
	}
	return (1);
}
/* TODO: CHECK FOR 1 ALL AROUND MAP */
int is_map_walled(char **map, size_t width, size_t height)
{
	int i;

	i = 0;
	if (ft_strncmp(map[0], "1", width)) // Checks for walls on the first row
		return (0);
	if (ft_stncmp(map[height], "1", width)) // Checks for walls on the last row
		return (0);
	while (map[i])
	{
		if (map[i][0] != 1)
			return (0);
		if (map[i][width] != 1)
			return (0);
		i++;
	}
	return (1);
}

int is_map_correct(data_t game)
{
	if (!is_width_consistent(game.map, (size_t)game.map_width))
		return (0);
	if (!is_map_playable(game.map))
		return (0);
	if (!is_map_walled(game.map, (size_t)game.map_width, (size_t)game.map_height))
		return (0);
	return (1);
} 

int main(int ac, char **av)
{
	data_t game;

	ft_memset(&game, 0, sizeof(data_t));
	if (ac == 2)
	{
		populate_map(&game, av[1]);
		if (!is_map_correct(game))
			return (0);
	}
}
