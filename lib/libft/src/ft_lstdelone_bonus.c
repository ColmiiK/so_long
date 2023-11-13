/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:17:37 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:32 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// t_list	*create_node(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (new_node)
// 	{
// 		new_node->content = content;
// 		new_node->next = NULL;
// 	}
// 	return (new_node);
// }

// int	main(void)
// {
// 	t_list *head = create_node("lorem");
// 	ft_lstdelone(head, del);

// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }