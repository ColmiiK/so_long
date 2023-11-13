/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:15:26 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:49 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while ((n - 1) && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
/*

int	main(void)
{
	char string1[] = "ABCDe";
	char string2[] = "ABCDf";
	unsigned int chars_to_compare = 10;

	int resultado = ft_strncmp(string1, string2, chars_to_compare);
	int resultado_ofi = strncmp(string1, string2, chars_to_compare);
	printf("%d\n", resultado);
	printf("%d\n", resultado_ofi);
}
*/