/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:09 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/27 11:36:36 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	add_to_map(t_data *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (1);
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
	return (0);
}

int	populate_map(t_data *game, char *av)
{
	char	*temp_line;

	if (!ft_strnstr(av, ".ber", ft_strlen(av)))
		return (1);
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
		return (1);
	while (true)
	{
		temp_line = get_next_line(game->fd);
		if (add_to_map(game, temp_line))
			break ;
	}
	close(game->fd);
	game->map_width = get_width(game->map[0]);
	return (0);
}

static int	is_map_playable(t_data *game)
{
	int	i;
	int	player_flag;
	int	exit_flag;

	i = -1;
	player_flag = 0;
	exit_flag = 0;
	while (game->map[++i])
	{
		if (get_width(game->map[i]) != (size_t)game->map_width)
			return (1);
		if (ft_strchr(game->map[i], 'P'))
			player_flag++;
		if (ft_strchr(game->map[i], 'E'))
			exit_flag++;
		if (ft_strchr(game->map[i], 'C'))
			game->number_of_collectables++;
	}
	if (game->number_of_collectables < 1)
		return (1);
	if (player_flag != 1)
		return (1);
	if (exit_flag != 1)
		return (1);
	return (0);
}

static int	is_map_walled(t_data *game)
{
	int	i;

	i = 0;
	if (ft_strchr(game->map[0], '0'))
		return (1);
	if (ft_strchr(game->map[game->map_height - 1], '0'))
		return (1);
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (1);
		if (game->map[i][game->map_width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_map_correct(t_data *game)
{
	if (is_map_playable(game))
		return (1);
	if (is_map_walled(game))
		return (1);
	return (0);
}
