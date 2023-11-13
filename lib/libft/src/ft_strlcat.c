/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:18:14 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/19 11:18:20 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;

	i = ft_strlen(dest);
	x = ft_strlen(src);
	j = 0;
	if (size < i)
		x += size;
	else
		x += i;
	while (src[j] && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (x);
}

/*

int	main(void)
{
	char	destination[11] = "Hello";
	char	*source = "World";

	strlcat(destination, source, 11);
	printf("%s\n", destination);
	return (0);
}
*/