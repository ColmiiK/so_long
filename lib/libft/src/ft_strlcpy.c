/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:11:40 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:39 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

/*

int	main()
{
	char a[] = "Source";
	char b[] = "Destination";
	unsigned int c = 5;

	printf("STRING A = %s\n", a);
	printf("STRING B = %s\n", b);
	ft_strlcpy(a, b, c);
	printf("STRING cambiado = %s\n", a);
	return (0);
}
*/