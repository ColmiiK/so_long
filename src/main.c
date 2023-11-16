/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/16 14:00:52 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int map_check(char **map, int len)
{
	int i;
	
	int player_flag;
	int exit_flag;
	
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len) // Inconsistent width
			return (0);
		if (!ft_strchr(map[i], "P")) // No initial position
			return (0);
		if (ft_strchr(map[i], "P") && player_flag == 1) // More than one starting position
			return (0);
		if (!ft_strchr(map[i], "C")) // No collectable
			return (0);
		if (!ft_strchr(map[i], "E" && exit_flag == 1)) // No exit
			return (0);
		i++;
	}
	return (1);
}
int is_map_correct(data_t game)
{
	if (!map_check(game->map, game->map_width));
		return (0);
	
	
} 

int main(int ac, char **av)
{
	data_t game;

	ft_memset(&game, 0, sizeof(data_t));
	if (ac == 2)
	{
		populate_map(&game, av[1]);
		if (!is_map_correct(&game))
			return (0);
	}
}
