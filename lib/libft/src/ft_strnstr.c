/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:18:44 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:52 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j])
	{
		while (haystack[j + i] == needle[i] && needle[i] && j + i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + j);
		i = 0;
		j++;
	}
	return (0);
}

// int main()
// {
// 	char * big = "123456789";
//     char * little = "9";
//	size_t max = 8;
//     char *s1 = strnstr(big, little, max);
//     char *s2 = ft_strnstr(big, little, max);

// 	printf("%s\n%s\n", s1, s2);
// }