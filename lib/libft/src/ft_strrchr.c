/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:54:00 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:55 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	overflow(int c)
{
	while (c > 255)
		c -= 256;
	return (c);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	c = overflow(c);
	if (!s[i] && c == '\0')
		return ((char *)&s[i]);
	while (s[i])
	{
		if (c == s[i])
		{
			temp = (char *)&s[i];
			i++;
		}
		else if (c == '\0')
		{
			while (s[i])
				i++;
			return ((char *)&s[i]);
		}
		else
			i++;
	}
	return (temp);
}

// int main()
// {
// 	char *s = "";
// 	printf("%s\n", strrchr(s, '\0' + 256));
// 	printf("%s\n", ft_strrchr(s, '\0' + 256));
// }
