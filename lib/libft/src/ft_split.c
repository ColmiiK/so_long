/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:11:01 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:21 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	*fill(const char *s, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((end - start + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (start < end)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	int				index;
	char			**split;

	i = 0;
	j = 0;
	index = -1;
	split = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = fill(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// int	main(void)
// {
// 	char *s = "lorem ipsum dolor sit amet";
// 	char c = 32;
// 	char **split = ft_split(s, c);
// 	int i = 0;

// 	while (i < word_count(s, c))
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	free(split);
// }