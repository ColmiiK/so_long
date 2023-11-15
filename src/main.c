/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/15 16:53:35 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int add_to_map(data_t *game, char *line, int index)
{
	char *temp;

	temp = ft_calloc(ft_strlen(line), sizeof(char));
	
	temp = ft_strjoin(line, game->map[index]);
	game->map[index] = temp;
	if (!game->map[index])
		return (0);
	return (1);
}

void populate_map(data_t *game, char *av)
{
	char *line;
	int i;

	i = 0;
	if ((game->fd = open(av, O_RDONLY)) < 0)
		return ;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!(add_to_map(game, line, i)))
			break ;
		i++;
	}
	close(game->fd);
}

int main(int ac, char **av)
{
	data_t game;

	if (ac == 2)
	{
		populate_map(&game, av[1]);
		for (int i = 0; i < 20; i++)
			ft_printf("%s", game.map[i]);
	}
}
