/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:11:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:20:29 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (s || f)
	{
		while (i < len)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}

// void	print(unsigned int index, char *c)
// {
// 	printf("%d: %c\n", index, *c);
// }

// int	main(void)
// {
// 	char *str = "lorem ipsum dolor sit amet";

// 	ft_striteri(str, print);
// }