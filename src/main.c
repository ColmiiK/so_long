/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:34:57 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/15 13:51:22 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **check_map(char *file)
{
	char **map;
	int fd;

	fd = open(file, O_RDONLY);
	
	get_next_line()
}


int main(int ac, char **av)
{
	char **map;
	
	map = check_map(av[1]);
	if (map)
		init_game(map);
	else
		return (0);
}
