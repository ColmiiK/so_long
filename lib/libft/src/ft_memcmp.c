/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:08:40 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:54 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	int				j;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	j = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((n - 1) && (c1[i] == c2[j]))
	{
		i++;
		j++;
		n--;
	}
	return (c1[i] - c2[j]);
}
// int main()
// {
// 	char dst[20] = "lorem ipsum";
// 	char src[20] = "dolor sit a";
// 	size_t n = ft_strlen(dst);

// 	printf("%i\n", ft_memcmp(dst, src, n));
// }