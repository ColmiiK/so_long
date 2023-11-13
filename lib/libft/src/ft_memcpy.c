/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:31:29 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/19 11:11:15 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*temp_dst;
	const char		*temp_src;

	i = 0;
	temp_dst = dst;
	temp_src = src;
	if (!temp_dst && !temp_src)
		return (0);
	while (i != n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
// int main()
// {
// 	char dst[20] = "lorem ipsum";
// 	char src[20] = "dolor sit amet";
// 	size_t n = 5;

// 	printf("%s\n", ft_memcpy(dst, src, n));
// }