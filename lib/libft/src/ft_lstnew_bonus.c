/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:43:55 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/17 11:06:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
// int	main(void)
// {
// 	t_list *head = malloc(sizeof(t_list));

// 	char *content = "lorem ipsum dolor sit amet";

// 	head->content = "test";
// 	head->next = ft_lstnew(content);

// 	printf("%s\n", head->next->content);

// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }