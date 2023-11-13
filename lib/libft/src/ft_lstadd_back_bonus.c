/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:33:50 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:26 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

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
// 	t_list *head = malloc(sizeof(t_list));
// 	head->content = "lorem";

// 	t_list *new = create_node("ipsum");
// 	ft_lstadd_back(&head, new);
// 	while (head)
// 	{
// 		printf("%s\n", head->content);
// 		head = head->next;
// 	}

// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }