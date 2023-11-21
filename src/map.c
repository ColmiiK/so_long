/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:09 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/21 11:58:42 by alvega-g         ###   ########.fr       */
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
	game->map_width = get_width(game->map[0]);
}

static int is_map_playable(data_t *game)
{
	int i;
	int player_flag;
	int exit_flag;
	
	i = 0;
	player_flag = 0;
	exit_flag = 0;
	while (game->map[i])
	{
		if (get_width(game->map[i]) != (size_t)game->map_width)
			return (0);
		if (ft_strchr(game->map[i], 'P'))
			player_flag++;
		if (ft_strchr(game->map[i], 'E'))
			exit_flag++;
		if (ft_strchr(game->map[i], 'C'))
			game->collectables++;
		i++;
	}
	if (game->collectables < 1)
		return (0);
	if (player_flag != 1)
		return (0);
	if (exit_flag != 1)
		return (0);
	return (1);
}
/* TODO: CHECK FOR 1 ALL AROUND MAP */
static int is_map_walled(data_t *game)
{
	int i;

	i = 0;
	if (ft_strchr(game->map[0], '0'))
		return (0);
	if (ft_strchr(game->map[game->map_height - 1], '0'))
		return (0);
	while (game->map[i]) // Checks for walls on the first and last column
	{
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int is_map_correct(data_t *game)
{
	if (!is_map_playable(game))
		return (error_message('M'));
	if (!is_map_walled(game))
		return (error_message('M'));
	return (1);
} 