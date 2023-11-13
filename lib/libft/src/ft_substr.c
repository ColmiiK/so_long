/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:12:11 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/14 11:00:42 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*subs;

	i = 0;
	j = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (!subs)
		return (0);
	while (s[i] && i < start)
		i++;
	while (s[i] && j < len)
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = 0;
	return (subs);
}

// int main()
// {
// 	char *s = "";
// 	unsigned int start = 3;
// 	size_t len = 5;
// 	char *subs =  ft_substr(s, start, len);
// 	printf("%s\n", subs);
// 	free(subs);
// }