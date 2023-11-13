/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:24:34 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/14 13:59:26 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)s;
	if (!c && !n)
		return (0);
	while (i < n)
	{
		if ((unsigned char)c == src[i])
			return ((void *)&src[i]);
		else
			i++;
	}
	return (0);
}

// int main()
// {
//    char *s = "Hello";
//    printf("%s", (char *)memchr(s, 0, 1));
// 	printf("%s", (char *)ft_memchr(s, 0, 1));
// }
