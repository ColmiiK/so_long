/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:37:26 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:24 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c > 255)
		c -= 256;
	while (s[i])
	{
		if (c == s[i])
			return ((char *)&s[i]);
		else
			i++;
	}
	if (c == '\0')
		return ((char *)&s[i++]);
	return (0);
}

// int main()
// {
// 	char *s = "Hola";

// 	printf("%s\n", ft_strchr(s, 'a' + 256));
// }