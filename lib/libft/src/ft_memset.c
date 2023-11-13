/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:16 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/11 16:35:05 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = str;
	while (i != len)
	{
		temp[i] = c;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[20];

	str[20] = "Hello World";
	printf("%s\n", str);
	memset(str + 3, '.', 3);
	printf("%s", str);
}
*/