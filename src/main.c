/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/16 13:09:56 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int add_to_map(data_t *game, char *line)
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
	for (int i = 0; i < game->map_height; i++)
		ft_printf("%s", game->map[i]);

}

int main(int ac, char **av)
{
	data_t game;

	ft_memset(&game, 0, sizeof(data_t));
	if (ac == 2)
	{
		populate_map(&game, av[1]);
	}
}
