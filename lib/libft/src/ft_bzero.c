/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:26:41 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:18:47 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = str;
	while (i != n)
	{
		temp[i] = 0;
		i++;
	}
	return (str);
}

// int main()
// {
// 	char str[30] = "lorem ipsum dolor sit amet";
// 	size_t n = 0;

// 	printf("%s\n", ft_bzero(str, n));
// }